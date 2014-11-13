package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class PlayerType {


    private static Map<Long, PlayerType> instances = new HashMap<Long, PlayerType>();

    private PlayerType(long pointer) {
        this.pointer = pointer;
    }

    private static PlayerType get(long pointer) {
        PlayerType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new PlayerType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
