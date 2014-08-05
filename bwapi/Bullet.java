package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

/**
The Bullet class is used to get information about individual bullets, missiles, spells, and generally any sort of non-melee attack. Unlike Units, Bullet objects are reused after they are destroyed, however the ID of the bullet is updated when it represents a new bullet.
If <a href="Misc.html">Flag::CompleteMapInformation</a> is disabled, then a bullet is accessible if and only if it is visible. If a bullet is not visible, <a href="Bullet.html">Bullet::exists</a> will return false, regardless of whether or not the bullet exists. This is because absolutely no state information on invisible enemy bullets is made available to the AI.
If <a href="Misc.html">Flag::CompleteMapInformation</a> is enabled, then all bullets that exist in the game are accessible, and <a href="Bullet.html">Bullet::exists</a> is accurate for all bullets.
No message similar to <a href="AIModule.html">AIModule::onUnitDestroy</a> exists for bullets. To determine if a bullet has been destroyed, check to see if exists() is false or getID() has changed to a new value.


*/
public class Bullet {

/**
Returns a unique ID for this bullet.

*/
    public int getID() {
        return getID_native(pointer);
    }

/**
Returns the player of the source unit, or NULL if the source unit has been destroyed or is otherwise inaccessible.

*/
    public Player getPlayer() {
        return getPlayer_native(pointer);
    }

/**
Returns the type of the bullet.

*/
    public BulletType getType() {
        return getType_native(pointer);
    }

/**
Returns the unit that fired the bullet. If the unit is inaccessible (such as a cloaked or burrowed enemy unit with no detection around and complete map information disabled), this will return NULL.

*/
    public Unit getSource() {
        return getSource_native(pointer);
    }

/**
Returns the position of the bullet, or an invalid position if the bullet is inaccessible.

*/
    public Position getPosition() {
        return getPosition_native(pointer);
    }

/**
Returns the direction the bullet is facing/traveling in, measured in radians. An angle of 0 means the bullet is facing east/right. If the bullet is inaccessible this will return 0.

*/
    public double getAngle() {
        return getAngle_native(pointer);
    }

/**
Returns the x component of the bullet's velocity, measured in pixels per frame. If the bullet is inaccessible this will return 0.

*/
    public double getVelocityX() {
        return getVelocityX_native(pointer);
    }

/**
Returns the y component of the bullet's velocity, measured in pixels per frame. If the bullet is inaccessible this will return 0.

*/
    public double getVelocityY() {
        return getVelocityY_native(pointer);
    }

/**
Returns the unit that the bullet is trying to hit. If the unit is inaccessible (such as a cloaked or burrowed enemy unit with no detection around and complete map information disabled), this will return NULL. If the bullet is inaccessible this will return NULL.

*/
    public Unit getTarget() {
        return getTarget_native(pointer);
    }

/**
Returns the target position of the bullet. If the bullet is inaccessible this will return an invalid position.

*/
    public Position getTargetPosition() {
        return getTargetPosition_native(pointer);
    }

/**
Returns the maximum number of frames until this bullet is removed. Generally bullets hit their targets before this timer reaches 0. If the bullet is inaccessible this will return 0.

*/
    public int getRemoveTimer() {
        return getRemoveTimer_native(pointer);
    }

/**
Returns true if the bullet is accessible. If <a href="Misc.html">Flag::CompleteMapInformation</a> is enabled, all bullets that actually exist in the game will be accessible. If it is disabled, then only visible bullets will be accessible.

*/
    public boolean exists() {
        return exists_native(pointer);
    }

/**
bool isVisible(<a href="Player.html">Player</a><tt>*</tt> player) const;
Returns true if the bullet is visible.
If <a href="Misc.html">Flag::CompleteMapInformation</a> is enabled, you can also specify to which player you want to check visibility for, otherwise <a href="Game.html">Game::self</a> is used.

*/
    public boolean isVisible() {
        return isVisible_native(pointer);
    }

/**
bool isVisible(<a href="Player.html">Player</a><tt>*</tt> player) const;
Returns true if the bullet is visible.
If <a href="Misc.html">Flag::CompleteMapInformation</a> is enabled, you can also specify to which player you want to check visibility for, otherwise <a href="Game.html">Game::self</a> is used.

*/
    public boolean isVisible(Player player) {
        return isVisible_native(pointer, player);
    }


    private static Map<Long, Bullet> instances = new HashMap<Long, Bullet>();

    private Bullet(long pointer) {
        this.pointer = pointer;
    }

    private static Bullet get(long pointer) {
        Bullet instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Bullet(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native int getID_native(long pointer);

    private native Player getPlayer_native(long pointer);

    private native BulletType getType_native(long pointer);

    private native Unit getSource_native(long pointer);

    private native Position getPosition_native(long pointer);

    private native double getAngle_native(long pointer);

    private native double getVelocityX_native(long pointer);

    private native double getVelocityY_native(long pointer);

    private native Unit getTarget_native(long pointer);

    private native Position getTargetPosition_native(long pointer);

    private native int getRemoveTimer_native(long pointer);

    private native boolean exists_native(long pointer);

    private native boolean isVisible_native(long pointer);

    private native boolean isVisible_native(long pointer, Player player);


}
