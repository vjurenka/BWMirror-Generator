package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class UnitSizeType {

    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

    public static UnitSizeType Independent;

    public static UnitSizeType Small;

    public static UnitSizeType Medium;

    public static UnitSizeType Large;

    public static UnitSizeType None;

    public static UnitSizeType Unknown;


    private static Map<Long, UnitSizeType> instances = new HashMap<Long, UnitSizeType>();

    private UnitSizeType(long pointer) {
        this.pointer = pointer;
    }

    private static UnitSizeType get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        UnitSizeType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UnitSizeType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);


}
