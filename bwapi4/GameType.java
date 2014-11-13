package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class GameType {


    private static Map<Long, GameType> instances = new HashMap<Long, GameType>();

    private GameType(long pointer) {
        this.pointer = pointer;
    }

    private static GameType get(long pointer) {
        GameType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new GameType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
