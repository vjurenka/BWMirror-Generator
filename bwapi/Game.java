package bwapi;

import bwapi.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;

	/** The abstract Game class is implemented by BWAPI and offers many methods for retrieving information
	* about the current Broodwar game, including the set of players, units, map information, as well as
	* information about the user, such as mouse position, screen position, and the current selection of
	* units. */
public class Game {

	/** Returns the set of all forces in the match. */
    public List<Force> getForces() {
        return getForces_native(pointer);
    }

	/** Returns the set of all players in the match. Note that this includes the Neutral player, which owns
	* all the neutral units such as minerals, critters, etc. */
    public List<Player> getPlayers() {
        return getPlayers_native(pointer);
    }

	/** Returns all the visible units. If Flag::CompleteMapInformation is enabled, the set of all units
	* is returned, not just visible ones. Note that units inside refineries are not included in this set
	* yet. */
    public List<Unit> getAllUnits() {
        return getAllUnits_native(pointer);
    }

	/** Returns the set of all accessible mineral patches. */
    public List<Unit> getMinerals() {
        return getMinerals_native(pointer);
    }

	/** Returns the set of all accessible vespene geysers. */
    public List<Unit> getGeysers() {
        return getGeysers_native(pointer);
    }

	/** Returns the set of all accessible neutral units. */
    public List<Unit> getNeutralUnits() {
        return getNeutralUnits_native(pointer);
    }

	/** Returns the set of all mineral patches (including mined out and other inaccessible ones). */
    public List<Unit> getStaticMinerals() {
        return getStaticMinerals_native(pointer);
    }

	/** Returns the set of all vespene geysers (including mined out and other inaccessible ones). */
    public List<Unit> getStaticGeysers() {
        return getStaticGeysers_native(pointer);
    }

	/** Returns the set of all neutral units (including mined out and other inaccessible ones). */
    public List<Unit> getStaticNeutralUnits() {
        return getStaticNeutralUnits_native(pointer);
    }

	/** Returns all visible bullets. If Flag::CompleteMapInformation is enabled, the set of all bullets is
	* returned, not just visible ones. */
    public List<Bullet> getBullets() {
        return getBullets_native(pointer);
    }

	/** Returns all visible nuke dots. If Flag::CompleteMapInformation is enabled, the set of all nuke dots
	* is returned, not just visible ones. */
    public List<Position> getNukeDots() {
        return getNukeDots_native(pointer);
    }

	/** Returns the list of events */
    public Force getForce(int forceID) {
        return getForce_native(pointer, forceID);
    }

	/** Returns the player with the given ID, or NULL if no player has the given ID */
    public Player getPlayer(int playerID) {
        return getPlayer_native(pointer, playerID);
    }

	/** Returns the unit with the given ID, or NULL if no unit has the given ID */
    public Unit getUnit(int unitID) {
        return getUnit_native(pointer, unitID);
    }

	/** Returns a pointer to a Unit given an index. */
    public Unit indexToUnit(int unitIndex) {
        return indexToUnit_native(pointer, unitIndex);
    }

	/** Returns the Region with the given ID, or NULL if no region has the given ID */
    public Region getRegion(int regionID) {
        return getRegion_native(pointer, regionID);
    }

	/** Returns the game type */
    public GameType getGameType() {
        return getGameType_native(pointer);
    }

	/** Returns the amount of latency the current game has. Currently only returns Latency::SinglePlayer,
	* Latency::LanLow, Latency::LanMedium, or Latency::LanHigh. */
    public int getLatency() {
        return getLatency_native(pointer);
    }

	/** Returns the number of logical frames since the match started. If the game is paused,
	* Game::getFrameCount will not increase however AIModule::onFrame will still be called while paused.
	* On Fastest, there are about 23.8 - 24 frames per second. */
    public int getFrameCount() {
        return getFrameCount_native(pointer);
    }

	/** Returns the Frames Per Second (FPS) that the game is currently running at */
    public int getFPS() {
        return getFPS_native(pointer);
    }

    public double getAverageFPS() {
        return getAverageFPS_native(pointer);
    }

	/** Returns the position of the mouse on the screen. Returns Positions::Unknown if Flag::UserInput is
	* disabled. */
    public Position getMousePosition() {
        return getMousePosition_native(pointer);
    }

	/** Returns true if the specified mouse button is pressed. Returns false if Flag::UserInput is
	* disabled. */
    public boolean getMouseState(MouseButton button) {
        return getMouseState_native(pointer, button);
    }

	/** Returns true if the specified mouse button is pressed. Returns false if Flag::UserInput is
	* disabled. */
    public boolean getMouseState(int button) {
        return getMouseState_native(pointer, button);
    }

	/** Returns true if the specified key is pressed. Returns false if Flag::UserInput is disabled.
	* Unfortunately this does not read the raw keyboard input yet - when you hold down a key, the
	* getKeyState function is true for a frame, then false for a few frames, and then alternates between
	* true and false (as if you were holding down the key in a text box). Hopefully this will be fixed in
	* a later version. */
    public boolean getKeyState(Key key) {
        return getKeyState_native(pointer, key);
    }

	/** Returns true if the specified key is pressed. Returns false if Flag::UserInput is disabled.
	* Unfortunately this does not read the raw keyboard input yet - when you hold down a key, the
	* getKeyState function is true for a frame, then false for a few frames, and then alternates between
	* true and false (as if you were holding down the key in a text box). Hopefully this will be fixed in
	* a later version. */
    public boolean getKeyState(int key) {
        return getKeyState_native(pointer, key);
    }

	/** Returns the position of the top left corner of the screen on the map. Returns Positions::Unknown if
	* Flag::UserInput is disabled. */
    public Position getScreenPosition() {
        return getScreenPosition_native(pointer);
    }

