package bwmirror.c;

import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 10:48
 */
public interface CClass extends CDeclaration {

    public List<Field> getFields();

    public boolean isStatic();
}
