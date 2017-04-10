package bwmirror.generator;

import bwmirror.util.Generic;
import bwmirror.util.PointerTest;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 17:39
 */
public class JavaContext {

    private HashMap<String, String> javaToCType = new HashMap<>();

    private List<String> valueTypes = Arrays.asList("Position", "TilePosition", "WalkPosition", "Color", "BWTA::RectangleArray<double>", "PositionOrUnit", "Point", "UnitCommand", "Integer", "Long", "Double", "Boolean", "int", "void", "double", "long", "Pair");

    private List<String> constantTypes = Arrays.asList("UnitType", "TechType", "UpgradeType", "Race", "UnitCommand", "WeaponType", "Order", "GameType", "Error", "PlayerType", "UnitCommandType");

    private List<String> enumTypes = Arrays.asList("MouseButton", "Key", "bwapi.Text.Size.Enum", "bwapi.CoordinateType.Enum", "Text::Size::Enum", "CoordinateType::Enum");

    private List<String> valueReturnTypes = Arrays.asList("Event");

    private List<String> bwtaClasses = Arrays.asList("Chokepoint", "Region", "RectangleArray", "Polygon", "BaseLocation");

    private List<String> selfReturnTypes = Arrays.asList("BWTA::Polygon");


    private String packageName = "bwapi";


    public JavaContext() {
        javaToCType.put("long", "jlong");
        javaToCType.put("int", "jint");
        javaToCType.put("void", "void");
        javaToCType.put("boolean", "jboolean");
        javaToCType.put("String", "jstring");
    }

    public boolean isSelfReturnType(String clsName, String methodName) {
        return packageName.equals("bwta") && selfReturnTypes.contains(clsName) && methodName.equals("getPoints");
    }

    public String getPackageName() {
        return packageName;
    }

    public String getPackageName(String javaRetType) {
        if (packageName.equals("bwta") && (javaRetType.equals("Position") || javaRetType.equals("Unit") || javaRetType.equals("Pair") || javaRetType.equals("TilePosition"))) {
            return "bwapi";
        }
        return packageName;
    }

    public void setPackageName(String packageName) {
        this.packageName = packageName;
    }

    public String toCType(String javaType) {
        String result = javaToCType.get(javaType);
        return result != null ? result : "REF";
    }

    public String toCPair(String javaType) {
        if (javaType.startsWith("Pair")) {
            String[] pair = Generic.extractPair(javaType);
            return "std::pair<" + javaObjectToPrimitive(prefixPackageNameAndAddPointerIfNeeded(pair[0])) + ", " + javaObjectToPrimitive(prefixPackageNameAndAddPointerIfNeeded(pair[1])) + ">";
        }
        return javaType;
    }

    public String prefixPackageNameAndAddPointerIfNeeded(String javaType) {
        if (isBWTA(javaType)) {
            return PointerTest.test("BWTA::" + javaType);
        } else {
            return javaType;
        }
    }

    public boolean isReference(String javaType) {
        return javaType.equals("REF");
    }

    public boolean isValueType(String javaType) {
        return valueTypes.contains(javaType) || enumTypes.contains(javaType);
    }

    public boolean isConstantTye(String javaType) {
        return constantTypes.contains(javaType);
    }

    public String ptrCType() {
        return "jobject";
    }

    public String ptrPrefix() {
        return "p_";
    }

    private String getEnumValue(String variableName) {
        return "(int)env->GetIntField(" + ptrPrefix() + variableName + ", FindCachedField(env, env->GetObjectClass(" + ptrPrefix() + variableName + "), \"value\", \"I\"));";
    }

    private String copyFields(String variableType, String variableName, String rawName) {
        if (enumTypes.contains(variableType)) {
            return " = (" + variableType + ")" + getEnumValue(variableName);
        }
        switch (variableType) {
            case "Position":
            case "WalkPosition":
            case "TilePosition":
            case "Point":
                return "(" +
                        "(int)env->GetIntField(" + rawName + ", FindCachedField(env, env->GetObjectClass(" + rawName + "), \"x\", \"I\")), " +
                        "(int)env->GetIntField(" + rawName + ", FindCachedField(env, env->GetObjectClass(" + rawName + "), \"y\", \"I\"))" +
                        ");";
            case "Error":
                return "(" +
                        "(int)env->GetIntField(" + rawName + ", FindCachedField(env, env->GetObjectClass(" + rawName + "), \"id\", \"I\"))" +
                        ");";
            case "Color":
                return "(" +
                        "(int)env->GetIntField(" + rawName + ", FindCachedField(env, env->GetObjectClass(" + rawName + "), \"r\", \"I\")), " +
                        "(int)env->GetIntField(" + rawName + ", FindCachedField(env, env->GetObjectClass(" + rawName + "), \"g\", \"I\")), " +
                        "(int)env->GetIntField(" + rawName + ", FindCachedField(env, env->GetObjectClass(" + rawName + "), \"b\", \"I\"))" +
                        ");";
            case "PositionOrUnit":
                return "(convertPositionOrUnit(env, " + rawName + " ));";
            case "UnitCommand":
                return "(convertUnitCommand(env, " + rawName + " ));";
        }
        return ";";
    }

