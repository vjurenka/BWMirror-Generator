package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class Color {

    public int red() {
        return red_native(pointer);
    }

    public int green() {
        return green_native(pointer);
    }

    public int blue() {
        return blue_native(pointer);
    }

    public static Color Red;

    public static Color Blue;

    public static Color Teal;

    public static Color Purple;

    public static Color Orange;

    public static Color Brown;

    public static Color White;

    public static Color Yellow;

    public static Color Green;

    public static Color Cyan;

    public static Color Black;

    public static Color Grey;


    private static Map<Long, Color> instances = new HashMap<Long, Color>();

    private Color(long pointer) {
        this.pointer = pointer;
    }

    private static Color get(long pointer) {
        Color instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Color(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native int red_native(long pointer);

    private native int green_native(long pointer);

    private native int blue_native(long pointer);


}
