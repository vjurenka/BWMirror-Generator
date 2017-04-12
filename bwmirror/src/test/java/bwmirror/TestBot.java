package bwmirror;

import bwapi.*;
import bwapi.Text.Size.Enum;
import bwta.BWTA;
import bwta.BaseLocation;
import bwta.Chokepoint;
import bwta.Polygon;

import java.util.List;

/**
 * User: PC
 * Date: 18. 6. 2014
 * Time: 14:55
 */

public class TestBot {


    public void run() {
        final Mirror mirror = new Mirror();
        mirror.getModule().setEventListener(new DefaultBWListener() {
            @Override
            public void onUnitCreate(Unit unit) {
                System.out.println("New unit " + unit.getType());
            }

            @Override
            public void onStart() {
                System.out.println("-------Analysing map-------");
                BWTA.readMap();
                BWTA.analyze();
                System.out.println();

                mirror.getGame().enableFlag(bwapi.Flag.Enum.UserInput.getValue());
            }

            @Override
            public void onEnd(boolean b) {
                System.out.println("Ended");
                //System.exit(0);
            }

            @Override
            public void onFrame() {
                Game game = mirror.getGame();
                Player self = game.self();


                System.out.println(UnitType.Terran_Command_Center.toString());
                System.out.println(UnitType.Terran_SCV.whatBuilds().first == UnitType.Terran_Command_Center);


                game.drawBoxScreen(0, 0, 100, 100, Color.Red, true);

                game.setTextSize(Enum.Large);
                game.drawTextScreen(10, 10, "Playing as " + self.getName() + " - " + self.getRace());

                StringBuilder units = new StringBuilder("My units:\n");
                System.out.println(Order.AIPatrol.toString());

                for (BaseLocation baseLocation : BWTA.getBaseLocations()) {
                    //System.out.println(baseLocation.getPosition());
                    //System.out.println(baseLocation.getTilePosition());
                }

                for (Chokepoint chokepoint : BWTA.getChokepoints()) {
                   // System.out.println(chokepoint.getCenter());
                }

                for (Player player : game.getPlayers()) {
                    // System.out.println(player.getName());
                    for (Unit enemyUnit : player.getUnits()) {
                        // System.out.println(enemyUnit.getType());
                    }
                }


                for (Unit myUnit : self.getUnits()) {
                    units.append(myUnit.getType()).append(" ").append(myUnit.getTilePosition()).append("\n");
                  //  System.out.println(myUnit.getPosition().toTilePosition());
                  //  System.out.println(myUnit.getTilePosition());


                    if (myUnit.getType() == UnitType.Zerg_Larva && self.minerals() >= 50) {
                        myUnit.morph(UnitType.Zerg_Drone);
                    }

                    if (myUnit.getType().isWorker() && myUnit.isIdle()) {
                        Unit closestMineral = null;

                        for (Unit neutralUnit : game.neutral().getUnits()) {
                            if (neutralUnit.getType().isMineralField()) {
                                if (closestMineral == null || myUnit.getDistance(neutralUnit) < myUnit.getDistance(closestMineral)) {
                                    closestMineral = neutralUnit;
                                }
                            }
                        }


                        if (closestMineral != null) {
                            //myUnit.gather(closestMineral, false);
                            //game.issueCommand(UnitCommand.gather(myUnit, closestMineral, false));
                            UnitCommand uc = UnitCommand.gather(myUnit, closestMineral);
                            myUnit.issueCommand(uc);
                        }
                    }
                }


                for (Unit myUnit : self.getUnits()) {
                    if (myUnit.getType() == UnitType.Zerg_Hatchery) {
                        Position p = myUnit.getPosition();
                        TilePosition t = myUnit.getTilePosition();

                        game.drawBoxMap(p.getX(), p.getY(), p.getX() + 20, p.getY() + 20, Color.Cyan);
                        game.drawTextMap(p.getX(), p.getY(), "Can build? " + game.canBuildHere(t, UnitType.Zerg_Spawning_Pool) + "\nHas Creep? " + game.hasCreep(t.getX(), t.getY()));
                    }

                    if (myUnit.getType() == UnitType.Terran_Command_Center && self.minerals() >= 50) {
                        myUnit.train(UnitType.Terran_SCV);
                    }
                }


                //draw my units on screen
                //game.drawTextScreen(10, 25, Utils.formatText("hello world", Utils.Blue));
                game.drawTextScreen(10, 25, Utils.formatText(units.toString(), Utils.Blue));
            }
        });
        /*
        mirror.setFrameCallback(new Mirror.FrameCallback() {
            @Override
            public void update() {


            }
        });
          */
        mirror.startGame();
        System.out.println("It's over");
    }

    public static void main(String... args) {
        new TestBot().run();
    }
}
