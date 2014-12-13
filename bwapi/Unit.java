package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;
import bwapi.PositionedObject;

public class Unit extends PositionedObject 
{

    public int getID() {
        return getID_native(pointer);
    }

    public int getReplayID() {
        return getReplayID_native(pointer);
    }

    public Player getPlayer() {
        return getPlayer_native(pointer);
    }

    public UnitType getType() {
        return getType_native(pointer);
    }

    public Position getPosition() {
        return getPosition_native(pointer);
    }

    public TilePosition getTilePosition() {
        return getTilePosition_native(pointer);
    }

    public double getAngle() {
        return getAngle_native(pointer);
    }

    public double getVelocityX() {
        return getVelocityX_native(pointer);
    }

    public double getVelocityY() {
        return getVelocityY_native(pointer);
    }

    public Region getRegion() {
        return getRegion_native(pointer);
    }

    public int getLeft() {
        return getLeft_native(pointer);
    }

    public int getTop() {
        return getTop_native(pointer);
    }

    public int getRight() {
        return getRight_native(pointer);
    }

    public int getBottom() {
        return getBottom_native(pointer);
    }

    public int getHitPoints() {
        return getHitPoints_native(pointer);
    }

    public int getShields() {
        return getShields_native(pointer);
    }

    public int getEnergy() {
        return getEnergy_native(pointer);
    }

    public int getResources() {
        return getResources_native(pointer);
    }

    public int getResourceGroup() {
        return getResourceGroup_native(pointer);
    }

    public int getDistance(Unit target) {
        return getDistance_native(pointer, target);
    }

    public int getDistance(Position target) {
        return getDistance_native(pointer, target);
    }

    public boolean hasPath(Unit target) {
        return hasPath_native(pointer, target);
    }

    public boolean hasPath(Position target) {
        return hasPath_native(pointer, target);
    }

    public int getLastCommandFrame() {
        return getLastCommandFrame_native(pointer);
    }

    public Player getLastAttackingPlayer() {
        return getLastAttackingPlayer_native(pointer);
    }

    public int getUpgradeLevel(UpgradeType upgrade) {
        return getUpgradeLevel_native(pointer, upgrade);
    }

    public UnitType getInitialType() {
        return getInitialType_native(pointer);
    }

    public Position getInitialPosition() {
        return getInitialPosition_native(pointer);
    }

    public TilePosition getInitialTilePosition() {
        return getInitialTilePosition_native(pointer);
    }

    public int getInitialHitPoints() {
        return getInitialHitPoints_native(pointer);
    }

    public int getInitialResources() {
        return getInitialResources_native(pointer);
    }

    public int getKillCount() {
        return getKillCount_native(pointer);
    }

    public int getAcidSporeCount() {
        return getAcidSporeCount_native(pointer);
    }

    public int getInterceptorCount() {
        return getInterceptorCount_native(pointer);
    }

    public int getScarabCount() {
        return getScarabCount_native(pointer);
    }

    public int getSpiderMineCount() {
        return getSpiderMineCount_native(pointer);
    }

    public int getGroundWeaponCooldown() {
        return getGroundWeaponCooldown_native(pointer);
    }

    public int getAirWeaponCooldown() {
        return getAirWeaponCooldown_native(pointer);
    }

    public int getSpellCooldown() {
        return getSpellCooldown_native(pointer);
    }

    public int getDefenseMatrixPoints() {
        return getDefenseMatrixPoints_native(pointer);
    }

    public int getDefenseMatrixTimer() {
        return getDefenseMatrixTimer_native(pointer);
    }

    public int getEnsnareTimer() {
        return getEnsnareTimer_native(pointer);
    }

    public int getIrradiateTimer() {
        return getIrradiateTimer_native(pointer);
    }

    public int getLockdownTimer() {
        return getLockdownTimer_native(pointer);
    }

    public int getMaelstromTimer() {
        return getMaelstromTimer_native(pointer);
    }

    public int getOrderTimer() {
        return getOrderTimer_native(pointer);
    }

    public int getPlagueTimer() {
        return getPlagueTimer_native(pointer);
    }

    public int getRemoveTimer() {
        return getRemoveTimer_native(pointer);
    }

    public int getStasisTimer() {
        return getStasisTimer_native(pointer);
    }

    public int getStimTimer() {
        return getStimTimer_native(pointer);
    }

