package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

	/** The UnitType class is used to get information about a particular type of unit, such as the build time
	* of a Lurker, or the mineral price of an Ultralisk. TODO Add the unittype table from the wiki*/
public class UnitType {

	/** Returns the name of the unit. */
    public String c_str() {
        return c_str_native(pointer);
    }

    public String toString(){
        return c_str();
    }

	/** Returns the race that the unit belongs to. For example UnitTypes::Terran_SCV.getRace() will return
	* Races::Terran. */
    public Race getRace() {
        return getRace_native(pointer);
    }

	/** Returns what builds this unit type. The second number will usually be 1 unless the unit type is
	* Protoss_Archon or Protoss_Dark_Archon. Units that cannot be created, such as critters and mineral
	* fields, will return a pair where the unit type is UnitTypes::None, and the second component is 0.
	*<br/><br/>
	* Example: UnitTypes::Terran_Marine.whatBuilds() will return an std::pair, where the first component
	* is UnitTypes::Terran_Barracks. */
    public TechType requiredTech() {
        return requiredTech_native(pointer);
    }

	/** Returns the tech used to cloak the unit, or TechTypes::None if the unit cannot cloak or is
	permanently cloaked */
    public TechType cloakingTech() {
        return cloakingTech_native(pointer);
    }

	/** Returns the set of tech types this unit can use, provided the tech types have been researched and
	* the unit has enough energy. */
    public List<TechType> abilities() {
        return abilities_native(pointer);
    }

	/** Returns the set of upgrade types that can affect this unit. */
    public List<UpgradeType> upgrades() {
        return upgrades_native(pointer);
    }

	/** Returns the upgrade that increase's the unit's armor, or UpgradeTypes::None if no upgrade
	* increase's this unit's armor. For example UnitTypes::Terran_Marine.armorUpgrade() will return a
	* pointer to UpgradeTypes::Terran_Infantry_Armor. */
    public UpgradeType armorUpgrade() {
        return armorUpgrade_native(pointer);
    }

	/** Returns the maximum amount of hit points the unit type can have. */
    public int maxHitPoints() {
        return maxHitPoints_native(pointer);
    }

	/** Returns the maximum amount of shields the unit type can have. */
    public int maxShields() {
        return maxShields_native(pointer);
    }

	/** Returns the maximum amount of energy the unit type can have. */
    public int maxEnergy() {
        return maxEnergy_native(pointer);
    }

	/** Returns the amount of armor the non-upgraded unit type has. */
    public int armor() {
        return armor_native(pointer);
    }

	/** Returns the mineral price of the unit.
	*<br/><br/>
	* Example: UnitTypes::Siege_Tank_Tank_Mode.mineralPrice() returns 150. */
    public int mineralPrice() {
        return mineralPrice_native(pointer);
    }

	/** UnitTypes::Siege_Tank_Tank_Mode.gasPrice() returns 100. */
    public int gasPrice() {
        return gasPrice_native(pointer);
    }

	/** Returns the number of frames needed to make this unit type. */
    public int buildTime() {
        return buildTime_native(pointer);
    }

	/** Returns the amount of supply used by this unit. Supply counts returned by BWAPI are double what you
	*  would expect to see from playing the game. This is because zerglings take up 0.5 in-game supply. */
    public int supplyRequired() {
        return supplyRequired_native(pointer);
    }

	/** Returns the amount of supply produced by this unit (i.e. for a Protoss_Pylon). Supply counts
	* returned by BWAPI are double what you would expect to see from playing the game. This is because
	* zerglings take up 0.5 in-game supply. */
    public int supplyProvided() {
        return supplyProvided_native(pointer);
    }

	/** Returns the amount of space this unit type takes up inside a bunker or transport unit. */
    public int spaceRequired() {
        return spaceRequired_native(pointer);
    }

	/** Returns the amount of space this unit type provides. */
    public int spaceProvided() {
        return spaceProvided_native(pointer);
    }

