package bwapi;

import bwapi.AIModule;
import bwapi.BWEventListener;

import java.io.*;
import java.io.File;
import java.lang.Exception;
import java.lang.UnsupportedOperationException;
import java.util.*;
import java.util.regex.Pattern;
import java.util.zip.*;

/**
 * <p>The API entry point. Standard use case:</p>
 * <ul>
 *     <li>Create a Mirror object and use {@link #getModule()} and then set an {@link AIModule}'s {@link BWEventListener}<br/>
 *     <li>Call {@link #startGame()} to init the API and connect to Broodwar, then launch Broodwar from ChaosLauncher.</li>
 *     <li>In you {@link BWEventListener#onStart()} method, receive the Game object by calling {@link #getGame()}</li>
 * </ul>
 * <br/>
 * <b>Example</b>
 * <pre>
 *     {@code
 *
 *     mirror.getModule().setEventListener(new DefaultBWListener()
 *     {
 *            public void onStart() {
 *                game = mirror.getGame();
 *                self = game.self();
 *                //initialization
 *                ....
 *            }
 *
 *           public void onUpdate() {
 *               for (Unit myUnit : self.getUnits()) {
 *                   //give orders to unit
 *                   ...
 *                }
 *           }
 *        });
 *     }
 *     mirror.startGame();
 * </pre>

 * <p><b>Note:</b> The Game object is initialized during the {@link #startGame()} as well as other BWMirror API's constants.
 * Do not use any API releated methods/fields prior to {@link #startGame()}.</p>

 */
public class Mirror {

    private Game game;

    private AIModule module = new AIModule();

    private FrameCallback frameCallback;

    private static final boolean EXTRACT_JAR = true;

    private static void extractResourceFile(String resourceFilename, String outputFilename) throws Exception {
        InputStream in = Thread.currentThread().getContextClassLoader().getResourceAsStream(resourceFilename);
        if (in == null)
            throw new FileNotFoundException("Resource file not found: " + resourceFilename);
        FileOutputStream out;
        try {
            out = new FileOutputStream(outputFilename);
        } catch (Exception e) {
            throw new FileNotFoundException("Could not open output file: " + outputFilename);
        }
        byte[] buffer = new byte[4096];
        int bytesRead;
        while ((bytesRead = in.read(buffer, 0, buffer.length)) != -1) {
            out.write(buffer, 0, bytesRead);
        }
        out.close();
        in.close();
    }

    private static boolean extractAndLoadNativeLibraries() {
        try {
            System.out.println("Extracting bwapi_bridge.dll");
            extractResourceFile("bwapi_bridge.dll", "./bwapi_bridge.dll");

            System.out.println("Extracting libgmp-10.dll");
            extractResourceFile("libgmp-10.dll", "./libgmp-10.dll");

            System.out.println("Extracting libmpfr-4.dll");
            extractResourceFile("libmpfr-4.dll", "./libmpfr-4.dll");

            System.out.println("Loading native library bwapi_bridge.dll");
            System.load(new File("./bwapi_bridge.dll").getAbsolutePath());

        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

        return true;
    }

    private static boolean extractBwtaDataFiles() {
        try {
            Collection<String> bwtaFilenames = ResourceList.getResources(Pattern.compile("bwapi\\-data/BWTA2/[a-zA-Z0-9]+\\.bwta"));

            System.out.println("Creating ./bwapi-data/BWTA2 directory");
            new File("./bwapi-data/BWTA2").mkdirs();

            System.out.println("Extracting " + bwtaFilenames.size() + " BWTA2 files:");
            for (String filename : bwtaFilenames) {
                System.out.println(filename);
                String outputFilename = "./" + filename;
                extractResourceFile(filename, outputFilename);
            }

        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

        return true;
    }

    static {
        String arch = System.getProperty("os.arch");
        if(!arch.equals("x86")){
            throw new UnsupportedOperationException("BWMirror API supports only x86 architecture.");
        }

        if (!extractAndLoadNativeLibraries())
            System.exit(1);
        if (!extractBwtaDataFiles())
            System.exit(1);
    }

    public Game getGame() {
        return game;
    }

    public AIModule getModule() {
        return module;
    }

    /**
     * Starts the API, initializes all constants ( {@link UnitType}, {@link WeaponType} ) and the {@link Game} object.
     * This method blocks until the end of game.
     */
    public native void startGame();

    private void update() {
        if (frameCallback != null) {
            frameCallback.update();
        }
    }

    /*public void setFrameCallback(bwapi.Mirror.FrameCallback frameCallback) {
        this.frameCallback = frameCallback;
    } */

    /**
     * The simplest interface to receive update event from Broodwar. The {@link #update()} method is called once each frame.
     * For a simple bot and implementation of this interface is enough, to receive all in game events, implement {@link BWEventListener}.
     */
    /*public*/ private interface FrameCallback {
        public void update();
    }
}