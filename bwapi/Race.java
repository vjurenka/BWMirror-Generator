package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
List of all <a href="Race.html">Races</a>.


*/
public class Race {

	/** Returns the name of the race. For example Races::Terran.getName() will return a std::string object
	* containing "Terran". */
    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

	/** Returns the worker unit type for the given race. For example Races::Protoss.getWorker() will return
	* a pointer to UnitTypes::Protoss_Probe. */
    public UnitType getWorker() {
        return getWorker_native(pointer);
    }

	/** Returns the center unit type for the given race. For example Races::Terran.getCenter() will return a
	* pointer to UnitTypes::Terran_Command_Center. While there are three center types for Zerg
	* (Hatchery, Lair, and Hive), Races::Zerg.getCenter() will only return a pointer to
	* UnitTypes::Zerg_Hatchery, since it is the unit type needed to make a new center. */
    public UnitType getCenter() {
        return getCenter_native(pointer);
    }

	/** Returns the refinery unit type for the given race. For example: Races::Zerg.getRefinery() will
	* return a pointer to UnitTypes::Zerg_Extractor?. */
    public UnitType getRefinery() {
        return getRefinery_native(pointer);
    }

	/** Returns the transport unit type for the given race. For example: Races::Protoss.getTransport() will
	* return a pointer to UnitTypes::Protoss_Shuttle. */
    public UnitType getTransport() {
        return getTransport_native(pointer);
    }

	/** Returns the main supply provider unit type for the given race. For example:
	* Races::Terran.getSupplyProvider() will return a pointer to UnitTypes::Terran_Supply_Depot?. */
    public UnitType getSupplyProvider() {
        return getSupplyProvider_native(pointer);
    }

    public static Race Zerg;

    public static Race Terran;

    public static Race Protoss;

    public static Race Random;

    public static Race Other;

    public static Race None;

    public static Race Unknown;


    private static Map<Long, Race> instances = new HashMap<Long, Race>();

    private Race(long pointer) {
        this.pointer = pointer;
    }

    private static Race get(long pointer) {
        Race instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Race(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);

    private native UnitType getWorker_native(long pointer);

    private native UnitType getCenter_native(long pointer);

    private native UnitType getRefinery_native(long pointer);

    private native UnitType getTransport_native(long pointer);

    private native UnitType getSupplyProvider_native(long pointer);


}
