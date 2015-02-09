package generator.ccalls;

import c.Param;
import generator.CJavaPipeline;
import generator.JavaContext;
import util.Generic;
import util.PointerTest;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 18:20
 */
public class CallImplementer {

    private static final String SPACE = " ";

    private static final String INTEND = "    ";

    private static final String SEMICOLON = ";";

    private PrintStream out = System.out;

    private Pattern javaPackagePattern = Pattern.compile("^package\\s(.*);$");

    private Pattern javaNativeMethodPattern = Pattern.compile(".*\\snative\\s(.*)\\s(.*)(\\(.*);");

    private Pattern headerJniMethodPattern = Pattern.compile(".*JNIEXPORT(\\s.*\\s)JNICALL\\s(.*)$");

    private JavaContext javaContext;

    public CallImplementer(JavaContext javaContext) {
        this.javaContext = javaContext;
    }

    public boolean bwtaMode = false;

    private static final String VARIABLE_PREFIX = "x_";


    public void setOut(PrintStream out) {
        this.out = out;
        out.print("#include \"../concat_header.h\"\n" +
                "#include <BWAPI.h>\n" +
                "#include <BWAPI/Client.h>\n" +
                (CJavaPipeline.isBWAPI3() ? "#include <BWTA.h>\n" : "#include <thread>\n" + "#include <chrono>\n") +
                "#include <jni.h>\n" +
                "#include <cstring>\n" +
                (CJavaPipeline.isBWAPI3() ? "#include \"../BWTA_Result.h\"" : "")+
                "\n" +
                "using namespace BWAPI;\n\n");
    }

    private void implementAccessObject(String clsName, String objName) {
        if (javaContext.isValueType(clsName)) {
            out.println(javaContext.copyJavaObjectToC(clsName, VARIABLE_PREFIX + objName, "obj"));
        } else {
            out.println(PointerTest.test(clsName) + SPACE + VARIABLE_PREFIX + objName + SPACE + "=" + SPACE + "(" + PointerTest.test(clsName) + ")pointer" + SEMICOLON);
        }
    }


    private void implementAccessObjectsParams(List<Param> params) {
        for (Param param : params) {
            if (javaContext.isPointer(param.first)) {
                if (javaContext.isValueType(param.third)) {
                    out.println(javaContext.copyJavaObjectToC(param.third, param.second));
                    continue;
                }

                String paramName = javaContext.ptrPrefix() + param.second;

                if (javaContext.isCollection(param.third)) {
                    String genericType = Generic.extractGeneric(param.third);
                    if (CJavaPipeline.isBWAPI3()) {
                        out.println("std::set<" + PointerTest.test(genericType) + "> " + param.second + SEMICOLON);
                    } else {
                        out.println(genericType + "set " + param.second + SEMICOLON);
                    }

                    out.println("jclass colClass = env->GetObjectClass(" + paramName + ");");
                    out.println("jmethodID sizeMethodId = FindCachedMethod(env, colClass, \"size\", \"()I\");");
                    out.println("jmethodID getMethodId = FindCachedMethod(env, colClass, \"get\", \"(I)Ljava/lang/Object;\");");
                    out.println("int size = (int)env->CallIntMethod(" + paramName + ", sizeMethodId);");
                    out.println("for( int i = 0; i < size; i++ ) {");
                    out.println("jobject jobj  = env->CallObjectMethod(" + paramName + ",getMethodId);");
                    out.print(param.second + ".insert(");
                    out.print("(" + PointerTest.test(genericType) + ")");
                    out.print("env->GetLongField(jobj, FindCachedField(env, env->GetObjectClass(jobj), \"pointer\", \"J\"))");
                    out.println(");");
                    out.println("}");
                    continue;
                }


                out.println(PointerTest.test(param.third) + SPACE + param.second + SPACE + "=" + SPACE + "(" + PointerTest.test(param.third) + ")" +
                        "env->GetLongField(" + paramName + ", "
                        + "FindCachedField(env, env->GetObjectClass(" + paramName + "), \"pointer\", \"J\")" + ")" + SEMICOLON);
            }
        }
    }


    private void implementMethodParams(List<Param> params) {
        for (Param param : params) {
            if (javaContext.isPointer(param.first)) {
                out.print("," + SPACE + javaContext.ptrCType() + SPACE + javaContext.ptrPrefix() + param.second);
            } else {
                out.print("," + SPACE + param.first + SPACE + param.second);
            }
        }
    }

