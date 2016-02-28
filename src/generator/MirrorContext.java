package generator;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 16:05
 */
public class MirrorContext {

    private String packageName;

    private HashMap<String, String> cToJavaTypes = new HashMap<>();

    private List<String> additionalImports = new ArrayList<>();

    public MirrorContext() {
        cToJavaTypes.put("bool", "boolean");
        cToJavaTypes.put("int", "int");
        cToJavaTypes.put("string", "String");
    }

    public void setPackage(String packageName) {
        this.packageName = packageName;
    }


    public String getPackage() {
        return packageName;
    }

    public String getPackageDirs() {
        return getPackage().replaceAll("\\.", "/");
    }

    @SuppressWarnings("ResultOfMethodCallIgnored")
    public void prepareWrite(File root) {
        File dir = new File(root, getPackageDirs());
        dir.mkdirs();
    }

    private boolean isCollection(String cType) {
        return cType.startsWith("set<") || cType.startsWith("vector<");
    }

    private boolean isMap(String cType) {
        return cType.startsWith("map<");
    }

    private boolean isPair(String cType) {
        return cType.startsWith("pair<");
    }

    private boolean isDeque(String cType) {
        return cType.endsWith("::list");
    }

    private boolean isBWAPI4Collection(String cType) {
        return cType.endsWith("set");
    }

    private String convertPrimitive(String cType) {
        if (cType.equals("int")) {
            return "Integer";
        }
        if (cType.equals("bool")) {
            return "Boolean";
        }
        if (cType.equals("double")) {
            return "Double";
        }

        return cType;
    }

    private String extractPair(String cType) {
        cType = cType.substring(cType.indexOf("<") + 1, cType.lastIndexOf(">")).trim();
        String[] types = cType.split(",");
        return convertPrimitive(toJavaType(types[0].trim())) + ", " + convertPrimitive(toJavaType(types[1].trim()));
    }


    private String extractCollectionGeneric(String cType) {
        if(cType.contains("<")){
            cType = cType.substring(cType.indexOf("<") + 1, cType.lastIndexOf(">")).trim();
        }
        if(cType.endsWith("::list")) {
            cType = cType.substring(0, cType.lastIndexOf("::"));
        }

        if (cType.contains(":")) {
            cType = cType.substring(cType.lastIndexOf(":") + 1);
        }
        if (cType.endsWith("*")) {
            cType = cType.substring(0, cType.lastIndexOf("*"));
        }


        return cType;
    }

    private String extractBWAPI4CollectionGeneric(String cType) {
        cType = cType.substring(0, cType.length() - 3);
        return cType;
    }


    public String toJavaType(String cType) {
        if (isDeque(cType)) {
            return "List<" + extractCollectionGeneric(cType) + ">";
        }
        if (isCollection(cType)) {
            return "List<" + extractCollectionGeneric(cType) + ">";
        }
        if (isBWAPI4Collection(cType)) {
            return "List<" + extractBWAPI4CollectionGeneric(cType) + ">";
        }
        if (isMap(cType)) {
            return "Map<" + extractPair(cType) + ">";
        }
        if (isPair(cType)) {
            return "Pair<" + extractPair(cType) + ">";
        }
        String result = cToJavaTypes.get(cType);
        if (result == null) {
            result = cType;
        }
        int ddIndex;
        if ((ddIndex = result.lastIndexOf(':')) != -1) {
            result = result.substring(ddIndex + 1);
        }
        if (result.endsWith("*")) {
            return result.substring(0, result.length() - 1);
        }
        /*if (CJavaPipeline.BWAPI_VERSION == CJavaPipeline.BWAPI_V4 && cType.contains("bwapi.")) {
            cType = cType.replace("bwapi.", "bwapi4.");
        } */
        return result;
    }

    public List<String> getAdditionalImports() {
        return additionalImports;
    }

    public void setAdditionalImports(List<String> additionalImports) {
        this.additionalImports = additionalImports;
    }
}
