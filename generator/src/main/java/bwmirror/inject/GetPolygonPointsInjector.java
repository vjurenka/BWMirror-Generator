package bwmirror.inject;

import bwmirror.api.DefaultEventListener;
import bwmirror.c.CClass;
import bwmirror.c.CDeclaration;
import bwmirror.c.Param;
import bwmirror.generator.PackageProcessOptions;
import bwmirror.impl.Function;

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