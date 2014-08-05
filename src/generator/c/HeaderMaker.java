package generator.c;

import java.io.*;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 17:34
 */
public class HeaderMaker {

    private String prepareClassList(List<String> javaRoot, File clpath) {
        /*JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        try {
            compiler.run(null, new FileOutputStream("bwapi/Bullet.class"), null, new File("bwapi/Bullet.java").getAbsolutePath());
        } catch (Exception e) {
            e.printStackTrace();
        }              */
        StringBuffer result = new StringBuffer();
        for (String javaRootDir : javaRoot) {
            for (File f : new File(clpath, javaRootDir).listFiles(new FilenameFilter() {
                @Override
                public boolean accept(File dir, String name) {
                    return name.endsWith(".class");
                }
            })) {
                result.append(" ").append(javaRootDir).append(".").append(f.getName().substring(0, f.getName().indexOf(".")));
            }
        }
        //return "bwapi.Bullet";
        return result.toString();
    }

    public void run(List<String> javaRoot, File clpath) {
        String command;

        command = "javah -o concat_header.h -classpath " + clpath.toString() + prepareClassList(javaRoot, clpath);
//        System.out.println(command);
        try {
            Process process = Runtime.getRuntime().exec(command);
            //process.getErrorStream()
            BufferedReader br = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            String s;
            while ((s = br.readLine()) != null) {
                System.out.println(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        command = "javah -d headers -classpath " + clpath.toString() + prepareClassList(javaRoot, clpath);
        try {
            Process process = Runtime.getRuntime().exec(command);
            //process.getErrorStream()
            BufferedReader br = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            String s;
            while ((s = br.readLine()) != null) {
                System.out.println(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
