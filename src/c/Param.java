package c;

import util.Triple;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 17:03
 */
public class Param extends Triple<String, String, String> {

    public Param() {
    }

    public Param(String first, String second) {
        super(first, second);
    }

    //c type, name, javatype
    public Param(String first, String second, String third) {
        super(first, second, third);
    }
}
