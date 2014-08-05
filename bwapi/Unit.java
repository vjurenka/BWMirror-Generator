package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

	/** The Unit class is used to get information about individual units as well as issue orders to units. Each
	* unit in the game has a unique Unit object, and Unit objects are not deleted until the end of the match
	* (so you don't need to worry about unit pointers becoming invalid).
	*<br/><br/>
	* Every Unit in the game is either accessible or inaccessible. To determine if an AI can access a
	* particular unit, BWAPI checks to see if Flag::CompleteMapInformation? is enabled. So there are two cases
	* to consider - either the flag is enabled, or it is disabled:
	*<br/><br/>
	* If Flag::CompleteMapInformation? is disabled, then a unit is accessible if and only if it is visible.
	* Note also that some properties of visible enemy units will not be made available to the AI (such as the
	* contents of visible enemy dropships). If a unit is not visible, Unit::exists will return false,
	* regardless of whether or not the unit exists. This is because absolutely no state information on
	* invisible enemy units is made available to the AI. To determine if an enemy unit has been destroyed, the
	* AI must watch for AIModule::onUnitDestroy messages from BWAPI, which is only called for visible units
	* which get destroyed.
	*<br/><br/>
	* If Flag::CompleteMapInformation? is enabled, then all units that exist in the game are accessible, and
	* Unit::exists is accurate for all units. Similarly AIModule::onUnitDestroy messages are generated for all
	* units that get destroyed, not just visible ones.
	*<br/><br/>
	* If a Unit is not accessible, in general the only the getInitial__ functions will be available to the AI.
	* However for units that were owned by the player, getPlayer and getType will continue to work for units
	* that have been destroyed. */
public class Unit {

	/** Returns a unique ID for this unit. It simply casts the unit's address as an integer, since each unit
	* has a unique address. */
    public int getID() {
        return getID_native(pointer);
    }

	/** Returns the unit ID that is used in a replay (*.rep) file's action recordings. */
    public int getReplayID() {
        return getReplayID_native(pointer);
    }

	/** Returns a pointer to the player that owns this unit. */
    public Player getPlayer() {
        return getPlayer_native(pointer);
    }

	/** Returns the current type of the unit. */
    public UnitType getType() {
        return getType_native(pointer);
    }

	/** Returns the position of the unit on the map. */
    public Position getPosition() {
        return getPosition_native(pointer);
    }

	/** Returns the build tile position of the unit on the map. Useful if the unit is a building. The tile
	* position is of the top left corner of the building. */
    public TilePosition getTilePosition() {
        return getTilePosition_native(pointer);
    }

	/** Returns the direction the unit is facing, measured in radians. An angle of 0 means the unit is
	* facing east. */
    public double getAngle() {
        return getAngle_native(pointer);
    }

	/** Returns the x component of the unit's velocity, measured in pixels per frame. */
    public double getVelocityX() {
        return getVelocityX_native(pointer);
    }

	/** Returns the y component of the unit's velocity, measured in pixels per frame. */
    public double getVelocityY() {
        return getVelocityY_native(pointer);
    }

	/** Returns the region that this unit is currently in. */
    public Region getRegion() {
        return getRegion_native(pointer);
    }

	/** Returns the X coordinate of the left side of the unit. */
    public int getLeft() {
        return getLeft_native(pointer);
    }

	/** Returns the Y coordinate of the top side of the unit. */
    public int getTop() {
        return getTop_native(pointer);
    }

	/** Returns the X coordinate of the right side of the unit. */
    public int getRight() {
        return getRight_native(pointer);
    }

	/** Returns the Y coordinate of the bottom side of the unit. */
    public int getBottom() {
        return getBottom_native(pointer);
    }

	/** Returns the unit's current amount of hit points. */
    public int getHitPoints() {
        return getHitPoints_native(pointer);
    }

	/** Returns the unit's current amount of shields. */
    public int getShields() {
        return getShields_native(pointer);
    }

	/** Returns the unit's current amount of energy. */
    public int getEnergy() {
        return getEnergy_native(pointer);
    }

	/** Returns the unit's current amount of containing resources. Useful for determining how much minerals
	* are left in a mineral patch, or how much gas is left in a geyser
	* (can also be called on a refinery/assimilator/extractor). */
    public int getResources() {
        return getResources_native(pointer);
    }

	/** Retrieves the group ID of a resource. Can be used to identify which resources belong to an expansion. */
    public int getResourceGroup() {
        return getResourceGroup_native(pointer);
    }

	/** Returns the edge-to-edge distance between the current unit and the target unit. */
    public int getDistance(Unit target) {
        return getDistance_native(pointer, target);
    }

	/** Returns the distance from the edge of the current unit to the target position. */
    public int getDistance(Position target) {
        return getDistance_native(pointer, target);
    }

	/** Returns true if the unit is able to move to the target unit */
    public boolean hasPath(Unit target) {
        return hasPath_native(pointer, target);
    }

	/** Returns true if the unit is able to move to the target position */
    public boolean hasPath(Position target) {
        return hasPath_native(pointer, target);
    }

	/** Returns the frame of the last successful command. Frame is comparable to Game::getFrameCount(). */
    public int getLastCommandFrame() {
        return getLastCommandFrame_native(pointer);
    }

	/** Returns the last successful command. */
    public Player getLastAttackingPlayer() {
        return getLastAttackingPlayer_native(pointer);
    }

	/** Returns the player's current upgrade level for the given upgrade, if the unit is affected by this
	* upgrade.*/
    public int getUpgradeLevel(UpgradeType upgrade) {
        return getUpgradeLevel_native(pointer, upgrade);
    }

	/** Returns the initial type of the unit or Unknown if it wasn't a neutral unit at the beginning of the
	* game. */
    public UnitType getInitialType() {
        return getInitialType_native(pointer);
    }

	/** Returns the initial position of the unit on the map, or Positions::Unknown if the unit wasn't a
	* neutral unit at the beginning of the game. */
    public Position getInitialPosition() {
        return getInitialPosition_native(pointer);
    }

	/** Returns the initial build tile position of the unit on the map, or TilePositions::Unknown if the
	* unit wasn't a neutral unit at the beginning of the game. The tile position is of the top left corner
	* of the building. */
    public TilePosition getInitialTilePosition() {
        return getInitialTilePosition_native(pointer);
    }

