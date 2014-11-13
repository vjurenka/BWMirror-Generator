package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class UnitCommand {

    public UnitCommandType getType() {
        return getType_native(pointer);
    }


    private static Map<Long, UnitCommand> instances = new HashMap<Long, UnitCommand>();

    private UnitCommand(long pointer) {
        this.pointer = pointer;
    }

    private static UnitCommand get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        UnitCommand instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UnitCommand(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native UnitCommandType getType_native(long pointer);


}
