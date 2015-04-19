package inject;

import api.DefaultEventListener;
import c.CClass;
import c.CDeclaration;
import c.Param;
import generator.PackageProcessOptions;
import impl.Function;

import java.util.ArrayList;

public class GetPolygonPointsInjector extends DefaultEventListener {


    @Override
    public void onCDeclarationRead(PackageProcessOptions packageProcessOptions, CDeclaration cDeclaration) {
        if (cDeclaration.getName().equals("Polygon") && packageProcessOptions.packageName.equals("bwta")) {
            CClass cClass = (CClass) cDeclaration;

            Function getPolygons = new Function("getPoints", "set<Position>", false, new ArrayList<Param>());
            cClass.getFields().add(getPolygons);
        }
    }
}