    public String copyJavaObjectToC(String variableType, String variableName, String rawName) {
        String packageStrippedType = variableType;
        if (packageStrippedType.startsWith("bwapi")) {
            packageStrippedType = packageStrippedType.substring(packageStrippedType.indexOf(".") + 1);
        }
        packageStrippedType = packageStrippedType.replaceAll("\\.", "::");

        return (packageStrippedType + " " + variableName) + copyFields(packageStrippedType, variableName, rawName);
    }

    public String copyJavaObjectToC(String variableType, String variableName) {
        return copyJavaObjectToC(variableType, variableName, ptrPrefix() + variableName);
    }

    public String implementValueReturn(String javaReturnType) {
        if (valueReturnTypes.contains(javaReturnType) || constantTypes.contains(javaReturnType)) {
            return "table" + javaReturnType + ".find(";
        }
        return "";
    }

    public String implementValueReturnClosing(String javaReturnType) {
        if (valueReturnTypes.contains(javaReturnType) || constantTypes.contains(javaReturnType)) {
            return ".getID())->second";
        }
        return "";
    }

    public boolean isCollection(String javaType) {
        return javaType.startsWith("List");
    }

    public boolean isPair(String javaType) {
        return javaType.startsWith("Pair");
    }

    public boolean isMap(String javaType) {
        return javaType.startsWith("Map");
    }

    public boolean isDeque(String javaType) {
        return javaType.startsWith("List");
    }


    public String copyConstructor(String javaType) {
        switch (javaType) {
            case "Integer":
            case "int":
                return "I";
            case "Double":
            case "double":
                return "D";
            case "TilePosition":
            case "WalkPosition":
            case "Position":
            case "Point":
                return "II";
            case "Color":
                return "III";
            case "Error":
                return "I";
            case "UnitCommand":
                return "L" + packageName + "/Unit;L" + packageName + "/UnitCommandType;L" + packageName + "/Unit;III";
            case "Pair":
                return "Ljava/lang/Object;Ljava/lang/Object;";
            default:
                System.err.println("Invalid type " + javaType);
                throw new UnsupportedOperationException();
        }
    }

    public String implementCopyReturn(String javaType) {
        return implementCopyReturn(javaType, "cresult");
    }

    public static String checkBWAPI3brackets() {
        if (CJavaPipeline.isBWAPI3()) {
            return "()";
        }
        return "";
    }

    public String implementCopyReturn(String javaType, String fieldName) {
        switch (javaType) {
            case "Integer":
            case "int":
                return ", " + fieldName;
            case "Double":
            case "double":
                return "," + fieldName;

            case "bool":
                return "," + fieldName;
            case "Pair":
                return ", first, second";

            case "TilePosition":
            case "Position":
            case "WalkPosition":
            case "Point":
                return ", " + fieldName + ".x" + checkBWAPI3brackets() +
                        ", " + fieldName + ".y" + checkBWAPI3brackets();
            case "Color":
                return ", " + fieldName + ".red()" +
                        ", " + fieldName + ".green()" +
                        ", " + fieldName + ".blue()";
            case "UnitCommand":
                return
                        ", env->CallStaticObjectMethod(FindCachedClass(env, \"" + packageName + "/Unit\"), FindCachedMethodStatic(env, FindCachedClass(env, \"" + packageName + "/Unit\"), \"get\", \"(J)L" + packageName + "/Unit;\"), " + fieldName + ".getUnit())\n" +
                                ", env->CallStaticObjectMethod(FindCachedClass(env, \"" + packageName + "/UnitCommandType\"), FindCachedMethodStatic(env, FindCachedClass(env, \"" + packageName + "/UnitCommandType\"), \"get\", \"(J)L" + packageName + "/UnitCommandType;\"), (jlong)tableUnitCommandType.find(" + fieldName + ".getType().getID())->second )\n" +
                                ", env->CallStaticObjectMethod(FindCachedClass(env, \"" + packageName + "/Unit\"), FindCachedMethodStatic(env, FindCachedClass(env, \"" + packageName + "/Unit\"), \"get\", \"(J)L" + packageName + "/Unit;\"), " + fieldName + ".getTarget())\n" +
                                ", " + fieldName + ".getTargetPosition().x \n" +
                                ", " + fieldName + ".getTargetPosition().y \n" +
                                ", resolveUnitCommandExtra(" + fieldName + ")";
            default:
                System.err.println("Invalid type " + javaType);
                throw new UnsupportedOperationException();
        }
    }

    public boolean isBWTA(String cls) {
        return bwtaClasses.contains(cls);
    }


    public boolean isPrimitive(String javaType) {
        return javaType.equals("Integer") || javaType.equals("Boolean") || javaType.equals("Double");
    }

    public String javaObjectToPrimitive(String cType) {
        switch (cType) {
            case "Integer":
                return "int";
            case "Double":
                return "double";
            case "Boolean":
                return "bool";
            default:
                return cType;
        }
    }
}
