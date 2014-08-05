package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

	/** Each player in a match will have his or her own player instance. There is also a neutral player which
	* owns all the neutral units. */
public class Player {

	/** Returns a unique ID for the player. */
    public int getID() {
        return getID_native(pointer);
    }

	/** Returns the name of the player. */
    public String getName() {
        return getName_native(pointer);
    }

	/** Returns the set of units the player own. Note that units loaded into Terran dropships, Terran
	* bunkers, Terran refineries, Protoss assimilators, and Zerg extractors are not yet included in the
	* set. */
    public List<Unit> getUnits() {
        return getUnits_native(pointer);
    }

	/** Returns the race of the player. */
    public Race getRace() {
        return getRace_native(pointer);
    }

	/** Returns the type of the player. */
    public PlayerType getType() {
        return getType_native(pointer);
    }

	/** Returns the force the player is on. */
    public Force getForce() {
        return getForce_native(pointer);
    }

	/** Returns true if other player is an ally of this player. */
    public boolean isAlly(Player player) {
        return isAlly_native(pointer, player);
    }

	/** Returns true if other player is an enemy of this player. */
    public boolean isEnemy(Player player) {
        return isEnemy_native(pointer, player);
    }

	/** Returns true if the player is the neutral player. */
    public boolean isNeutral() {
        return isNeutral_native(pointer);
    }

	/** Returns the starting location of the player. If complete map information is disabled, this function
	* will return TilePositions::Unknown for enemy players. For the complete set of starting locations for
	* the current map, see Game::getStartLocations. */
    public TilePosition getStartLocation() {
        return getStartLocation_native(pointer);
    }

	/** Returns true if the player has achieved victory. */
    public boolean isVictorious() {
        return isVictorious_native(pointer);
    }

	/** Returns true if the player has been defeated. */
    public boolean isDefeated() {
        return isDefeated_native(pointer);
    }

	/** Returns true if the player left the game. */
    public boolean leftGame() {
        return leftGame_native(pointer);
    }

	/** Returns the amount of minerals the player has. */
    public int minerals() {
        return minerals_native(pointer);
    }

	/** Returns the amount of vespene gas the player has. */
    public int gas() {
        return gas_native(pointer);
    }

	/** Returns the cumulative amount of minerals the player has mined up to this point (including the 50
	* minerals at the start of the game). */
    public int gatheredMinerals() {
        return gatheredMinerals_native(pointer);
    }

	/** Returns the cumulative amount of gas the player has harvested up to this point. */
    public int gatheredGas() {
        return gatheredGas_native(pointer);
    }

	/** Returns the cumulative amount of minerals the player has spent on repairs up to this point. */
    public int repairedMinerals() {
        return repairedMinerals_native(pointer);
    }

	/** Returns the cumulative amount of gas the player has spent on repairs up to this point. */
    public int repairedGas() {
        return repairedGas_native(pointer);
    }

	/** Returns the cumulative amount of minerals the player has gained from refunded units up to this point. */
    public int refundedMinerals() {
        return refundedMinerals_native(pointer);
    }

	/** Returns the cumulative amount of gas the player has gained from refunded units up to this point. */
    public int refundedGas() {
        return refundedGas_native(pointer);
    }

	/** Returns the cumulative amount of minerals the player has spent up to this point (not including repairs). */
    public int spentMinerals() {
        return spentMinerals_native(pointer);
    }

	/** Returns the cumulative amount of gas the player has spent up to this point (not including repairs). */
    public int spentGas() {
        return spentGas_native(pointer);
    }

	/** Returns the total amount of supply the player has. If a race is provided, the total supply for the
	* given race will be returned, otherwise the player's initial race will be used. Supply counts returned
	* by BWAPI are double what you would expect to see from playing the game. This is because zerglings
	* take up 0.5 in-game supply. */
    public int supplyTotal() {
        return supplyTotal_native(pointer);
    }

    public int supplyTotal(Race race) {
        return supplyTotal_native(pointer, race);
    }