	/** Returns the score which is used to determine the total scores in the after-game stats screen. */
    public int buildScore() {
        return buildScore_native(pointer);
    }

	/** Returns the score which is used to determine the total scores in the after-game stats screen. */
    public int destroyScore() {
        return destroyScore_native(pointer);
    }

	/** Returns the size of the unit - either Small, Medium, Large, or Independent. */
    public UnitSizeType size() {
        return size_native(pointer);
    }

	/** Returns the tile width of the unit. Useful for determining the size of buildings. For example
	* UnitTypes::Terran_Supply_Depot.tileWidth() will return 3. */
    public int tileWidth() {
        return tileWidth_native(pointer);
    }

	/** Returns the tile height of the unit. Useful for determining the size of buildings. For example
	* UnitTypes::Terran_Supply_Depot.tileHeight() will return 2. */
    public int tileHeight() {
        return tileHeight_native(pointer);
    }

	/** Distance from the center of the unit to the left edge of the unit, measured in pixels. */
    public int dimensionLeft() {
        return dimensionLeft_native(pointer);
    }

	/** Distance from the center of the unit to the top edge of the unit, measured in pixels. */
    public int dimensionUp() {
        return dimensionUp_native(pointer);
    }

	/** Distance from the center of the unit to the right edge of the unit, measured in pixels. */
    public int dimensionRight() {
        return dimensionRight_native(pointer);
    }

	/** Distance from the center of the unit to the bottom edge of the unit, measured in pixels. */
    public int dimensionDown() {
        return dimensionDown_native(pointer);
    }

	/** Returns the range at which the unit will start targeting enemy units, measured in pixels. */
    public int seekRange() {
        return seekRange_native(pointer);
    }

	/** Returns how far the un-upgraded unit type can see into the fog of war, measured in pixels. */
    public int sightRange() {
        return sightRange_native(pointer);
    }

	/** Returns the unit's ground weapon. */
    public WeaponType groundWeapon() {
        return groundWeapon_native(pointer);
    }

    public int maxGroundHits() {
        return maxGroundHits_native(pointer);
    }

	/** Returns the unit's air weapon. */
    public WeaponType airWeapon() {
        return airWeapon_native(pointer);
    }

    public int maxAirHits() {
        return maxAirHits_native(pointer);
    }

	/** Returns the unit's non-upgraded top speed in pixels per frame. For Terran buildings that can lift
	* off and the Zerg Infested Command Center, this returns how fast the building moves when it is
	* lifted. */
    public double topSpeed() {
        return topSpeed_native(pointer);
    }

	/** Returns how fast the unit can accelerate to its top speed. What units this quantity is measured in
	* is currently unknown. */
    public int acceleration() {
        return acceleration_native(pointer);
    }

	/** Related to how fast the unit can halt. What units this quantity is measured in is currently
	* unknown. */
    public int haltDistance() {
        return haltDistance_native(pointer);
    }

	/** Related to how fast the unit can turn. What units this quantity is measured in is currently
	* unknown. */
    public int turnRadius() {
        return turnRadius_native(pointer);
    }

	/** Returns true if the unit can train other units. For example, UnitTypes::Terran_Barracks.canProduce()
	* will return true, while UnitTypes::Terran_Marine?.canProduce() will return false. This is also true
	* for two non-building units: Protoss Carrier (can produce interceptors) and Protoss Reaver
	* (can produce scarabs). */
    public boolean canProduce() {
        return canProduce_native(pointer);
    }

	/** Returns true if the unit can attack (either ground or air). Returns false for units that can only
	* inflict damage via special abilities (such as Protoss High Templar). */
    public boolean canAttack() {
        return canAttack_native(pointer);
    }

	/** Returns true if the unit can move. Note that buildings will return false, even Terran buildings
	* which can move once lifted. */
    public boolean canMove() {
        return canMove_native(pointer);
    }

	/** Returns true for flying/air units. */
    public boolean isFlyer() {
        return isFlyer_native(pointer);
    }