	/** Moves the screen to the given position on the map. The position specified where the top left corner
	* of the screen will be. */
    public void setScreenPosition(int x, int y) {
        setScreenPosition_native(pointer, x, y);
    }

	/** Moves the screen to the given position on the map. The position specified where the top left corner
	* of the screen will be. */
    public void setScreenPosition(Position p) {
        setScreenPosition_native(pointer, p);
    }

	/** Pings the given position on the minimap. */
    public void pingMinimap(int x, int y) {
        pingMinimap_native(pointer, x, y);
    }

	/** Pings the given position on the minimap. */
    public void pingMinimap(Position p) {
        pingMinimap_native(pointer, p);
    }

	/** Returns true if the given flag has been enabled. Note that flags can only be enabled at the
	* beginning of a match, during the AIModule::onStart callback. */
    public boolean isFlagEnabled(int flag) {
        return isFlagEnabled_native(pointer, flag);
    }

	/** Enables the specified flag. Note that flags can only be enabled at the beginning of a match, during
	* the AIModule::onStart callback. */
    public void enableFlag(int flag) {
        enableFlag_native(pointer, flag);
    }

	/** Returns the set of accessible units that are on the given build tile. */
    public List<Unit> getUnitsOnTile(int tileX, int tileY) {
        return getUnitsOnTile_native(pointer, tileX, tileY);
    }

	/** Returns the set of accessible units that are in or overlapping the given rectangle. */
    public List<Unit> getUnitsInRectangle(int left, int top, int right, int bottom) {
        return getUnitsInRectangle_native(pointer, left, top, right, bottom);
    }

    public List<Unit> getUnitsInRectangle(Position topLeft, Position bottomRight) {
        return getUnitsInRectangle_native(pointer, topLeft, bottomRight);
    }

	/** Returns the set of accessible units within or overlapping a circle at the given point with the given radius. */
    public List<Unit> getUnitsInRadius(Position center, int radius) {
        return getUnitsInRadius_native(pointer, center, radius);
    }

	/** Returns the last error that was set. If you try to order enemy units around, or morph bunkers into
	* lurkers, BWAPI will set error codes, which can be retrieved using this function. */
    public Error getLastError() {
        return getLastError_native(pointer);
    }

	/** Sets the last error code. */
    public boolean setLastError(Error e) {
        return setLastError_native(pointer, e);
    }

	/** Returns the width of the current map, in build tile units. To get the width of the current map in
	* walk tile units, multiply by 4. To get the width of the current map in Position units, multiply by
	* TILE_SIZE (which is 32). */
    public int mapWidth() {
        return mapWidth_native(pointer);
    }

	/** Returns the height of the current map, in build tile units. To get the height of the current map in
	* walk tile units, multiply by 4. To get the height of the current map in Position units, multiply by
	* TILE_SIZE (which is 32). */
    public int mapHeight() {
        return mapHeight_native(pointer);
    }

	/** Returns the file name of the current map. */
    public String mapFileName() {
        return mapFileName_native(pointer);
    }

	/** Returns the full path name of the current map. */
    public String mapPathName() {
        return mapPathName_native(pointer);
    }

	/** Returns the name/title of the current map. */
    public String mapName() {
        return mapName_native(pointer);
    }

	/** Returns the SHA-1 hash of the map file. */
    public String mapHash() {
        return mapHash_native(pointer);
    }

	/** Returns true if the specified walk tile is walkable. The values of x and y are in walk tile
	* coordinates (different from build tile coordinates). Note that this just uses the static map data.
	* You will also need to make sure no ground units are on the coresponding build tile to see if its
	* currently walkable. To do this, see unitsOnTile. */
    public boolean isWalkable(int walkX, int walkY) {
        return isWalkable_native(pointer, walkX, walkY);
    }

	/** Returns the ground height of the given build tile. 0 = normal, 1 = high ground.  2 = very high ground. */
    public boolean isBuildable(int tileX, int tileY) {
        return isBuildable_native(pointer, tileX, tileY);
    }

    public boolean isBuildable(int tileX, int tileY, boolean includeBuildings) {
        return isBuildable_native(pointer, tileX, tileY, includeBuildings);
    }

	/** Returns the ground height of the given build tile. 0 = normal, 1 = high ground.  2 = very high ground. */
    public boolean isBuildable(TilePosition position) {
        return isBuildable_native(pointer, position);
    }

    public boolean isBuildable(TilePosition position, boolean includeBuildings) {
        return isBuildable_native(pointer, position, includeBuildings);
    }

	/** Returns true if the specified build tile is visible. If the tile is concealed by fog of war, the
	* function will return false. */
    public boolean isVisible(int tileX, int tileY) {
        return isVisible_native(pointer, tileX, tileY);
    }

	/** Returns true if the specified build tile is visible. If the tile is concealed by fog of war, the
	* function will return false. */
    public boolean isVisible(TilePosition position) {
        return isVisible_native(pointer, position);
    }

	/** Returns true if the specified build tile has been explored (i.e. was visible at some point in the
	* match). */
    public boolean isExplored(int tileX, int tileY) {
        return isExplored_native(pointer, tileX, tileY);
    }

	/** Returns true if the specified build tile has been explored (i.e. was visible at some point in the
	* match). */
    public boolean isExplored(TilePosition position) {
        return isExplored_native(pointer, position);
    }

	/** Returns true if the specified build tile has zerg creep on it. If the tile is concealed by fog of
	* war, the function will return false. */
    public boolean hasCreep(int tileX, int tileY) {
        return hasCreep_native(pointer, tileX, tileY);
    }

	/** Returns true if the specified build tile has zerg creep on it. If the tile is concealed by fog of
	* war, the function will return false. */
    public boolean hasCreep(TilePosition position) {
        return hasCreep_native(pointer, position);
    }