	/** Returns how much of the supply is actually being used by units. If a race is provided, the used
	* supply for the given race will be returned, otherwise the player's initial race will be used. Supply
	* counts returned by BWAPI are double what you would expect to see from playing the game. This is
	* because zerglings take up 0.5 in-game supply. */
    public int supplyUsed() {
        return supplyUsed_native(pointer);
    }

    public int supplyUsed(Race race) {
        return supplyUsed_native(pointer, race);
    }

	/** Returns the number of all accessible units of the given type. */
    public int allUnitCount(UnitType unit) {
        return allUnitCount_native(pointer, unit);
    }

	/** Returns the number of visible units of the given type. */
    public int visibleUnitCount(UnitType unit) {
        return visibleUnitCount_native(pointer, unit);
    }

	/** Returns the number of completed units of the given type. */
    public int completedUnitCount(UnitType unit) {
        return completedUnitCount_native(pointer, unit);
    }

	/** Returns the number of incomplete units of the given type. */
    public int incompleteUnitCount(UnitType unit) {
        return incompleteUnitCount_native(pointer, unit);
    }

	/** Returns the number of dead units of the given type. */
    public int deadUnitCount(UnitType unit) {
        return deadUnitCount_native(pointer, unit);
    }

	/** Returns the number of killed units of the given type. */
    public int killedUnitCount(UnitType unit) {
        return killedUnitCount_native(pointer, unit);
    }

	/** Returns the player's current upgrade level of the given upgrade. To order a unit to upgrade a given
	* upgrade type, see Unit::upgrade. */
    public boolean hasResearched(TechType tech) {
        return hasResearched_native(pointer, tech);
    }

	/** Returns true if the player is researching the given tech. To order a unit to research a given tech
	* type, see Unit::reseach. */
    public boolean isResearching(TechType tech) {
        return isResearching_native(pointer, tech);
    }

	/** Returns true if the player is upgrading the given upgrade. To order a unit to upgrade a given
	* upgrade type, see Unit::upgrade. */
    public boolean isUpgrading(UpgradeType upgrade) {
        return isUpgrading_native(pointer, upgrade);
    }

	/** Returns the color of the player for drawing */
    public Color getColor() {
        return getColor_native(pointer);
    }

	/** Returns the color of the player for text messages */
    public int getTextColor() {
        return getTextColor_native(pointer);
    }

	/** Returns the max energy of the given unit type, taking into account upgrades */
    public int maxEnergy(UnitType unit) {
        return maxEnergy_native(pointer, unit);
    }

	/** Returns the top speed of the given unit type, includes upgrades */
    public double topSpeed(UnitType unit) {
        return topSpeed_native(pointer, unit);
    }

	/** Returns the max ground weapon range of the given unit type, includes upgrades */
    public int groundWeaponMaxRange(UnitType unit) {
        return groundWeaponMaxRange_native(pointer, unit);
    }

	/** Returns the max air weapon range of the given unit type, includes upgrades */
    public int airWeaponMaxRange(UnitType unit) {
        return airWeaponMaxRange_native(pointer, unit);
    }

	/** Returns the max range of the given weapon with upgrades */
    public int weaponMaxRange(WeaponType weapon) {
        return weaponMaxRange_native(pointer, weapon);
    }

	/** Returns the sight range of the given unit type, includes upgrades */
    public int sightRange(UnitType unit) {
        return sightRange_native(pointer, unit);
    }

	/** Returns the ground weapon cooldown of the given unit type, includes upgrades */
    public int groundWeaponDamageCooldown(UnitType unit) {
        return groundWeaponDamageCooldown_native(pointer, unit);
    }

	/** Returns the armor of the given unit type, includes upgrades */
    public int armor(UnitType unit) {
        return armor_native(pointer, unit);
    }

	/** Returns the Player's Total Unit Score */
    public int getUnitScore() {
        return getUnitScore_native(pointer);
    }

	/** Returns the Player's Total Kill Score */
    public int getKillScore() {
        return getKillScore_native(pointer);
    }

	/** Returns the Player's Total Buildings Score */
    public int getBuildingScore() {
        return getBuildingScore_native(pointer);
    }

