package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class InterfaceEvent {

    public boolean isFinished() {
        return isFinished_native(pointer);
    }

    public void removeEvent() {
        removeEvent_native(pointer);
    }


    private static Map<Long, InterfaceEvent> instances = new HashMap<Long, InterfaceEvent>();

    private InterfaceEvent(long pointer) {
        this.pointer = pointer;
    }

    private static InterfaceEvent get(long pointer) {
        InterfaceEvent instance = instances.get(pointer);
        if (instance == null ) {
            instance = new InterfaceEvent(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native boolean isFinished_native(long pointer);

    private native void removeEvent_native(long pointer);


}
