package generator.java;

import c.*;
import generator.MirrorContext;

import java.io.File;
import java.io.PrintStream;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 16:02
 */
public class ClassMirror extends Mirror {

    private CClass cClass;

    private String nativeBinds;

    public ClassMirror(CClass cClass) {
        this.cClass = cClass;
    }

    public void write(File root, MirrorContext context) throws Exception {
        nativeBinds = "";
        this.context = context;
        File file = new File(new File(root, context.getPackageDirs()), cClass.getName() + ".java");

        out = new PrintStream(file);

        writePackage();
        writeImports();
        out.println("public" + SPACE + "class" + SPACE + cClass.getName() + SPACE + "{");
        out.println();
        writeFields(cClass.getFields());
        if (!cClass.isStatic()) {
            writeInstanceMap();
            writeConstructor();
            writeInstanceGetter();
            writePointerField();
            out.println(nativeBinds);
        }
        out.println("}");

        out.close();
        nativeBinds = null;
    }

    private void writeInstanceMap() {
        out.println(INTEND + "private" + SPACE + "static" + SPACE + "Map<Long," + SPACE + cClass.getName() + "> instances = " +
                "new HashMap<Long," + SPACE + cClass.getName() + ">()" + SEMICOLON);
        out.println();
    }

    private void writeInstanceGetter() {
        out.println(INTEND + "private" + SPACE + "static" + SPACE + cClass.getName() + SPACE + "get(long pointer)" + SPACE + "{");
        out.println(INTEND + INTEND + cClass.getName() + SPACE + "instance = instances.get(pointer)" + SEMICOLON);
        out.println(INTEND + INTEND + "if (instance == null ) {");
        out.println(INTEND + INTEND + INTEND + "instance = new" + SPACE + cClass.getName() + "(pointer)" + SEMICOLON);
        out.println(INTEND + INTEND + INTEND + "instances.put(pointer, instance)" + SEMICOLON);
        out.println(INTEND + INTEND + "}");
        out.println(INTEND + INTEND + "return instance" + SEMICOLON);
        out.println(INTEND + "}");
        out.println();
    }

    private void writeConstructor() {
        out.println(INTEND + "private" + SPACE + cClass.getName() + "(long pointer)" + SPACE + "{");
        out.println(INTEND + INTEND + "this.pointer" + SPACE + "=" + SPACE + "pointer" + SEMICOLON);
        out.println(INTEND + "}");
        out.println();
    }

    private void writePointerField() {
        out.println(INTEND + "private" + SPACE + "long" + SPACE + "pointer" + SEMICOLON);
        out.println();
    }

    private void writeFields(List<Field> fields) {
        for (Field field : fields) {
            if (field instanceof Method) {
                writeJavadoc(field);
                writeMethod((Method) field);
            } else {
                if (field instanceof Variable) {
                    writeVariable((Variable) field);
                } else {
                    writeConstant((Constant) field);
                }

                out.println(SEMICOLON);
            }
            out.println();
        }
        out.println();
    }

    private void writeVariable(Variable variable) {
        out.print(INTEND + "public" + SPACE + "static" + SPACE + context.toJavaType(variable.getType()) + SPACE + variable.getName());
    }

    private void writeConstant(Constant constant) {
        out.print(INTEND + "public" + SPACE + "static" + SPACE + "final" + SPACE + context.toJavaType(constant.getType()) + SPACE + constant.getName());
    }

    private void checkToString(Method method) {
        if (method.getName().equals("c_str") && method.getParams().isEmpty()) {
            out.println();
            out.println(INTEND + "public String toString(){");
            out.println(INTEND + INTEND + "return c_str();");
            out.println(INTEND + "}");
        }
    }
    private void writeMethod(Method method) {
        writeMethod(method, true);
    }

    private void writeMethod(Method method, boolean checkDefaults) {
        if(checkDefaults){
            handleDefaults(method);
        }
        out.print(INTEND + "public" + SPACE + (cClass.isStatic() ? "static" + SPACE + "native" + SPACE : "") + context.toJavaType(method.getType()) + SPACE + method.getName() + "(");
        boolean first = true;
        for (Param param : method.getParams()) {
            if (!first) {
                out.print("," + SPACE);
            }
            first = false;
            out.print(paramString(param));
        }
        out.print(")");
        if (!cClass.isStatic()) {
            out.println(SPACE + "{");
            writeNativeCall(method);
            out.println(INTEND + "}");


            nativeBinds += INTEND + "private" + SPACE + "native" + SPACE + context.toJavaType(method.getType()) + SPACE + method.getName() +
                    "_native(" + nativeCallParams(method) + ")" + SEMICOLON + NEW_LINE + NEW_LINE;

            checkToString(method);
        }
        else{
            out.println(SEMICOLON);
        }
    }

    private void handleDefaults(Method method) {
        int numParams =  method.getParams().size();
        for (int i = numParams - 1; i >= 0; i--) {
            if (method.getParams().get(i).third != null) {
                Method clone = method.clone();

                for(int j = 0; j < numParams - i; j++){
                    clone.getParams().remove(clone.getParams().size() - 1);
                }
                writeMethod(clone, false);
                out.println();
            }
        }
    }

    private String handlePointerInName(String paramName) {
        return (paramName.startsWith("*") ? paramName.substring(1) : paramName);
    }

    private void writeNativeCall(Method method) {
        String paramCallString = "";
        for (Param param : method.getParams()) {
            paramCallString += "," + SPACE + handlePointerInName(param.second);
        }
        out.println(INTEND + INTEND + (method.getType().equals("void") ? "" : ("return" + SPACE)) + method.getName() + "_native(pointer" + paramCallString + ")" + SEMICOLON);
    }

    private String nativeCallParams(Method method) {
        String paramString = "long pointer";
        List<Param> params = method.getParams();
        if (!params.isEmpty()) {
            for (Param param : params) {
                paramString += "," + SPACE + paramString(param);
            }
        }
        return paramString;
    }

    private String paramString(Param param) {
        return context.toJavaType(param.first) + SPACE + handlePointerInName(param.second);
    }

    @Override
    protected CDeclaration getDecl() {
        return cClass;
    }
}
