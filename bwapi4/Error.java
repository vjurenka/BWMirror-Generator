package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class Error {


    private static Map<Long, Error> instances = new HashMap<Long, Error>();

    private Error(long pointer) {
        this.pointer = pointer;
    }

    private static Error get(long pointer) {
        Error instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Error(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
