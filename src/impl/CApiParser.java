package impl;

import c.*;
import generator.CJavaPipeline;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FilenameFilter;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * User: PC
 * Date: 26.2.2014
 * Time: 20:24
 */
public class CApiParser {

    enum LineState {
        CLASS_DEF,
        ENUM_DEF,
        CONST_DEF,
        MULTI_LINE,
        OK,
        SKIP,
        WTF,
        END
    }

    enum ACCESS {
        PUBLIC, PRIVATE, PROTECTED
    }

    ACCESS access;

    String currentNamespace = "";

    //String FUNC_REGEX = "^(\\s*)(virtual)?\\s(\\w+)\\s(\\w+)\\((.*)\\)";
    //String FUNC_REGEX = "^(\\s*)(virtual)?\\s([\\w\\*]+)\\s([\\w\\*]+)\\((.*)\\)(\\s=\\s0;)?";
    //String FUNC_REGEX = "^(\\s*)(virtual)?\\s(BWAPI::)?([\\w\\*]+)\\s([\\w\\*]+)\\((.*)\\)((\\sconst)?\\s=\\s0;)?";
    //String FUNC_REGEX = "^(\\s*)(virtual)?\\s((BWAPI)|(std)::)?([\\w\\*]+)\\s([\\w\\*]+)\\((.*)\\)((\\sconst)?\\s=\\s0;)?";
    //                    1     2             3         4           56         7        891011     12    13    14             15   16                     17                     18                19            20
    String FUNC_REGEX = "^(\\s*)(virtual\\s)?(const\\s)?(static\\s)?((BWAPI::)|(std::))?((((pair)|(vector)|(set)|(map)|(SetContainer))<(\\s*(BWAPI::)?\\w+\\*?\\s*)(\\s*,\\s*\\w+\\s*)?>)|([\\w\\*]+))&?\\s+(&?[\\w\\*]+)\\((.*)\\)(\\s*const)?(\\s*=\\s0)?(;)?\\s*";

    static final int F_REGEX_STATIC = 4;
    static final int F_REGEX_RETURN_TYPE = 8;
    static final int F_REGEX_NAME = 20;
    static final int F_REGEX_PARAMS = 21;

    String ENUM_VALUE_REGEX = "^(\\s*)(\\w+)(\\s*=\\s*(0x)?([0-9A-Fa-f]+))?\\s*[\\,;]";

    Pattern funcPattern = Pattern.compile(FUNC_REGEX);
    Pattern enumPattern = Pattern.compile(ENUM_VALUE_REGEX);

    private List<CDeclaration> declarations = new ArrayList<>();

    private CClass globalClass = new Clazz("BwapiGlobals");

    private int currentEnumValue = 0;

    public CClass getGlobalClass() {
        return globalClass;
    }

    public void setGlobalClass(CClass globalClass) {
        this.globalClass = globalClass;
        declarations.add(globalClass);
    }

    private String javadoc = null;

    private LineState processLine(String line) {
        line = line.trim();
        if (javadoc == null && line.contains("/*")) {
            if (line.endsWith("*")) {
                line += "<br/><br/>";
            }
            if (line.contains("*/")) {
                javadoc = "\t" + line.substring(line.indexOf("/*"), line.indexOf("*/") + 2) + "\n";
            } else {
                javadoc = "\t" + line.substring(line.indexOf("/*")) + "\n";
            }
        } else if (javadoc != null && !javadoc.endsWith("*/\n")) {
            if (line.endsWith("*")) {
                line += "<br/><br/>";
            }
            if (line.contains("*/")) {
                javadoc += "\t" + line.substring(0, line.indexOf("*/") + 2) + "\n";
            } else {
                javadoc += "\t" + line + "\n";
            }
        }
        if (line.startsWith("namespace")) {
            currentNamespace = null;

            line = line.substring("namespace".length()).trim();

            if (!line.equals("BWAPI")) {
                currentNamespace = line;
            }


            if (line.equals("Errors")) {
                return LineState.END;
            }
            if (line.equals("Colors")) {
                return LineState.END;
            }
            if (line.equals("Orders")) {
                return LineState.END;
            }

            if(CJavaPipeline.isBWAPI3()) {
                if (line.endsWith("Types")) {
                    return LineState.END;
                }
                if (line.equals("Races")) {
                    return LineState.END;
                }
            }
            return LineState.SKIP;
        }

        if (isSkip(line)) {
            return LineState.SKIP;
        }


        if (line.startsWith("extern const")) {
            return LineState.CONST_DEF;
        }
        if (line.startsWith("typedef")) {

            return LineState.OK;
        }
        if (line.startsWith("class")) {
            return LineState.CLASS_DEF;
        }

        if (line.startsWith("enum")) {
            return LineState.ENUM_DEF;
        }


        if (line.startsWith("public")) {
            access = ACCESS.PUBLIC;
            return LineState.OK;
        }
        if (line.startsWith("private")) {
            access = ACCESS.PRIVATE;
            return LineState.OK;
        }
        if (line.startsWith("protected")) {
            access = ACCESS.PROTECTED;
            return LineState.OK;
        }

        //skip non public members
        if (access == ACCESS.PUBLIC) {
            return LineState.OK;
        }

        return LineState.SKIP;
    }

