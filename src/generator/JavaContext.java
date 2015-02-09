package generator;

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

    private List<String> valueTypes = Arrays.asList("Position", "TilePosition", "WalkPosition", "Color", "BWTA::RectangleArray<double>", "PositionOrUnit", "Point", "UnitCommand");

    private List<String> constantTypes = Arrays.asList("UnitType", "TechType", "UpgradeType", "Race", "UnitCommand", "WeaponType", "Order", "GameType", "Error");

    private List<String> enumTypes = Arrays.asList("MouseButton", "Key", "bwapi4.Text.Size.Enum", "bwapi4.CoordinateType.Enum", "Text::Size::Enum", "CoordinateType::Enum");

    private List<String> valueReturnTypes = Arrays.asList("Event");

    private List<String> bwtaClasses = Arrays.asList("Chokepoint", "Region", "RectangleArray", "Polygon", "BaseLocation");


    private String packageName = "bwapi";

    public JavaContext() {
        javaToCType.put("long", "jlong");
        javaToCType.put("int", "jint");
        javaToCType.put("void", "void");
        javaToCType.put("boolean", "jboolean");
        javaToCType.put("String", "jstring");
    }

    public String getPackageName() {
        return packageName;
    }

    public String getPackageName(String javaRetType) {
        if (javaRetType.equals("Position") || javaRetType.equals("TilePosition")) {
            return "bwapi";
        }
        return packageName;
    }

    public void setPackageName(String packageName) {
        this.packageName = packageName;
    }

    public String toCType(String javaType) {
        String result = javaToCType.get(javaType);
        return result != null ? result : "PTR";
    }

    public boolean isPointer(String javaType) {
        return javaType.equals("PTR");
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
            return ")->second";
        }
        return "";
    }

    public boolean isCollection(String javaType) {
        return javaType.startsWith("List");
    }

    public String copyConstructor(String javaType) {
        switch (javaType) {
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
            default:
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
                        ", env->CallStaticObjectMethod(FindCachedClass(env, \"" + packageName + "/Unit\"), FindCachedMethodStatic(env, FindCachedClass(env, \"" + packageName + "/Unit\"), \"get\", \"(J)Lbwapi4/Unit;\"), " +fieldName+ ".getUnit())" +
                                ", env->CallStaticObjectMethod(FindCachedClass(env, \"" + packageName + "/UnitCommandType\"), FindCachedMethodStatic(env, FindCachedClass(env, \"" + packageName + "/UnitCommandType\"), \"get\", \"(J)Lbwapi4/UnitCommandType;\"), "+fieldName+".getType())" +
                                ", env->CallStaticObjectMethod(FindCachedClass(env, \"" + packageName + "/Unit\"), FindCachedMethodStatic(env, FindCachedClass(env, \"" + packageName + "/Unit\"), \"get\", \"(J)Lbwapi4/Unit;\"), "+fieldName+".getTarget())" +
                                ", "+ fieldName +".getTargetPosition().x " +
                                ", "+ fieldName +".getTargetPosition().y " +
                                ", resolveUnitCommandExtra("+fieldName+")";
            default:
                throw new UnsupportedOperationException();
        }
    }

    public boolean isBWTA(String cls) {
        return bwtaClasses.contains(cls);
    }
}
