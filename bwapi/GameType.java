package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
List of all <a href="GameType.html">GameTypes</a>.


*/
public class GameType {

	/** Returns the name of the game type. For example GameTypes::Melee.getName() will return an
	* std::string object containing "Melee". */
    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

    public static GameType Melee;

    public static GameType Free_For_All;

    public static GameType One_on_One;

    public static GameType Capture_The_Flag;

    public static GameType Greed;

    public static GameType Slaughter;

    public static GameType Sudden_Death;

    public static GameType Ladder;

    public static GameType Use_Map_Settings;

    public static GameType Team_Melee;

    public static GameType Team_Free_For_All;

    public static GameType Team_Capture_The_Flag;

    public static GameType Top_vs_Bottom;

    public static GameType Pro_Gamer_League;

    public static GameType None;

    public static GameType Unknown;


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

    private native String c_str_native(long pointer);


}