	/** Returns true if the given build location is powered by a nearby friendly pylon. */
    public boolean hasPower(int tileX, int tileY) {
        return hasPower_native(pointer, tileX, tileY);
    }

    public boolean hasPower(int tileX, int tileY, UnitType unitType) {
        return hasPower_native(pointer, tileX, tileY, unitType);
    }

	/** Returns true if the given build location is powered by a nearby friendly pylon. */
    public boolean hasPower(TilePosition position) {
        return hasPower_native(pointer, position);
    }

    public boolean hasPower(TilePosition position, UnitType unitType) {
        return hasPower_native(pointer, position, unitType);
    }

	/** Returns true if the given build location is powered by a nearby friendly pylon. */
    public boolean hasPower(int tileX, int tileY, int tileWidth, int tileHeight) {
        return hasPower_native(pointer, tileX, tileY, tileWidth, tileHeight);
    }

    public boolean hasPower(int tileX, int tileY, int tileWidth, int tileHeight, UnitType unitType) {
        return hasPower_native(pointer, tileX, tileY, tileWidth, tileHeight, unitType);
    }

	/** Returns true if the given build location is powered by a nearby friendly pylon. */
    public boolean hasPower(TilePosition position, int tileWidth, int tileHeight) {
        return hasPower_native(pointer, position, tileWidth, tileHeight);
    }

    public boolean hasPower(TilePosition position, int tileWidth, int tileHeight, UnitType unitType) {
        return hasPower_native(pointer, position, tileWidth, tileHeight, unitType);
    }

	/** Returns true if the given pixel location is powered by a nearby friendly pylon. */
    public boolean hasPowerPrecise(int x, int y) {
        return hasPowerPrecise_native(pointer, x, y);
    }

    public boolean hasPowerPrecise(int x, int y, UnitType unitType) {
        return hasPowerPrecise_native(pointer, x, y, unitType);
    }

	/** Returns true if the given pixel location is powered by a nearby friendly pylon. */
    public boolean hasPowerPrecise(Position position) {
        return hasPowerPrecise_native(pointer, position);
    }

    public boolean hasPowerPrecise(Position position, UnitType unitType) {
        return hasPowerPrecise_native(pointer, position, unitType);
    }

	/** Returns true if the given unit type can be built at the given build tile position. Note the tile
	* position specifies the top left tile of the building. If builder is not null, the unit will be
	* discarded when determining whether or not any ground units are blocking the build location. */
    public boolean canBuildHere(Unit builder, TilePosition position, UnitType type) {
        return canBuildHere_native(pointer, builder, position, type);
    }

    public boolean canBuildHere(Unit builder, TilePosition position, UnitType type, boolean checkExplored) {
        return canBuildHere_native(pointer, builder, position, type, checkExplored);
    }

	/** Returns true if the AI player has enough resources, supply, tech, and required units in order to
	* make the given unit type. If builder is not null, canMake will return true only if the builder unit
	* can build the given unit type. */
    public boolean canMake(Unit builder, UnitType type) {
        return canMake_native(pointer, builder, type);
    }

	/** Returns true if the AI player has enough resources required to research the given tech type. If unit
	* is not null, canResearch will return true only if the given unit can research the given tech type. */
    public boolean canResearch(Unit unit, TechType type) {
        return canResearch_native(pointer, unit, type);
    }

	/** Returns true if the AI player has enough resources required to upgrade the given upgrade type. If
	* unit is not null, canUpgrade will return true only if the given unit can upgrade the given upgrade
	* type. */
    public boolean canUpgrade(Unit unit, UpgradeType type) {
        return canUpgrade_native(pointer, unit, type);
    }

	/** Returns the set of starting locations for the given map. To determine the starting location for the
	* players in the current match, see Player::getStartLocation. */
    public List<TilePosition> getStartLocations() {
        return getStartLocations_native(pointer);
    }

	/** Prints text on the screen. Text is not sent to other players in multiplayer games. */
    public void printf(String cstr_format) {
        printf_native(pointer, cstr_format);
    }

	/** Sends text to other players - as if it were entered in chat. In single player games and replays,
	* this will just print the text on the screen. If the game is a single player match and not a replay,
	* then this function can be used to execute cheat codes, i.e. Broodwar->sendText("show me the money"). */
    public void sendText(String cstr_format) {
        sendText_native(pointer, cstr_format);
    }

    public void sendTextEx(boolean toAllies, String cstr_format) {
        sendTextEx_native(pointer, toAllies, cstr_format);
    }

	/** Used to change the race while in a lobby. Note that there is no onLobbyEnter callback yet, so this
	* function cannot be used at this time. */
    public void changeRace(Race race) {
        changeRace_native(pointer, race);
    }

	/** Returns true if Broodwar is in a game. Returns false for lobby and menu screens */
    public boolean isInGame() {
        return isInGame_native(pointer);
    }

	/** Returns true if Broodwar is in a multiplayer game. Returns false for single player games and
	* replays. */
    public boolean isMultiplayer() {
        return isMultiplayer_native(pointer);
    }

	/** Returns true if Broodwar is in a BNet multiplayer game.
	*/
    public boolean isBattleNet() {
        return isBattleNet_native(pointer);
    }

	/** Returns true if Broodwar is paused. If the game is paused, Game::getFrameCount will continue to
	* increase and AIModule::onFrame will still be called while paused. */
    public boolean isPaused() {
        return isPaused_native(pointer);
    }

	/** Returns true if Broodwar is in a replay. */
    public boolean isReplay() {
        return isReplay_native(pointer);
    }

	/** Used to start the game while in a lobby. Note that there is no onLobbyEnter callback yet, so this
	* function cannot be used at this time. */
    public void startGame() {
        startGame_native(pointer);
    }