	/** Returns the unit's initial amount of hit points, or 0 if it wasn't a neutral unit at the beginning
	* of the game. */
    public int getInitialHitPoints() {
        return getInitialHitPoints_native(pointer);
    }

	/** Returns the unit's initial amount of containing resources, or 0 if the unit wasn't a neutral unit
	* at the beginning of the game. */
    public int getInitialResources() {
        return getInitialResources_native(pointer);
    }

	/** Returns the unit's current kill count. */
    public int getKillCount() {
        return getKillCount_native(pointer);
    }

	/** Returns the unit's acid spore count. */
    public int getAcidSporeCount() {
        return getAcidSporeCount_native(pointer);
    }

	/** Returns the number of interceptors the Protoss Carrier has. */
    public int getInterceptorCount() {
        return getInterceptorCount_native(pointer);
    }

	/** Returns the number of scarabs in the Protoss Reaver. */
    public int getScarabCount() {
        return getScarabCount_native(pointer);
    }

	/** Returns the number of spider mines in the Terran Vulture. */
    public int getSpiderMineCount() {
        return getSpiderMineCount_native(pointer);
    }

	/** Returns unit's ground weapon cooldown. It is 0 if the unit is ready to attack. */
    public int getGroundWeaponCooldown() {
        return getGroundWeaponCooldown_native(pointer);
    }

	/** Returns unit's air weapon cooldown. It is 0 if the unit is ready to attack. */
    public int getAirWeaponCooldown() {
        return getAirWeaponCooldown_native(pointer);
    }

	/** Returns unit's ground weapon cooldown. It is 0 if the unit is ready cast a spell. */
    public int getSpellCooldown() {
        return getSpellCooldown_native(pointer);
    }

	/** Returns the remaining hit points of the defense matrix. Initially a defense Matrix has 250 points.
	* \see Unit::getDefenseMatrixTimer, Unit::isDefenseMatrixed. */
    public int getDefenseMatrixPoints() {
        return getDefenseMatrixPoints_native(pointer);
    }

	/** Returns the time until the defense matrix wears off. 0 -> No defense Matrix present. */
    public int getDefenseMatrixTimer() {
        return getDefenseMatrixTimer_native(pointer);
    }

	/** Returns the time until the ensnare effect wears off. 0 -> No ensnare effect present. */
    public int getEnsnareTimer() {
        return getEnsnareTimer_native(pointer);
    }

	/** Returns the time until the radiation wears off. 0 -> No radiation present. */
    public int getIrradiateTimer() {
        return getIrradiateTimer_native(pointer);
    }

	/** Returns the time until the lockdown wears off. 0 -> No lockdown present. */
    public int getLockdownTimer() {
        return getLockdownTimer_native(pointer);
    }

	/** Returns the time until the maelstrom wears off. 0 -> No maelstrom present. */
    public int getMaelstromTimer() {
        return getMaelstromTimer_native(pointer);
    }

    public int getOrderTimer() {
        return getOrderTimer_native(pointer);
    }

	/** Returns the time until the plague wears off. 0 -> No plague present. */
    public int getPlagueTimer() {
        return getPlagueTimer_native(pointer);
    }

	/** Returns the amount of time until the unit is removed, or 0 if the unit does not have a remove timer.
	* Used to determine how much time remains before hallucinated units, dark swarm, etc have until they
	* are removed. */
    public int getRemoveTimer() {
        return getRemoveTimer_native(pointer);
    }

	/** Returns the time until the stasis field wears off. 0 -> No stasis field present. */
    public int getStasisTimer() {
        return getStasisTimer_native(pointer);
    }

	/** Returns the time until the stimpack wears off. 0 -> No stimpack boost present. */
    public int getStimTimer() {
        return getStimTimer_native(pointer);
    }

	/** Returns the building type a worker is about to construct. If the unit is a morphing Zerg unit or an
	* incomplete building, this returns the UnitType the unit is about to become upon completion.*/
    public UnitType getBuildType() {
        return getBuildType_native(pointer);
    }

	/** Returns the list of units queued up to be trained.
	* \see Unit::train, Unit::cancelTrain, Unit::isTraining. */
    public TechType getTech() {
        return getTech_native(pointer);
    }

	/** Returns the upgrade that the unit is currently upgrading. If the unit is not upgrading anything,
	* UpgradeTypes::None is returned.
	* \see Unit::upgrade, Unit::cancelUpgrade, Unit::isUpgrading, Unit::getRemainingUpgradeTime. */
    public UpgradeType getUpgrade() {
        return getUpgrade_native(pointer);
    }

	/** Returns the remaining build time of a unit/building that is being constructed. */
    public int getRemainingBuildTime() {
        return getRemainingBuildTime_native(pointer);
    }

	/** Returns the remaining time of the unit that is currently being trained. If the unit is a Hatchery,
	* Lair, or Hive, this returns the amount of time until the next larva spawns, or 0 if the unit already
	* has 3 larva. */
    public int getRemainingTrainTime() {
        return getRemainingTrainTime_native(pointer);
    }

	/** Returns the amount of time until the unit is done researching its current tech. If the unit is not
	* researching anything, 0 is returned.
	* \see Unit::research, Unit::cancelResearch, Unit::isResearching, Unit::getTech. */
    public int getRemainingResearchTime() {
        return getRemainingResearchTime_native(pointer);
    }

	/** Returns the amount of time until the unit is done upgrading its current upgrade. If the unit is not
	* upgrading anything, 0 is returned.
	* \see Unit::upgrade, Unit::cancelUpgrade, Unit::isUpgrading, Unit::getUpgrade. */
    public int getRemainingUpgradeTime() {
        return getRemainingUpgradeTime_native(pointer);
    }

	/** If the unit is an SCV that is constructing a building, this will return the building it is
	* constructing. If the unit is a Terran building that is being constructed, this will return the SCV
	* that is constructing it. */
    public Unit getBuildUnit() {
        return getBuildUnit_native(pointer);
    }

