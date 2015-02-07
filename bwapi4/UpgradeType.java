package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class UpgradeType {

    public static UpgradeType Terran_Infantry_Armor;

    public static UpgradeType Terran_Vehicle_Plating;

    public static UpgradeType Terran_Ship_Plating;

    public static UpgradeType Zerg_Carapace;

    public static UpgradeType Zerg_Flyer_Carapace;

    public static UpgradeType Protoss_Ground_Armor;

    public static UpgradeType Protoss_Air_Armor;

    public static UpgradeType Terran_Infantry_Weapons;

    public static UpgradeType Terran_Vehicle_Weapons;

    public static UpgradeType Terran_Ship_Weapons;

    public static UpgradeType Zerg_Melee_Attacks;

    public static UpgradeType Zerg_Missile_Attacks;

    public static UpgradeType Zerg_Flyer_Attacks;

    public static UpgradeType Protoss_Ground_Weapons;

    public static UpgradeType Protoss_Air_Weapons;

    public static UpgradeType Protoss_Plasma_Shields;

    public static UpgradeType U_238_Shells;

    public static UpgradeType Ion_Thrusters;

    public static UpgradeType Titan_Reactor;

    public static UpgradeType Ocular_Implants;

    public static UpgradeType Moebius_Reactor;

    public static UpgradeType Apollo_Reactor;

    public static UpgradeType Colossus_Reactor;

    public static UpgradeType Ventral_Sacs;

    public static UpgradeType Antennae;

    public static UpgradeType Pneumatized_Carapace;

    public static UpgradeType Metabolic_Boost;

    public static UpgradeType Adrenal_Glands;

    public static UpgradeType Muscular_Augments;

    public static UpgradeType Grooved_Spines;

    public static UpgradeType Gamete_Meiosis;

    public static UpgradeType Metasynaptic_Node;

    public static UpgradeType Singularity_Charge;

    public static UpgradeType Leg_Enhancements;

    public static UpgradeType Scarab_Damage;

    public static UpgradeType Reaver_Capacity;

    public static UpgradeType Gravitic_Drive;

    public static UpgradeType Sensor_Array;

    public static UpgradeType Gravitic_Boosters;

    public static UpgradeType Khaydarin_Amulet;

    public static UpgradeType Apial_Sensors;

    public static UpgradeType Gravitic_Thrusters;

    public static UpgradeType Carrier_Capacity;

    public static UpgradeType Khaydarin_Core;

    public static UpgradeType Argus_Jewel;

    public static UpgradeType Argus_Talisman;

    public static UpgradeType Caduceus_Reactor;

    public static UpgradeType Chitinous_Plating;

    public static UpgradeType Anabolic_Synthesis;

    public static UpgradeType Charon_Boosters;

    public static UpgradeType Upgrade_60;

    public static UpgradeType None;

    public static UpgradeType Unknown;


    private static Map<Long, UpgradeType> instances = new HashMap<Long, UpgradeType>();

    private UpgradeType(long pointer) {
        this.pointer = pointer;
    }

    private static UpgradeType get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        UpgradeType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UpgradeType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