	/** Returns the Player's Total Razings Score */
    public int getRazingScore() {
        return getRazingScore_native(pointer);
    }

	/** Returns the Player's Custom Score */
    public int getCustomScore() {
        return getCustomScore_native(pointer);
    }

	/** Returns true if the Player is only observing the game, and not participating */
    public boolean isObserver() {
        return isObserver_native(pointer);
    }

	/** Returns the maximum upgrades available specific to the player (Use Map Settings). */
    public boolean isResearchAvailable(TechType tech) {
        return isResearchAvailable_native(pointer, tech);
    }

	/** Returns true if the unit is available for the player to build (Use Map Settings). */
    public boolean isUnitAvailable(UnitType unit) {
        return isUnitAvailable_native(pointer, unit);
    }


    private static Map<Long, Player> instances = new HashMap<Long, Player>();

    private Player(long pointer) {
        this.pointer = pointer;
    }

    private static Player get(long pointer) {
        Player instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Player(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native int getID_native(long pointer);

    private native String getName_native(long pointer);

    private native List<Unit> getUnits_native(long pointer);

    private native Race getRace_native(long pointer);

    private native PlayerType getType_native(long pointer);

    private native Force getForce_native(long pointer);

    private native boolean isAlly_native(long pointer, Player player);

    private native boolean isEnemy_native(long pointer, Player player);

    private native boolean isNeutral_native(long pointer);

    private native TilePosition getStartLocation_native(long pointer);

    private native boolean isVictorious_native(long pointer);

    private native boolean isDefeated_native(long pointer);

    private native boolean leftGame_native(long pointer);

    private native int minerals_native(long pointer);

    private native int gas_native(long pointer);

    private native int gatheredMinerals_native(long pointer);

    private native int gatheredGas_native(long pointer);

    private native int repairedMinerals_native(long pointer);

    private native int repairedGas_native(long pointer);

    private native int refundedMinerals_native(long pointer);

    private native int refundedGas_native(long pointer);

    private native int spentMinerals_native(long pointer);

    private native int spentGas_native(long pointer);

    private native int supplyTotal_native(long pointer);

    private native int supplyTotal_native(long pointer, Race race);

    private native int supplyUsed_native(long pointer);

    private native int supplyUsed_native(long pointer, Race race);

    private native int allUnitCount_native(long pointer, UnitType unit);

    private native int visibleUnitCount_native(long pointer, UnitType unit);

    private native int completedUnitCount_native(long pointer, UnitType unit);

    private native int incompleteUnitCount_native(long pointer, UnitType unit);

    private native int deadUnitCount_native(long pointer, UnitType unit);

    private native int killedUnitCount_native(long pointer, UnitType unit);

    private native boolean hasResearched_native(long pointer, TechType tech);

    private native boolean isResearching_native(long pointer, TechType tech);

    private native boolean isUpgrading_native(long pointer, UpgradeType upgrade);

    private native Color getColor_native(long pointer);

    private native int getTextColor_native(long pointer);

    private native int maxEnergy_native(long pointer, UnitType unit);

    private native double topSpeed_native(long pointer, UnitType unit);

    private native int groundWeaponMaxRange_native(long pointer, UnitType unit);

    private native int airWeaponMaxRange_native(long pointer, UnitType unit);

    private native int weaponMaxRange_native(long pointer, WeaponType weapon);

    private native int sightRange_native(long pointer, UnitType unit);

    private native int groundWeaponDamageCooldown_native(long pointer, UnitType unit);

    private native int armor_native(long pointer, UnitType unit);

    private native int getUnitScore_native(long pointer);

    private native int getKillScore_native(long pointer);

    private native int getBuildingScore_native(long pointer);

    private native int getRazingScore_native(long pointer);

    private native int getCustomScore_native(long pointer);

    private native boolean isObserver_native(long pointer);

    private native boolean isResearchAvailable_native(long pointer, TechType tech);

    private native boolean isUnitAvailable_native(long pointer, UnitType unit);


}
