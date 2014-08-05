package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
Events correspond to <a href="AIModule.html">AIModule</a> callbacks and can be obtained by calling <a href="Game.html">Game::getEvents</a>.


*/
public class Event {

/**
Returns the Position. Used in EventType::NukeDetect.

*/
    public Position getPosition() {
        return getPosition_native(pointer);
    }

/**
Returns the text. Used in EventType::SendText, EventType::ReceiveText, EventType::SaveGame.

*/
    public String getText() {
        return getText_native(pointer);
    }

/**
Returns the unit. Used in EventType::UnitDiscover, EventType::UnitEvade, EventType::UnitCreate, EventType::UnitDestroy, EventType::UnitShow, EventType::UnitHide, EventType::UnitMorph, EventType::UnitRenegade, and EventType::UnitComplete.

*/
    public Unit getUnit() {
        return getUnit_native(pointer);
    }

/**
Returns the player. Used in EventType::ReceiveText and EventType::PlayerLeft.

*/
    public Player getPlayer() {
        return getPlayer_native(pointer);
    }

/**
Returns true if the BWAPI-controlled player is the winner. Used in EventType::MatchEnd.

*/
    public boolean isWinner() {
        return isWinner_native(pointer);
    }


    private static Map<Long, Event> instances = new HashMap<Long, Event>();

    private Event(long pointer) {
        this.pointer = pointer;
    }

    private static Event get(long pointer) {
        Event instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Event(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native Position getPosition_native(long pointer);

    private native String getText_native(long pointer);

    private native Unit getUnit_native(long pointer);

    private native Player getPlayer_native(long pointer);

    private native boolean isWinner_native(long pointer);


}
