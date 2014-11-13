package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class ExplosionType {


    private static Map<Long, ExplosionType> instances = new HashMap<Long, ExplosionType>();

    private ExplosionType(long pointer) {
        this.pointer = pointer;
    }

    private static ExplosionType get(long pointer) {
        ExplosionType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new ExplosionType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
