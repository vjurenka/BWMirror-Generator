package bwmirror.c;

import java.util.List;

/**
 * User: PC
 * Date: 14. 6. 2014
 * Time: 14:06
 */
public interface CEnum extends CDeclaration{

    public List<EnumValue> getValues();

    public String getNameSpaceName();

    public String getFullName();
}
