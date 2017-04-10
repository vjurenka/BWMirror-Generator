package bwmirror.impl;

import bwmirror.c.DeclarationType;
import bwmirror.c.Variable;

/**
 * User: PC
 * Date: 17. 6. 2014
 * Time: 19:44
 */
public class ClassVariable implements Variable {

    private String type, name;

    private boolean isFinal;

    public ClassVariable(String type, String name, boolean isFinal) {
        this.type = type;
        this.name = name;
        this.isFinal = isFinal;
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

    @Override
    public boolean isFinal() {
        return isFinal;
    }
}
