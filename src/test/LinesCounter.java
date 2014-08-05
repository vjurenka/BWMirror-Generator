package test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

/**
 * Author: Vladimir
 * Date: May 30, 2009
 * Time: 8:12:51 PM
 */
public class LinesCounter {

    public static final String start = "src/";

    private static int lines = 0;

    private static int files = 0;

    public LinesCounter() {
    }

    public static void countLines() {
        File begin = new File(start);
        countArray(begin.listFiles());
        System.out.println("Files: " + files);
        System.out.println("Lines: " + lines);
    }

    public static void countArray(File[] files) {
        for (File f : files) {
            if (f.isDirectory()) {
                if (f.listFiles().length > 0) {
                    countArray(f.listFiles());
                }
            } else {
                countSingle(f);
            }
        }
    }

    public static void countSingle(File f) {
        if(!f.getName().endsWith(".java")){
            return;
        }
        try {
            files++;
            BufferedReader newFile = new BufferedReader(new FileReader(f));
            while (true) {
                if (!newFile.ready()) break;
                newFile.readLine();
                lines++;
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        countLines();
    }
}
