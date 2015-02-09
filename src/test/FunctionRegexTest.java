package test;

import impl.CApiParser;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * User: PC
 * Date: 19. 6. 2014
 * Time: 11:28
 */
public class FunctionRegexTest {

    //                    1     2             3       4 56       7        89                 10               11          12,13    14,15
    //String FUNC_REGEX = "^(\\s*)(virtual)?\\s(const\\s)?((BWAPI::)|(std::))?((set<(\\w+\\*?)>)|([\\w\\*]+))&?\\s([\\w\\*]+)\\((.*)\\)((\\sconst)?\\s*=\\s*0;)?";
    String FUNC_REGEX = "^(\\s*)(virtual)?\\s(const\\s)?(static\\s)?((BWAPI::)|(std)::)?((set<(\\s*(BWAPI::)?\\w+\\*?\\s*)>)|([\\w\\*]+))&?\\s+(&?[\\w\\*]+)\\((.*)\\)(\\s*const)?(\\s*=\\s0)?(;)?\\s*";
    String ENUM_VALUE_REGEX = "^(\\s*)(\\w+)(\\s*=\\s*(0x)?([0-9A-Fa-f]+))?\\s*[\\,;]";

    Pattern funcPattern = Pattern.compile(CApiParser.FUNC_REGEX);

    public void run() {
        Matcher matcher = funcPattern.matcher("      static UnitCommand repair(Unit unit, Unit target, bool shiftQueueCommand = false);");
        if (matcher.matches()) {
            System.out.println("match");
        }
    }

    public static void main(String... args) {
        new FunctionRegexTest().run();
    }
}
