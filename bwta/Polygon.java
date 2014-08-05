package bwta;

import bwta.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;
import bwapi.Position;
import bwapi.TilePosition;
import bwapi.Player;

/**
A Polygon is a geometric representation of <a href="Region.html">Region</a>

*/
public class Polygon {

/**
Returns the area of the polygon.

*/
    public double getArea() {
        return getArea_native(pointer);
    }

/**
Returns the perimeter of the polygon.

*/
    public double getPerimeter() {
        return getPerimeter_native(pointer);
    }

/**
Returns the centroid of the polygon.

*/
    public Position getCenter() {
        return getCenter_native(pointer);
    }

/**
Returns true if the given point is inside the polygon.

*/
    public boolean isInside(Position p) {
        return isInside_native(pointer, p);
    }

/**
Returns the point on the boundary of the polygon that is nearest to the given point.

*/
    public Position getNearestPoint(Position p) {
        return getNearestPoint_native(pointer, p);
    }


    private static Map<Long, Polygon> instances = new HashMap<Long, Polygon>();

    private Polygon(long pointer) {
        this.pointer = pointer;
    }

    private static Polygon get(long pointer) {
        Polygon instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Polygon(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native double getArea_native(long pointer);

    private native double getPerimeter_native(long pointer);

    private native Position getCenter_native(long pointer);

    private native boolean isInside_native(long pointer, Position p);

    private native Position getNearestPoint_native(long pointer, Position p);


}
