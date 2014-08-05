package generator.c;

import java.io.PrintStream;

/**
 * User: PC
 * Date: 28. 7. 2014
 * Time: 13:51
 */
public class IdCache {

    private PrintStream out;

    public void setOut(PrintStream out) {
        this.out = out;
    }

    public void implementCache() {
        out.println("using namespace std;");
        out.println();
        out.println("map<string, jclass> clsCache;");
        out.println("map<pair<jclass, pair<string, string>>, jmethodID> staticMethodCache;");
        out.println("map<pair<jclass, pair<string, string>>, jmethodID> methodCache;");
        out.println("map<pair<jclass, pair<string, string>>, jfieldID> fieldCache;");
        out.println();
        out.println();
        implementClsCache();
        implementStaticMethodCache();
        implementMethodCache();
        implementFieldCache();
        out.println("using namespace BWAPI;");
        out.println();
    }

    private void implementClsCache() {
        out.println("jclass FindCachedClass(JNIEnv * env, string name){");
        out.println("\tif(clsCache.find(name) == clsCache.end()){");
        out.println("\t\tclsCache.insert(pair<string, jclass>(name, (jclass)env->NewGlobalRef(env->FindClass(name.c_str()))));");
        out.println("\t}");
        out.println("\t return clsCache.find(name)->second;");
        out.println("};");
        out.println();
    }

    private void implementStaticMethodCache() {
        out.println("jmethodID FindCachedMethodStatic(JNIEnv * env, jclass clz, string name, string signature){");
        out.println("\tpair<jclass, pair<string, string>> clsNameSig(clz, pair<string, string>(name, signature));");
        out.println("\tif(staticMethodCache.find(clsNameSig) == staticMethodCache.end()){");
        out.println("\t\tstaticMethodCache.insert(pair<pair<jclass, pair<string, string>>, jmethodID> (clsNameSig, env->GetStaticMethodID(clz, name.c_str(), signature.c_str())));");
        out.println("\t}");
        out.println("\t return staticMethodCache.find(clsNameSig)->second;");
        out.println("};");
        out.println();
    }

    private void implementMethodCache() {
        out.println("jmethodID FindCachedMethod(JNIEnv * env, jclass clz, string name, string signature){");
        out.println("\tpair<jclass, pair<string, string>> clsNameSig(clz, pair<string, string>(name, signature));");
        out.println("\tif(methodCache.find(clsNameSig) == methodCache.end()){");
        out.println("\t\tmethodCache.insert(pair<pair<jclass, pair<string, string>>, jmethodID>(clsNameSig, env->GetMethodID(clz, name.c_str(), signature.c_str())));");
        out.println("\t}");
        out.println("\t return methodCache.find(clsNameSig)->second;");
        out.println("};");
        out.println();
    }


    private void implementFieldCache() {
        out.println("jfieldID FindCachedField(JNIEnv * env, jclass clz, string name, string signature){");
        out.println("\tpair<jclass, pair<string, string>> clsNameSig(clz, pair<string, string>(name, signature));");
        out.println("\tif(fieldCache.find(clsNameSig) == fieldCache.end()){");
        out.println("\t\tfieldCache.insert(pair<pair<jclass, pair<string, string>>, jfieldID>(clsNameSig, env->GetFieldID(clz, name.c_str(), signature.c_str())));");
        out.println("\t}");
        out.println("\t return fieldCache.find(clsNameSig)->second;");
        out.println("};");
        out.println();
    }
}
