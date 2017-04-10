package bwmirror.generator;

import bwmirror.c.CClass;
import bwmirror.c.CEnum;
import bwmirror.generator.java.ClassMirror;
import bwmirror.generator.java.EnumMirror;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 10:57
 */
public class Generator {

    private List<CClass> classes = new ArrayList<>();
    private List<CEnum> enums = new ArrayList<>();

    private MirrorContext context;

    private HashMap<String,String> javaSuperClasses = new HashMap<>();

    public Generator(MirrorContext context) {
        this.context = context;
    }

    public void addClass(CClass cclass){
        classes.add(cclass);
    }

    public void addEnum(CEnum cenum){
        enums.add(cenum);
    }

    public void setJavaSuperClasses(HashMap<String, String> javaSuperClasses) {
        this.javaSuperClasses = javaSuperClasses;
    }

    public void run(File javaRoot){
        context.prepareWrite(javaRoot);
        for(CClass cclass : classes){
            processClass(javaRoot, cclass);
        }
        for(CEnum cenum : enums){
            processEnum(javaRoot, cenum);
        }
    }

    public void flush(){
        classes.clear();
        enums.clear();
    }

    protected void processClass(File root, CClass cClass){
        ClassMirror mirror = new ClassMirror(cClass);
        try {
            mirror.write(root, context, javaSuperClasses.get(cClass.getName()));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    protected void processEnum(File root, CEnum cenum){
        EnumMirror mirror = new EnumMirror(cenum);
        try {
            mirror.write(root, context);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
