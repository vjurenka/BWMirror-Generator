package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
List of all <a href="TechType.html">TechTypes</a>.


*/
public class TechType {

	/** Returns the name of the tech type. */
    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

	/** Returns the race that uses the TechType. For example, TechTypes::Scanner_Sweep?.getRace() will
	* return Races::Terran. */
    public Race getRace() {
        return getRace_native(pointer);
    }

	/** Returns the mineral cost of the tech type. */
    public int mineralPrice() {
        return mineralPrice_native(pointer);
    }

	/** Returns the vespene gas price of the tech type. */
    public int gasPrice() {
        return gasPrice_native(pointer);
    }

	/** Returns the number of frames needed to research the tech type. */
    public int researchTime() {
        return researchTime_native(pointer);
    }

	/** Returns the amount of energy used each time this tech type is used. */
    public int energyUsed() {
        return energyUsed_native(pointer);
    }

	/** Returns the type of unit that researches this tech type. If this tech type is available for free
	* (does not need to be researched), then this method will return UnitTypes::None. */
    public UnitType whatResearches() {
        return whatResearches_native(pointer);
    }

	/** Returns the corresponding weapon for this tech type, or TechTypes::None if no corresponding weapon
	* exists. For example, TechTypes::Dark_Swarm.getWeapon() will return a pointer to
	* WeaponTypes::Dark_Swarm. */
    public WeaponType getWeapon() {
        return getWeapon_native(pointer);
    }

	/** Returns true if this tech type must be used on another unit (i.e. Irradiate) */
    public boolean targetsUnit() {
        return targetsUnit_native(pointer);
    }

	/** Returns true if this tech type must be specified a position (i.e. Dark Swarm) */
    public boolean targetsPosition() {
        return targetsPosition_native(pointer);
    }

	/** Returns the set of units that can use this tech type. Usually this will just be a set of one unit
	* type, however in some cases, such as TechTypes::Burrowing, several unit types will be returned. */
    public List<UnitType> whatUses() {
        return whatUses_native(pointer);
    }

	/** Returns the order used to execute this tech type as an action. */
    public Order getOrder() {
        return getOrder_native(pointer);
    }

    public static TechType Stim_Packs;

    public static TechType Lockdown;

    public static TechType EMP_Shockwave;

    public static TechType Spider_Mines;

    public static TechType Scanner_Sweep;

    public static TechType Tank_Siege_Mode;

    public static TechType Defensive_Matrix;

    public static TechType Irradiate;

    public static TechType Yamato_Gun;

    public static TechType Cloaking_Field;

    public static TechType Personnel_Cloaking;

    public static TechType Burrowing;

    public static TechType Infestation;

    public static TechType Spawn_Broodlings;

    public static TechType Dark_Swarm;

    public static TechType Plague;

    public static TechType Consume;

    public static TechType Ensnare;

    public static TechType Parasite;

    public static TechType Psionic_Storm;

    public static TechType Hallucination;

    public static TechType Recall;

    public static TechType Stasis_Field;

    public static TechType Archon_Warp;

    public static TechType Restoration;

    public static TechType Disruption_Web;

    public static TechType Mind_Control;

    public static TechType Dark_Archon_Meld;

    public static TechType Feedback;

    public static TechType Optical_Flare;

    public static TechType Maelstrom;

    public static TechType Lurker_Aspect;

    public static TechType Healing;

    public static TechType None;

    public static TechType Unknown;

    public static TechType Nuclear_Strike;


    private static Map<Long, TechType> instances = new HashMap<Long, TechType>();

    private TechType(long pointer) {
        this.pointer = pointer;
    }

    private static TechType get(long pointer) {
        TechType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new TechType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);

    private native Race getRace_native(long pointer);

    private native int mineralPrice_native(long pointer);

    private native int gasPrice_native(long pointer);

    private native int researchTime_native(long pointer);

    private native int energyUsed_native(long pointer);

    private native UnitType whatResearches_native(long pointer);

    private native WeaponType getWeapon_native(long pointer);

    private native boolean targetsUnit_native(long pointer);

    private native boolean targetsPosition_native(long pointer);

    private native List<UnitType> whatUses_native(long pointer);

    private native Order getOrder_native(long pointer);


}