	/** Returns true for units that regenerate health (i.e. zerg units). */
    public boolean regeneratesHP() {
        return regeneratesHP_native(pointer);
    }

	/** Returns true if the unit type is capable of casting spells / using technology. */
    public boolean isSpellcaster() {
        return isSpellcaster_native(pointer);
    }

	/** Returns true for the two units that are permanently cloaked - Protoss Observer and Protoss Dark
	* Templar. */
    public boolean hasPermanentCloak() {
        return hasPermanentCloak_native(pointer);
    }

	/** Returns true for units that cannot be destroyed (i.e. Terran Nuclear Missile, Mineral Field,
	* Vespene Geyser, etc) */
    public boolean isInvincible() {
        return isInvincible_native(pointer);
    }

	/** Returns true if the unit is organic, such as a Terran Marine. */
    public boolean isOrganic() {
        return isOrganic_native(pointer);
    }

	/** Returns true if the unit is mechanical such as a Terran Vulture. */
    public boolean isMechanical() {
        return isMechanical_native(pointer);
    }

	/** Returns true for the four robotic Protoss units - Probe, Shuttle, Reaver, and Observer. */
    public boolean isRobotic() {
        return isRobotic_native(pointer);
    }

	/** Returns true for the seven units that can detect cloaked units - Terran Science Vessel, Spell
	* Scanner Sweep, Zerg Overlord, Protoss Observer, Terran Missile Turret, Zerg Spore Colony, and Protoss
	* Photon Cannon. */
    public boolean isDetector() {
        return isDetector_native(pointer);
    }

	/** Returns true for the five units that hold resources - Mineral Field, Vespene Geyser,
	* Terran Refinery, Zerg Extractor, and Protoss Assimilator. */
    public boolean isResourceContainer() {
        return isResourceContainer_native(pointer);
    }

	/** Returns true for the five units that can accept resources - Terran Command Center, Protoss Nexus,
	* Zerg Hatchery, Zerg Lair, and Zerg Hive. */
    public boolean isResourceDepot() {
        return isResourceDepot_native(pointer);
    }

	/** Returns true for Terran Refinery, Zerg Extractor, and Protoss Assimilator. */
    public boolean isRefinery() {
        return isRefinery_native(pointer);
    }

	/** Returns true for Protoss Probe, Terran SCV, and Zerg Drone. */
    public boolean isWorker() {
        return isWorker_native(pointer);
    }

	/** Returns true for buildings that must be near a pylon to be constructed. */
    public boolean requiresPsi() {
        return requiresPsi_native(pointer);
    }

	/** Returns true for buildings that can only be built on zerg creep. */
    public boolean requiresCreep() {
        return requiresCreep_native(pointer);
    }

	/** Returns true for Zergling and Scourge. */
    public boolean isTwoUnitsInOneEgg() {
        return isTwoUnitsInOneEgg_native(pointer);
    }

	/** Returns true for Zerg Lurker and units that can burrow when burrow tech is researched. */
    public boolean isBurrowable() {
        return isBurrowable_native(pointer);
    }

	/** Returns true for units that can be cloaked - Terran Ghost and Terran Wraith. Does not include units
	* which have permanent cloak (Protoss Observer and Protoss Dark Templar). */
    public boolean isCloakable() {
        return isCloakable_native(pointer);
    }

	/** Returns true if the unit is a building (also true for mineral field and vespene geyser). */
    public boolean isBuilding() {
        return isBuilding_native(pointer);
    }

	/** Returns true if the unit is an add-on, such as a Terran Comsat Station. */
    public boolean isAddon() {
        return isAddon_native(pointer);
    }

	/** Returns true for Terran buildings that can lift off (i.e. Barracks). */
    public boolean isFlyingBuilding() {
        return isFlyingBuilding_native(pointer);
    }

	/** Returns true if the unit is neutral, such as a critter or mineral field. */
    public boolean isNeutral() {
        return isNeutral_native(pointer);
    }

