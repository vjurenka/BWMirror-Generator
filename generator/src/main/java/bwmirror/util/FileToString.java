package bwmirror.util;

import java.io.IOException;
import java.net.URI;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * User: PC
 * Date: 30.4.2014
 * Time: 16:34
 */
public class FileToString {
    public static String readFile(URI path) {
        byte[] encoded = new byte[0];
        try {
            encoded = Files.readAllBytes(Paths.get(path));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return new String(encoded, Charset.defaultCharset());
    }
}
