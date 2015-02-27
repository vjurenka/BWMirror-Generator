package generator.java;

import c.CClass;
import c.CDeclaration;
import generator.MirrorContext;
import javadoc.Crawler;
import javadoc.Documentation;
import javadoc.DocumentedField;

import java.io.PrintStream;

/**
 * User: PC
 * Date: 14. 6. 2014
 * Time: 14:27
 */
public abstract class Mirror {

    private static final boolean WRITE_DOC = false;

    protected static final String SPACE = " ";

    protected static final String SEMICOLON = ";";

    protected static final String INTEND = "    ";

    protected static final String NEW_LINE = "\r\n";

    protected PrintStream out;

    protected MirrorContext context;

    private Documentation documentation;

    //private static final boolean DOC = false;

    protected abstract CDeclaration getDecl();

    protected String lastDoc = null;

    protected void writeJavadoc(CDeclaration field) {
        if (WRITE_DOC) {
            if (field.getJavadoc() != null) {
                if (field.getJavadoc().contains("copydoc")) {
                    if (lastDoc != null) {
                        out.print(lastDoc);
                    }
                } else {
                    out.print(field.getJavadoc());
                    lastDoc = field.getJavadoc();
                }
            } else {
                if (field instanceof CClass) {
                    Crawler cl = new Crawler();
                    if (context.getPackage().equals("bwta")) {
                        cl.setBaseUrl("https://code.google.com/p/bwta/wiki/");
                    }
                    documentation = cl.request(getDecl().getName());
                    if (documentation != null) {
                        printJavadoc(documentation.header);
                    }
                }
                if (documentation == null) {
                    return;
                }
                String javadoc = documentation.fields.get(new DocumentedField(field.getName()));
                if (javadoc != null) {
                    printJavadoc(javadoc);
                }
            }
        }
    }

    private void printJavadoc(String javadoc) {
        out.println("/**");
        out.println(javadoc);
        out.println("*/");
    }

    protected void writePackage() {
        out.println("package" + SPACE + context.getPackage() + SEMICOLON);
        out.println();
    }


    protected void writeImports(String superClass) {
        out.println("import" + SPACE + context.getPackage() + ".*" + SEMICOLON);
        out.println();
        out.println("import java.util.Map" + SEMICOLON);
        out.println("import java.util.HashMap" + SEMICOLON);
        out.println("import java.util.Collection" + SEMICOLON);
        out.println("import java.util.List" + SEMICOLON);
        for (String pkg : context.getAdditionalImports()) {
            out.println("import" + SPACE + pkg + SEMICOLON);
        }
        if (superClass != null) {
            out.println("import" + SPACE + /*context.getPackage() +*/ "bwapi." + superClass + SEMICOLON);
        }
        out.println();
        writeJavadoc(getDecl());
    }
}