	/** Returns true if the unit is a Hero unit. */
    public boolean isHero() {
        return isHero_native(pointer);
    }

	/** Returns true if the unit is a Powerup unit. */
    public boolean isPowerup() {
        return isPowerup_native(pointer);
    }

	/** Returns true if the unit is a regular Beacon. */
    public boolean isBeacon() {
        return isBeacon_native(pointer);
    }

	/** Returns true if the unit is a flag Beacon. */
    public boolean isFlagBeacon() {
        return isFlagBeacon_native(pointer);
    }

	/** Returns true if the unit is a special building. */
    public boolean isSpecialBuilding() {
        return isSpecialBuilding_native(pointer);
    }

	/** Returns true if the unit is a spell unit. */
    public boolean isSpell() {
        return isSpell_native(pointer);
    }

	/** Returns true if the unit produces larva. */
    public boolean producesLarva() {
        return producesLarva_native(pointer);
    }

	/** Returns true if the unit is one of the three mineral field types. */
    public boolean isMineralField() {
        return isMineralField_native(pointer);
    }

	/** Returns true if the unit is capable of constructing an addon.
	This consists of Command Center, Factory, Starport, and Science Facility. */
    public boolean canBuildAddon() {
        return canBuildAddon_native(pointer);
    }

    public static UnitType Terran_Marine;

    public static UnitType Hero_Jim_Raynor_Marine;

    public static UnitType Terran_Ghost;

    public static UnitType Hero_Sarah_Kerrigan;

    public static UnitType Hero_Samir_Duran;

    public static UnitType Hero_Infested_Duran;

    public static UnitType Hero_Alexei_Stukov;

    public static UnitType Terran_Vulture;

    public static UnitType Hero_Jim_Raynor_Vulture;

    public static UnitType Terran_Goliath;

    public static UnitType Hero_Alan_Schezar;

    public static UnitType Terran_Siege_Tank_Tank_Mode;

    public static UnitType Hero_Edmund_Duke_Tank_Mode;

    public static UnitType Terran_SCV;

    public static UnitType Terran_Wraith;

    public static UnitType Hero_Tom_Kazansky;

    public static UnitType Terran_Science_Vessel;

    public static UnitType Hero_Magellan;

    public static UnitType Terran_Dropship;

    public static UnitType Terran_Battlecruiser;

    public static UnitType Hero_Arcturus_Mengsk;

    public static UnitType Hero_Hyperion;

    public static UnitType Hero_Norad_II;

    public static UnitType Hero_Gerard_DuGalle;

    public static UnitType Terran_Vulture_Spider_Mine;

    public static UnitType Terran_Nuclear_Missile;

    public static UnitType Terran_Siege_Tank_Siege_Mode;

    public static UnitType Hero_Edmund_Duke_Siege_Mode;

    public static UnitType Terran_Firebat;

    public static UnitType Hero_Gui_Montag;

    public static UnitType Spell_Scanner_Sweep;

    public static UnitType Terran_Medic;

    public static UnitType Terran_Civilian;

    public static UnitType Zerg_Larva;

    public static UnitType Zerg_Egg;

    public static UnitType Zerg_Zergling;

    public static UnitType Hero_Devouring_One;

    public static UnitType Hero_Infested_Kerrigan;

    public static UnitType Zerg_Hydralisk;

    public static UnitType Hero_Hunter_Killer;

    public static UnitType Zerg_Ultralisk;

    public static UnitType Hero_Torrasque;

    public static UnitType Zerg_Broodling;

    public static UnitType Zerg_Drone;

    public static UnitType Zerg_Overlord;

    public static UnitType Hero_Yggdrasill;

    public static UnitType Zerg_Mutalisk;

    public static UnitType Hero_Kukulza_Mutalisk;

    public static UnitType Zerg_Guardian;

    public static UnitType Hero_Kukulza_Guardian;

    public static UnitType Zerg_Queen;

    public static UnitType Hero_Matriarch;

    public static UnitType Zerg_Defiler;