	/** Pauses the game. If the game is paused, Game::getFrameCount will not increase however
	* AIModule::onFrame will still be called while paused. */
    public void pauseGame() {
        pauseGame_native(pointer);
    }

	/** Resumes the game. */
    public void resumeGame() {
        resumeGame_native(pointer);
    }

	/** Leaves the current match and goes to the after-game stats screen. */
    public void leaveGame() {
        leaveGame_native(pointer);
    }

	/** Restarts the match. Works the same way as if you restarted the match from the menu screen. Only
	* available in single player mode. */
    public void restartGame() {
        restartGame_native(pointer);
    }

	/** Sets the speed of the game to the given number. Lower numbers are faster. 0 is the fastest speed
	* StarCraft can handle (which is about as fast as the fastest speed you can view a replay at). Any
	* negative value will reset the speed to the StarCraft default. */
    public void setLocalSpeed() {
        setLocalSpeed_native(pointer);
    }

    public void setLocalSpeed(int speed) {
        setLocalSpeed_native(pointer, speed);
    }

	/** Issues a command to a group of units */
    public boolean issueCommand(List<Unit> units, UnitCommand command) {
        return issueCommand_native(pointer, units, command);
    }

	/** Returns the set of units currently selected by the user in the GUI. If Flag?::UserInput? was not
	* enabled during the AIModule::onStart callback, this function will always return an empty set. */
    public List<Unit> getSelectedUnits() {
        return getSelectedUnits_native(pointer);
    }

	/** Returns a pointer to the player that BWAPI controls. In replays this will return null. */
    public Player self() {
        return self_native(pointer);
    }

	/** Returns a pointer to the enemy player. If there is more than one enemy, this returns a pointer to
	* just one enemy (see enemies to get all enemies still in game). In replays this will
	* return NULL. */
    public Player enemy() {
        return enemy_native(pointer);
    }

	/** Returns a pointer to the neutral player. */
    public Player neutral() {
        return neutral_native(pointer);
    }

	/** Returns a set of all the ally players that have not left or been defeated. Does not include self. */
    public List<Player> allies() {
        return allies_native(pointer);
    }

	/** Returns a set of all the enemy players that have not left or been defeated. */
    public List<Player> enemies() {
        return enemies_native(pointer);
    }

	/** Returns a set of all the observer players that have not left. */
    public List<Player> observers() {
        return observers_native(pointer);
    }

    public void setTextSize() {
        setTextSize_native(pointer);
    }

    public void setTextSize(int size) {
        setTextSize_native(pointer, size);
    }

	/** Draws text on the screen at the given position. Text can be drawn in different colors by using the
	* following control characters: TODO: add image from wiki.*/
    public void drawText(int ctype, int x, int y, String cstr_format) {
        drawText_native(pointer, ctype, x, y, cstr_format);
    }

    public void drawTextMap(int x, int y, String cstr_format) {
        drawTextMap_native(pointer, x, y, cstr_format);
    }

    public void drawTextMouse(int x, int y, String cstr_format) {
        drawTextMouse_native(pointer, x, y, cstr_format);
    }

    public void drawTextScreen(int x, int y, String cstr_format) {
        drawTextScreen_native(pointer, x, y, cstr_format);
    }

	/** Draws a box on the screen, with the given color. If isSolid is true, the entire box will be
	* rendered, otherwise just the outline will be drawn. */
    public void drawBox(int ctype, int left, int top, int right, int bottom, Color color) {
        drawBox_native(pointer, ctype, left, top, right, bottom, color);
    }

    public void drawBox(int ctype, int left, int top, int right, int bottom, Color color, boolean isSolid) {
        drawBox_native(pointer, ctype, left, top, right, bottom, color, isSolid);
    }

    public void drawBoxMap(int left, int top, int right, int bottom, Color color) {
        drawBoxMap_native(pointer, left, top, right, bottom, color);
    }

    public void drawBoxMap(int left, int top, int right, int bottom, Color color, boolean isSolid) {
        drawBoxMap_native(pointer, left, top, right, bottom, color, isSolid);
    }

    public void drawBoxMouse(int left, int top, int right, int bottom, Color color) {
        drawBoxMouse_native(pointer, left, top, right, bottom, color);
    }

    public void drawBoxMouse(int left, int top, int right, int bottom, Color color, boolean isSolid) {
        drawBoxMouse_native(pointer, left, top, right, bottom, color, isSolid);
    }

    public void drawBoxScreen(int left, int top, int right, int bottom, Color color) {
        drawBoxScreen_native(pointer, left, top, right, bottom, color);
    }

    public void drawBoxScreen(int left, int top, int right, int bottom, Color color, boolean isSolid) {
        drawBoxScreen_native(pointer, left, top, right, bottom, color, isSolid);
    }

	/** Draws a triangle on the screen. If isSolid is true, a solid triangle is drawn, otherwise just the
	* outline of the triangle will be drawn. */
    public void drawTriangle(int ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color) {
        drawTriangle_native(pointer, ctype, ax, ay, bx, by, cx, cy, color);
    }

    public void drawTriangle(int ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color, boolean isSolid) {
        drawTriangle_native(pointer, ctype, ax, ay, bx, by, cx, cy, color, isSolid);
    }

    public void drawTriangleMap(int ax, int ay, int bx, int by, int cx, int cy, Color color) {
        drawTriangleMap_native(pointer, ax, ay, bx, by, cx, cy, color);
    }

    public void drawTriangleMap(int ax, int ay, int bx, int by, int cx, int cy, Color color, boolean isSolid) {
        drawTriangleMap_native(pointer, ax, ay, bx, by, cx, cy, color, isSolid);
    }

