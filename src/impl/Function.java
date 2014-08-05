package impl;

import c.DeclarationType;
import c.Method;
import c.Param;

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

    @Override
    public List<Param> getParams() {
        return args;
    }

    @Override
    public Method clone() {
        Function f = new Function();
        f.name = name;
        f.returnType = returnType;
        f.args.addAll(args);
        return f;
    }

    @Override
    public String getType() {
        return returnType;
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
}
