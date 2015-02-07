package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class PositionOrUnit {

    public boolean isUnit() {
        return isUnit_native(pointer);
    }

    public Unit getUnit() {
        return getUnit_native(pointer);
    }

    public boolean isPosition() {
        return isPosition_native(pointer);
    }

    public Position getPosition() {
        return getPosition_native(pointer);
    }


    private static Map<Long, PositionOrUnit> instances = new HashMap<Long, PositionOrUnit>();

    private PositionOrUnit(long pointer) {
        this.pointer = pointer;
    }

    private static PositionOrUnit get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        PositionOrUnit instance = instances.get(pointer);
        if (instance == null ) {
            instance = new PositionOrUnit(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native boolean isUnit_native(long pointer);

    private native Unit getUnit_native(long pointer);

    private native boolean isPosition_native(long pointer);

    private native Position getPosition_native(long pointer);


}