    public void drawTriangleMouse(int ax, int ay, int bx, int by, int cx, int cy, Color color) {
        drawTriangleMouse_native(pointer, ax, ay, bx, by, cx, cy, color);
    }

    public void drawTriangleMouse(int ax, int ay, int bx, int by, int cx, int cy, Color color, boolean isSolid) {
        drawTriangleMouse_native(pointer, ax, ay, bx, by, cx, cy, color, isSolid);
    }

    public void drawTriangleScreen(int ax, int ay, int bx, int by, int cx, int cy, Color color) {
        drawTriangleScreen_native(pointer, ax, ay, bx, by, cx, cy, color);
    }

    public void drawTriangleScreen(int ax, int ay, int bx, int by, int cx, int cy, Color color, boolean isSolid) {
        drawTriangleScreen_native(pointer, ax, ay, bx, by, cx, cy, color, isSolid);
    }

	/** Draws a circle on the screen, with the given color. If isSolid is true, a solid circle is drawn,
	* otherwise just the outline of a circle will be drawn. */
    public void drawCircle(int ctype, int x, int y, int radius, Color color) {
        drawCircle_native(pointer, ctype, x, y, radius, color);
    }

    public void drawCircle(int ctype, int x, int y, int radius, Color color, boolean isSolid) {
        drawCircle_native(pointer, ctype, x, y, radius, color, isSolid);
    }

    public void drawCircleMap(int x, int y, int radius, Color color) {
        drawCircleMap_native(pointer, x, y, radius, color);
    }

    public void drawCircleMap(int x, int y, int radius, Color color, boolean isSolid) {
        drawCircleMap_native(pointer, x, y, radius, color, isSolid);
    }

    public void drawCircleMouse(int x, int y, int radius, Color color) {
        drawCircleMouse_native(pointer, x, y, radius, color);
    }

    public void drawCircleMouse(int x, int y, int radius, Color color, boolean isSolid) {
        drawCircleMouse_native(pointer, x, y, radius, color, isSolid);
    }

    public void drawCircleScreen(int x, int y, int radius, Color color) {
        drawCircleScreen_native(pointer, x, y, radius, color);
    }

    public void drawCircleScreen(int x, int y, int radius, Color color, boolean isSolid) {
        drawCircleScreen_native(pointer, x, y, radius, color, isSolid);
    }

	/** Draws an ellipse on the screen, with the given color. If isSolid is true, a solid ellipse is drawn,
	* otherwise just the outline of an ellipse will be drawn. */
    public void drawEllipse(int ctype, int x, int y, int xrad, int yrad, Color color) {
        drawEllipse_native(pointer, ctype, x, y, xrad, yrad, color);
    }

    public void drawEllipse(int ctype, int x, int y, int xrad, int yrad, Color color, boolean isSolid) {
        drawEllipse_native(pointer, ctype, x, y, xrad, yrad, color, isSolid);
    }

    public void drawEllipseMap(int x, int y, int xrad, int yrad, Color color) {
        drawEllipseMap_native(pointer, x, y, xrad, yrad, color);
    }

    public void drawEllipseMap(int x, int y, int xrad, int yrad, Color color, boolean isSolid) {
        drawEllipseMap_native(pointer, x, y, xrad, yrad, color, isSolid);
    }

    public void drawEllipseMouse(int x, int y, int xrad, int yrad, Color color) {
        drawEllipseMouse_native(pointer, x, y, xrad, yrad, color);
    }

    public void drawEllipseMouse(int x, int y, int xrad, int yrad, Color color, boolean isSolid) {
        drawEllipseMouse_native(pointer, x, y, xrad, yrad, color, isSolid);
    }

    public void drawEllipseScreen(int x, int y, int xrad, int yrad, Color color) {
        drawEllipseScreen_native(pointer, x, y, xrad, yrad, color);
    }

    public void drawEllipseScreen(int x, int y, int xrad, int yrad, Color color, boolean isSolid) {
        drawEllipseScreen_native(pointer, x, y, xrad, yrad, color, isSolid);
    }

	/** Draws a dot on the screen at the given position with the given color. */
    public void drawDot(int ctype, int x, int y, Color color) {
        drawDot_native(pointer, ctype, x, y, color);
    }

    public void drawDotMap(int x, int y, Color color) {
        drawDotMap_native(pointer, x, y, color);
    }

    public void drawDotMouse(int x, int y, Color color) {
        drawDotMouse_native(pointer, x, y, color);
    }

    public void drawDotScreen(int x, int y, Color color) {
        drawDotScreen_native(pointer, x, y, color);
    }

	/** Draws a line on the screen from (x1,y1) to (x2,y2) with the given color. */
    public void drawLine(int ctype, int x1, int y1, int x2, int y2, Color color) {
        drawLine_native(pointer, ctype, x1, y1, x2, y2, color);
    }

    public void drawLineMap(int x1, int y1, int x2, int y2, Color color) {
        drawLineMap_native(pointer, x1, y1, x2, y2, color);
    }

    public void drawLineMouse(int x1, int y1, int x2, int y2, Color color) {
        drawLineMouse_native(pointer, x1, y1, x2, y2, color);
    }

    public void drawLineScreen(int x1, int y1, int x2, int y2, Color color) {
        drawLineScreen_native(pointer, x1, y1, x2, y2, color);
    }

	/** Retrieves the screen buffer for the game (excluding the HUD) */
    public void getScreenBuffer() {
        getScreenBuffer_native(pointer);
    }

	/** Retrieves latency values for the game. Includes latency, speed, and mode */
    public int getLatencyFrames() {
        return getLatencyFrames_native(pointer);
    }

    public int getLatencyTime() {
        return getLatencyTime_native(pointer);
    }

