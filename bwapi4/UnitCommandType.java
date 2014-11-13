package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class UnitCommandType {


    private static Map<Long, UnitCommandType> instances = new HashMap<Long, UnitCommandType>();

    private UnitCommandType(long pointer) {
        this.pointer = pointer;
    }

    private static UnitCommandType get(long pointer) {
        UnitCommandType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UnitCommandType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
