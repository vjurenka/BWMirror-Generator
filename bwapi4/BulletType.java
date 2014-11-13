package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class BulletType {


    private static Map<Long, BulletType> instances = new HashMap<Long, BulletType>();

    private BulletType(long pointer) {
        this.pointer = pointer;
    }

    private static BulletType get(long pointer) {
        BulletType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new BulletType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
