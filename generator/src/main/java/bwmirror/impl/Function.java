package bwmirror.impl;

import bwmirror.c.DeclarationType;
import bwmirror.c.Method;
import bwmirror.c.Param;

import java.util.ArrayList;
import java.util.List;

/**
 * User: PC
 * Date: 26.2.2014
 * Time: 20:34
 */
public class Function implements Method {

    String returnType;

    String name;

    ArrayList<Param> args = new ArrayList<Param>();

    boolean isStatic = false;

    @Override
    public List<Param> getParams() {
        return args;
    }

    @Override
    public Method clone() {
        Function f = new Function();
        f.name = name;
        f.returnType = returnType;
        //f.args.addAll(args);
        for (Param p : args){
            f.args.add(new Param(p.first, p.second, p.third));
        }
        f.isStatic = isStatic;
        return f;
    }

    Function() {
    }

    public Function(String name, String returnType, boolean isStatic, ArrayList<Param> args) {
        this.name = name;
        this.returnType = returnType;
        this.isStatic = isStatic;
        this.args = args;
    }

    @Override
    public String getType() {
        return returnType;
    }

    //final functions are not supported yet
    @Override
    public boolean isFinal() {
        return false;
    }

    @Override
    public String getName() {
        return name;
    }

    public String toString(){
       String sig =  returnType +" "+name+"(";
        for(Param p: getParams()){
            sig += p.first +" "+p.second +" ";
        }
        sig +=")";
        return sig;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Function)) return false;

        Function function = (Function) o;

        if (name != null ? !name.equals(function.name) : function.name != null) return false;
        if (returnType != null ? !returnType.equals(function.returnType) : function.returnType != null) return false;

        if(this.args.size()!= function.args.size()){return false;}

        for(int i = 0; i < args.size(); i++){
            if(!args.get(i).first.equals(function.args.get(i).first)){
                return false;
            }
        }

        return true;
    }

    @Override
    public int hashCode() {
        int result = returnType != null ? returnType.hashCode() : 0;
        result = 31 * result + (name != null ? name.hashCode() : 0);
        result = 31 * result + (args != null ? args.hashCode() : 0);
        return result;
    }

    @Override
    public DeclarationType getDeclType() {
        return DeclarationType.METHOD;
    }

    private String javadoc;

    public String getJavadoc() {
        return javadoc;
    }

    public void setJavadoc(String javadoc) {
        this.javadoc = javadoc;
    }

    @Override
    public boolean isStatic() {
        return isStatic;
    }

    public void setStatic(boolean isStatic) {
        this.isStatic = isStatic;
    }
}
