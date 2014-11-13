package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class UnitType {


    private static Map<Long, UnitType> instances = new HashMap<Long, UnitType>();

    private UnitType(long pointer) {
        this.pointer = pointer;
    }

    private static UnitType get(long pointer) {
        UnitType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UnitType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