    public static UnitType Hero_Unclean_One;

    public static UnitType Zerg_Scourge;

    public static UnitType Zerg_Infested_Terran;

    public static UnitType Terran_Valkyrie;

    public static UnitType Zerg_Cocoon;

    public static UnitType Protoss_Corsair;

    public static UnitType Hero_Raszagal;

    public static UnitType Protoss_Dark_Templar;

    public static UnitType Hero_Dark_Templar;

    public static UnitType Hero_Zeratul;

    public static UnitType Zerg_Devourer;

    public static UnitType Protoss_Dark_Archon;

    public static UnitType Protoss_Probe;

    public static UnitType Protoss_Zealot;

    public static UnitType Hero_Fenix_Zealot;

    public static UnitType Protoss_Dragoon;

    public static UnitType Hero_Fenix_Dragoon;

    public static UnitType Protoss_High_Templar;

    public static UnitType Hero_Tassadar;

    public static UnitType Hero_Aldaris;

    public static UnitType Protoss_Archon;

    public static UnitType Hero_Tassadar_Zeratul_Archon;

    public static UnitType Protoss_Shuttle;

    public static UnitType Protoss_Scout;

    public static UnitType Hero_Mojo;

    public static UnitType Hero_Artanis;

    public static UnitType Protoss_Arbiter;

    public static UnitType Hero_Danimoth;

    public static UnitType Protoss_Carrier;

    public static UnitType Hero_Gantrithor;

    public static UnitType Protoss_Interceptor;

    public static UnitType Protoss_Reaver;

    public static UnitType Hero_Warbringer;

    public static UnitType Protoss_Observer;

    public static UnitType Protoss_Scarab;

    public static UnitType Critter_Rhynadon;

    public static UnitType Critter_Bengalaas;

    public static UnitType Special_Cargo_Ship;

    public static UnitType Special_Mercenary_Gunship;

    public static UnitType Critter_Scantid;

    public static UnitType Critter_Kakaru;

    public static UnitType Critter_Ragnasaur;

    public static UnitType Critter_Ursadon;

    public static UnitType Zerg_Lurker_Egg;

    public static UnitType Zerg_Lurker;

    public static UnitType Spell_Disruption_Web;

    public static UnitType Terran_Command_Center;

    public static UnitType Terran_Comsat_Station;

    public static UnitType Terran_Nuclear_Silo;

    public static UnitType Terran_Supply_Depot;

    public static UnitType Terran_Refinery;

    public static UnitType Terran_Barracks;

    public static UnitType Terran_Academy;

    public static UnitType Terran_Factory;

    public static UnitType Terran_Starport;

    public static UnitType Terran_Control_Tower;

    public static UnitType Terran_Science_Facility;

    public static UnitType Terran_Covert_Ops;

    public static UnitType Terran_Physics_Lab;

    public static UnitType Terran_Machine_Shop;

    public static UnitType Terran_Engineering_Bay;

    public static UnitType Terran_Armory;

    public static UnitType Terran_Missile_Turret;

    public static UnitType Terran_Bunker;

    public static UnitType Special_Crashed_Norad_II;

    public static UnitType Special_Ion_Cannon;

    public static UnitType Zerg_Infested_Command_Center;

    public static UnitType Zerg_Hatchery;

    public static UnitType Zerg_Lair;

    public static UnitType Zerg_Hive;

    public static UnitType Zerg_Nydus_Canal;

    public static UnitType Zerg_Hydralisk_Den;

    public static UnitType Zerg_Defiler_Mound;

    public static UnitType Zerg_Greater_Spire;

    public static UnitType Zerg_Queens_Nest;

    public static UnitType Zerg_Evolution_Chamber;

    public static UnitType Zerg_Ultralisk_Cavern;

    public static UnitType Zerg_Spire;

    public static UnitType Zerg_Spawning_Pool;

    public static UnitType Zerg_Creep_Colony;

    public static UnitType Zerg_Spore_Colony;

    public static UnitType Zerg_Sunken_Colony;