	/** Generally returns the appropriate target unit after issuing an order that accepts a target unit
	* (i.e. attack, repair, gather, follow, etc.). To check for a target that has been acquired
	* automatically (without issuing an order) see getOrderTarget. */
    public Unit getTarget() {
        return getTarget_native(pointer);
    }

	/** Returns the target position the unit is moving to (provided a valid path to the target position
	* exists). */
    public Position getTargetPosition() {
        return getTargetPosition_native(pointer);
    }

    public Order getOrder() {
        return getOrder_native(pointer);
    }

    public Order getSecondaryOrder() {
        return getSecondaryOrder_native(pointer);
    }

	/** This is usually set when the low level unit AI acquires a new target automatically. For example if
	* an enemy probe comes in range of your marine, the marine will start attacking it, and getOrderTarget
	* will be set in this case, but not getTarget. */
    public Unit getOrderTarget() {
        return getOrderTarget_native(pointer);
    }

	/** Returns the target position for the units order. For example for the move order getTargetPosition
	* returns the end of the units path but this returns the location the unit is trying to move to.  */
    public Position getOrderTargetPosition() {
        return getOrderTargetPosition_native(pointer);
    }

	/** Returns the position the building is rallied to. If the building does not produce units,
	* Positions::None is returned.
	* \see Unit::setRallyPoint, Unit::getRallyUnit. */
    public Position getRallyPosition() {
        return getRallyPosition_native(pointer);
    }

	/** Returns the unit the building is rallied to. If the building is not rallied to any unit, NULL is
	* returned.
	* \see Unit::setRallyPoint, Unit::getRallyPosition. */
    public Unit getRallyUnit() {
        return getRallyUnit_native(pointer);
    }

	/** Returns the add-on of this unit, or NULL if the unit doesn't have an add-on. */
    public Unit getAddon() {
        return getAddon_native(pointer);
    }

	/** Returns the corresponding connected nydus canal of this unit, or NULL if the unit does not have a
	* connected nydus canal. */
    public Unit getNydusExit() {
        return getNydusExit_native(pointer);
    }

	/** Returns the power up the unit is holding, or NULL if the unit is not holding a power up */
    public Unit getPowerUp() {
        return getPowerUp_native(pointer);
    }

	/** Returns the dropship, shuttle, overlord, or bunker that is this unit is loaded in to. */
    public Unit getTransport() {
        return getTransport_native(pointer);
    }

	/** Returns a list of the units loaded into a Terran Bunker, Terran Dropship, Protoss Shuttle, or Zerg
	* Overlord. */
    public List<Unit> getLoadedUnits() {
        return getLoadedUnits_native(pointer);
    }

	/** For Protoss Interceptors, this returns the Carrier unit this Interceptor is controlled by. For all
	* other unit types this function returns NULL. */
    public Unit getCarrier() {
        return getCarrier_native(pointer);
    }

	/** Returns the set of interceptors controlled by this unit. If the unit has no interceptors, or is not
	* a Carrier, this function returns an empty set. */
    public List<Unit> getInterceptors() {
        return getInterceptors_native(pointer);
    }

	/** For Zerg Larva, this returns the Hatchery, Lair, or Hive unit this Larva was spawned from. For all
	* other unit types this function returns NULL. */
    public Unit getHatchery() {
        return getHatchery_native(pointer);
    }

	/** Returns the set of larva spawned by this unit. If the unit has no larva, or is not a Hatchery, Lair,
	* or Hive, this function returns an empty set. Equivalent to clicking "Select Larva" from the Starcraft
	* GUI. */
    public List<Unit> getLarva() {
        return getLarva_native(pointer);
    }

	/** Returns the set of units within the given radius of this unit */
    public List<Unit> getUnitsInRadius(int radius) {
        return getUnitsInRadius_native(pointer, radius);
    }

	/** Returns the set of units within weapon range of this unit. */
    public List<Unit> getUnitsInWeaponRange(WeaponType weapon) {
        return getUnitsInWeaponRange_native(pointer, weapon);
    }

	/** Returns the unit's custom client info. The client is responsible for deallocation. */
    public boolean exists() {
        return exists_native(pointer);
    }

	/* Returns true if the Nuclear Missile Silo has a nuke */
    public boolean hasNuke() {
        return hasNuke_native(pointer);
    }

	/** Returns true if the unit is currently accelerating. */
    public boolean isAccelerating() {
        return isAccelerating_native(pointer);
    }

    public boolean isAttacking() {
        return isAttacking_native(pointer);
    }

    public boolean isAttackFrame() {
        return isAttackFrame_native(pointer);
    }

	/** Returns true if the unit is being constructed. Always true for incomplete Protoss and Zerg
	* buildings, and true for incomplete Terran buildings that have an SCV constructing them. If the SCV
	* halts construction, isBeingConstructed will return false.
	*<br/><br/>
	* \see Unit::build, Unit::cancelConstruction, Unit::haltConstruction, Unit::isConstructing. */
    public boolean isBeingConstructed() {
        return isBeingConstructed_native(pointer);
    }

	/** Returns true if the unit is a mineral patch or refinery that is being gathered. */
    public boolean isBeingGathered() {
        return isBeingGathered_native(pointer);
    }

	/** Returns true if the unit is currently being healed by a Terran Medic, or repaired by a Terran SCV. */
    public boolean isBeingHealed() {
        return isBeingHealed_native(pointer);
    }

	/** Returns true if the unit is currently blind from a Medic's Optical Flare. */
    public boolean isBlind() {
        return isBlind_native(pointer);
    }

	/** Returns true if the unit is currently braking/slowing down. */
    public boolean isBraking() {
        return isBraking_native(pointer);
    }

	/** Returns true if the unit is a Zerg unit that is current burrowed.
	* \see Unit::burrow, Unit::unburrow. */
    public boolean isBurrowed() {
        return isBurrowed_native(pointer);
    }

	/** Returns true if the unit is a worker that is carrying gas.
	* \see Unit::returnCargo, Unit::isGatheringGas. */
    public boolean isCarryingGas() {
        return isCarryingGas_native(pointer);
    }

	/** Returns true if the unit is a worker that is carrying minerals.
	* \see Unit::returnCargo, Unit::isGatheringMinerals. */
    public boolean isCarryingMinerals() {
        return isCarryingMinerals_native(pointer);
    }

