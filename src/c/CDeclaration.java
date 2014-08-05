package c;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 10:50
 */
public interface CDeclaration {
    public String getName();
    public DeclarationType getDeclType();
    public void setJavadoc(String string);
    public String getJavadoc();
}