    private void implementRealParams(List<Param> params) {
        int start = 1;
        if (params.size() > 0 && !params.get(0).second.equals("pointer")) {
            start = 0;
        }
        for (int i = start; i < params.size(); i++) {
            if (i > start) {
                out.print("," + SPACE);
            }
            Param param = params.get(i);
            if (param.first.equals("jstring")) {
                out.print("std::string(env->GetStringUTFChars(" + param.second + ", NULL))");
                if (param.second.startsWith("cstr_")) {
                    out.print(".c_str()");
                }
            } else {
                if (javaContext.isConstantTye(param.third)) {
                    out.print(PointerTest.test(param.third, false));
                }
                if (param.first.equals("jboolean")) {
                    out.print("(bool)");
                }
                out.print(param.second);
            }
        }
    }


    public void implementMethod(String clsName, String objName, String headerMethodName, String javaMethodName, List<Param> params, String cReturnType, String javaRetType, String javaPackageName, boolean isStatic) {
        out.print("JNIEXPORT" + SPACE + cReturnType + SPACE + "JNICALL" + SPACE + headerMethodName + "(" +
                "JNIEnv * env, ");
        if (isStatic) {
            out.print("jclass jclz");
        } else {
            out.print("jobject obj");
        }
        implementMethodParams(params);
        out.println("){");
        if (!isStatic) {
            implementAccessObject(clsName, objName);
        }
        implementAccessObjectsParams(params);
        implementMethodReturn(objName, javaMethodName, params, cReturnType, javaRetType, javaPackageName, clsName, isStatic);
        out.println("}");
    }

    private String wrapInCCollection(String genericType) {
        String buffer = "";
        boolean isBWAPI4Collection = !CJavaPipeline.isBWAPI3();
        if (!isBWAPI4Collection) {
            buffer += "std::set<";
        }
        if (!javaContext.isConstantTye(genericType) && !javaContext.isValueType(genericType)) {
            buffer += (PointerTest.test(genericType));
        }
        if (!isBWAPI4Collection) {
            buffer += ">";
        } else {
            buffer += "set";
        }
        return buffer;
    }

    /**
     * this basically just converts a std::set to java.util.ArrayList
     * it simply creates an array list and then loops through the set and calls list.add(element)
     *
     * @param genericType
     */
    private void implementCollectionReturn(String genericType) {
        String classGenericType = genericType;
        if (classGenericType.contains("::")) {
            classGenericType = classGenericType.substring(classGenericType.lastIndexOf(":") + 1);
        }

        //get all the method ids and create na empty arraylist
        out.println("jclass listCls = FindCachedClass(env, \"java/util/ArrayList\");\n" +
                "jmethodID listConsID = FindCachedMethod(env, listCls, \"<init>\", \"()V\");\n" +
                "jobject result = env->NewObject(listCls, listConsID);");

        out.println("jmethodID addMethodID = FindCachedMethod(env, listCls, \"add\", \"(Ljava/lang/Object;)Z\");");
        out.println("jclass elemClass = FindCachedClass(env, \"" + javaContext.getPackageName() + "/" + classGenericType + "\");");
        if (!javaContext.isValueType(genericType)) {
            out.println("jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, \"get\", \"(J)L" + javaContext.getPackageName() + "/" + classGenericType + ";\");");
        } else {
            out.println("jmethodID elemConsID = FindCachedMethod(env, elemClass, \"<init>\", \"(" + javaContext.copyConstructor(genericType) + ")V\");");
        }


        //the for loop
        out.print("for(" + wrapInCCollection(genericType) + "::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){");
        out.print("const " + genericType);
        if (!javaContext.isValueType(genericType)) {
            out.print(PointerTest.test(genericType, false));
        }
        out.print(" elem_ptr = ");
        if (javaContext.isConstantTye(genericType)) {
            out.println("table" + genericType + ".find((*it).getID())->second;");
        } else {
            out.println("*it;");
        }
        if (!javaContext.isValueType(genericType)) {
            out.println("jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;");
        } else {
            out.println("jobject elem = env->NewObject(elemClass, elemConsID" + javaContext.implementCopyReturn(genericType, "elem_ptr") + ")" + SEMICOLON);
        }
        out.println("env->CallVoidMethod(result, addMethodID, elem);");
        out.println("}");
        //for loop ends here

        out.println("return result;");

    }

