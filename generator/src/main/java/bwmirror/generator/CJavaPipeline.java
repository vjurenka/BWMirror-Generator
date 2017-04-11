package bwmirror.generator;

import bwmirror.api.DefaultEventListener;
import bwmirror.api.GeneratorEventListener;
import bwmirror.c.CClass;
import bwmirror.c.CDeclaration;
import bwmirror.c.CEnum;
import bwmirror.c.DeclarationType;
import bwmirror.generator.c.Bind;
import bwmirror.generator.c.HeaderMaker;
import bwmirror.generator.c.IdCache;
import bwmirror.generator.c.TypeTable;
import bwmirror.generator.ccalls.CallImplementer;
import bwmirror.impl.CApiParser;
import bwmirror.impl.Clazz;
import bwmirror.inject.GetPolygonPointsInjector;
import org.apache.commons.io.FileUtils;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
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

    /**
     * Classes from BWAPI 4 that don't need mirroring
     */
    private static final List<String> ignoredClasses = new ArrayList<>(Arrays.asList(
        "Client",
        "Vectorset",
        "ConstVectorset",
        "VSetIterator",
        "GameWrapper",
        "Interface",
        "RectangleArray",
        "UnitImpl",
        "PlayerImpl",
        "GameImpl",
        "BulletImpl",
        "ForceImpl",
        "TournamentModule",
        "RegionImpl",
        "SetContainer",
        "InterfaceEvent",
        "PositionOrUnit",
        "Point"
    ));

    private static final HashMap<String, String> superClasses = new HashMap<>();

    private GeneratorEventListener listener = new DefaultEventListener();

    static {
        superClasses.put("Unit", "PositionedObject");
        superClasses.put("Region", "CenteredObject");
        superClasses.put("Chokepoint", "CenteredObject");
        superClasses.put("BaseLocation", "PositionedObject");
    }

    public CJavaPipeline() {
        listener = new GetPolygonPointsInjector();
    }

    public void run(PackageProcessOptions[] packages, Properties processingOptions) throws Exception {
        PackageProcessOptions bwapiOptions = packages[0];
        PackageProcessOptions bwtaOptions = packages[1];

        System.out.println("BWAPI package processing options:");
        System.out.println("  cHeadersDir = " + bwapiOptions.cHeadersDir);
        System.out.println("  manualCopyClassesDir = " + bwapiOptions.manualCopyClassesDir);
        System.out.println();

        System.out.println("BWTA package processing options:");
        System.out.println("  cHeadersDir = " + bwtaOptions.cHeadersDir);
        System.out.println("  manualCopyClassesDir = " + bwtaOptions.manualCopyClassesDir);
        System.out.println();

        System.out.println("Processing options:");
        for (String propKey : processingOptions.stringPropertyNames())
            System.out.println("   " + propKey + " = " + processingOptions.getProperty(propKey));

        // some input path/files sanity checking first ...
        if (bwapiOptions.cHeadersDir != null && !bwapiOptions.cHeadersDir.exists())
            throw new FileNotFoundException("BWAPI cHeadersDir not found: " + bwapiOptions.cHeadersDir.toString());
        if (bwapiOptions.manualCopyClassesDir != null && !bwapiOptions.manualCopyClassesDir.exists())
            throw new FileNotFoundException("BWAPI manualCopyClassesDir not found: " + bwapiOptions.manualCopyClassesDir.toString());
        if (bwtaOptions.cHeadersDir != null && !bwtaOptions.cHeadersDir.exists())
            throw new FileNotFoundException("BWTA cHeadersDir not found: " + bwtaOptions.cHeadersDir.toString());
        if (bwtaOptions.manualCopyClassesDir != null && !bwtaOptions.manualCopyClassesDir.exists())
            throw new FileNotFoundException("BWTA manualCopyClassesDir not found: " + bwtaOptions.manualCopyClassesDir.toString());

        /**
         Init
         */
        System.out.println("\n\nInit");
        System.out.println("Cleaning existing generated output");
        for (PackageProcessOptions pkg : packages) {
            FileUtils.deleteDirectory(new File(processingOptions.getProperty(GENERATE_TO_DIR) + "/" + pkg.packageName));
        }
        FileUtils.deleteDirectory(new File(processingOptions.getProperty(HEADERS_DIR_PROPERTY)));
        FileUtils.deleteDirectory(new File(processingOptions.getProperty(COMPILE_DIR_PROPERTY)));
        FileUtils.deleteDirectory(new File(processingOptions.getProperty(C_IMPLEMENTATION_FILE_PROPERTY)).getParentFile());
        FileUtils.deleteDirectory(new File(processingOptions.getProperty(HEADER_FILE_PROPERTY)).getParentFile());

        MirrorContext context = new MirrorContext();
        Generator generator = new Generator(context);
        generator.setJavaSuperClasses(superClasses);
        List<CDeclaration> allDecs = new ArrayList<>();

        /**
         * Phase 1 & 2 - parse headers and create .java source files
         */
        System.out.println("\n\nPhase 1 & 2 - parse headers and create .java source files");
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

                listener.onCDeclarationRead(pkg, cDeclaration);

                if (cDeclaration.getDeclType().equals(DeclarationType.CLASS)) {
                    generator.addClass((CClass) cDeclaration);
                } else if (cDeclaration.getDeclType().equals(DeclarationType.ENUM)) {
                    generator.addEnum((CEnum) cDeclaration);
                }
            }
            //run the generator to create .java source files
            context.setPackage(pkg.packageName);
            generator.run(new File(processingOptions.getProperty(GENERATE_TO_DIR)));

            //store declarations for later (for binding constants)
            allDecs.addAll(cClasses);
        }

        /**
         * Phase 3 - copy additional classes into api, such as Mirror.java, AIModule, EventListener, etc
         */
        System.out.println("\n\nPhase 3 - copy additional classes into api, such as Mirror.java, AIModule, EventListener, etc");
        for (PackageProcessOptions pkg : packages) {
            if (pkg.manualCopyClassesDir != null) {
                try {
                    for (File file : pkg.manualCopyClassesDir.listFiles()) {
                        Path source = file.getAbsoluteFile().toPath();
                        Path target = new File(processingOptions.get(GENERATE_TO_DIR) + "/" + pkg.packageName + "/" + file.getName()).getAbsoluteFile().toPath();
                        System.out.println("File copy: " + source + "  -->  " + target);
                        Files.copy(source, target, StandardCopyOption.REPLACE_EXISTING);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }


        /**
         * Phase 4 - compile .java sources
         */
        System.out.println("\n\nPhase 4 - compile .java sources");
        File javaOut = new File(processingOptions.getProperty(COMPILE_DIR_PROPERTY));
        MyJavaCompiler compiler = new MyJavaCompiler();

        for (PackageProcessOptions pkg : packages) {
            if (!compiler.run(new File(processingOptions.get(GENERATE_TO_DIR) + "/" + pkg.packageName), javaOut)) {
                System.out.println("\n\nAborting due to compile errors (see above).");
                System.exit(1);
                return;
            }
        }

        /**
         * Phase 5 - run javah to create header files for native functions
         */
        System.out.println("\n\nPhase 5 - run javah to create header files for native functions");
        List<String> packageDirNames = new ArrayList<>();
        for (PackageProcessOptions pkg : packages) {
            System.out.println("Adding package: " + pkg.packageName);
            packageDirNames.add(pkg.packageName);
        }
        HeaderMaker hm = new HeaderMaker();
        hm.run(packageDirNames, javaOut, processingOptions.getProperty(HEADER_FILE_PROPERTY), processingOptions.getProperty(HEADERS_DIR_PROPERTY));

        /**
         * Phase 6 - implementation of native functions
         */
        System.out.println("\n\nPhase 6 - implementation of native functions");
        JavaContext javaContext = new JavaContext();
        CallImplementer callImplementer = new CallImplementer(javaContext);

        TypeTable typeTable = new TypeTable();

        File cImplFile = new File(processingOptions.getProperty(C_IMPLEMENTATION_FILE_PROPERTY));
        System.out.println("Using output native implementation source file: " + cImplFile);
        File cImplDir = cImplFile.getParentFile();
        if (!cImplDir.exists())
            cImplDir.mkdirs();

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
        System.out.println("\n\nPhase 6.1 - implement caches");
        //caches for constants
        typeTable.implementTypeTable(allDecs);

        //caches for methodIds, fieldIds, classes
        IdCache idCache = new IdCache();
        idCache.setOut(out);
        idCache.implementCache();

        /**
         * Phase 6.2 - implement the native function bodies
         */
        System.out.println("\n\nPhase 6.2 - implement the native function bodies");
        File headersDir = new File(processingOptions.getProperty(HEADERS_DIR_PROPERTY));

        for (PackageProcessOptions pkg : packages) {
            callImplementer.setBwtaMode(pkg.packageName.equals("bwta"));
            javaContext.setPackageName(pkg.packageName);

            callImplementer.notifyPackageStart();

            for (File file : new File(processingOptions.getProperty(GENERATE_TO_DIR) + "/" + pkg.packageName).listFiles(new FilenameFilter() {
                @Override
                public boolean accept(File dir, String name) {
                    //we skip mirror.java as it has a native function which we implement manually
                    return !name.equals("Mirror.java") && name.endsWith(".java");
                }
            })) {

                //pair each .java file with its native header file
                File header = new File(headersDir, pkg.packageName + "_" + file.getName().substring(0, file.getName().lastIndexOf(".")) + ".h");
                System.out.println("implementing natives in " + file + " using native header " + header);
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
        System.out.println("\n\nPhase 6.3 - bind the remaining part of the java API to the C part");
        javaContext.setPackageName(packages[0].packageName);
        Bind bind = new Bind(javaContext);
        bind.setOut(out);
        bind.implementBind(allDecs);

        System.out.println("\n\nAll done.");
    }

    public static void main(String... args) {
        String basePathString;
        if (args.length > 0)
            basePathString = args[0];
        else
            // assumes running from this project's directory, which means the correct path to use in the
            // current un-altered git repository layout is one level up from this one
            basePathString = "..";

        File basePath = new File(basePathString);

        if (!basePath.exists()) {
            System.out.println("Working directory \"" + basePath + "\" does not exist. Exiting.");
            System.exit(1);
            return;
        }

        System.out.println("Using base path: " + basePath.getPath());
        if (!basePath.isAbsolute())
            System.out.println("Absolute base path: " + basePath.getAbsolutePath());
        System.out.println();

        try {
            ignoredClasses.add("Position");

            PackageProcessOptions bwapiOptions = new PackageProcessOptions();
            bwapiOptions.packageName = "bwapi";
            bwapiOptions.cHeadersDir = new File(basePath.getPath() + "/bwapi-includes");
            bwapiOptions.manualCopyClassesDir = new File(basePath.getPath() + "/manual-bwapi");

            PackageProcessOptions bwtaOptions = new PackageProcessOptions();
            bwtaOptions.packageName = "bwta";
            bwtaOptions.cHeadersDir = new File(basePath.getPath() + "/bwta2-includes");
            bwtaOptions.additionalImportClasses = Arrays.asList("bwapi.Position", "bwapi.TilePosition", "bwapi.Player", "bwapi.Unit", "bwapi.Pair");
            bwtaOptions.globalClassName = "BWTA";

            Properties props = new Properties();
            props.put(COMPILE_DIR_PROPERTY, basePath.getPath() + "/output/compiled");
            props.put(HEADERS_DIR_PROPERTY, basePath.getPath() + "/output/headers");
            props.put(HEADER_FILE_PROPERTY, basePath.getPath() + "/output/bwapi_bridge_src/concat_header.h");
            props.put(C_IMPLEMENTATION_FILE_PROPERTY, basePath.getPath() + "/output/bwapi_bridge_src/impl.cpp");
            props.put(GENERATE_TO_DIR, basePath.getPath() + "/bwmirror/src/main/java");

            new CJavaPipeline().run(new PackageProcessOptions[]{bwapiOptions, bwtaOptions}, props);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static final String COMPILE_DIR_PROPERTY = "compiled_dir";
    private static final String HEADERS_DIR_PROPERTY = "headers_dir";
    private static final String C_IMPLEMENTATION_FILE_PROPERTY = "impl_file";
    private static final String HEADER_FILE_PROPERTY = "header_file";
    private static final String GENERATE_TO_DIR = "generate_to_dir";
}