	/** Returns true if the unit is cloaked.
	* \see Unit::cloak, Unit::decloak. */
    public boolean isCloaked() {
        return isCloaked_native(pointer);
    }

	/** Returns true if the unit has been completed. */
    public boolean isCompleted() {
        return isCompleted_native(pointer);
    }

	/** Returns true when a unit has been issued an order to build a structure and is moving to the build
	* location. Also returns true for Terran SCVs while they construct a building.
	* \see Unit::build, Unit::cancelConstruction, Unit::haltConstruction, Unit::isBeingConstructed. */
    public boolean isConstructing() {
        return isConstructing_native(pointer);
    }

	/** Returns true if the unit has a defense matrix from a Terran Science Vessel. */
    public boolean isDefenseMatrixed() {
        return isDefenseMatrixed_native(pointer);
    }

	/** Returns true if the unit is detected. */
    public boolean isDetected() {
        return isDetected_native(pointer);
    }

	/** Returns true if the unit has been ensnared by a Zerg Queen. */
    public boolean isEnsnared() {
        return isEnsnared_native(pointer);
    }

	/** Returns true if the unit is following another unit.
	* \see Unit::follow, Unit::getTarget. */
    public boolean isFollowing() {
        return isFollowing_native(pointer);
    }

	/** Returns true if the unit is in one of the four states for gathering gas (MoveToGas, WaitForGas,
	* HarvestGas, ReturnGas).
	* \see Unit::isCarryingGas. */
    public boolean isGatheringGas() {
        return isGatheringGas_native(pointer);
    }

	/** Returns true if the unit is in one of the four states for gathering minerals (MoveToMinerals,
	* WaitForMinerals, MiningMinerals, ReturnMinerals).
	* \see Unit::isCarryingMinerals. */
    public boolean isGatheringMinerals() {
        return isGatheringMinerals_native(pointer);
    }

	/** Returns true for hallucinated units, false for normal units. Returns true for hallucinated enemy
	* units only if Complete Map Information is enabled.
	* \see Unit::getRemoveTimer. */
    public boolean isHallucination() {
        return isHallucination_native(pointer);
    }

	/** Returns true if the unit is holding position
	* \see Unit::holdPosition. */
    public boolean isHoldingPosition() {
        return isHoldingPosition_native(pointer);
    }

	/** Returns true if the unit is not doing anything.
	* \see Unit::stop. */
    public boolean isIdle() {
        return isIdle_native(pointer);
    }

	/** Returns true if the unit can be interrupted. */
    public boolean isInterruptible() {
        return isInterruptible_native(pointer);
    }

	/** Returns true if the unit is invincible. */
    public boolean isInvincible() {
        return isInvincible_native(pointer);
    }

	/** Returns true if the unit can attack a specified target from its current position. */
    public boolean isInWeaponRange(Unit target) {
        return isInWeaponRange_native(pointer, target);
    }

	/** Returns true if the unit is being irradiated by a Terran Science Vessel.
	* \see Unit::getIrradiateTimer. */
    public boolean isIrradiated() {
        return isIrradiated_native(pointer);
    }

	/** Returns true if the unit is a Terran building that is currently lifted off the ground.
	* \see Unit::lift,Unit::land. */
    public boolean isLifted() {
        return isLifted_native(pointer);
    }

	/** Return true if the unit is loaded into a Terran Bunker, Terran Dropship, Protoss Shuttle, or Zerg
	* Overlord.
	* \see Unit::load, Unit::unload, Unit::unloadAll. */
    public boolean isLoaded() {
        return isLoaded_native(pointer);
    }

	/** Returns true if the unit is locked down by a Terran Ghost.
	*  \see Unit::getLockdownTimer. */
    public boolean isLockedDown() {
        return isLockedDown_native(pointer);
    }

	/** Returns true if the unit is being maelstrommed.
	* \see Unit::getMaelstromTimer. */
    public boolean isMaelstrommed() {
        return isMaelstrommed_native(pointer);
    }

	/** Returns true if the unit is a zerg unit that is morphing.
	* \see Unit::morph, Unit::cancelMorph, Unit::getBuildType, Unit::getRemainingBuildTime. */
    public boolean isMorphing() {
        return isMorphing_native(pointer);
    }

	/** Returns true if the unit is moving.
	* \see Unit::attack, Unit::stop. */
    public boolean isMoving() {
        return isMoving_native(pointer);
    }

	/** Returns true if the unit has been parasited by some other player. */
    public boolean isParasited() {
        return isParasited_native(pointer);
    }

	/** Returns true if the unit is patrolling between two positions.
	* \see Unit::patrol. */
    public boolean isPatrolling() {
        return isPatrolling_native(pointer);
    }

	/** Returns true if the unit has been plagued by a Zerg Defiler.
	* \see Unit::getPlagueTimer. */
    public boolean isPlagued() {
        return isPlagued_native(pointer);
    }

	/** Returns true if the unit is a Terran SCV that is repairing or moving to repair another unit. */
    public boolean isRepairing() {
        return isRepairing_native(pointer);
    }

	/** Returns true if the unit is a building that is researching tech. See TechTypes for the complete list
	* of available techs in Broodwar.
	* \see Unit::research, Unit::cancelResearch, Unit::getTech, Unit::getRemainingResearchTime. */
    public boolean isResearching() {
        return isResearching_native(pointer);
    }

	/** Returns true if the unit has been selected by the user via the starcraft GUI. Only available if you
	* enable Flag::UserInput during AIModule::onStart.
	* \see Game::getSelectedUnits. */
    public boolean isSelected() {
        return isSelected_native(pointer);
    }

	/** Returns true if the unit is a Terran Siege Tank that is currently in Siege mode.
	* \see Unit::siege, Unit::unsiege. */
    public boolean isSieged() {
        return isSieged_native(pointer);
    }

	/** Returns true if the unit is starting to attack.
	* \see Unit::attackUnit, Unit::getGroundWeaponCooldown, Unit::getAirWeaponCooldown. */
    public boolean isStartingAttack() {
        return isStartingAttack_native(pointer);
    }

