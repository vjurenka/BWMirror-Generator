package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class PlayerType {

    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

    public static PlayerType None;

    public static PlayerType Computer;

    public static PlayerType Player;

    public static PlayerType RescuePassive;

    public static PlayerType EitherPreferComputer;

    public static PlayerType EitherPreferHuman;

    public static PlayerType Neutral;

    public static PlayerType Closed;

    public static PlayerType PlayerLeft;

    public static PlayerType ComputerLeft;

    public static PlayerType Unknown;


    private static Map<Long, PlayerType> instances = new HashMap<Long, PlayerType>();

    private PlayerType(long pointer) {
        this.pointer = pointer;
    }

    private static PlayerType get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        PlayerType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new PlayerType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);


}
