package generator.java;

import c.CDeclaration;
import c.CEnum;
import c.EnumValue;
import generator.MirrorContext;

import java.io.File;
import java.io.PrintStream;
import java.util.List;

/**
 * User: PC
 * Date: 14. 6. 2014
 * Time: 14:27
 */
public class EnumMirror extends Mirror {

    private CEnum cEnum;

    public EnumMirror(CEnum cEnum) {
        this.cEnum = cEnum;
    }

    protected void writePackage() {
        if (cEnum.getNameSpaceName() == null) {
            super.writePackage();
            return;
        }
        out.println("package" + SPACE + context.getPackage() + "." + cEnum.getNameSpaceName() + SEMICOLON);
        out.println();
    }

    public void write(File root, MirrorContext context) throws Exception {
        this.context = context;

        File innerDir = new File(root, context.getPackageDirs());
        if (cEnum.getNameSpaceName() != null) {
            String namespace = cEnum.getNameSpaceName();
            if(namespace.contains(".")){
                innerDir = new File(innerDir,namespace.substring(0, namespace.indexOf(".")));
                innerDir.mkdirs();
                namespace = namespace.substring(namespace.indexOf(".") + 1);
            }
            innerDir = new File(innerDir,namespace);
            innerDir.mkdirs();
        }
        File file = new File(innerDir, cEnum.getName() + ".java");

        out = new PrintStream(file);

        writePackage();
        writeImports();
        out.println("public" + SPACE + "enum" + SPACE + cEnum.getName() + SPACE + "{");
        out.println();
        writeValues(cEnum.getValues());
        writeValueField();
        writeConstructor();

        out.println("}");

        out.close();
    }

    private void writeValueField() {
        out.println("\tprivate int value;");
        out.println("");
        out.println("\tpublic int getValue(){");
        out.println("\t\treturn value;");
        out.println("\t}");
        out.println();
    }

    private void writeConstructor() {
        out.println("\t" + cEnum.getName() + "(int value){");
        out.println("\t\tthis.value = value;");
        out.println("\t}");
        out.println();
    }

    private void writeValues(List<EnumValue> values) {
        for (int i = 0; i < values.size(); i++) {
            EnumValue value = values.get(i);
            if (i > 0) {
                out.println(",");
            }
            out.print("\t" + value.first + "(" + value.second + ")");
        }
        out.println(SEMICOLON);
        out.println();
    }

    @Override
    protected CDeclaration getDecl() {
        return cEnum;
    }
}