    private void implementMethodReturn(String objName, String javaMethodName, List<Param> params, String cReturnType, String javaRetType, String javaPackageName, String clsName, boolean isStatic) {

        String objectAccessor = VARIABLE_PREFIX + objName + (javaContext.isValueType(clsName) ? "." : "->");
        if (isStatic) {
            objectAccessor = clsName + "::";
        }

        //case 1 - method returns a collection type, this requires a LOT of work, so get the std::set and proceed in implementCollectionReturn
        if (javaRetType.startsWith("List<")) {
            String genericType = convertToBWTA(Generic.extractGeneric(javaRetType));
            out.print(wrapInCCollection(genericType) + " cresult = " + objectAccessor + javaMethodName + "(");
            implementRealParams(params);
            out.println(")" + SEMICOLON);
            implementCollectionReturn(genericType);
            return;
        }
        //case 2 method returns a java object
        if (cReturnType.equals("jobject")) {
            //we may need to create a new java object in case this a value type (we can't use the instance map)
            if (javaContext.isValueType(javaRetType)) {
                //first make the normal c++ call
                out.print(javaRetType + " cresult = " + objectAccessor + javaMethodName + "(");
                implementRealParams(params);
                out.print(")");
                out.println(SEMICOLON);
                out.println("jclass retcls = FindCachedClass(env, \"" + javaContext.getPackageName(javaRetType) + "/" + javaRetType + "\");");

                //now create a new object and return it
                out.println("jmethodID retConsID = FindCachedMethod(env, retcls, \"<init>\", \"(" + javaContext.copyConstructor(javaRetType) + ")V\");");
                out.print("jobject result = env->NewObject(retcls, retConsID");
                //use the proper constructor
                out.print(javaContext.implementCopyReturn(javaRetType));
                out.println(");");
                out.println("return result;");
            } else {
                //this is a pointer return, so we will use the instance map
                //first make the normal c++ call
                out.print("jlong resptr = (jlong)" + (javaMethodName.equals("getPolygon") ? "&" : "") + javaContext.implementValueReturn(javaRetType) + objectAccessor + javaMethodName + "(");
                implementRealParams(params);
                out.print(")");
                out.print(javaContext.implementValueReturnClosing(javaRetType));
                out.println(SEMICOLON);
                //go get the class we need to return and the spawning "get" method
                out.println("jclass retcls = FindCachedClass(env, \"" + javaContext.getPackageName(javaRetType) + "/" + javaRetType + "\");");
                out.println("jmethodID mid = FindCachedMethodStatic(env, retcls, \"get\", \"(J)L" + javaPackageName.replaceAll("\\.", "/") + "/" + javaRetType + ";\");");
                //do the magic :)
                out.println("return env->CallStaticObjectMethod(retcls, mid, resptr)" + SEMICOLON);
            }
        } else {
            //now this is either a primitive a string or a void

            if (!cReturnType.equals("void")) {
                //we must return!
                out.print("return" + SPACE);
            }

            //strings are tricky...
            boolean isString = cReturnType.equals("jstring");
            if (isString) {
                out.print("env->NewStringUTF(");
            }


            //just call the method
            out.print(objectAccessor + javaMethodName + "(");
            implementRealParams(params);

            //finish a tricky string
            if (isString) {
                out.print(")");
                if (!javaMethodName.endsWith("c_str")) {
                    out.print(".c_str()");
                }
            }
            out.println(")" + SEMICOLON);
        }
    }


    private List<Param> buildParamList(String params) {
        ArrayList<Param> result = new ArrayList<>();
        if (!params.trim().isEmpty()) {
            String[] paramsArray = params.split("\\,");
            for (String param : paramsArray) {
                String[] paramKV = param.trim().split("\\s+");
                result.add(new Param(convertToBWTA(javaContext.toCType(paramKV[0])), paramKV[1], convertToBWTA(paramKV[0])));
            }
        }
        return result;
    }


    public void implementMethodCalls(File javaClass, File headerFile) throws Exception {
        String clsName = javaClass.getName().substring(0, javaClass.getName().lastIndexOf('.'));
        String objName = ("" + clsName.charAt(0)).toLowerCase() + clsName.substring(1);
        //keywords
        if (objName.equals("event")) {
            objName = "evt";
        }

        BufferedReader javaReader = new BufferedReader(new FileReader(javaClass));
        BufferedReader headerReader = new BufferedReader(new FileReader(headerFile));

        String packageName = "";
        String javaLine;
        while ((javaLine = javaReader.readLine()) != null) {
            if (packageName.isEmpty()) {
                Matcher javaPackageMatcher = javaPackagePattern.matcher(javaLine);
                if (javaPackageMatcher.matches()) {
                    packageName = javaPackageMatcher.group(1);
                }
            }
            Matcher javaMatcher = javaNativeMethodPattern.matcher(javaLine);
            if (javaMatcher.matches()) {
                //return type
                String javaReturnType = javaMatcher.group(1).trim();

                //name
                String javaMethodName = javaMatcher.group(2).trim();
                if (javaMethodName.contains("_")) {
                    javaMethodName = javaMethodName.substring(0, javaMethodName.lastIndexOf("_"));
                }

                //params
                String paramList = javaMatcher.group(3).trim();
                paramList = paramList.substring(1, paramList.length() - 1);
                List<Param> params = buildParamList(paramList);


                String headerLine;
                while ((headerLine = headerReader.readLine()) != null) {
                    Matcher headerMatcher = headerJniMethodPattern.matcher(headerLine);
                    if (headerMatcher.matches()) {
                        //at this point java method is paired with the c method

                        //return type
                        String cReturnType = headerMatcher.group(1).trim();

                        //name
                        String headerMethodName = headerMatcher.group(2).trim();

                        implementMethod(convertToBWTA(clsName), objName, headerMethodName, javaMethodName, params, cReturnType, javaReturnType, packageName, javaLine.contains(" static "));
                        break;
                    }
                }
            }
        }
    }

