package test;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * User: PC
 * Date: 24. 6. 2014
 * Time: 20:36
 */
public class RegexTest {

    public static void main(String...args){
        Pattern p = Pattern.compile("(.*<a href=\"[^>]*)(\">)(.*)");
        String input = "<a href=\"file:///C:/Users/PC/IdeaProjects/BWLIB/javadoc/bwapi/GameTypes\">";
        Matcher m = p.matcher(input);
        if (m.find()) {
            // replace first number with "number" and second number with the first
            String output = m.replaceFirst("$1.html$2$3");
            System.out.println("rep "+output);
        }
    }
}