    public UnitType getBuildType() {
        return getBuildType_native(pointer);
    }

    public TechType getTech() {
        return getTech_native(pointer);
    }

    public UpgradeType getUpgrade() {
        return getUpgrade_native(pointer);
    }

    public int getRemainingBuildTime() {
        return getRemainingBuildTime_native(pointer);
    }

    public int getRemainingTrainTime() {
        return getRemainingTrainTime_native(pointer);
    }

    public int getRemainingResearchTime() {
        return getRemainingResearchTime_native(pointer);
    }

    public int getRemainingUpgradeTime() {
        return getRemainingUpgradeTime_native(pointer);
    }

    public Unit getBuildUnit() {
        return getBuildUnit_native(pointer);
    }

    public Unit getTarget() {
        return getTarget_native(pointer);
    }

    public Position getTargetPosition() {
        return getTargetPosition_native(pointer);
    }

    public Order getOrder() {
        return getOrder_native(pointer);
    }

    public Order getSecondaryOrder() {
        return getSecondaryOrder_native(pointer);
    }

    public Unit getOrderTarget() {
        return getOrderTarget_native(pointer);
    }

    public Position getOrderTargetPosition() {
        return getOrderTargetPosition_native(pointer);
    }

    public Position getRallyPosition() {
        return getRallyPosition_native(pointer);
    }

    public Unit getRallyUnit() {
        return getRallyUnit_native(pointer);
    }

    public Unit getAddon() {
        return getAddon_native(pointer);
    }

    public Unit getNydusExit() {
        return getNydusExit_native(pointer);
    }

    public Unit getPowerUp() {
        return getPowerUp_native(pointer);
    }

    public Unit getTransport() {
        return getTransport_native(pointer);
    }

    public List<Unit> getLoadedUnits() {
        return getLoadedUnits_native(pointer);
    }

    public Unit getCarrier() {
        return getCarrier_native(pointer);
    }

    public List<Unit> getInterceptors() {
        return getInterceptors_native(pointer);
    }

    public Unit getHatchery() {
        return getHatchery_native(pointer);
    }

    public List<Unit> getLarva() {
        return getLarva_native(pointer);
    }

    public List<Unit> getUnitsInRadius(int radius) {
        return getUnitsInRadius_native(pointer, radius);
    }

    public List<Unit> getUnitsInWeaponRange(WeaponType weapon) {
        return getUnitsInWeaponRange_native(pointer, weapon);
    }

    public boolean exists() {
        return exists_native(pointer);
    }

    public boolean hasNuke() {
        return hasNuke_native(pointer);
    }

    public boolean isAccelerating() {
        return isAccelerating_native(pointer);
    }

    public boolean isAttacking() {
        return isAttacking_native(pointer);
    }

    public boolean isAttackFrame() {
        return isAttackFrame_native(pointer);
    }

    public boolean isBeingConstructed() {
        return isBeingConstructed_native(pointer);
    }

    public boolean isBeingGathered() {
        return isBeingGathered_native(pointer);
    }

    public boolean isBeingHealed() {
        return isBeingHealed_native(pointer);
    }

    public boolean isBlind() {
        return isBlind_native(pointer);
    }

    public boolean isBraking() {
        return isBraking_native(pointer);
    }

    public boolean isBurrowed() {
        return isBurrowed_native(pointer);
    }

    public boolean isCarryingGas() {
        return isCarryingGas_native(pointer);
    }

    public boolean isCarryingMinerals() {
        return isCarryingMinerals_native(pointer);
    }

    public boolean isCloaked() {
        return isCloaked_native(pointer);
    }

    public boolean isCompleted() {
        return isCompleted_native(pointer);
    }

    public boolean isConstructing() {
        return isConstructing_native(pointer);
    }

    public boolean isDefenseMatrixed() {
        return isDefenseMatrixed_native(pointer);
    }

    public boolean isDetected() {
        return isDetected_native(pointer);
    }

    public boolean isEnsnared() {
        return isEnsnared_native(pointer);
    }

    public boolean isFollowing() {
        return isFollowing_native(pointer);
    }

    public boolean isGatheringGas() {
        return isGatheringGas_native(pointer);
    }

    public boolean isGatheringMinerals() {
        return isGatheringMinerals_native(pointer);
    }

    public boolean isHallucination() {
        return isHallucination_native(pointer);
    }

    public boolean isHoldingPosition() {
        return isHoldingPosition_native(pointer);
    }