    public int getRemainingLatencyFrames() {
        return getRemainingLatencyFrames_native(pointer);
    }

    public int getRemainingLatencyTime() {
        return getRemainingLatencyTime_native(pointer);
    }

	/** Retrieves the current revision of BWAPI. */
    public int getRevision() {
        return getRevision_native(pointer);
    }

	/** Retrieves the debug state of the BWAPI build. */
    public boolean isDebug() {
        return isDebug_native(pointer);
    }

	/** Returns true if latency compensation is enabled */
    public boolean isLatComEnabled() {
        return isLatComEnabled_native(pointer);
    }

	/** Use to enable or disable latency compensation. Default: Enabled */
    public void setLatCom(boolean isEnabled) {
        setLatCom_native(pointer, isEnabled);
    }

	/** Retrieves the number of frames in the replay */
    public int getReplayFrameCount() {
        return getReplayFrameCount_native(pointer);
    }

	/** Sets the rendering state of the Starcraft GUI */
    public void setGUI() {
        setGUI_native(pointer);
    }

    public void setGUI(boolean enabled) {
        setGUI_native(pointer, enabled);
    }

	/** Retrieves the instance number recorded by BWAPI to identify which instance an AI module belongs to */
    public int getAPM() {
        return getAPM_native(pointer);
    }

    public int getAPM(boolean includeSelects) {
        return getAPM_native(pointer, includeSelects);
    }

	/** Changes the map to the one specified. Changes do not take effect unless the game is restarted. */
    public boolean setMap(String cstr_mapFileName) {
        return setMap_native(pointer, cstr_mapFileName);
    }

	/** Sets the frame skip value. 1 = normal */
    public void setFrameSkip() {
        setFrameSkip_native(pointer);
    }

    public void setFrameSkip(int frameSkip) {
        setFrameSkip_native(pointer, frameSkip);
    }

	/** Returns true if Starcraft can find a path from the source to the destination. */
    public boolean hasPath(Position source, Position destination) {
        return hasPath_native(pointer, source, destination);
    }

	/** Sets the BWAPI player's alliance with another player. */
    public boolean setAlliance(Player player, boolean allied) {
        return setAlliance_native(pointer, player, allied);
    }

    public boolean setAlliance(Player player) {
        return setAlliance_native(pointer, player);
    }

    public boolean setAlliance(Player player, boolean allied, boolean alliedVictory) {
        return setAlliance_native(pointer, player, allied, alliedVictory);
    }

	/** Sets the BWAPI player's vision with another player. */
    public boolean setVision(Player player) {
        return setVision_native(pointer, player);
    }

    public boolean setVision(Player player, boolean enabled) {
        return setVision_native(pointer, player, enabled);
    }

	/** Returns the elapsed game time in seconds. */
    public void setCommandOptimizationLevel() {
        setCommandOptimizationLevel_native(pointer);
    }

    public void setCommandOptimizationLevel(int level) {
        setCommandOptimizationLevel_native(pointer, level);
    }

	/** Returns the remaining countdown time in seconds. */
    public Region getRegionAt(int x, int y) {
        return getRegionAt_native(pointer, x, y);
    }

    public Region getRegionAt(Position position) {
        return getRegionAt_native(pointer, position);
    }

	/** Returns the time taken to perform the previous event call. Used for tournament management. */
    public int getLastEventTime() {
        return getLastEventTime_native(pointer);
    }

	/** Hides or reveals a player in a replay. */
    public boolean setReplayVision(Player player) {
        return setReplayVision_native(pointer, player);
    }

    public boolean setReplayVision(Player player, boolean enabled) {
        return setReplayVision_native(pointer, player, enabled);
    }

	/** Enables or disables the Fog of War in a replay. */
    public boolean setRevealAll() {
        return setRevealAll_native(pointer);
    }

    public boolean setRevealAll(boolean reveal) {
        return setRevealAll_native(pointer, reveal);
    }


    private static Map<Long, Game> instances = new HashMap<Long, Game>();

    private Game(long pointer) {
        this.pointer = pointer;
    }

    private static Game get(long pointer) {
        Game instance = instances.get(pointer);
        if (instance == null ) {
            instance = new Game(pointer);
            instances.put(pointer, instance);
        }
        return instance;
    }

    private long pointer;

    private native List<Force> getForces_native(long pointer);

    private native List<Player> getPlayers_native(long pointer);

    private native List<Unit> getAllUnits_native(long pointer);

    private native List<Unit> getMinerals_native(long pointer);

    private native List<Unit> getGeysers_native(long pointer);

    private native List<Unit> getNeutralUnits_native(long pointer);

    private native List<Unit> getStaticMinerals_native(long pointer);

    private native List<Unit> getStaticGeysers_native(long pointer);

    private native List<Unit> getStaticNeutralUnits_native(long pointer);

    private native List<Bullet> getBullets_native(long pointer);

    private native List<Position> getNukeDots_native(long pointer);

    private native Force getForce_native(long pointer, int forceID);

    private native Player getPlayer_native(long pointer, int playerID);

    private native Unit getUnit_native(long pointer, int unitID);

    private native Unit indexToUnit_native(long pointer, int unitIndex);

    private native Region getRegion_native(long pointer, int regionID);

    private native GameType getGameType_native(long pointer);

    private native int getLatency_native(long pointer);

    private native int getFrameCount_native(long pointer);

    private native int getFPS_native(long pointer);

    private native double getAverageFPS_native(long pointer);

    private native Position getMousePosition_native(long pointer);

    private native boolean getMouseState_native(long pointer, MouseButton button);

    private native boolean getMouseState_native(long pointer, int button);

    private native boolean getKeyState_native(long pointer, Key key);

    private native boolean getKeyState_native(long pointer, int key);

