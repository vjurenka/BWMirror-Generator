package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class TechType {

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

    public static TechType Nuclear_Strike;

    public static TechType Unknown;


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


}
