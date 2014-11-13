package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class Order {


    private static Map<Long, Order> instances = new HashMap<Long, Order>();

    private Order(long pointer) {
        this.pointer = pointer;
    }

    private static Order get(long pointer) {
        Order instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Order(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
