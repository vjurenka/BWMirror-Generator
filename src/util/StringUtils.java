package util;

/**
 * User: PC
 * Date: 22. 3. 2015
 * Time: 14:52
 */
public class StringUtils {
    public static String capitalize(final String line) {
       return Character.toUpperCase(line.charAt(0)) + line.substring(1);
    }
}