	/** Returns true if the unit has been stasised by a Protoss Arbiter.
	* \see Unit::getStasisTimer. */
    public boolean isStasised() {
        return isStasised_native(pointer);
    }

	/** Returns true if the unit is currently stimmed.
	* \see Unit::getStimTimer. */
    public boolean isStimmed() {
        return isStimmed_native(pointer);
    }

	/** Returns true if the unit is being pushed off of another unit */
    public boolean isStuck() {
        return isStuck_native(pointer);
    }

	/** Returns true if the unit is training units (i.e. a Barracks training Marines).
	* \see Unit::train, Unit::getTrainingQueue, Unit::cancelTrain, Unit::getRemainingTrainTime. */
    public boolean isTraining() {
        return isTraining_native(pointer);
    }

	/** Returns true if the unit was recently attacked. */
    public boolean isUnderAttack() {
        return isUnderAttack_native(pointer);
    }

	/** Returns true if the unit is under a Dark Swarm. */
    public boolean isUnderDarkSwarm() {
        return isUnderDarkSwarm_native(pointer);
    }

	/** Returns true if the unit is under a Disruption Web. */
    public boolean isUnderDisruptionWeb() {
        return isUnderDisruptionWeb_native(pointer);
    }

	/** Returns true if the unit is under a Protoss Psionic Storm. */
    public boolean isUnderStorm() {
        return isUnderStorm_native(pointer);
    }

	/** Returns true if the unit is a Protoss building that is unpowered because no pylons are in range. */
    public boolean isUnpowered() {
        return isUnpowered_native(pointer);
    }

	/** Returns true if the unit is a building that is upgrading. See UpgradeTypes for the complete list
	* of available upgrades in Broodwar.
	* \see Unit::upgrade, Unit::cancelUpgrade, Unit::getUpgrade, Unit::getRemainingUpgradeTime. */
    public boolean isUpgrading() {
        return isUpgrading_native(pointer);
    }

	/** Returns true if the unit is visible. If the CompleteMapInformation?  cheat flag is enabled, existing
	* units hidden by the fog of war will be accessible, but isVisible will still return false.
	* \see Unit::exists. */
    public boolean isVisible() {
        return isVisible_native(pointer);
    }

    public boolean isVisible(Player player) {
        return isVisible_native(pointer, player);
    }

	/** Returns true if the unit is able to execute the given command, or false if there is an error */
    public boolean canIssueCommand(UnitCommand command) {
        return canIssueCommand_native(pointer, command);
    }

	/** Issues the give unit command, or returns false if there is an error */
    public boolean issueCommand(UnitCommand command) {
        return issueCommand_native(pointer, command);
    }

	/** Orders the unit to attack move to the specified location. */
    public boolean attack(Position target) {
        return attack_native(pointer, target);
    }

