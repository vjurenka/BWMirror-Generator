package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class GameWrapper {

    public void flush() {
        flush_native(pointer);
    }


    private static Map<Long, GameWrapper> instances = new HashMap<Long, GameWrapper>();

    private GameWrapper(long pointer) {
        this.pointer = pointer;
    }

    private static GameWrapper get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        GameWrapper instance = instances.get(pointer);
        if (instance == null ) {
            instance = new GameWrapper(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native void flush_native(long pointer);


}
