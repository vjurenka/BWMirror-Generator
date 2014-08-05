package util;

/**
 * User: PC
 * Date: 19. 6. 2014
 * Time: 12:49
 */
public class Generic {
    public static String extractGeneric(String str){
        return str.substring(str.indexOf("<") +1, str.indexOf(">")).trim();
    }
}
