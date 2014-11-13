package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class Regionset {

    public Position getCenter() {
        return getCenter_native(pointer);
    }

    public Unitset getUnits(UnitFilter pred) {
        return getUnits_native(pointer, pred);
    }


    private static Map<Long, Regionset> instances = new HashMap<Long, Regionset>();

    private Regionset(long pointer) {
        this.pointer = pointer;
    }

    private static Regionset get(long pointer) {
        Regionset instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Regionset(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native Position getCenter_native(long pointer);

    private native Unitset getUnits_native(long pointer, UnitFilter pred);


}