    private static boolean isSkip(String line) {
        if (line.isEmpty()) {
            return true;
        }

        if (line.startsWith("//")) {
            return true;
        }
        if (line.startsWith("#")) {
            return true;
        }
        //forward declaration
        if (line.startsWith("class") && line.endsWith(";")) {
            return true;
        }

        if (line.startsWith("{")) {
            return true;
        }

        if (line.startsWith("}")) {
            return true;
        }


        if (line.startsWith("return")) {
            return true;
        }

        if (line.startsWith("namespace")) {
            return true;
        }

        return false;
    }

    private EnumValue processEnumValue(String line) {
        Matcher matcher = enumPattern.matcher(line);
        if (matcher.find()) {
            int enumOrdinal = currentEnumValue;
            if (matcher.group(3) != null) {
                //is it hex? (0x...)
                if (matcher.group(4) != null) {
                    enumOrdinal = Integer.parseInt(matcher.group(5), 16);
                } else {
                    enumOrdinal = Integer.parseInt(matcher.group(5), 10);
                }
                //                               1      2      3      4 5
                // String ENUM_VALUE_REGEX = "^(\\s*)(\\w+)(\\s*=\\s*(0x)?([0-9A-Fa-f]+))?";

            }
            EnumValue enumValue = new EnumValue(matcher.group(2), enumOrdinal);
            currentEnumValue = enumValue.second + 1;
            return enumValue;
        }
        return null;
    }

