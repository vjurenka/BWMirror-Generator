package bwmirror.util;

/**
 * User: PC
 * Date: 19. 6. 2014
 * Time: 12:49
 */
public class Generic {
    public static String extractGeneric(String str){
        return str.substring(str.indexOf("<") +1, str.indexOf(">")).trim();
    }

    public static  String[] extractPair(String str) {
        str = str.substring(str.indexOf("<") +1, str.indexOf(">")).trim();
        String[] kv = str.split(",");
        return new String[]{kv[0].trim(), kv[1].trim()};
    }

    public static String stripGeneric(String str){
        int index = str.indexOf("<");
        if (index == -1){
            return str;
        }
        return str.substring(0, index);
    }
}
