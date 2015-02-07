package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class Race {

    public static Race Zerg;

    public static Race Terran;

    public static Race Protoss;

    public static Race Random;

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


}
