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

    //                    1     2             3         4           56         7        891011     12    13    14   15                     16                     17                18            19
    String FUNC_REGEX = "^(\\s*)(virtual\\s)?(const\\s)?(static\\s)?((BWAPI::)|(std::))?((((pair)|(set)|(map))<(\\s*(BWAPI::)?\\w+\\*?\\s*)(\\s*,\\s*\\w+\\s*)?>)|([\\w\\*]+))&?\\s+(&?[\\w\\*]+)\\((.*)\\)(\\s*const)?(\\s*=\\s0)?(;)?\\s*";


    String ENUM_VALUE_REGEX = "^(\\s*)(\\w+)(\\s*=\\s*(0x)?([0-9A-Fa-f]+))?\\s*[\\,;]";

    Pattern funcPattern = Pattern.compile(FUNC_REGEX);

    public void run() {
        Matcher matcher = funcPattern.matcher("const pair< UnitType , int > whatBuilds() const;");
        if (matcher.matches()) {
            System.out.println("match");
            System.out.print(matcher.group(18));
        }
    }

    public static void main(String... args) {
        new FunctionRegexTest().run();
    }
}
