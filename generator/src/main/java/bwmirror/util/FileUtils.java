package bwmirror.util;

import java.io.File;

/**
 * User: PC
 * Date: 14. 8. 2014
 * Time: 10:11
 */
public class FileUtils {

    @SuppressWarnings("ResultOfMethodCallIgnored")
    public static void deleteDirectory(File directory) {
        if (directory.exists()) {
            File[] files = directory.listFiles();
            if (files != null) {
                for (File file : files) {
                    if (file.isDirectory()) {
                        deleteDirectory(file);
                    } else {
                        file.delete();
                    }
                }
            }
        }
    }

}
