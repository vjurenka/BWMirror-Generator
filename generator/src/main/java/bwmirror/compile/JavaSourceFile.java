package bwmirror.compile;

import bwmirror.util.FileToString;

import javax.tools.SimpleJavaFileObject;
import java.io.File;

/**
 * User: PC
 * Date: 30.4.2014
 * Time: 16:30
 */
public class JavaSourceFile extends SimpleJavaFileObject {

    private String sourceCode;

    public JavaSourceFile(File file) {
        super(file.toURI(), Kind.SOURCE);
        this.sourceCode = FileToString.readFile(file.toURI());
    }

    @Override
    public CharSequence getCharContent(boolean ignoreEncodingErrors) {
        return sourceCode;
    }

}
