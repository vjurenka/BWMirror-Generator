package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
The Region class provides access to some of Broodwar's pathing information and offers members that can assist in navigation, scouting, construction, and information for key areas such as chokepoints. Though not always accurate, it is a lightweight alternative to BWTA that beginners can start with.
These regions are not so advanced as to cover everything up to a choke point with accurate polygons, but instead are small clusters of tiles connected to each other, kind of like a honeycomb.


*/
public class Region {

	/** Returns the unique ID for this region assigned by Broodwar. */
    public int getID() {
        return getID_native(pointer);
    }

	/** Returns an ID for the body of land that this region belongs to. */
    public int getRegionGroupID() {
        return getRegionGroupID_native(pointer);
    }

	/** Retrieves the center of the region. */
    public Position getCenter() {
        return getCenter_native(pointer);
    }

	/** Returns true if this region belongs to strategic higher ground, assigned by Broodwar. */
    public boolean isHigherGround() {
        return isHigherGround_native(pointer);
    }

	/** Returns a value representing the strategic advantage of this region according to Broodwar. */
    public int getDefensePriority() {
        return getDefensePriority_native(pointer);
    }

	/** Returns true if the region can be walked on by ground units. */
    public boolean isWalkable() {
        return isWalkable_native(pointer);
    }

	/** Retrieves the set of neighbors that this region is connected to. */
    public int getBoundsLeft() {
        return getBoundsLeft_native(pointer);
    }

/**


*/
    public int getBoundsTop() {
        return getBoundsTop_native(pointer);
    }

/**


*/
    public int getBoundsRight() {
        return getBoundsRight_native(pointer);
    }

/**


*/
    public int getBoundsBottom() {
        return getBoundsBottom_native(pointer);
    }

	/** Retrieves the closest accessable neighbor region. */
    public Region getClosestAccessibleRegion() {
        return getClosestAccessibleRegion_native(pointer);
    }

	/** Retrieves the closest inaccessable neighbor region. */
    public Region getClosestInaccessibleRegion() {
        return getClosestInaccessibleRegion_native(pointer);
    }

	/** Retrieves the center-to-center distance between two regions. */
    public int getDistance(Region other) {
        return getDistance_native(pointer, other);
    }


    private static Map<Long, Region> instances = new HashMap<Long, Region>();

    private Region(long pointer) {
        this.pointer = pointer;
    }

    private static Region get(long pointer) {
        Region instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Region(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native int getID_native(long pointer);

    private native int getRegionGroupID_native(long pointer);

    private native Position getCenter_native(long pointer);

    private native boolean isHigherGround_native(long pointer);

    private native int getDefensePriority_native(long pointer);

    private native boolean isWalkable_native(long pointer);

    private native int getBoundsLeft_native(long pointer);

    private native int getBoundsTop_native(long pointer);

    private native int getBoundsRight_native(long pointer);

    private native int getBoundsBottom_native(long pointer);

    private native Region getClosestAccessibleRegion_native(long pointer);

    private native Region getClosestInaccessibleRegion_native(long pointer);

    private native int getDistance_native(long pointer, Region other);


}
