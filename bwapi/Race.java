package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class Race {

    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

    public UnitType getWorker() {
        return getWorker_native(pointer);
    }

    public UnitType getCenter() {
        return getCenter_native(pointer);
    }

    public UnitType getRefinery() {
        return getRefinery_native(pointer);
    }

    public UnitType getTransport() {
        return getTransport_native(pointer);
    }

    public UnitType getSupplyProvider() {
        return getSupplyProvider_native(pointer);
    }

    public static Race Zerg;

    public static Race Terran;

    public static Race Protoss;

    public static Race Random;

    public static Race Other;

    public static Race None;

    public static Race Unknown;


    private static Map<Long, Race> instances = new HashMap<Long, Race>();

    private Race(long pointer) {
        this.pointer = pointer;
    }

    private static Race get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        Race instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Race(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);

    private native UnitType getWorker_native(long pointer);

    private native UnitType getCenter_native(long pointer);

    private native UnitType getRefinery_native(long pointer);

    private native UnitType getTransport_native(long pointer);

    private native UnitType getSupplyProvider_native(long pointer);


}