    public boolean attack(Position target, boolean shiftQueueCommand) {
        return attack_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the unit to attack the specified unit. */
    public boolean attack(Unit target) {
        return attack_native(pointer, target);
    }

    public boolean attack(Unit target, boolean shiftQueueCommand) {
        return attack_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the unit to build the given unit type at the given position. Note that if the player does not
	* have enough resources when the unit attempts to place the building down, the order will fail. The
	* tile position specifies where the top left corner of the building will be placed. */
    public boolean build(TilePosition target, UnitType type) {
        return build_native(pointer, target, type);
    }

	/** Orders the unit to build the given addon. The unit must be a Terran building that can have an addon
	* and the specified unit type must be an addon unit type. */
    public boolean buildAddon(UnitType type) {
        return buildAddon_native(pointer, type);
    }

	/** Orders this unit to add the specified unit type to the training queue. Note that the player must
	* have sufficient resources to train. If you wish to make units from a hatchery, use getLarva to get
	* the larva associated with the hatchery and then call morph on the larva you want to morph. This
	* command can also be used to make interceptors and scarabs. */
    public boolean train(UnitType type) {
        return train_native(pointer, type);
    }

	/** Orders the unit to morph into the specified unit type. Returns false if given a wrong type.
	* \see Unit::cancelMorph, Unit::isMorphing. */
    public boolean morph(UnitType type) {
        return morph_native(pointer, type);
    }

	/** Orders the unit to research the given tech type.
	* \see Unit::cancelResearch, Unit::Unit#isResearching, Unit::getRemainingResearchTime, Unit::getTech. */
    public boolean research(TechType tech) {
        return research_native(pointer, tech);
    }

	/** Orders the unit to upgrade the given upgrade type.
	* \see Unit::cancelUpgrade, Unit::Unit#isUpgrading, Unit::getRemainingUpgradeTime, Unit::getUpgrade. */
    public boolean upgrade(UpgradeType upgrade) {
        return upgrade_native(pointer, upgrade);
    }

	/** Orders the unit to set its rally position to the specified position.
	* \see Unit::getRallyPosition, Unit::getRallyUnit. */
    public boolean setRallyPoint(Position target) {
        return setRallyPoint_native(pointer, target);
    }

	/** Orders the unit to set its rally unit to the specified unit.
	* \see Unit::setRallyPosition, Unit::getRallyPosition, Unit::getRallyUnit. */
    public boolean setRallyPoint(Unit target) {
        return setRallyPoint_native(pointer, target);
    }

	/** Orders the unit to move from its current position to the specified position.
	* \see Unit::isMoving.  */
    public boolean move(Position target) {
        return move_native(pointer, target);
    }

    public boolean move(Position target, boolean shiftQueueCommand) {
        return move_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the unit to patrol between its current position and the specified position.
	* \see Unit::isPatrolling.  */
    public boolean patrol(Position target) {
        return patrol_native(pointer, target);
    }

    public boolean patrol(Position target, boolean shiftQueueCommand) {
        return patrol_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the unit to hold its position.*/
    public boolean holdPosition() {
        return holdPosition_native(pointer);
    }

    public boolean holdPosition(boolean shiftQueueCommand) {
        return holdPosition_native(pointer, shiftQueueCommand);
    }

	/** Orders the unit to stop. */
    public boolean stop() {
        return stop_native(pointer);
    }

    public boolean stop(boolean shiftQueueCommand) {
        return stop_native(pointer, shiftQueueCommand);
    }

	/** Orders the unit to follow the specified unit.
	* \see Unit::isFollowing. */
    public boolean follow(Unit target) {
        return follow_native(pointer, target);
    }

    public boolean follow(Unit target, boolean shiftQueueCommand) {
        return follow_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the unit to gather the specified unit (must be mineral or refinery type).
	* \see Unit::isGatheringGas, Unit::isGatheringMinerals. */
    public boolean gather(Unit target) {
        return gather_native(pointer, target);
    }

    public boolean gather(Unit target, boolean shiftQueueCommand) {
        return gather_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the unit to return its cargo to a nearby resource depot such as a Command Center. Only
	* workers that are carrying minerals or gas can be ordered to return cargo.
	* \see Unit::isCarryingGas, Unit::isCarryingMinerals. */
    public boolean returnCargo() {
        return returnCargo_native(pointer);
    }

    public boolean returnCargo(boolean shiftQueueCommand) {
        return returnCargo_native(pointer, shiftQueueCommand);
    }

	/** Orders the unit to repair the specified unit. Only Terran SCVs can be ordered to repair, and the
	* target must be a mechanical Terran unit or building.
	* \see Unit::isRepairing. */
    public boolean repair(Unit target) {
        return repair_native(pointer, target);
    }

    public boolean repair(Unit target, boolean shiftQueueCommand) {
        return repair_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the unit to burrow. Either the unit must be a Zerg Lurker, or the unit must be a Zerg ground
	* unit and burrow tech must be researched.
	* \see: Unit::unburrow, Unit::isBurrowed. */
    public boolean burrow() {
        return burrow_native(pointer);
    }

	/** Orders the burrowed unit to unburrow.
	* \see: Unit::burrow, Unit::isBurrowed.
	* */
    public boolean unburrow() {
        return unburrow_native(pointer);
    }

	/** Orders the unit to cloak.
	* \see: Unit::decloak, Unit::isCloaked. */
    public boolean cloak() {
        return cloak_native(pointer);
    }

	/** Orders the unit to decloak.
	* \see: Unit::cloak, Unit::isCloaked. */
    public boolean decloak() {
        return decloak_native(pointer);
    }

	/** Orders the unit to siege. Note: unit must be a Terran siege tank.
	* \see Unit::unsiege, Unit::isSieged. */
    public boolean siege() {
        return siege_native(pointer);
    }

	/** Orders the unit to unsiege. Note: unit must be a Terran siege tank.
	* \see: Unit::unsiege, Unit::isSieged. */
    public boolean unsiege() {
        return unsiege_native(pointer);
    }

	/** Orders the unit to lift. Note: unit must be a Terran building that can be lifted.
	* \see Unit::land, Unit::isLifted.  */
    public boolean lift() {
        return lift_native(pointer);
    }

	/** Orders the unit to land. Note: unit must be a Terran building that is currently lifted.
	* \see Unit::lift, Unit::isLifted. */
    public boolean land(TilePosition target) {
        return land_native(pointer, target);
    }

	/** Orders the unit to load the target unit.
	* \see Unit::unload, Unit::unloadAll, Unit::getLoadedUnits, Unit:isLoaded. */
    public boolean load(Unit target) {
        return load_native(pointer, target);
    }

    public boolean load(Unit target, boolean shiftQueueCommand) {
        return load_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the unit to unload the target unit.
	* \see Unit::load, Unit::unloadAll, Unit::getLoadedUnits, Unit:isLoaded. */
    public boolean unload(Unit target) {
        return unload_native(pointer, target);
    }

	/** Orders the unit to unload all loaded units at the unit's current position.
	* \see Unit::load, Unit::unload, Unit::unloadAll, Unit::getLoadedUnits, Unit:isLoaded. */
    public boolean unloadAll() {
        return unloadAll_native(pointer);
    }

    public boolean unloadAll(boolean shiftQueueCommand) {
        return unloadAll_native(pointer, shiftQueueCommand);
    }

	/** Orders the unit to unload all loaded units at the specified location. Unit should be a Terran
	* Dropship, Protoss Shuttle, or Zerg Overlord. If the unit is a Terran Bunker, the units will be
	* unloaded right outside the bunker, like in the first version of unloadAll.
	* \see Unit::load, Unit::unload, Unit::unloadAll, Unit::getLoadedUnits, Unit:isLoaded. */
    public boolean unloadAll(Position target) {
        return unloadAll_native(pointer, target);
    }

    public boolean unloadAll(Position target, boolean shiftQueueCommand) {
        return unloadAll_native(pointer, target, shiftQueueCommand);
    }

	/** Works like the right click in the GUI. */
    public boolean rightClick(Position target) {
        return rightClick_native(pointer, target);
    }

    public boolean rightClick(Position target, boolean shiftQueueCommand) {
        return rightClick_native(pointer, target, shiftQueueCommand);
    }

	/** Works like the right click in the GUI. Right click on a mineral patch to order a worker to mine,
	* right click on an enemy to attack it. */
    public boolean rightClick(Unit target) {
        return rightClick_native(pointer, target);
    }

    public boolean rightClick(Unit target, boolean shiftQueueCommand) {
        return rightClick_native(pointer, target, shiftQueueCommand);
    }

	/** Orders the SCV to stop constructing the building, and the building is left in a partially complete
	* state until it is canceled, destroyed, or completed.
	* \see Unit::isConstructing. */
    public boolean haltConstruction() {
        return haltConstruction_native(pointer);
    }

	/** Orders the building to stop being constructed.
	* \see Unit::beingConstructed. */
    public boolean cancelConstruction() {
        return cancelConstruction_native(pointer);
    }

	/** Orders the unit to stop making the addon. */
    public boolean cancelAddon() {
        return cancelAddon_native(pointer);
    }

	/** Orders the unit to remove the specified unit from its training queue.
	* \see Unit::train, Unit::cancelTrain, Unit::isTraining, Unit::getTrainingQueue. */
    public boolean cancelTrain() {
        return cancelTrain_native(pointer);
    }

    public boolean cancelTrain(int slot) {
        return cancelTrain_native(pointer, slot);
    }

	/** Orders the unit to stop morphing.
	* \see Unit::morph, Unit::isMorphing. */
    public boolean cancelMorph() {
        return cancelMorph_native(pointer);
    }

	/** Orders the unit to cancel a research in progress.
	* \see Unit::research, Unit::isResearching, Unit::getTech. */
    public boolean cancelResearch() {
        return cancelResearch_native(pointer);
    }

	/** Orders the unit to cancel an upgrade in progress.
	* \see Unit::upgrade, Unit::isUpgrading, Unit::getUpgrade. */
    public boolean cancelUpgrade() {
        return cancelUpgrade_native(pointer);
    }

	/** Orders the unit to use a tech not requiring a target (ie Stim Pack). Returns true if it is a valid
	* tech. */
    public boolean useTech(TechType tech) {
        return useTech_native(pointer, tech);
    }

	/** Orders the unit to use a tech requiring a position target (ie Dark Swarm). Returns true if it is a
	* valid tech.*/
    public boolean useTech(TechType tech, Position target) {
        return useTech_native(pointer, tech, target);
    }

	/** Orders the unit to use a tech requiring a unit target (ie Irradiate). Returns true if it is a valid
	* tech.*/
    public boolean useTech(TechType tech, Unit target) {
        return useTech_native(pointer, tech, target);
    }

	/** Moves a Flag Beacon to the target location. */
    public boolean placeCOP(TilePosition target) {
        return placeCOP_native(pointer, target);
    }


    private static Map<Long, Unit> instances = new HashMap<Long, Unit>();

    private Unit(long pointer) {
        this.pointer = pointer;
    }

    private static Unit get(long pointer) {
        Unit instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Unit(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native int getID_native(long pointer);

    private native int getReplayID_native(long pointer);

    private native Player getPlayer_native(long pointer);

    private native UnitType getType_native(long pointer);

    private native Position getPosition_native(long pointer);

    private native TilePosition getTilePosition_native(long pointer);

    private native double getAngle_native(long pointer);

    private native double getVelocityX_native(long pointer);

    private native double getVelocityY_native(long pointer);

    private native Region getRegion_native(long pointer);

    private native int getLeft_native(long pointer);

    private native int getTop_native(long pointer);

    private native int getRight_native(long pointer);

    private native int getBottom_native(long pointer);

    private native int getHitPoints_native(long pointer);

    private native int getShields_native(long pointer);

    private native int getEnergy_native(long pointer);

    private native int getResources_native(long pointer);

    private native int getResourceGroup_native(long pointer);

    private native int getDistance_native(long pointer, Unit target);

    private native int getDistance_native(long pointer, Position target);

    private native boolean hasPath_native(long pointer, Unit target);

    private native boolean hasPath_native(long pointer, Position target);

    private native int getLastCommandFrame_native(long pointer);

    private native Player getLastAttackingPlayer_native(long pointer);

    private native int getUpgradeLevel_native(long pointer, UpgradeType upgrade);

    private native UnitType getInitialType_native(long pointer);

    private native Position getInitialPosition_native(long pointer);

    private native TilePosition getInitialTilePosition_native(long pointer);

    private native int getInitialHitPoints_native(long pointer);

    private native int getInitialResources_native(long pointer);

    private native int getKillCount_native(long pointer);

    private native int getAcidSporeCount_native(long pointer);

    private native int getInterceptorCount_native(long pointer);

    private native int getScarabCount_native(long pointer);

    private native int getSpiderMineCount_native(long pointer);

    private native int getGroundWeaponCooldown_native(long pointer);

    private native int getAirWeaponCooldown_native(long pointer);

    private native int getSpellCooldown_native(long pointer);

    private native int getDefenseMatrixPoints_native(long pointer);

    private native int getDefenseMatrixTimer_native(long pointer);

    private native int getEnsnareTimer_native(long pointer);

    private native int getIrradiateTimer_native(long pointer);

    private native int getLockdownTimer_native(long pointer);

    private native int getMaelstromTimer_native(long pointer);

    private native int getOrderTimer_native(long pointer);

    private native int getPlagueTimer_native(long pointer);

    private native int getRemoveTimer_native(long pointer);

    private native int getStasisTimer_native(long pointer);

    private native int getStimTimer_native(long pointer);

    private native UnitType getBuildType_native(long pointer);

    private native TechType getTech_native(long pointer);

    private native UpgradeType getUpgrade_native(long pointer);

    private native int getRemainingBuildTime_native(long pointer);

    private native int getRemainingTrainTime_native(long pointer);

    private native int getRemainingResearchTime_native(long pointer);

    private native int getRemainingUpgradeTime_native(long pointer);

    private native Unit getBuildUnit_native(long pointer);

    private native Unit getTarget_native(long pointer);

    private native Position getTargetPosition_native(long pointer);

    private native Order getOrder_native(long pointer);

    private native Order getSecondaryOrder_native(long pointer);

    private native Unit getOrderTarget_native(long pointer);

    private native Position getOrderTargetPosition_native(long pointer);

    private native Position getRallyPosition_native(long pointer);

    private native Unit getRallyUnit_native(long pointer);

    private native Unit getAddon_native(long pointer);

    private native Unit getNydusExit_native(long pointer);

    private native Unit getPowerUp_native(long pointer);

    private native Unit getTransport_native(long pointer);

    private native List<Unit> getLoadedUnits_native(long pointer);

    private native Unit getCarrier_native(long pointer);

    private native List<Unit> getInterceptors_native(long pointer);

    private native Unit getHatchery_native(long pointer);

    private native List<Unit> getLarva_native(long pointer);

    private native List<Unit> getUnitsInRadius_native(long pointer, int radius);

    private native List<Unit> getUnitsInWeaponRange_native(long pointer, WeaponType weapon);

    private native boolean exists_native(long pointer);

    private native boolean hasNuke_native(long pointer);

    private native boolean isAccelerating_native(long pointer);

    private native boolean isAttacking_native(long pointer);

    private native boolean isAttackFrame_native(long pointer);

    private native boolean isBeingConstructed_native(long pointer);

    private native boolean isBeingGathered_native(long pointer);

    private native boolean isBeingHealed_native(long pointer);

    private native boolean isBlind_native(long pointer);

    private native boolean isBraking_native(long pointer);

    private native boolean isBurrowed_native(long pointer);

    private native boolean isCarryingGas_native(long pointer);

    private native boolean isCarryingMinerals_native(long pointer);

    private native boolean isCloaked_native(long pointer);

    private native boolean isCompleted_native(long pointer);

    private native boolean isConstructing_native(long pointer);

    private native boolean isDefenseMatrixed_native(long pointer);

    private native boolean isDetected_native(long pointer);

    private native boolean isEnsnared_native(long pointer);

    private native boolean isFollowing_native(long pointer);

    private native boolean isGatheringGas_native(long pointer);

    private native boolean isGatheringMinerals_native(long pointer);

    private native boolean isHallucination_native(long pointer);

    private native boolean isHoldingPosition_native(long pointer);

    private native boolean isIdle_native(long pointer);

    private native boolean isInterruptible_native(long pointer);

    private native boolean isInvincible_native(long pointer);

    private native boolean isInWeaponRange_native(long pointer, Unit target);

    private native boolean isIrradiated_native(long pointer);

    private native boolean isLifted_native(long pointer);

    private native boolean isLoaded_native(long pointer);

    private native boolean isLockedDown_native(long pointer);

    private native boolean isMaelstrommed_native(long pointer);

    private native boolean isMorphing_native(long pointer);

    private native boolean isMoving_native(long pointer);

    private native boolean isParasited_native(long pointer);

    private native boolean isPatrolling_native(long pointer);

    private native boolean isPlagued_native(long pointer);

    private native boolean isRepairing_native(long pointer);

    private native boolean isResearching_native(long pointer);

    private native boolean isSelected_native(long pointer);

    private native boolean isSieged_native(long pointer);

    private native boolean isStartingAttack_native(long pointer);

    private native boolean isStasised_native(long pointer);

    private native boolean isStimmed_native(long pointer);

    private native boolean isStuck_native(long pointer);

    private native boolean isTraining_native(long pointer);

    private native boolean isUnderAttack_native(long pointer);

    private native boolean isUnderDarkSwarm_native(long pointer);

    private native boolean isUnderDisruptionWeb_native(long pointer);

    private native boolean isUnderStorm_native(long pointer);

    private native boolean isUnpowered_native(long pointer);

    private native boolean isUpgrading_native(long pointer);

    private native boolean isVisible_native(long pointer);

    private native boolean isVisible_native(long pointer, Player player);

    private native boolean canIssueCommand_native(long pointer, UnitCommand command);

    private native boolean issueCommand_native(long pointer, UnitCommand command);

    private native boolean attack_native(long pointer, Position target);

    private native boolean attack_native(long pointer, Position target, boolean shiftQueueCommand);

    private native boolean attack_native(long pointer, Unit target);

    private native boolean attack_native(long pointer, Unit target, boolean shiftQueueCommand);

    private native boolean build_native(long pointer, TilePosition target, UnitType type);

    private native boolean buildAddon_native(long pointer, UnitType type);

    private native boolean train_native(long pointer, UnitType type);

    private native boolean morph_native(long pointer, UnitType type);

    private native boolean research_native(long pointer, TechType tech);

    private native boolean upgrade_native(long pointer, UpgradeType upgrade);

    private native boolean setRallyPoint_native(long pointer, Position target);

    private native boolean setRallyPoint_native(long pointer, Unit target);

    private native boolean move_native(long pointer, Position target);

    private native boolean move_native(long pointer, Position target, boolean shiftQueueCommand);

    private native boolean patrol_native(long pointer, Position target);

    private native boolean patrol_native(long pointer, Position target, boolean shiftQueueCommand);

    private native boolean holdPosition_native(long pointer);

    private native boolean holdPosition_native(long pointer, boolean shiftQueueCommand);

    private native boolean stop_native(long pointer);

    private native boolean stop_native(long pointer, boolean shiftQueueCommand);

    private native boolean follow_native(long pointer, Unit target);

    private native boolean follow_native(long pointer, Unit target, boolean shiftQueueCommand);

    private native boolean gather_native(long pointer, Unit target);

    private native boolean gather_native(long pointer, Unit target, boolean shiftQueueCommand);

    private native boolean returnCargo_native(long pointer);

    private native boolean returnCargo_native(long pointer, boolean shiftQueueCommand);

    private native boolean repair_native(long pointer, Unit target);

    private native boolean repair_native(long pointer, Unit target, boolean shiftQueueCommand);

    private native boolean burrow_native(long pointer);

    private native boolean unburrow_native(long pointer);

    private native boolean cloak_native(long pointer);

    private native boolean decloak_native(long pointer);

    private native boolean siege_native(long pointer);

    private native boolean unsiege_native(long pointer);

    private native boolean lift_native(long pointer);

    private native boolean land_native(long pointer, TilePosition target);

    private native boolean load_native(long pointer, Unit target);

    private native boolean load_native(long pointer, Unit target, boolean shiftQueueCommand);

    private native boolean unload_native(long pointer, Unit target);

    private native boolean unloadAll_native(long pointer);

    private native boolean unloadAll_native(long pointer, boolean shiftQueueCommand);

    private native boolean unloadAll_native(long pointer, Position target);

    private native boolean unloadAll_native(long pointer, Position target, boolean shiftQueueCommand);

    private native boolean rightClick_native(long pointer, Position target);

    private native boolean rightClick_native(long pointer, Position target, boolean shiftQueueCommand);

    private native boolean rightClick_native(long pointer, Unit target);

    private native boolean rightClick_native(long pointer, Unit target, boolean shiftQueueCommand);

    private native boolean haltConstruction_native(long pointer);

    private native boolean cancelConstruction_native(long pointer);

    private native boolean cancelAddon_native(long pointer);

    private native boolean cancelTrain_native(long pointer);

    private native boolean cancelTrain_native(long pointer, int slot);

    private native boolean cancelMorph_native(long pointer);

    private native boolean cancelResearch_native(long pointer);

    private native boolean cancelUpgrade_native(long pointer);

    private native boolean useTech_native(long pointer, TechType tech);

    private native boolean useTech_native(long pointer, TechType tech, Position target);

    private native boolean useTech_native(long pointer, TechType tech, Unit target);

    private native boolean placeCOP_native(long pointer, TilePosition target);


}
