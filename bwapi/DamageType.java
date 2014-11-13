package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class DamageType {

    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

    public static DamageType Independent;

    public static DamageType Explosive;

    public static DamageType Concussive;

    public static DamageType Normal;

    public static DamageType Ignore_Armor;

    public static DamageType None;

    public static DamageType Unknown;


    private static Map<Long, DamageType> instances = new HashMap<Long, DamageType>();

    private DamageType(long pointer) {
        this.pointer = pointer;
    }

    private static DamageType get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        DamageType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new DamageType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);


}