    public boolean isIdle() {
        return isIdle_native(pointer);
    }

    public boolean isInterruptible() {
        return isInterruptible_native(pointer);
    }

    public boolean isInvincible() {
        return isInvincible_native(pointer);
    }

    public boolean isInWeaponRange(Unit target) {
        return isInWeaponRange_native(pointer, target);
    }

    public boolean isIrradiated() {
        return isIrradiated_native(pointer);
    }

    public boolean isLifted() {
        return isLifted_native(pointer);
    }

    public boolean isLoaded() {
        return isLoaded_native(pointer);
    }

    public boolean isLockedDown() {
        return isLockedDown_native(pointer);
    }

    public boolean isMaelstrommed() {
        return isMaelstrommed_native(pointer);
    }

    public boolean isMorphing() {
        return isMorphing_native(pointer);
    }

    public boolean isMoving() {
        return isMoving_native(pointer);
    }

    public boolean isParasited() {
        return isParasited_native(pointer);
    }

    public boolean isPatrolling() {
        return isPatrolling_native(pointer);
    }

    public boolean isPlagued() {
        return isPlagued_native(pointer);
    }

    public boolean isRepairing() {
        return isRepairing_native(pointer);
    }

    public boolean isResearching() {
        return isResearching_native(pointer);
    }

    public boolean isSelected() {
        return isSelected_native(pointer);
    }

    public boolean isSieged() {
        return isSieged_native(pointer);
    }

    public boolean isStartingAttack() {
        return isStartingAttack_native(pointer);
    }

    public boolean isStasised() {
        return isStasised_native(pointer);
    }

    public boolean isStimmed() {
        return isStimmed_native(pointer);
    }

    public boolean isStuck() {
        return isStuck_native(pointer);
    }

    public boolean isTraining() {
        return isTraining_native(pointer);
    }

    public boolean isUnderAttack() {
        return isUnderAttack_native(pointer);
    }

    public boolean isUnderDarkSwarm() {
        return isUnderDarkSwarm_native(pointer);
    }

    public boolean isUnderDisruptionWeb() {
        return isUnderDisruptionWeb_native(pointer);
    }

    public boolean isUnderStorm() {
        return isUnderStorm_native(pointer);
    }

    public boolean isUnpowered() {
        return isUnpowered_native(pointer);
    }

    public boolean isUpgrading() {
        return isUpgrading_native(pointer);
    }

    public boolean isVisible() {
        return isVisible_native(pointer);
    }

    public boolean isVisible(Player player) {
        return isVisible_native(pointer, player);
    }

    public boolean canIssueCommand(UnitCommand command) {
        return canIssueCommand_native(pointer, command);
    }

    public boolean issueCommand(UnitCommand command) {
        return issueCommand_native(pointer, command);
    }

    public boolean attack(Position target) {
        return attack_native(pointer, target);
    }

    public boolean attack(Position target, boolean shiftQueueCommand) {
        return attack_native(pointer, target, shiftQueueCommand);
    }

    public boolean attack(Unit target) {
        return attack_native(pointer, target);
    }

    public boolean attack(Unit target, boolean shiftQueueCommand) {
        return attack_native(pointer, target, shiftQueueCommand);
    }

    public boolean build(TilePosition target, UnitType type) {
        return build_native(pointer, target, type);
    }

    public boolean buildAddon(UnitType type) {
        return buildAddon_native(pointer, type);
    }

    public boolean train(UnitType type) {
        return train_native(pointer, type);
    }

    public boolean morph(UnitType type) {
        return morph_native(pointer, type);
    }

    public boolean research(TechType tech) {
        return research_native(pointer, tech);
    }

    public boolean upgrade(UpgradeType upgrade) {
        return upgrade_native(pointer, upgrade);
    }

    public boolean setRallyPoint(Position target) {
        return setRallyPoint_native(pointer, target);
    }

    public boolean setRallyPoint(Unit target) {
        return setRallyPoint_native(pointer, target);
    }

    public boolean move(Position target) {
        return move_native(pointer, target);
    }

    public boolean move(Position target, boolean shiftQueueCommand) {
        return move_native(pointer, target, shiftQueueCommand);
    }

    public boolean patrol(Position target) {
        return patrol_native(pointer, target);
    }

    public boolean patrol(Position target, boolean shiftQueueCommand) {
        return patrol_native(pointer, target, shiftQueueCommand);
    }