    private native Position getScreenPosition_native(long pointer);

    private native void setScreenPosition_native(long pointer, int x, int y);

    private native void setScreenPosition_native(long pointer, Position p);

    private native void pingMinimap_native(long pointer, int x, int y);

    private native void pingMinimap_native(long pointer, Position p);

    private native boolean isFlagEnabled_native(long pointer, int flag);

    private native void enableFlag_native(long pointer, int flag);

    private native List<Unit> getUnitsOnTile_native(long pointer, int tileX, int tileY);

    private native List<Unit> getUnitsInRectangle_native(long pointer, int left, int top, int right, int bottom);

    private native List<Unit> getUnitsInRectangle_native(long pointer, Position topLeft, Position bottomRight);

    private native List<Unit> getUnitsInRadius_native(long pointer, Position center, int radius);

    private native Error getLastError_native(long pointer);

    private native boolean setLastError_native(long pointer, Error e);

    private native int mapWidth_native(long pointer);

    private native int mapHeight_native(long pointer);

    private native String mapFileName_native(long pointer);

    private native String mapPathName_native(long pointer);

    private native String mapName_native(long pointer);

    private native String mapHash_native(long pointer);

    private native boolean isWalkable_native(long pointer, int walkX, int walkY);

    private native boolean isBuildable_native(long pointer, int tileX, int tileY);

    private native boolean isBuildable_native(long pointer, int tileX, int tileY, boolean includeBuildings);

    private native boolean isBuildable_native(long pointer, TilePosition position);

    private native boolean isBuildable_native(long pointer, TilePosition position, boolean includeBuildings);

    private native boolean isVisible_native(long pointer, int tileX, int tileY);

    private native boolean isVisible_native(long pointer, TilePosition position);

    private native boolean isExplored_native(long pointer, int tileX, int tileY);

    private native boolean isExplored_native(long pointer, TilePosition position);

    private native boolean hasCreep_native(long pointer, int tileX, int tileY);

    private native boolean hasCreep_native(long pointer, TilePosition position);

    private native boolean hasPower_native(long pointer, int tileX, int tileY);

    private native boolean hasPower_native(long pointer, int tileX, int tileY, UnitType unitType);

    private native boolean hasPower_native(long pointer, TilePosition position);

    private native boolean hasPower_native(long pointer, TilePosition position, UnitType unitType);

    private native boolean hasPower_native(long pointer, int tileX, int tileY, int tileWidth, int tileHeight);

    private native boolean hasPower_native(long pointer, int tileX, int tileY, int tileWidth, int tileHeight, UnitType unitType);

    private native boolean hasPower_native(long pointer, TilePosition position, int tileWidth, int tileHeight);

    private native boolean hasPower_native(long pointer, TilePosition position, int tileWidth, int tileHeight, UnitType unitType);

    private native boolean hasPowerPrecise_native(long pointer, int x, int y);

    private native boolean hasPowerPrecise_native(long pointer, int x, int y, UnitType unitType);

    private native boolean hasPowerPrecise_native(long pointer, Position position);

    private native boolean hasPowerPrecise_native(long pointer, Position position, UnitType unitType);

    private native boolean canBuildHere_native(long pointer, Unit builder, TilePosition position, UnitType type);

    private native boolean canBuildHere_native(long pointer, Unit builder, TilePosition position, UnitType type, boolean checkExplored);

    private native boolean canMake_native(long pointer, Unit builder, UnitType type);

    private native boolean canResearch_native(long pointer, Unit unit, TechType type);

    private native boolean canUpgrade_native(long pointer, Unit unit, UpgradeType type);

    private native List<TilePosition> getStartLocations_native(long pointer);

    private native void printf_native(long pointer, String cstr_format);

    private native void sendText_native(long pointer, String cstr_format);

    private native void sendTextEx_native(long pointer, boolean toAllies, String cstr_format);

    private native void changeRace_native(long pointer, Race race);

    private native boolean isInGame_native(long pointer);

    private native boolean isMultiplayer_native(long pointer);

    private native boolean isBattleNet_native(long pointer);

    private native boolean isPaused_native(long pointer);

    private native boolean isReplay_native(long pointer);

    private native void startGame_native(long pointer);

    private native void pauseGame_native(long pointer);

    private native void resumeGame_native(long pointer);

    private native void leaveGame_native(long pointer);

    private native void restartGame_native(long pointer);

    private native void setLocalSpeed_native(long pointer);

    private native void setLocalSpeed_native(long pointer, int speed);

    private native boolean issueCommand_native(long pointer, List<Unit> units, UnitCommand command);

    private native List<Unit> getSelectedUnits_native(long pointer);

    private native Player self_native(long pointer);

    private native Player enemy_native(long pointer);

    private native Player neutral_native(long pointer);

    private native List<Player> allies_native(long pointer);

    private native List<Player> enemies_native(long pointer);

    private native List<Player> observers_native(long pointer);

    private native void setTextSize_native(long pointer);

    private native void setTextSize_native(long pointer, int size);

    private native void drawText_native(long pointer, int ctype, int x, int y, String cstr_format);

    private native void drawTextMap_native(long pointer, int x, int y, String cstr_format);

    private native void drawTextMouse_native(long pointer, int x, int y, String cstr_format);

    private native void drawTextScreen_native(long pointer, int x, int y, String cstr_format);

    private native void drawBox_native(long pointer, int ctype, int left, int top, int right, int bottom, Color color);

    private native void drawBox_native(long pointer, int ctype, int left, int top, int right, int bottom, Color color, boolean isSolid);

    private native void drawBoxMap_native(long pointer, int left, int top, int right, int bottom, Color color);

    private native void drawBoxMap_native(long pointer, int left, int top, int right, int bottom, Color color, boolean isSolid);

