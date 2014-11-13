package bwapi.CommandType;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

public enum Enum {

	None(0),
	SetScreenPosition(1),
	PingMinimap(2),
	EnableFlag(3),
	Printf(4),
	SendText(5),
	ChangeRace(6),
	StartGame(7),
	PauseGame(8),
	ResumeGame(9),
	LeaveGame(10),
	RestartGame(11),
	SetLocalSpeed(12),
	SetLatCom(13),
	SetGui(14),
	SetFrameSkip(15),
	SetMap(16),
	SetAllies(17),
	SetVision(18),
	SetCommandOptimizerLevel(19),
	SetReplayVision(20);

	private int value;

	public int getValue(){
		return value;
	}

	Enum(int value){
		this.value = value;
	}

}
