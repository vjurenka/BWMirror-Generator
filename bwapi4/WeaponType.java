package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class WeaponType {

    public static WeaponType Gauss_Rifle;

    public static WeaponType Gauss_Rifle_Jim_Raynor;

    public static WeaponType C_10_Canister_Rifle;

    public static WeaponType C_10_Canister_Rifle_Sarah_Kerrigan;

    public static WeaponType C_10_Canister_Rifle_Samir_Duran;

    public static WeaponType C_10_Canister_Rifle_Infested_Duran;

    public static WeaponType C_10_Canister_Rifle_Alexei_Stukov;

    public static WeaponType Fragmentation_Grenade;

    public static WeaponType Fragmentation_Grenade_Jim_Raynor;

    public static WeaponType Spider_Mines;

    public static WeaponType Twin_Autocannons;

    public static WeaponType Twin_Autocannons_Alan_Schezar;

    public static WeaponType Hellfire_Missile_Pack;

    public static WeaponType Hellfire_Missile_Pack_Alan_Schezar;

    public static WeaponType Arclite_Cannon;

    public static WeaponType Arclite_Cannon_Edmund_Duke;

    public static WeaponType Fusion_Cutter;

    public static WeaponType Gemini_Missiles;

    public static WeaponType Gemini_Missiles_Tom_Kazansky;

    public static WeaponType Burst_Lasers;

    public static WeaponType Burst_Lasers_Tom_Kazansky;

    public static WeaponType ATS_Laser_Battery;

    public static WeaponType ATS_Laser_Battery_Hero;

    public static WeaponType ATS_Laser_Battery_Hyperion;

    public static WeaponType ATA_Laser_Battery;

    public static WeaponType ATA_Laser_Battery_Hero;

    public static WeaponType ATA_Laser_Battery_Hyperion;

    public static WeaponType Flame_Thrower;

    public static WeaponType Flame_Thrower_Gui_Montag;

    public static WeaponType Arclite_Shock_Cannon;

    public static WeaponType Arclite_Shock_Cannon_Edmund_Duke;

    public static WeaponType Longbolt_Missile;

    public static WeaponType Claws;

    public static WeaponType Claws_Devouring_One;

    public static WeaponType Claws_Infested_Kerrigan;

    public static WeaponType Needle_Spines;

    public static WeaponType Needle_Spines_Hunter_Killer;

    public static WeaponType Kaiser_Blades;

    public static WeaponType Kaiser_Blades_Torrasque;

    public static WeaponType Toxic_Spores;

    public static WeaponType Spines;

    public static WeaponType Acid_Spore;

    public static WeaponType Acid_Spore_Kukulza;

    public static WeaponType Glave_Wurm;

    public static WeaponType Glave_Wurm_Kukulza;

    public static WeaponType Seeker_Spores;

    public static WeaponType Subterranean_Tentacle;

    public static WeaponType Suicide_Infested_Terran;

    public static WeaponType Suicide_Scourge;

    public static WeaponType Particle_Beam;

    public static WeaponType Psi_Blades;

    public static WeaponType Psi_Blades_Fenix;

    public static WeaponType Phase_Disruptor;

    public static WeaponType Phase_Disruptor_Fenix;

    public static WeaponType Psi_Assault;

    public static WeaponType Psionic_Shockwave;

    public static WeaponType Psionic_Shockwave_TZ_Archon;

    public static WeaponType Dual_Photon_Blasters;

    public static WeaponType Dual_Photon_Blasters_Mojo;

    public static WeaponType Dual_Photon_Blasters_Artanis;

    public static WeaponType Anti_Matter_Missiles;

    public static WeaponType Anti_Matter_Missiles_Mojo;

    public static WeaponType Anti_Matter_Missiles_Artanis;

    public static WeaponType Phase_Disruptor_Cannon;

    public static WeaponType Phase_Disruptor_Cannon_Danimoth;

    public static WeaponType Pulse_Cannon;

    public static WeaponType STS_Photon_Cannon;

    public static WeaponType STA_Photon_Cannon;

    public static WeaponType Scarab;

    public static WeaponType Neutron_Flare;

    public static WeaponType Halo_Rockets;

    public static WeaponType Corrosive_Acid;

    public static WeaponType Subterranean_Spines;

    public static WeaponType Warp_Blades;

    public static WeaponType Warp_Blades_Hero;

    public static WeaponType Warp_Blades_Zeratul;

    public static WeaponType Independant_Laser_Battery;

    public static WeaponType Twin_Autocannons_Floor_Trap;

    public static WeaponType Hellfire_Missile_Pack_Wall_Trap;

    public static WeaponType Flame_Thrower_Wall_Trap;

    public static WeaponType Hellfire_Missile_Pack_Floor_Trap;

    public static WeaponType Yamato_Gun;

    public static WeaponType Nuclear_Strike;

    public static WeaponType Lockdown;

    public static WeaponType EMP_Shockwave;

    public static WeaponType Irradiate;

    public static WeaponType Parasite;

    public static WeaponType Spawn_Broodlings;

    public static WeaponType Ensnare;

    public static WeaponType Dark_Swarm;

    public static WeaponType Plague;

    public static WeaponType Consume;

    public static WeaponType Stasis_Field;

    public static WeaponType Psionic_Storm;

    public static WeaponType Disruption_Web;

    public static WeaponType Restoration;

    public static WeaponType Mind_Control;

    public static WeaponType Feedback;

    public static WeaponType Optical_Flare;

    public static WeaponType Maelstrom;

    public static WeaponType None;

    public static WeaponType Unknown;


    private static Map<Long, WeaponType> instances = new HashMap<Long, WeaponType>();

    private WeaponType(long pointer) {
        this.pointer = pointer;
    }

    private static WeaponType get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        WeaponType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new WeaponType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;


}