    private native void drawBoxMouse_native(long pointer, int left, int top, int right, int bottom, Color color);

    private native void drawBoxMouse_native(long pointer, int left, int top, int right, int bottom, Color color, boolean isSolid);

    private native void drawBoxScreen_native(long pointer, int left, int top, int right, int bottom, Color color);

    private native void drawBoxScreen_native(long pointer, int left, int top, int right, int bottom, Color color, boolean isSolid);

    private native void drawTriangle_native(long pointer, int ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color);

    private native void drawTriangle_native(long pointer, int ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color, boolean isSolid);

    private native void drawTriangleMap_native(long pointer, int ax, int ay, int bx, int by, int cx, int cy, Color color);

    private native void drawTriangleMap_native(long pointer, int ax, int ay, int bx, int by, int cx, int cy, Color color, boolean isSolid);

    private native void drawTriangleMouse_native(long pointer, int ax, int ay, int bx, int by, int cx, int cy, Color color);

    private native void drawTriangleMouse_native(long pointer, int ax, int ay, int bx, int by, int cx, int cy, Color color, boolean isSolid);

    private native void drawTriangleScreen_native(long pointer, int ax, int ay, int bx, int by, int cx, int cy, Color color);

    private native void drawTriangleScreen_native(long pointer, int ax, int ay, int bx, int by, int cx, int cy, Color color, boolean isSolid);

    private native void drawCircle_native(long pointer, int ctype, int x, int y, int radius, Color color);

    private native void drawCircle_native(long pointer, int ctype, int x, int y, int radius, Color color, boolean isSolid);

    private native void drawCircleMap_native(long pointer, int x, int y, int radius, Color color);

    private native void drawCircleMap_native(long pointer, int x, int y, int radius, Color color, boolean isSolid);

    private native void drawCircleMouse_native(long pointer, int x, int y, int radius, Color color);

    private native void drawCircleMouse_native(long pointer, int x, int y, int radius, Color color, boolean isSolid);

    private native void drawCircleScreen_native(long pointer, int x, int y, int radius, Color color);

    private native void drawCircleScreen_native(long pointer, int x, int y, int radius, Color color, boolean isSolid);

    private native void drawEllipse_native(long pointer, int ctype, int x, int y, int xrad, int yrad, Color color);

    private native void drawEllipse_native(long pointer, int ctype, int x, int y, int xrad, int yrad, Color color, boolean isSolid);

    private native void drawEllipseMap_native(long pointer, int x, int y, int xrad, int yrad, Color color);

    private native void drawEllipseMap_native(long pointer, int x, int y, int xrad, int yrad, Color color, boolean isSolid);

    private native void drawEllipseMouse_native(long pointer, int x, int y, int xrad, int yrad, Color color);

    private native void drawEllipseMouse_native(long pointer, int x, int y, int xrad, int yrad, Color color, boolean isSolid);

    private native void drawEllipseScreen_native(long pointer, int x, int y, int xrad, int yrad, Color color);

    private native void drawEllipseScreen_native(long pointer, int x, int y, int xrad, int yrad, Color color, boolean isSolid);

    private native void drawDot_native(long pointer, int ctype, int x, int y, Color color);

    private native void drawDotMap_native(long pointer, int x, int y, Color color);

    private native void drawDotMouse_native(long pointer, int x, int y, Color color);

    private native void drawDotScreen_native(long pointer, int x, int y, Color color);

    private native void drawLine_native(long pointer, int ctype, int x1, int y1, int x2, int y2, Color color);

    private native void drawLineMap_native(long pointer, int x1, int y1, int x2, int y2, Color color);

    private native void drawLineMouse_native(long pointer, int x1, int y1, int x2, int y2, Color color);

    private native void drawLineScreen_native(long pointer, int x1, int y1, int x2, int y2, Color color);

    private native void getScreenBuffer_native(long pointer);

    private native int getLatencyFrames_native(long pointer);

    private native int getLatencyTime_native(long pointer);

    private native int getRemainingLatencyFrames_native(long pointer);

    private native int getRemainingLatencyTime_native(long pointer);

    private native int getRevision_native(long pointer);

    private native boolean isDebug_native(long pointer);

    private native boolean isLatComEnabled_native(long pointer);

    private native void setLatCom_native(long pointer, boolean isEnabled);

    private native int getReplayFrameCount_native(long pointer);

    private native void setGUI_native(long pointer);

    private native void setGUI_native(long pointer, boolean enabled);

    private native int getAPM_native(long pointer);

    private native int getAPM_native(long pointer, boolean includeSelects);

    private native boolean setMap_native(long pointer, String cstr_mapFileName);

    private native void setFrameSkip_native(long pointer);

    private native void setFrameSkip_native(long pointer, int frameSkip);

    private native boolean hasPath_native(long pointer, Position source, Position destination);

    private native boolean setAlliance_native(long pointer, Player player, boolean allied);

    private native boolean setAlliance_native(long pointer, Player player);

    private native boolean setAlliance_native(long pointer, Player player, boolean allied, boolean alliedVictory);

    private native boolean setVision_native(long pointer, Player player);

    private native boolean setVision_native(long pointer, Player player, boolean enabled);

    private native void setCommandOptimizationLevel_native(long pointer);

    private native void setCommandOptimizationLevel_native(long pointer, int level);

    private native Region getRegionAt_native(long pointer, int x, int y);

    private native Region getRegionAt_native(long pointer, Position position);

    private native int getLastEventTime_native(long pointer);

    private native boolean setReplayVision_native(long pointer, Player player);

    private native boolean setReplayVision_native(long pointer, Player player, boolean enabled);

    private native boolean setRevealAll_native(long pointer);

    private native boolean setRevealAll_native(long pointer, boolean reveal);


}
