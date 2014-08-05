package bwta;

import bwta.*;

import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.List;
import bwapi.Position;
import bwapi.TilePosition;
import bwapi.Player;

/**
BWTA class wraps the functionality of <a href="https://code.google.com/p/bwta/">BWTA library</a>

*/
public class BWTA {

/**
Reads the contents of the map in to BWTA. This was added so analyze() can be executed in another thread.

*/
    public static native void readMap();

/**
Before any other global functions can be called, the map must first be analyzed. Analyzing a starcraft map can take a long time, depending on your computer, so BWTA also automatically saves the results to a file when it is done. When you call analyze on the same map, BWTA will see that the results file for that map already exists, and load the results from file, rather than re-analyze the map.

*/
    public static native void analyze();

/**
Returns the set of regions in the map.

*/
    public static native List<Region> getRegions();

/**
Returns the set of chokepoints in the map.

*/
    public static native List<Chokepoint> getChokepoints();

/**
Returns the set of base locations on the map.

*/
    public static native List<BaseLocation> getBaseLocations();

/**
Returns the set of base locations that are start locations.

*/
    public static native List<BaseLocation> getStartLocations();

/**
Returns the set of unwalkable polygons.

*/
    public static native List<Polygon> getUnwalkablePolygons();

/**
Given a pointer to a Player object, this function returns a pointer to the player's starting base location.

*/
    public static native BaseLocation getStartLocation(Player player);

/**
Returns the region that the tile position is inside. Returns NULL if the tile position is not inside any valid region.

*/
    public static native Region getRegion(int x, int y);

/**
Returns the region that the tile position is inside. Returns NULL if the tile position is not inside any valid region.

*/
    public static native Region getRegion(TilePosition tileposition);

/**
Returns the region that the tile position is inside. Returns NULL if the tile position is not inside any valid region.

*/
    public static native Region getRegion(Position position);

/**
Returns the nearest chokepoint (in ground/walking distance). Returns NULL if no chokepoint is reachable from the given tile position (such as in an island component with no chokepoints). The Position version of this function has walk tile accuracy, while the other two have build tile accuracy.

*/
    public static native Chokepoint getNearestChokepoint(int x, int y);

/**
Returns the nearest chokepoint (in ground/walking distance). Returns NULL if no chokepoint is reachable from the given tile position (such as in an island component with no chokepoints). The Position version of this function has walk tile accuracy, while the other two have build tile accuracy.

*/
    public static native Chokepoint getNearestChokepoint(TilePosition tileposition);

/**
Returns the nearest chokepoint (in ground/walking distance). Returns NULL if no chokepoint is reachable from the given tile position (such as in an island component with no chokepoints). The Position version of this function has walk tile accuracy, while the other two have build tile accuracy.

*/
    public static native Chokepoint getNearestChokepoint(Position position);

/**
Returns the nearest base location(in ground/walking distance). Returns NULL if no base location is reachable from the given tile position. The Position version of this function has walk tile accuracy, while the other two have build tile accuracy.

*/
    public static native BaseLocation getNearestBaseLocation(int x, int y);

/**
Returns the nearest base location(in ground/walking distance). Returns NULL if no base location is reachable from the given tile position. The Position version of this function has walk tile accuracy, while the other two have build tile accuracy.

*/
    public static native BaseLocation getNearestBaseLocation(TilePosition tileposition);

/**
Returns the nearest base location(in ground/walking distance). Returns NULL if no base location is reachable from the given tile position. The Position version of this function has walk tile accuracy, while the other two have build tile accuracy.

*/
    public static native BaseLocation getNearestBaseLocation(Position position);

/**
Returns the nearest unwalkable polygon. Note: The border of the map is not considered an unwalkable polygon.

*/
    public static native Polygon getNearestUnwalkablePolygon(int x, int y);

/**
Returns the nearest unwalkable polygon. Note: The border of the map is not considered an unwalkable polygon.

*/
    public static native Polygon getNearestUnwalkablePolygon(TilePosition tileposition);

/**
Returns the nearest position that is on the boundary of an unwalkable polygon, or border of the map.

*/
    public static native Position getNearestUnwalkablePosition(Position position);

/**
Returns true if there exists a static path between the two given tile positions.

*/
    public static native boolean isConnected(int x1, int y1, int x2, int y2);

/**
Returns true if there exists a static path between the two given tile positions.

*/
    public static native boolean isConnected(TilePosition a, TilePosition b);

/**
Returns the ground distance between the two given tile positions.

*/
    public static native double getGroundDistance(TilePosition start, TilePosition end);


}
