package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class Point {

    public boolean isValid() {
        return isValid_native(pointer);
    }

    public double getLength() {
        return getLength_native(pointer);
    }


    private static Map<Long, Point> instances = new HashMap<Long, Point>();

    private Point(long pointer) {
        this.pointer = pointer;
    }

    private static Point get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        Point instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Point(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native boolean isValid_native(long pointer);

    private native double getLength_native(long pointer);


}
