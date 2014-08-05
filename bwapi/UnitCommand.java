package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
<a href="UnitCommand.html">UnitCommand</a> objects are currently used only as arguments to one function - <a href="Unit.html">Unit::issueCommand</a>. While units can be issued commands the normal way via the <a href="Unit.html">Unit</a> methods (i.e. <a href="Unit.html">Unit::attack</a>), in some cases you may want to have a function that can process any unit command, such as when you're writing a proxy for BWAPI.


*/
public class UnitCommand {

/**
Returns the type of the command

*/
    public UnitCommandType getType() {
        return getType_native(pointer);
    }


    private static Map<Long, UnitCommand> instances = new HashMap<Long, UnitCommand>();

    private UnitCommand(long pointer) {
        this.pointer = pointer;
    }

    private static UnitCommand get(long pointer) {
        UnitCommand instance = instances.get(pointer);
        if (instance == null ) {
            instance = new UnitCommand(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native UnitCommandType getType_native(long pointer);


}
