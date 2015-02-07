package bwapi4;

import bwapi4.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public class AIModule {

    public void onStart() {
        onStart_native(pointer);
    }

    public void onEnd(boolean isWinner) {
        onEnd_native(pointer, isWinner);
    }

    public void onFrame() {
        onFrame_native(pointer);
    }

    public void onSendText(String text) {
        onSendText_native(pointer, text);
    }

    public void onReceiveText(Player player, String text) {
        onReceiveText_native(pointer, player, text);
    }

    public void onPlayerLeft(Player player) {
        onPlayerLeft_native(pointer, player);
    }

    public void onNukeDetect(Position target) {
        onNukeDetect_native(pointer, target);
    }

    public void onUnitDiscover(Unit unit) {
        onUnitDiscover_native(pointer, unit);
    }

    public void onUnitEvade(Unit unit) {
        onUnitEvade_native(pointer, unit);
    }

    public void onUnitShow(Unit unit) {
        onUnitShow_native(pointer, unit);
    }

    public void onUnitHide(Unit unit) {
        onUnitHide_native(pointer, unit);
    }

    public void onUnitCreate(Unit unit) {
        onUnitCreate_native(pointer, unit);
    }

    public void onUnitDestroy(Unit unit) {
        onUnitDestroy_native(pointer, unit);
    }

    public void onUnitMorph(Unit unit) {
        onUnitMorph_native(pointer, unit);
    }

    public void onUnitRenegade(Unit unit) {
        onUnitRenegade_native(pointer, unit);
    }

    public void onSaveGame(String gameName) {
        onSaveGame_native(pointer, gameName);
    }

    public void onUnitComplete(Unit unit) {
        onUnitComplete_native(pointer, unit);
    }


    private static Map<Long, AIModule> instances = new HashMap<Long, AIModule>();

    private AIModule(long pointer) {
        this.pointer = pointer;
    }

    private static AIModule get(long pointer) {
        if (pointer == 0 ) {
            return null;
        }
        AIModule instance = instances.get(pointer);
        if (instance == null ) {
            instance = new AIModule(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native void onStart_native(long pointer);

    private native void onEnd_native(long pointer, boolean isWinner);

    private native void onFrame_native(long pointer);

    private native void onSendText_native(long pointer, String text);

    private native void onReceiveText_native(long pointer, Player player, String text);

    private native void onPlayerLeft_native(long pointer, Player player);

    private native void onNukeDetect_native(long pointer, Position target);

    private native void onUnitDiscover_native(long pointer, Unit unit);

    private native void onUnitEvade_native(long pointer, Unit unit);

    private native void onUnitShow_native(long pointer, Unit unit);

    private native void onUnitHide_native(long pointer, Unit unit);

    private native void onUnitCreate_native(long pointer, Unit unit);

    private native void onUnitDestroy_native(long pointer, Unit unit);

    private native void onUnitMorph_native(long pointer, Unit unit);

    private native void onUnitRenegade_native(long pointer, Unit unit);

    private native void onSaveGame_native(long pointer, String gameName);

    private native void onUnitComplete_native(long pointer, Unit unit);


}
