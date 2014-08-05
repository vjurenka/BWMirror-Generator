package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
Each type of Unit in Starcraft: Broodwar has a particular <a href="WeaponType.html">WeaponType</a> for its ground weapon and air weapon (either of which could be <a href="WeaponType.html">WeaponTypes</a>::None). Each type of Weapon has a particular damage type, which could be explosive, concussive, or something else. Here is the list of all the possible <a href="DamageType.html">DamageTypes</a>.


*/
public class DamageType {

	/** Returns the name of this damage type. For example DamageTypes::Explosive.getName() will return
	* std::string("Explosive"). */
    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

    public static DamageType Independent;

    public static DamageType Explosive;

    public static DamageType Concussive;

    public static DamageType Normal;

    public static DamageType Ignore_Armor;

    public static DamageType None;

    public static DamageType Unknown;


    private static Map<Long, DamageType> instances = new HashMap<Long, DamageType>();

    private DamageType(long pointer) {
        this.pointer = pointer;
    }

    private static DamageType get(long pointer) {
        DamageType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new DamageType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);


}
