package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class UnitSizeType {


    private static Map<Long, UnitSizeType> instances = new HashMap<Long, UnitSizeType>();

    private UnitSizeType(long pointer) {
        this.pointer = pointer;
    }

    private static UnitSizeType get(long pointer) {
        UnitSizeType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UnitSizeType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
