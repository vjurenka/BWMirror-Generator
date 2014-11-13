package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class WeaponType {


    private static Map<Long, WeaponType> instances = new HashMap<Long, WeaponType>();

    private WeaponType(long pointer) {
        this.pointer = pointer;
    }

    private static WeaponType get(long pointer) {
        WeaponType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new WeaponType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
