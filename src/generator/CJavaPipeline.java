package generator;

import c.CClass;
import c.CDeclaration;
import c.CEnum;
import c.DeclarationType;
import generator.c.Bind;
import generator.c.HeaderMaker;
import generator.c.IdCache;
import generator.c.TypeTable;
import generator.ccalls.CallImplementer;
import impl.CApiParser;
import impl.Clazz;
import util.FileUtils;

import java.io.*;
import java.lang.reflect.Array;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 5.3.2014
 * Time: 16:30
 */
@SuppressWarnings("ConstantConditions")
public class CJavaPipeline {

    public static final int BWAPI_V3 = 3;

    public static final int BWAPI_V4 = 4;


    public static int BWAPI_VERSION = BWAPI_V3;

    /**
     * Classes from BWAPI 4 that don't need mirroring
     * Not used in mirroring BWAPI 3
     */
    private static final List<String> ignoredClasses = new ArrayList<>(Arrays.asList("Vectorset", "ConstVectorset", "VSetIterator",
            "Interface", "RectangleArray", "UnitImpl", "PlayerImpl", "GameImpl", "BulletImpl", "ForceImpl", "TournamentModule", "RegionImpl"));


    private static final HashMap<String, String> superClasses = new HashMap<>();

    static {
        superClasses.put("Unit", "PositionedObject");
        superClasses.put("Region", "CenteredObject");
        superClasses.put("Chokepoint", "CenteredObject");
        superClasses.put("BaseLocation", "PositionedObject");
    }

