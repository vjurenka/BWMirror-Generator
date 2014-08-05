package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
The Client class manages the connection between a BWAPI client program and the BWAPI server running in BWAPI.dll. For examples of how to use this class please see the Example AI Client and the AI Module Loader that are included in the latest release of BWAPI.
The BWAPIClient.lib library contains the implementation of the Client class along with classes which implement the <a href="Game.html">Game</a>, <a href="Force.html">Force</a>, <a href="Player.html">Player</a>, <a href="Unit.html">Unit</a>, and <a href="Bullet.html">Bullet</a> interfaces.
Stand-alone programs made with BWAPIClient should keep all interaction with dynamic BWAPI classes (Game, Force, Player, Unit, Bullet) in a single thread that runs synchronously with Starcraft: Broodwar via calls to <a href="update.html">update()</a>.


*/
public class Client {

/**
Returns true if the client is currently connected to the server.

*/
    public boolean isConnected() {
        return isConnected_native(pointer);
    }

/**
Attempts to connect the client to the server. If it succeeds, it returns true. If Starcraft/BWAPI is not yet running, this will fail and return false.

*/
    public boolean connect() {
        return connect_native(pointer);
    }

/**
Disconnects the client from the server.

*/
    public void disconnect() {
        disconnect_native(pointer);
    }

/**
This is a blocking command that tells the server to process commands sent from the client and proceed to the next frame in the game. Thus update() will only return once the next game frame (or if in menus, next menu frame) has been received. Once the server proceeds to the next frame, the client will update some local information and then return so the AI can execute its code for the current frame. Rather than sending callbacks to the client for things like <a href="AIModule.html">AIModule::onUnitCreate</a>, BWAPI generates a list of event objects, which can be accessed via <a href="Game.html">Game::getEvents</a>. These events correspond to AIModule callbacks.

*/
    public void update() {
        update_native(pointer);
    }


    private static Map<Long, Client> instances = new HashMap<Long, Client>();

    private Client(long pointer) {
        this.pointer = pointer;
    }

    private static Client get(long pointer) {
        Client instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Client(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native boolean isConnected_native(long pointer);

    private native boolean connect_native(long pointer);

    private native void disconnect_native(long pointer);

    private native void update_native(long pointer);


}
