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
        return cType.startsWith("set<");
    }

    private boolean isBWAPI4Collection(String cType) {
        return cType.endsWith("set");
    }

    private String extractCollectionGeneric(String cType) {
        cType = cType.substring(cType.indexOf("<") + 1, cType.lastIndexOf(">")).trim();
        if (cType.contains(":")) {
            cType = cType.substring(cType.lastIndexOf(":") + 1);
        }
        if (cType.endsWith("*")) {
            cType = cType.substring(0, cType.lastIndexOf("*"));
        }
        return cType;
    }

    private String extractBWAPI4CollectionGeneric(String cType) {
        return cType.substring(0, cType.length() - 3);
    }


    public String toJavaType(String cType) {
        if (isCollection(cType)) {
            return "List<" + extractCollectionGeneric(cType) + ">";
        }
        if (isBWAPI4Collection(cType)) {
            return "List<" + extractBWAPI4CollectionGeneric(cType) + ">";
        }
        String result = cToJavaTypes.get(cType);
        int ddIndex;
        if (result != null && (ddIndex = result.lastIndexOf(':')) != -1) {
            result = result.substring(ddIndex + 1);
        }
        if (cType.endsWith("*")) {
            return cType.substring(0, cType.length() - 1);
        }
        /*if (CJavaPipeline.BWAPI_VERSION == CJavaPipeline.BWAPI_V4 && cType.contains("bwapi.")) {
            cType = cType.replace("bwapi.", "bwapi4.");
        } */
        return result != null ? result : cType;
    }

    public List<String> getAdditionalImports() {
        return additionalImports;
    }

    public void setAdditionalImports(List<String> additionalImports) {
        this.additionalImports = additionalImports;
    }
}
