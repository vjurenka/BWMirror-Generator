package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
Each type of Unit in Starcraft: Broodwar has a particular <a href="WeaponType.html">WeaponType</a> for its ground weapon and air weapon (either of which could be <a href="WeaponType.html">WeaponTypes</a>::None). Each type of Weapon has a particular explosion type. Here is the list of all the possible <a href="ExplosionType.html">ExplosionTypes</a>.


*/
public class ExplosionType {

	/** Returns the name of this explosion type. */
    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

    public static ExplosionType None;

    public static ExplosionType Normal;

    public static ExplosionType Radial_Splash;

    public static ExplosionType Enemy_Splash;

    public static ExplosionType Lockdown;

    public static ExplosionType Nuclear_Missile;

    public static ExplosionType Parasite;

    public static ExplosionType Broodlings;

    public static ExplosionType EMP_Shockwave;

    public static ExplosionType Irradiate;

    public static ExplosionType Ensnare;

    public static ExplosionType Plague;

    public static ExplosionType Stasis_Field;

    public static ExplosionType Dark_Swarm;

    public static ExplosionType Consume;

    public static ExplosionType Yamato_Gun;

    public static ExplosionType Restoration;

    public static ExplosionType Disruption_Web;

    public static ExplosionType Corrosive_Acid;

    public static ExplosionType Mind_Control;

    public static ExplosionType Feedback;

    public static ExplosionType Optical_Flare;

    public static ExplosionType Maelstrom;

    public static ExplosionType Air_Splash;

    public static ExplosionType Unknown;


    private static Map<Long, ExplosionType> instances = new HashMap<Long, ExplosionType>();

    private ExplosionType(long pointer) {
        this.pointer = pointer;
    }

    private static ExplosionType get(long pointer) {
        ExplosionType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new ExplosionType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);


}
