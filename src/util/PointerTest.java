package util;

import generator.CJavaPipeline;

import java.util.Arrays;
import java.util.List;

/**
 * User: PC
 * Date: 7. 2. 2015
 * Time: 16:39
 */
public class PointerTest {

    private static final List<String> BWAPI4_INTERFACES = Arrays.asList("Client", "Game", "AIModule" ,"Event", "Race", "Error");

    private static boolean testCls(String cls){
        return BWAPI4_INTERFACES.contains(cls) || cls.endsWith("set") || cls.endsWith("Type");
    }

    public static String test(String cls) {
        return test(cls, true);
    }


    public static String test(String cls, boolean print) {
        if (CJavaPipeline.isBWAPI3()) {
            return (print ? cls : "" )+ "*";
        }
        return (print ? cls : "" ) + (testCls(cls) ? "*" : "");
    }

}
