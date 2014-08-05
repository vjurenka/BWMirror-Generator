package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

	/** The Force class is used to get information about each force in the match, such as the name of the force
	* and the set of players in the force. */
public class Force {

	/** Returns a unique ID for the force. */
    public int getID() {
        return getID_native(pointer);
    }

	/** Returns the name of the force. */
    public String getName() {
        return getName_native(pointer);
    }

	/** Returns the set of players in the force. */
    public List<Player> getPlayers() {
        return getPlayers_native(pointer);
    }


    private static Map<Long, Force> instances = new HashMap<Long, Force>();

    private Force(long pointer) {
        this.pointer = pointer;
    }

    private static Force get(long pointer) {
        Force instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Force(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native int getID_native(long pointer);

    private native String getName_native(long pointer);

    private native List<Player> getPlayers_native(long pointer);


}