    public boolean holdPosition() {
        return holdPosition_native(pointer);
    }

    public boolean holdPosition(boolean shiftQueueCommand) {
        return holdPosition_native(pointer, shiftQueueCommand);
    }

    public boolean stop() {
        return stop_native(pointer);
    }

    public boolean stop(boolean shiftQueueCommand) {
        return stop_native(pointer, shiftQueueCommand);
    }

    public boolean follow(Unit target) {
        return follow_native(pointer, target);
    }

    public boolean follow(Unit target, boolean shiftQueueCommand) {
        return follow_native(pointer, target, shiftQueueCommand);
    }

    public boolean gather(Unit target) {
        return gather_native(pointer, target);
    }

    public boolean gather(Unit target, boolean shiftQueueCommand) {
        return gather_native(pointer, target, shiftQueueCommand);
    }

    public boolean returnCargo() {
        return returnCargo_native(pointer);
    }

    public boolean returnCargo(boolean shiftQueueCommand) {
        return returnCargo_native(pointer, shiftQueueCommand);
    }

    public boolean repair(Unit target) {
        return repair_native(pointer, target);
    }

    public boolean repair(Unit target, boolean shiftQueueCommand) {
        return repair_native(pointer, target, shiftQueueCommand);
    }

    public boolean burrow() {
        return burrow_native(pointer);
    }

    public boolean unburrow() {
        return unburrow_native(pointer);
    }

    public boolean cloak() {
        return cloak_native(pointer);
    }

    public boolean decloak() {
        return decloak_native(pointer);
    }

    public boolean siege() {
        return siege_native(pointer);
    }

    public boolean unsiege() {
        return unsiege_native(pointer);
    }

    public boolean lift() {
        return lift_native(pointer);
    }

    public boolean land(TilePosition target) {
        return land_native(pointer, target);
    }

    public boolean load(Unit target) {
        return load_native(pointer, target);
    }

    public boolean load(Unit target, boolean shiftQueueCommand) {
        return load_native(pointer, target, shiftQueueCommand);
    }

    public boolean unload(Unit target) {
        return unload_native(pointer, target);
    }

    public boolean unloadAll() {
        return unloadAll_native(pointer);
    }

    public boolean unloadAll(boolean shiftQueueCommand) {
        return unloadAll_native(pointer, shiftQueueCommand);
    }

    public boolean unloadAll(Position target) {
        return unloadAll_native(pointer, target);
    }

    public boolean unloadAll(Position target, boolean shiftQueueCommand) {
        return unloadAll_native(pointer, target, shiftQueueCommand);
    }

    public boolean rightClick(Position target) {
        return rightClick_native(pointer, target);
    }

    public boolean rightClick(Position target, boolean shiftQueueCommand) {
        return rightClick_native(pointer, target, shiftQueueCommand);
    }

    public boolean rightClick(Unit target) {
        return rightClick_native(pointer, target);
    }

    public boolean rightClick(Unit target, boolean shiftQueueCommand) {
        return rightClick_native(pointer, target, shiftQueueCommand);
    }

    public boolean haltConstruction() {
        return haltConstruction_native(pointer);
    }

    public boolean cancelConstruction() {
        return cancelConstruction_native(pointer);
    }

    public boolean cancelAddon() {
        return cancelAddon_native(pointer);
    }

    public boolean cancelTrain() {
        return cancelTrain_native(pointer);
    }

    public boolean cancelTrain(int slot) {
        return cancelTrain_native(pointer, slot);
    }

    public boolean cancelMorph() {
        return cancelMorph_native(pointer);
    }

    public boolean cancelResearch() {
        return cancelResearch_native(pointer);
    }

    public boolean cancelUpgrade() {
        return cancelUpgrade_native(pointer);
    }

    public boolean useTech(TechType tech) {
        return useTech_native(pointer, tech);
    }

    public boolean useTech(TechType tech, Position target) {
        return useTech_native(pointer, tech, target);
    }

    public boolean useTech(TechType tech, Unit target) {
        return useTech_native(pointer, tech, target);
    }

    public boolean placeCOP(TilePosition target) {
        return placeCOP_native(pointer, target);
    }


    private static Map<Long, Unit> instances = new HashMap<Long, Unit>();

    private Unit(long pointer) {
        this.pointer = pointer;
    }

    private static Unit get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
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