    private Function processFunction(String line) {
        if (line.trim().equals("Event& setType(EventType::Enum type);")) {
            return null;
        }
        Matcher matcher = funcPattern.matcher(line);
        if (matcher.find()) {
            Function function = new Function();
            function.returnType = matcher.group(F_REGEX_RETURN_TYPE);
            function.name = matcher.group(F_REGEX_NAME);
            if(function.name.startsWith("&")){
                function.name = function.name.substring(1);
            }
            if (function.returnType.equals("operator")) {
                return null;
            }
            if (function.returnType.equals("void*")) {
                System.err.println("function skipped - void* return (" + function.name + ")");
                return null;
            }

            if (function.returnType.equals("Type")) {
                function.returnType = "double";
            }

            if (function.returnType.startsWith("SetContainer")) {
                function.returnType = "set" + function.returnType.substring("SetContainer".length());
            }

            if (function.returnType.equals("GameData*")) {
                System.err.println("function skipped - GameData* return (" + function.name + ")");
                return null;
            }
            if (CJavaPipeline.isBWAPI3() && function.returnType.equals("UnitCommand")) {
                System.err.println("function skipped - UnitCommand return (" + function.name + ")");
                return null;
            }
            if (function.returnType.equals("Event")) {
                System.err.println("function skipped - Event return (" + function.name + ")");
                return null;
            }


            if (function.name.startsWith("*")) {
                function.name = function.name.substring(1);
                if (function.returnType.equals("char")) {
                    function.returnType = "string";
                }
            }

            if(function.name.equals("setClientInfo")){
                System.err.println("function skipped - BWAPI4 set client info return (" + function.name + ")");
                return null;
            }

            if(function.name.equals("maxUnitWidth")){
                System.err.println("function skipped - BWAPI4 (" + function.name + ")");
                return null;
            }

            if(function.name.equals("maxUnitHeight")){
                System.err.println("function skipped - BWAPI4 (" + function.name + ")");
                return null;
            }

            if(matcher.group(F_REGEX_STATIC) != null){
                function.setStatic(true);
            }

            if (matcher.group(F_REGEX_PARAMS) != null) {
                String paramsString = matcher.group(F_REGEX_PARAMS);
                String paramStrings[] = paramsString.split("\\,");
                int i = 0;
                for (String param : paramStrings) {
                    i++;
                    if (param.isEmpty()) {
                        continue;
                    }
                    param = param.trim();

                    String[] arg = param.split("\\s");
                    if (arg[0].equals("...")) {
                        //function.args.add(new Param("Object[]", "arr"));
                        continue;
                    }

                    if (!param.contains(" ")) {
                        System.err.println("Macro function skipped " + function.name);
                        return null;
                    }

                    try {
                        String argType = "";
                        String argName = "";

                        if (arg[0].equals("const")  || arg[0].equals("unsigned")) {
                            if (arg.length == 2) {
                                System.err.println("Macro function skipped " + function.name);
                                return null;
                            }
                            argType = arg[1];
                            argName = arg[2];
                        } else {
                            argType = arg[0];
                            argName = arg[1];
                        }
                        if (argType.startsWith("std::")) {
                            argType = argType.substring(argType.lastIndexOf("std::") + 5);
                        }

                        if (argType.startsWith("BWAPI::")) {
                            argType = argType.substring(argType.lastIndexOf("BWAPI::") + 7);
                        }
                        if (argType.startsWith("BWAPIC::")) {
                            argType = argType.substring(argType.lastIndexOf("BWAPIC::") + 8);
                            System.err.println("BWAPIC function skipped : " + function.name);
                            return null;
                        }
                        if (argType.contains("::") && !argType.contains("BWAPI")) {
                            argType = argType.replace("::", ".");
                            argType = "bwapi." + argType;
                        }
                        //
                        if (argType.equals("char") && argName.startsWith("*")) {
                            argType = "string";
                            argName = argName.substring(1);
                            argName = "cstr_" + argName;
                        }

                        if (argType.equals("char*")) {
                            argType = "string";
                            argName = "cstr_" + argName;
                        }
                        //
                        if (argType.equals("va_list")) {
                            if(function.name.startsWith("v")){
                                System.err.println("BWAPI4 va_list function skipped : " + function.name);
                                return null;
                            }
                            argType = "Object ...";
                            continue;
                        }

                        if (argType.equals("UnitFilter") && i == paramStrings.length) {
                           continue;
                        }

                        //
                        /*if (argType.equals("void") && argName.startsWith("*")) {
                            argType = "long";
                            argName = argName.substring(1);
                        } */

                        //
                   /*     if(argType.contains("<")){
                            argType=argType.substring(0, argType.indexOf('<'));
                        }     */

                        //
                        if (argName.startsWith("&")) {
                            argName = argName.substring(1);
                        }

                        if (argType.endsWith("&")) {
                            argType = argType.substring(0, argType.length() - 1);
                        }

                        //
                        if (argName.startsWith("*")) {
                            argName = argName.substring(1);
                        }

                        if (argType.endsWith("*")) {
                            argType = argType.substring(0, argType.length() - 1);
                        }

                        if (argType.equals("Type")) {
                            argType = "double";
                        }

                        if (argType.equals("RectangleArray<double>")) {
                            argType = "RectangleArray";
                        }

                        if (argType.equals("void")) {
                            System.err.println("function skipped - void* param (" + function.name + ")");
                            return null;
                        }

                        if (argType.equals("FILE")) {
                            System.err.println("function skipped - FILE param (" + function.name + ")");
                            return null;
                        }

                        if (argType.equals("RectangleArray")) {
                            System.err.println("function skipped - RectangleArray param (" + function.name + ")");
                            return null;
                        }

                        if (argType.equals("UnitFilter")) {
                            System.err.println("function skipped - UnitFilter param (" + function.name + ")");
                            return null;
                        }

                        if (argType.equals("BestUnitFilter")) {
                            System.err.println("function skipped - BestUnitFilter param (" + function.name + ")");
                            return null;
                        }


                        if (arg.length > 2 && arg[2].equals("=")) {
                            function.args.add(new Param(argType, argName, arg[3]));
                        } else {
                            function.args.add(new Param(argType, argName));
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                        return null;
                    }
                }
            }
            return function;
        }
        return null;
    }

    public Variable processVariable(String line) {
        line = line.trim();
        line = line.substring("extern const".length(), line.lastIndexOf(";")).trim();
        String[] nameType = line.split("\\s");
        Variable variable = new ClassVariable(nameType[0], nameType[1]);
        return variable;
    }

    public List<CDeclaration> processFile(File file) {
        try {
            javadoc = null;
            List<CClass> classes = new ArrayList<>();
            List<CEnum> enums = new ArrayList<>();
            //CClass cClass = new Clazz(file.getName().substring(0, file.getName().indexOf('.')));
            if (file.getName().equals("Type.h")) {
                return null;
            }
            BufferedReader br = new BufferedReader(new FileReader(file));
            String line;
            boolean skippingFunctions = false;
            while ((line = br.readLine()) != null) {
                LineState lineState = processLine(line);
                if (lineState == LineState.END) {
                    skippingFunctions = true;
                }
                if (lineState == LineState.OK && !skippingFunctions) {
                    Function f = processFunction(line);
                    if (f != null) {
                        if (javadoc != null) {
                            f.setJavadoc(javadoc);
                            javadoc = null;
                        }
                        //skip constructors
                        if (f.returnType.isEmpty()) {
                            continue;
                        }
                        if (classes.isEmpty()) {
                            globalClass.getFields().add(f);
                            System.err.println("Global function - " + f.getName());
                            continue;
                        }
                        classes.get(classes.size() - 1).getFields().add(f);
                        continue;
                    }

                }
                if (!enums.isEmpty()) {
                    EnumValue ev = processEnumValue(line);
                    if (ev != null) {
                        enums.get(enums.size() - 1).getValues().add(ev);
                    }
                }
                if (lineState == LineState.CLASS_DEF) {
                    String clazzName = line.trim().split(" ")[1];
                    if (clazzName.endsWith("Interface") && !clazzName.equals("Interface")) {
                        clazzName = clazzName.substring(0, clazzName.length() - "Interface".length());
                    }
                    Clazz clz = new Clazz(clazzName);

                    if(!CJavaPipeline.isBWAPI3()){
                        if(clazzName.endsWith("Type") || clazzName.equals("Error") || clazzName.equals("Race") || clazzName.equals("Order")){
                            Function function = new Function();
                            function.name = "toString";
                            function.returnType = "string";
                            clz.fields.add(function);
                        }
                    }

                    if (javadoc != null) {
                        clz.setJavadoc(javadoc);
                        javadoc = null;
                    }
                    classes.add(clz);
                }
                if (lineState == LineState.ENUM_DEF) {
                    String enumName = line.trim().split(" ")[1];
                    if (currentNamespace != null && currentNamespace.equals("Size")) {
                        currentNamespace = "Text.Size";
                    }
                    Enum e = new Enum(enumName, currentNamespace);
                    if (javadoc != null) {
                        e.setJavadoc(javadoc);
                        javadoc = null;
                    }
                    enums.add(e);
                    currentEnumValue = 0;
                }
                if (lineState == LineState.CONST_DEF) {
                    if (classes.isEmpty()) {
                        System.err.println("Skipping constant, no class to add it to  - " + line);
                        continue;
                    }

                    Variable variable = processVariable(line);
                    if (variable != null) {
                        if (javadoc != null) {
                            variable.setJavadoc(javadoc);
                            javadoc = null;
                        }
                        classes.get(classes.size() - 1).getFields().add(variable);
                    }
                }
            }
            List<CDeclaration> result = new ArrayList<>();
            result.addAll(classes);
            result.addAll(enums);
            return result;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public List<CDeclaration> parseDir(File dir) {
        File[] files = dir.listFiles(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name) {
                return dir.isDirectory() || name.endsWith(".h");
            }
        });
        for (File file : files) {
            if (file.isDirectory()) {
                parseDir(file);
            } else {
                List<CDeclaration> declList = processFile(file);
                if (declList != null) {
                    declarations.addAll(declList);
                }
            }
        }
        return declarations;
    }

    public static void main(String... args) {
        CApiParser CApiParser = new CApiParser();
        Function f = CApiParser.processFunction("bool isEnemy(Player player, Random me) const = 0;");
        System.out.println();
    }
}
