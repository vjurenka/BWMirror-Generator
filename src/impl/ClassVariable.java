package impl;

import c.DeclarationType;
import c.Variable;

/**
 * User: PC
 * Date: 17. 6. 2014
 * Time: 19:44
 */
public class ClassVariable implements Variable {

    private String type, name;

    public ClassVariable(String type, String name) {
        this.type = type;
        this.name = name;
    }

    @Override
    public String getType() {
        return type;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public DeclarationType getDeclType() {
        return DeclarationType.VARIABLE;
    }

    private String javadoc;

    public String getJavadoc() {
        return javadoc;
    }

    public void setJavadoc(String javadoc) {
        this.javadoc = javadoc;
    }
}
