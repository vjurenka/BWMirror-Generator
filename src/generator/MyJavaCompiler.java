package generator;

import compile.JavaSourceFile;

import javax.tools.*;
import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;

/**
 * User: PC
 * Date: 30.4.2014
 * Time: 16:13
 */
public class MyJavaCompiler {

    JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();

    @SuppressWarnings("ConstantConditions")
    public void run(File inDir, File outDir) {
        outDir.delete();
        outDir.mkdir();

        List<JavaFileObject> javaFileObjects = new ArrayList<JavaFileObject>();
        DiagnosticCollector<JavaFileObject> diagnostics = new DiagnosticCollector<JavaFileObject>();
        Iterable<String> compilationOptions = Arrays.asList("-d", outDir.getName());

        for (File file : inDir.listFiles()) {
            if(file.isDirectory()){
                for(File ffile : file.listFiles()){
                    javaFileObjects.add(new JavaSourceFile(ffile));
                }
                continue;
            }
            javaFileObjects.add(new JavaSourceFile(file));
        }

        JavaCompiler.CompilationTask compilerTask =
                compiler.getTask(null, compiler.getStandardFileManager(null, Locale.getDefault(), null), diagnostics, compilationOptions, null, javaFileObjects);

        try {
            boolean status = compilerTask.call();

            for (Diagnostic diagnostic : diagnostics.getDiagnostics()){
                    System.out.format("Error on line %d in %s", diagnostic.getLineNumber(), diagnostic);
                }
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println();
    }
}