    public static UnitType Special_Overmind_With_Shell;

    public static UnitType Special_Overmind;

    public static UnitType Zerg_Extractor;

    public static UnitType Special_Mature_Chrysalis;

    public static UnitType Special_Cerebrate;

    public static UnitType Special_Cerebrate_Daggoth;

    public static UnitType Protoss_Nexus;

    public static UnitType Protoss_Robotics_Facility;

    public static UnitType Protoss_Pylon;

    public static UnitType Protoss_Assimilator;

    public static UnitType Protoss_Observatory;

    public static UnitType Protoss_Gateway;

    public static UnitType Protoss_Photon_Cannon;

    public static UnitType Protoss_Citadel_of_Adun;

    public static UnitType Protoss_Cybernetics_Core;

    public static UnitType Protoss_Templar_Archives;

    public static UnitType Protoss_Forge;

    public static UnitType Protoss_Stargate;

    public static UnitType Special_Stasis_Cell_Prison;

    public static UnitType Protoss_Fleet_Beacon;

    public static UnitType Protoss_Arbiter_Tribunal;

    public static UnitType Protoss_Robotics_Support_Bay;

    public static UnitType Protoss_Shield_Battery;

    public static UnitType Special_Khaydarin_Crystal_Form;

    public static UnitType Special_Protoss_Temple;

    public static UnitType Special_XelNaga_Temple;

    public static UnitType Resource_Mineral_Field;

    public static UnitType Resource_Mineral_Field_Type_2;

    public static UnitType Resource_Mineral_Field_Type_3;

    public static UnitType Special_Independant_Starport;

    public static UnitType Resource_Vespene_Geyser;

    public static UnitType Special_Warp_Gate;

    public static UnitType Special_Psi_Disrupter;

    public static UnitType Special_Power_Generator;

    public static UnitType Special_Overmind_Cocoon;

    public static UnitType Special_Zerg_Beacon;

    public static UnitType Special_Terran_Beacon;

    public static UnitType Special_Protoss_Beacon;

    public static UnitType Special_Zerg_Flag_Beacon;

    public static UnitType Special_Terran_Flag_Beacon;

    public static UnitType Special_Protoss_Flag_Beacon;

    public static UnitType Spell_Dark_Swarm;

    public static UnitType Powerup_Uraj_Crystal;

    public static UnitType Powerup_Khalis_Crystal;

    public static UnitType Powerup_Flag;

    public static UnitType Powerup_Young_Chrysalis;

    public static UnitType Powerup_Psi_Emitter;

    public static UnitType Powerup_Data_Disk;

    public static UnitType Powerup_Khaydarin_Crystal;

    public static UnitType Powerup_Mineral_Cluster_Type_1;

    public static UnitType Powerup_Mineral_Cluster_Type_2;

    public static UnitType Powerup_Protoss_Gas_Orb_Type_1;

    public static UnitType Powerup_Protoss_Gas_Orb_Type_2;

    public static UnitType Powerup_Zerg_Gas_Sac_Type_1;

    public static UnitType Powerup_Zerg_Gas_Sac_Type_2;

    public static UnitType Powerup_Terran_Gas_Tank_Type_1;

    public static UnitType Powerup_Terran_Gas_Tank_Type_2;

    public static UnitType Special_Map_Revealer;

    public static UnitType Special_Floor_Missile_Trap;

    public static UnitType Special_Floor_Hatch;

    public static UnitType Special_Upper_Level_Door;

    public static UnitType Special_Right_Upper_Level_Door;

    public static UnitType Special_Pit_Door;

    public static UnitType Special_Right_Pit_Door;

    public static UnitType Special_Floor_Gun_Trap;

    public static UnitType Special_Wall_Missile_Trap;

    public static UnitType Special_Wall_Flame_Trap;

    public static UnitType Special_Right_Wall_Missile_Trap;

    public static UnitType Special_Right_Wall_Flame_Trap;

    public static UnitType Special_Start_Location;

