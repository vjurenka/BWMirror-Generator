package bwmirror.impl;

import bwmirror.c.CEnum;
import bwmirror.c.DeclarationType;
import bwmirror.c.EnumValue;

import java.util.ArrayList;
import java.util.List;

/**
 * User: PC
 * Date: 14. 6. 2014
 * Time: 14:07
 */
public class Enum implements CEnum {

    String name;

    List<EnumValue> values = new ArrayList<>();

    String nameSpaceName = null;

    public Enum(String name, String nameSpaceName) {
        this.name = name;
        if(nameSpaceName != null && !nameSpaceName.isEmpty()){
            this.nameSpaceName = nameSpaceName;
        }
    }

    @Override
    public List<EnumValue> getValues() {
        return values;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public String getNameSpaceName() {
        return nameSpaceName;
    }

    public String getFullName() {
        return (nameSpaceName != null ? (getNameSpaceName() + "_" ): "") + getName();
    }

    public String toString() {
        String str = "enum " + nameSpaceName + "_" + name + "\n";
        for (EnumValue f : values) {
            str += f + "\n";
        }
        return str;
    }

    @Override
    public DeclarationType getDeclType() {
        return DeclarationType.ENUM;
    }

    private String javadoc;

    public String getJavadoc() {
        return javadoc;
    }

    public void setJavadoc(String javadoc) {
        this.javadoc = javadoc;
    }
}