    public String convertToBWTA(String clsName) {
        if (clsName.equals("RectangleArray")) {
            return "BWTA::RectangleArray<double>";
        }
        return ((bwtaMode && javaContext.isBWTA(clsName)) ? "BWTA::" : "") + clsName;
    }

    public void setBwtaMode(boolean bwtaMode) {
        this.bwtaMode = bwtaMode;
    }

    public void notifyPackageStart() {
        out.println("PositionOrUnit convertPositionOrUnit(JNIEnv * env, jobject obj){ \n" +
                "\tjclass clz = FindCachedClass(env, \"" + javaContext.getPackageName() + "/PositionOrUnit\");\n" +
                "\tjmethodID typeMethodId = FindCachedMethod(env, clz, \"isUnit\", \"()Z\");\n" +
                "\tbool isUnit = (bool)env->CallBooleanMethod(obj, typeMethodId);\n" +
                "\tif(isUnit){\n" +
                "\t\tjobject unitObj = env->CallObjectMethod(obj, FindCachedMethod(env, clz, \"getUnit\", \"()L" + javaContext.getPackageName() + "/Unit;\"));\n" +
                "\t\tUnit unit = (Unit)env->GetLongField(unitObj, FindCachedField(env, env->GetObjectClass(unitObj), \"pointer\", \"J\"));\n" +
                "\t\treturn PositionOrUnit(unit);\n" +
                "\t}\n" +
                "\tjobject posObj = env->CallObjectMethod(obj, FindCachedMethod(env, clz, \"getPosition\", \"()L" + javaContext.getPackageName() + "/Position;\"));\n" +
                "\t" + javaContext.copyJavaObjectToC("Position", "position", "posObj") + "\n" +
                "\treturn PositionOrUnit(position);\n" +
                "}\n\n");

        out.println("UnitCommand convertUnitCommand(JNIEnv * env, jobject obj){" +
                "\tjclass clz = FindCachedClass(env, \"" + javaContext.getPackageName() + "/UnitCommand\");\n" +

                "\tjobject unitObj = env->CallObjectMethod(obj, FindCachedMethod(env, clz, \"getUnit\", \"()L" + javaContext.getPackageName() + "/Unit;\"));\n" +
                "\tUnit unit = (Unit)env->GetLongField(unitObj, FindCachedField(env, env->GetObjectClass(unitObj), \"pointer\", \"J\"));\n" +

                "\tjobject targetObj = env->CallObjectMethod(obj, FindCachedMethod(env, clz, \"getTarget\", \"()L" + javaContext.getPackageName() + "/Unit;\"));\n" +
                "\tUnit target = (Unit)env->GetLongField(targetObj, FindCachedField(env, env->GetObjectClass(targetObj), \"pointer\", \"J\"));\n" +

                "\tjobject typeObj = env->CallObjectMethod(obj, FindCachedMethod(env, clz, \"getType\", \"()L" + javaContext.getPackageName() + "/UnitCommandType;\"));\n" +
                "\tUnitCommandType type = (UnitCommandType)env->GetIntField(typeObj, FindCachedField(env, env->GetObjectClass(typeObj), \"value\", \"I\"));\n" +

                "\tint extra = (int)env->GetIntField(obj, FindCachedField(env, clz, \"extra\", \"I\"));\n" +

                "\tjobject posObj = env->CallObjectMethod(obj, FindCachedMethod(env, clz, \"getPosition\", \"()L" + javaContext.getPackageName() + "/Position;\"));\n" +
                "\t" + javaContext.copyJavaObjectToC("Position", "position", "posObj") + "\n" +
                "\treturn UnitCommand(unit, UnitCommandType(type), target, position.x, position.y, extra);\n" +
                "}\n\n");

        out.println("int resolveUnitCommandExtra(UnitCommand& command){\n" +
                "\tif(command.getUnitType() != UnitTypes::None){" +
                "\t\treturn command.getUnitType().getID();" +
                "}\n" +
                "\tif(command.getTechType() != TechTypes::None){" +
                "\t\treturn command.getTechType().getID();" +
                "}\n" +
                "\tif(command.getUpgradeType() != UpgradeTypes::None){" +
                "\t\treturn command.getUpgradeType().getID();" +
                "}\n" +
                "\tif(command.getSlot() != -1){" +
                "\t\treturn command.extra;" +
                "}\n" +
                "\treturn command.isQueued();\n" +
                "}\n\n");
    }
}
