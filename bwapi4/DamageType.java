package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class DamageType {


    private static Map<Long, DamageType> instances = new HashMap<Long, DamageType>();

    private DamageType(long pointer) {
        this.pointer = pointer;
    }

    private static DamageType get(long pointer) {
        DamageType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new DamageType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
