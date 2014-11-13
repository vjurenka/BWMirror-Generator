package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class TechType {


    private static Map<Long, TechType> instances = new HashMap<Long, TechType>();

    private TechType(long pointer) {
        this.pointer = pointer;
    }

    private static TechType get(long pointer) {
        TechType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new TechType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
