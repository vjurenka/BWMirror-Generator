package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class TechType {

    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

    public Race getRace() {
        return getRace_native(pointer);
    }

    public int mineralPrice() {
        return mineralPrice_native(pointer);
    }

    public int gasPrice() {
        return gasPrice_native(pointer);
    }

    public int researchTime() {
        return researchTime_native(pointer);
    }

    public int energyUsed() {
        return energyUsed_native(pointer);
    }

    public UnitType whatResearches() {
        return whatResearches_native(pointer);
    }

    public WeaponType getWeapon() {
        return getWeapon_native(pointer);
    }

    public boolean targetsUnit() {
        return targetsUnit_native(pointer);
    }

    public boolean targetsPosition() {
        return targetsPosition_native(pointer);
    }

    public List<UnitType> whatUses() {
        return whatUses_native(pointer);
    }

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
        if (pointer == 0 ) {
            return null;
        }
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
