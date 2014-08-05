package bwapi.Tournament;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public enum ActionID {

	EnableFlag(0),
	ChangeRace(1),
	StartGame(2),
	PauseGame(3),
	ResumeGame(4),
	LeaveGame(5),
	RestartGame(6),
	SetLocalSpeed(7),
	SetTextSize(8),
	SetLatCom(9),
	SetGUI(10),
	SetMap(11),
	SetFrameSkip(12),
	Printf(13),
	SendText(14);

	private int value;

	public int getValue(){
		return value;
	}

	ActionID(int value){
		this.value = value;
	}

}
