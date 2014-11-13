package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class UpgradeType {


    private static Map<Long, UpgradeType> instances = new HashMap<Long, UpgradeType>();

    private UpgradeType(long pointer) {
        this.pointer = pointer;
    }

    private static UpgradeType get(long pointer) {
        UpgradeType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UpgradeType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
