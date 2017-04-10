package bwmirror.javadoc;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.regex.Pattern;

/**
 * User: PC
 * Date: 12. 7. 2015
 * Time: 14:27
 */
public class CrawlerBWAPI4 {

    private String baseUrl = "http://bwapi.github.io/";

    private Pattern p = Pattern.compile("(<a href=\"[^\"]*?)(\">)");

    private Pattern pp = Pattern.compile("#(.*?)\\.html");

    public void setBaseUrl(String baseUrl) {
        this.baseUrl = baseUrl;
    }

    public Documentation request(String className) {
        String url = baseUrl + "class_b_w_a_p_i_1_1" + className.replaceAll("([A-Z])", "_$1").toLowerCase() + ".html";
        try {
            Document document = null;
            try {
                document = Jsoup.connect(url).get();
            } catch (IOException e) {
                url = baseUrl + "class_b_w_a_p_i_1_1" + className.replaceAll("([A-Z])", "_$1").toLowerCase() +"_interface" + ".html";
                document = Jsoup.connect(url).get();
            }

            Documentation documentation = new Documentation();

            //$('.contents > .textblock').html()


            try {
                Element element = document.select(".contents > .textblock").get(0);
                documentation.header = element.text();
            } catch (Exception e) {
                //
            }

            Elements elements = document.select(".memitem");
            for (Object element1 : elements) {

                Element node = (Element) element1;

                String methodText = node.select(".memdoc").get(0).text();
                String methodName = node.select("td.memname").get(0).text();

                methodName = methodName.substring(methodName.lastIndexOf("::") + 2);
                DocumentedField df = new DocumentedField(methodName);
                if(documentation.fields.get(df) == null){
                    documentation.fields.put(df, methodText);
                }


            }

            return documentation;
        } catch (IOException e) {
            //e.printStackTrace();
            System.err.println("Documentation for " + className + " not found, skipping." + url);
            return null;
        } catch (Exception e) {
            System.err.println("Documentation for " + className + " not found, skipping.");
            return null;

        }

    }

}