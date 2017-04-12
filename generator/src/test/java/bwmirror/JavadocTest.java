package bwmirror;

import bwmirror.javadoc.CrawlerBWAPI4;

/**
 * User: PC
 * Date: 24. 6. 2014
 * Time: 18:26
 */
public class JavadocTest {

    public static void main(String...args){
        CrawlerBWAPI4 c = new CrawlerBWAPI4();
        c.request("Race");
    }

}
