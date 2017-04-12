package bwmirror.impl;

import bwmirror.c.CClass;
import bwmirror.c.DeclarationType;
import bwmirror.c.Field;

import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 5.3.2014
 * Time: 10:12
 */
public class Clazz implements CClass {

    String name;

    List<Field> fields = new FieldList<Field>();

    public Clazz(String name) {
        this.name = name;
    }

    @Override
    public List<Field> getFields() {
        return fields;
    }

    @Override
    public boolean isStatic() {
        return false;
    }

    @Override
    public String getName() {
        return name;
    }

    public String toString(){
        String str = "class " + name + "\n";
        for(Field f: fields){
            str += f+"\n";
        }
        return str ;
    }

    @Override
    public DeclarationType getDeclType() {
        return DeclarationType.CLASS;
    }

    private String javadoc;

    public String getJavadoc() {
        return javadoc;
    }

    public void setJavadoc(String javadoc) {
        this.javadoc = javadoc;
    }
}