    public static UnitType None;

    public static UnitType AllUnits;

    public static UnitType Men;

    public static UnitType Buildings;

    public static UnitType Factories;

    public static UnitType Unknown;


    private static Map<Long, UnitType> instances = new HashMap<Long, UnitType>();

    private UnitType(long pointer) {
        this.pointer = pointer;
    }

    private static UnitType get(long pointer) {
        UnitType instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UnitType(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native String c_str_native(long pointer);

    private native Race getRace_native(long pointer);

    private native TechType requiredTech_native(long pointer);

    private native TechType cloakingTech_native(long pointer);

    private native List<TechType> abilities_native(long pointer);

    private native List<UpgradeType> upgrades_native(long pointer);

    private native UpgradeType armorUpgrade_native(long pointer);

    private native int maxHitPoints_native(long pointer);

    private native int maxShields_native(long pointer);

    private native int maxEnergy_native(long pointer);

    private native int armor_native(long pointer);

    private native int mineralPrice_native(long pointer);

    private native int gasPrice_native(long pointer);

    private native int buildTime_native(long pointer);

    private native int supplyRequired_native(long pointer);

    private native int supplyProvided_native(long pointer);

    private native int spaceRequired_native(long pointer);

    private native int spaceProvided_native(long pointer);

    private native int buildScore_native(long pointer);

    private native int destroyScore_native(long pointer);

    private native UnitSizeType size_native(long pointer);

    private native int tileWidth_native(long pointer);

    private native int tileHeight_native(long pointer);

    private native int dimensionLeft_native(long pointer);

    private native int dimensionUp_native(long pointer);

    private native int dimensionRight_native(long pointer);

    private native int dimensionDown_native(long pointer);

    private native int seekRange_native(long pointer);

    private native int sightRange_native(long pointer);

    private native WeaponType groundWeapon_native(long pointer);

    private native int maxGroundHits_native(long pointer);

    private native WeaponType airWeapon_native(long pointer);

    private native int maxAirHits_native(long pointer);

    private native double topSpeed_native(long pointer);

    private native int acceleration_native(long pointer);

    private native int haltDistance_native(long pointer);

    private native int turnRadius_native(long pointer);

    private native boolean canProduce_native(long pointer);

    private native boolean canAttack_native(long pointer);

    private native boolean canMove_native(long pointer);

    private native boolean isFlyer_native(long pointer);

    private native boolean regeneratesHP_native(long pointer);

    private native boolean isSpellcaster_native(long pointer);

    private native boolean hasPermanentCloak_native(long pointer);

    private native boolean isInvincible_native(long pointer);

    private native boolean isOrganic_native(long pointer);

    private native boolean isMechanical_native(long pointer);

    private native boolean isRobotic_native(long pointer);

    private native boolean isDetector_native(long pointer);

    private native boolean isResourceContainer_native(long pointer);

    private native boolean isResourceDepot_native(long pointer);

    private native boolean isRefinery_native(long pointer);

    private native boolean isWorker_native(long pointer);

    private native boolean requiresPsi_native(long pointer);

    private native boolean requiresCreep_native(long pointer);

    private native boolean isTwoUnitsInOneEgg_native(long pointer);

    private native boolean isBurrowable_native(long pointer);

    private native boolean isCloakable_native(long pointer);

    private native boolean isBuilding_native(long pointer);

    private native boolean isAddon_native(long pointer);

    private native boolean isFlyingBuilding_native(long pointer);

    private native boolean isNeutral_native(long pointer);

    private native boolean isHero_native(long pointer);

    private native boolean isPowerup_native(long pointer);

    private native boolean isBeacon_native(long pointer);

    private native boolean isFlagBeacon_native(long pointer);

    private native boolean isSpecialBuilding_native(long pointer);

    private native boolean isSpell_native(long pointer);

    private native boolean producesLarva_native(long pointer);

    private native boolean isMineralField_native(long pointer);

    private native boolean canBuildAddon_native(long pointer);


}