    public void run(PackageProcessOptions[] packages, Properties processingOptions) {
        /**
         Init
         */
        for (PackageProcessOptions pkg : packages) {
            FileUtils.deleteDirectory(new File(pkg.packageName));
        }

        MirrorContext context = new MirrorContext();
        Generator generator = new Generator(context);
        generator.setJavaSuperClasses(superClasses);
        List<CDeclaration> allDecs = new ArrayList<>();

        /**
         * Phase 1 & 2 - parse headers and create .java source files
         */
        for (PackageProcessOptions pkg : packages) {
            CApiParser parser = new CApiParser();

            //create a class to hold global functions (currently used to create BWTA.java)
            if (pkg.globalClassName != null) {
                parser.setGlobalClass(new Clazz(pkg.globalClassName) {
                    @Override
                    public boolean isStatic() {
                        return true;
                    }
                });
            }

            //bwta needs some imports from bwapi
            if (pkg.additionalImportClasses != null) {
                context.setAdditionalImports(pkg.additionalImportClasses);
            }

            //parse the headers
            List<CDeclaration> cClasses = parser.parseDir(pkg.cHeadersDir);


            //reset the generator
            generator.flush();
            //separate classes and enums and/or filter out classes
            for (CDeclaration cDeclaration : cClasses) {
                if (ignoredClasses.contains(cDeclaration.getName())) {
                    continue;
                }
                if (cDeclaration.getDeclType().equals(DeclarationType.CLASS)) {
                    generator.addClass((CClass) cDeclaration);
                } else if (cDeclaration.getDeclType().equals(DeclarationType.ENUM)) {
                    generator.addEnum((CEnum) cDeclaration);
                }
            }
            //run the generator to create .java source files
            context.setPackage(pkg.packageName);
            generator.run(new File("."));

            //store declarations for later (for binding constants)
            allDecs.addAll(cClasses);
        }

        /**
         * Phase 3 - copy additional classes into api, such as Mirror.java, AIModule, EventListener, etc
         */
        for (PackageProcessOptions pkg : packages) {
            if (pkg.manualCopyClassesDir != null) {
                try {
                    for (File file : pkg.manualCopyClassesDir.listFiles()) {
                        Files.copy(file.getAbsoluteFile().toPath(), new File(pkg.packageName + "/" + file.getName()).getAbsoluteFile().toPath(), StandardCopyOption.REPLACE_EXISTING);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }


        /**
         * Phase 4 - compile .java sources
         */
        File javaOut = new File(processingOptions.getProperty(COMPILE_DIR_PROPERTY));
        MyJavaCompiler compiler = new MyJavaCompiler();

        for (PackageProcessOptions pkg : packages) {
            compiler.run(new File(pkg.packageName), javaOut);
        }

        /**
         * Phase 5 - run javah to create header files for native functions
         */
        List<String> packageDirNames = new ArrayList<>();
        for (PackageProcessOptions pkg : packages) {
            packageDirNames.add(pkg.packageName);
        }
        HeaderMaker hm = new HeaderMaker();
        hm.run(packageDirNames, javaOut, processingOptions.getProperty(HEADER_FILE_PROPERTY) , processingOptions.getProperty(HEADERS_DIR_PROPERTY));

        /**
         * Phase 6 - implementation of native functions
         */

        JavaContext javaContext = new JavaContext();
        CallImplementer callImplementer = new CallImplementer(javaContext);

        TypeTable typeTable = new TypeTable();

        PrintStream out = null;
        try {
            out = new PrintStream(new FileOutputStream(new File(processingOptions.getProperty(C_IMPLEMENTATION_FILE_PROPERTY))));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        callImplementer.setOut(out);
        typeTable.setOut(out);

        /**
         * Phase 6.1 - implement caches
         */
        //caches for constants
        typeTable.implementTypeTable(allDecs);

        //caches for methodIds, fieldIds, classes
        IdCache idCache = new IdCache();
        idCache.setOut(out);
        idCache.implementCache();

        /**
         * Phase 6.2 - implement the native function bodies
         */

        File headersDir = new File(processingOptions.getProperty(HEADERS_DIR_PROPERTY));

        for (PackageProcessOptions pkg : packages) {
            callImplementer.setBwtaMode(pkg.packageName.equals("bwta"));
            javaContext.setPackageName(pkg.packageName);

            for (File file : new File(pkg.packageName).listFiles(new FilenameFilter() {
                @Override
                public boolean accept(File dir, String name) {
                    //we skip mirror.java as it has a native function which we implement manually
                    return !name.equals("Mirror.java") && name.endsWith(".java");
                }
            })) {

                //pair each .java file with its native header file
                File header = new File(headersDir, pkg.packageName + "_" + file.getName().substring(0, file.getName().lastIndexOf(".")) + ".h");
                try {
                    //implement the native method bodies
                    callImplementer.implementMethodCalls(file, header);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        callImplementer.setBwtaMode(false);

        /**
         * Phase 6.3 - bind the remaining part of the java API to the C part:
         * Bind constants together and create initialisation function
         */

        Bind bind = new Bind();
        bind.setOut(out);
        bind.implementBind(allDecs);

    }

    public static void main(String... args) {

        if (BWAPI_VERSION == BWAPI_V3) {

            PackageProcessOptions bwapiOptions = new PackageProcessOptions();
            bwapiOptions.packageName = "bwapi";
            bwapiOptions.cHeadersDir = new File("bwapi-master");
            bwapiOptions.manualCopyClassesDir = new File("manual-bwapi");

            PackageProcessOptions bwtaOptions = new PackageProcessOptions();
            bwtaOptions.packageName = "bwta";
            bwtaOptions.cHeadersDir = new File("bwta-c");
            bwtaOptions.additionalImportClasses = Arrays.asList("bwapi.Position", "bwapi.TilePosition", "bwapi.Player");
            bwtaOptions.globalClassName = "BWTA";

            Properties props = new Properties();
            props.put(COMPILE_DIR_PROPERTY, "compiled");
            props.put(HEADERS_DIR_PROPERTY, "headers");
            props.put(HEADER_FILE_PROPERTY, "concat_header.h");
            props.put(C_IMPLEMENTATION_FILE_PROPERTY, "c/impl.cpp");

            new CJavaPipeline().run(new PackageProcessOptions[]{bwapiOptions, bwtaOptions}, props);
        }

        if (BWAPI_VERSION == BWAPI_V4) {

            ignoredClasses.add("Position");

            PackageProcessOptions bwapiOptions = new PackageProcessOptions();
            bwapiOptions.packageName = "bwapi4";
            bwapiOptions.cHeadersDir = new File("bwapi4-includes");
            bwapiOptions.manualCopyClassesDir = new File("manual-bwapi4");

            Properties props = new Properties();
            props.put(COMPILE_DIR_PROPERTY, "compiled4");
            props.put(HEADERS_DIR_PROPERTY, "headers4");
            props.put(HEADER_FILE_PROPERTY, "concat_header4.h");
            props.put(C_IMPLEMENTATION_FILE_PROPERTY, "c4/impl.cpp");

            new CJavaPipeline().run(new PackageProcessOptions[]{bwapiOptions}, props);
        }

    }

    private static final String COMPILE_DIR_PROPERTY = "compiled_dir";
    private static final String HEADERS_DIR_PROPERTY = "headers_dir";
    private static final String C_IMPLEMENTATION_FILE_PROPERTY = "impl_file";
    private static final String HEADER_FILE_PROPERTY = "header_file";

}
