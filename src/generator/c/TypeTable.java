package generator.c;

import c.CClass;
import c.CDeclaration;
import c.DeclarationType;
import c.Field;
import generator.CJavaPipeline;
import util.PointerTest;

import java.io.PrintStream;
import java.util.List;

/**
 * User: PC
 * Date: 19. 6. 2014
 * Time: 15:06
 */
public class TypeTable {

    private PrintStream out;

    public void setOut(PrintStream out) {
        this.out = out;
    }

    public void implementTypeTable(List<CDeclaration> declarationList){
        for (CDeclaration cDeclaration : declarationList) {
            if (cDeclaration.getDeclType().equals(DeclarationType.CLASS)) {
                checkTypeTable((CClass) cDeclaration);
            }
        }
        out.println();
    }

    private void checkTypeTable(CClass cClass) {
        if(cClass.getName().equals("Position") || cClass.getName().equals("TilePosition") || cClass.getName().equals("WalkPosition") || cClass.getName().equals("Point")){
            return;
        }
        for (Field field : cClass.getFields()) {
            if (field.getDeclType().equals(DeclarationType.VARIABLE)) {
                implementTypeTable(cClass.getName());
                break;
            }
        }
    }

    public void implementTypeTable(String type) {
        out.println("std::map<int, const " + type + " *> table" + type + ";");
    }

}
