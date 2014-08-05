package javadoc;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * User: PC
 * Date: 24. 6. 2014
 * Time: 18:13
 */
public class Crawler {

    private String baseUrl = "https://code.google.com/p/bwapi/wiki/";

    private Pattern p = Pattern.compile("(<a href=\"[^\"]*?)(\">)");

    private Pattern pp = Pattern.compile("#(.*?)\\.html");

    public void setBaseUrl(String baseUrl) {
        this.baseUrl = baseUrl;
    }

    public static String reformat(String html){
        return html.replaceAll("/p/bwapi/wiki/", "").replaceAll("Types\">", "Type\">").
                    replaceAll("Races\">", "Race\">").
                replaceAll("href=\"#", "href=\"").replaceAll("/p/bwta/wiki/", "").replaceAll("BWAPI::","").replaceAll("BWTA::","").replaceAll("Methods:","");
    }

    public Documentation request(String className) {
        String url = baseUrl + className;
        try {
            Document document = Jsoup.connect(url).get();

            Documentation documentation = new Documentation();

            Element element = document.select("#wikicontent").get(0);
            Elements elements = element.children().get(0).children();

            String header = "";

            int i = 0;
            for (i = 0; i < elements.size(); i++) {
                Element node = elements.get(i);
                if (node.nodeName().equals("ul")) {
                    break;
                }
                if (node.text().startsWith("Class header") || node.text().startsWith("Library header")) {
                    continue;
                }
                String html = node.html() + "\n";
                html = reformat(html);
                Matcher m = p.matcher(html);
                if (m.find()) {
                    html = m.replaceAll("$1.html$2");
                }
                m = pp.matcher(html);
                if (m.find()) {
                    html = m.replaceAll(".html");
                }
                header += html;
            }

            //System.out.println(header);
            if(className.equals("Polygon")){
                header = "A Polygon is a geometric representation of <a href=\"Region.html\">Region</a>\n";
            }
            if(className.equals("BWTA")){
                header = "BWTA class wraps the functionality of <a href=\"https://code.google.com/p/bwta/\">BWTA library</a>\n";
            }
            documentation.header = header;

            for (; i < elements.size(); i++) {
                String methodText = "";
                String methodName = "";
                Element node = elements.get(i);
                if (node.nodeName().equals("h2") || node.nodeName().equals("h3")) {
                    methodName = node.text();
                    Element methodNameElement = node.nextElementSibling();
                    Element next = methodNameElement.nextElementSibling();
                    i++;
                    while (next != null && !next.text().startsWith("See also") && !next.nodeName().equals("h2") && !next.nodeName().equals("h3")) {
                        if (!next.nodeName().equals("pre") && !next.text().trim().endsWith(");")) {
                            String html = next.html() + "\n";
                            html = reformat(html);
                            Matcher m = p.matcher(html);
                            if (m.find()) {
                                html = m.replaceAll("$1.html$2");
                            }
                            m = pp.matcher(html);
                            if (m.find()) {
                                html = m.replaceAll(".html");
                            }
                            methodText += html;
                        }
                        next = next.nextElementSibling();
                        if (next == null) {
                            break;
                        }
                        i++;
                    }

                    /*System.out.println(methodName);
                    System.out.println(methodText);
                    System.out.println();      */
                    documentation.fields.put(new DocumentedField(methodName), methodText);

                }
            }

            return documentation;
        } catch (IOException e) {
            //e.printStackTrace();
            System.err.println("Documentation for " + className + " not found, skipping.");
            return null;
        }

    }

}
