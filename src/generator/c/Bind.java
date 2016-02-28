package generator.c;

import c.CClass;
import c.CDeclaration;
import c.DeclarationType;
import c.Field;
import generator.CJavaPipeline;
import generator.JavaContext;
import impl.ClassVariable;

import java.io.PrintStream;
import java.util.List;

import static generator.JavaContext.checkBWAPI3brackets;

/**
 * User: PC
 * Date: 18. 6. 2014
 * Time: 11:51
 */
public class Bind {

    private PrintStream out;


    public void setOut(PrintStream out) {
        this.out = out;
    }

    private JavaContext context;

    public Bind(JavaContext context) {
        this.context = context;
    }

    private void implementBWAPIInit() {
        out.println("println(\"Attempting to init BWAPI...\");");
        out.println("\t\tBWAPI_init();");
        out.println("\t\tprintln(\"BWAPI ready.\");");
    }


    private void implementConnectionRoutine() {
        if (CJavaPipeline.isBWAPI3()) {
            out.println("            if (Broodwar != NULL) {\n" +
                    "\t\t\t\tprintln(\"Waiting...\");\n" +
                    "                while (!Broodwar->isInGame()) {\n" +
                    "                    BWAPIClient.update();\n" +
                    "\t\t\t\t\tif (Broodwar == NULL) {\n" +
                    "                            println(\"Match ended.\");\n" +
                    "                            return;\n" +
                    "                    }\n" +
                    "                }\n" +
                    "            }\n" +
                    "\n");
        } else {
            out.println("\t\t\t\tprintln(\"Waiting...\");\n" +
                    "while ( !Broodwar->isInGame() )\n" +
                    "    {\n" +
                    "      BWAPI::BWAPIClient.update();\n" +
                    "      if (!BWAPI::BWAPIClient.isConnected())\n" +
                    "      {\n" +
                    "        println(\"Reconnecting...\");\n" +
                    "        reconnect();\n" +
                    "      }\n" +
                    "    }");
        }
    }


    private void implementGameStart() {
        out.println("println(\"Connecting to Broodwar...\");\n" +
                "\t\treconnect();\n" +
                "\t\tprintln(\"Connection successful, starting match...\");\n" +
                "\n" +
                "\t\tcls = env->GetObjectClass(obj);\n" +
                "\t\tjclass gamecls = env->FindClass(\"L" + context.getPackageName() + "/Game;\");\n" +
                "\t\tjclass unitCls = env->FindClass(\"L" + context.getPackageName() + "/Unit;\");\n" +
                "\t\tjclass playerCls = env->FindClass(\"L" + context.getPackageName() + "/Player;\");\n" +
                "\t\tjclass posCls = env->FindClass(\"L" + context.getPackageName() + "/Position;\");\n" +
                "\t\tjobject moduleObj = env->GetObjectField(obj, env->GetFieldID(cls, \"module\", \"L" + context.getPackageName() + "/AIModule;\"));\n" +
                "\t\tjclass moduleCls = env->GetObjectClass(moduleObj);\n" +
                "\t\tenv->SetObjectField(obj, env->GetFieldID(cls, \"game\", \"L" + context.getPackageName() + "/Game;\"), " +
                "env->CallStaticObjectMethod(gamecls, env->GetStaticMethodID(gamecls, \"get\", \"(J)L" + context.getPackageName() + "/Game;\"), (long)Broodwar" + (CJavaPipeline.isBWAPI3() ? "" : "Ptr")+"));\n" +
                "\n" +
                "\t\tjmethodID updateMethodID = env->GetMethodID(env->GetObjectClass(obj), \"update\", \"()V\");");

        out.println("\t\tjmethodID matchStartCallback = env->GetMethodID(moduleCls, \"onStart\", \"()V\");\n" +
                "\t\tjmethodID matchEndCallback = env->GetMethodID(moduleCls, \"onEnd\", \"(Z)V\");\n" +
                "\t\tjmethodID matchFrameCallback = env->GetMethodID(moduleCls, \"onFrame\", \"()V\");\n" +
                "\t\tjmethodID sendTextCallback = env->GetMethodID(moduleCls, \"onSendText\", \"(Ljava/lang/String;)V\");\n" +
                "\t\tjmethodID receiveTextCallback = env->GetMethodID(moduleCls, \"onReceiveText\", \"(L" + context.getPackageName() + "/Player;Ljava/lang/String;)V\");\n" +
                "\t\tjmethodID playerLeftCallback = env->GetMethodID(moduleCls, \"onPlayerLeft\", \"(L" + context.getPackageName() + "/Player;)V\");\n" +
                "\t\tjmethodID nukeDetectCallback = env->GetMethodID(moduleCls, \"onNukeDetect\", \"(L" + context.getPackageName() + "/Position;)V\");\n" +
                "\t\tjmethodID unitDiscoverCallback = env->GetMethodID(moduleCls, \"onUnitDiscover\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID unitEvadeCallback = env->GetMethodID(moduleCls, \"onUnitEvade\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID unitShowCallback = env->GetMethodID(moduleCls, \"onUnitShow\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID unitHideCallback = env->GetMethodID(moduleCls, \"onUnitHide\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID unitCreateCallback = env->GetMethodID(moduleCls, \"onUnitCreate\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID unitDestroyCallback = env->GetMethodID(moduleCls, \"onUnitDestroy\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID unitMorphCallback = env->GetMethodID(moduleCls, \"onUnitMorph\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID unitRenegadeCallback = env->GetMethodID(moduleCls, \"onUnitRenegade\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID saveGameCallback = env->GetMethodID(moduleCls, \"onSaveGame\", \"(Ljava/lang/String;)V\");\n" +
                "\t\tjmethodID unitCompleteCallback = env->GetMethodID(moduleCls, \"onUnitComplete\", \"(L" + context.getPackageName() + "/Unit;)V\");\n" +
                "\t\tjmethodID playerDroppedCallback = env->GetMethodID(moduleCls, \"onPlayerDropped\", \"(L" + context.getPackageName() + "/Player;)V\");");

        out.println("\t\twhile (true) {\n");
        implementConnectionRoutine();
        out.println("\t\t\tprintln(\"Game ready!!!\");\n" +
                "\n" +
                "\t\t\twhile (Broodwar->isInGame()) {\n" +
                "\t\t\t\t\n" +
                "\t\t\t\tenv->CallVoidMethod(obj, updateMethodID);\n");
        out.println("\n" +
                "\t\t\t\tfor(std::list<Event>::const_iterator it = Broodwar->getEvents().begin(); it!=Broodwar->getEvents().end(); it++)\n" +
                "\t\t\t\t  {\n" +
                "\t\t\t\t\t  switch (it->getType()) {\n" +

                "\t\t\t\t\t\t  case EventType::MatchStart:\n" +
                (CJavaPipeline.isBWAPI3() ?
                        "\t\t\t\t\t\t\t  BWTA::BWTA_Result::regions.clear();\n" +
                                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::baselocations.clear();\n" +
                                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::startlocations.clear();\n" +
                                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::chokepoints.clear();\n" +
                                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::unwalkablePolygons.clear();\n" : "") +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, matchStartCallback);\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::MatchEnd:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, matchEndCallback, it->isWinner());\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::MatchFrame:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, matchFrameCallback);\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::SendText:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, sendTextCallback,  env->NewStringUTF(it->getText().c_str()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::ReceiveText:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, receiveTextCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, \"get\", \"(J)L" + context.getPackageName() + "/Player;\"), (jlong)it->getPlayer()), env->NewStringUTF(it->getText().c_str()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::PlayerLeft:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, playerLeftCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, \"get\", \"(J)L" + context.getPackageName() + "/Player;\"), (jlong)it->getPlayer()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::NukeDetect:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, nukeDetectCallback, env->NewObject(posCls, env->GetMethodID(posCls,\"<init>\", \"(II)V\"), it->getPosition().x" + checkBWAPI3brackets() + ", it->getPosition().y" + checkBWAPI3brackets() + "));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitDiscover:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitDiscoverCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitEvade:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitEvadeCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t   case EventType::UnitShow:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitShowCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitHide:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitHideCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitCreate:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitCreateCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitDestroy:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitDestroyCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitMorph:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitMorphCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitRenegade:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitRenegadeCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::SaveGame:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, saveGameCallback, env->NewStringUTF(it->getText().c_str()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitComplete:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitCompleteCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)L" + context.getPackageName() + "/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                (CJavaPipeline.isBWAPI3() ?
                        "\t\t\t\t\t\t  case EventType::PlayerDropped:\n" +
                                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, playerDroppedCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, \"get\", \"(J)L" + context.getPackageName() + "/Player;\")));\n" +
                                "\t\t\t\t\t\t  break;\n"
                        : "") +
                "\n" +
                "\t\t\t\t\t  }\n" +
                "\t\t\t\t  }");
        out.println(
                "\t\t\t\tBWAPIClient.update();\n" +
                        "\t\t\t\tif (!BWAPI::BWAPIClient.isConnected()) {\n" +
                        "\t\t\t\t\t\tprintln(\"Reconnecting...\");\n" +
                        "\t\t\t\t\t\treconnect();\n" +
                        "\t\t\t\t}\n" +
                        "\t\t\t}\n" +
                        (CJavaPipeline.isBWAPI3() ? "" : "println(\"Match ended.\");") +
                        "\t\t}");
    }

    private void implementHelpers() {
        if (CJavaPipeline.isBWAPI3()) {
            out.println("void reconnect()\n" +
                    "{\n" +
                    "\twhile (!BWAPIClient.connect()) {\n" +
                    "            Sleep(1000);\n" +
                    "    }\n" +
                    "}\n" +
                    "\n" +
                    "\n");
        } else {
            out.println("void reconnect()\n" +
                    "{\n" +
                    "\twhile (!BWAPIClient.connect()) {\n" +
                    "            std::this_thread::sleep_for(std::chrono::milliseconds{ 1000 });\n" +
                    "    }\n" +
                    "}\n" +
                    "\n" +
                    "\n");
        }

        out.println(
                "void flushPrint(const char * text){\n" +
                        "\tprintf(text);\n" +
                        "\tfflush(stdout); \n" +
                        "}\n" +
                        "\n" +
                        "void println(const char * text){\n" +
                        "\tprintf(text);\n" +
                        "\tflushPrint(\"\\n\");\n" +
                        "}\n");

    }

    private void implementMirrorInit(List<CDeclaration> declarationList) {
        implementHelpers();
        out.println("JNIEXPORT void JNICALL Java_" + context.getPackageName() + "_Mirror_startGame(JNIEnv * env, jobject obj){");
        if (CJavaPipeline.isBWAPI3()) {
            implementBWAPIInit();
        }
        implementVariablesBind(declarationList);
        implementGameStart();
        out.println("}");
        out.println();
    }

    private void implementVariablesBind(List<CDeclaration> declarationList) {
        out.println("jclass cls;");
        out.println("jmethodID getId;");
        out.println("jobject cst;");
        for (CDeclaration cDeclaration : declarationList) {
            if (cDeclaration.getDeclType().equals(DeclarationType.CLASS)) {
                bindVariables((CClass) cDeclaration);
            }
        }
    }

    private void bindVariables(CClass cClass) {
        boolean printedIntro = false;
        for (Field field : cClass.getFields()) {
            if (field.getDeclType().equals(DeclarationType.VARIABLE)) {
                if (!printedIntro) {
                    out.println("cls = env->FindClass(\"L" + context.getPackageName() + "/" + cClass.getName() + ";\");");
                    if (cClass.getName().equals("Color")) {
                        out.println("getId = env->GetMethodID(cls,\"<init>\", \"(III)V\");");
                    } else {
                        out.println("getId = env->GetStaticMethodID(cls, \"get\", \"(J)L" + context.getPackageName() + "/" + cClass.getName() + ";\");");
                    }
                    printedIntro = true;
                }
                bindVariable(cClass, (ClassVariable) field);
            }
        }
    }

    private void bindVariable(CClass cClass, ClassVariable classVariable) {

        String cValue = cClass.getName() + "s::" + classVariable.getName();

        if (cClass.getName().equals("Color")) {
            out.println(
                    "env->SetStaticObjectField(cls, " +
                            "env->GetStaticFieldID(cls, \"" + classVariable.getName() + "\", \"L" + context.getPackageName() + "/" + classVariable.getType() + ";\"), " +
                            "env->NewObject(cls, getId, " + cValue + ".red(), " + cValue + ".green(), " + cValue + ".blue())" +
                            ");");
            return;
        }

/*
        out.println("cst = env->GetStaticObjectField(" +
                "cls, " +
                "env->GetStaticFieldID(cls, \"" + classVariable.getName() + "\", \"L" + context.getPackageName() + "/" + classVariable.getType() + ";\")" + ");");
        out.println("env->SetLongField(cst, env->GetFieldID(cls, \"pointer\", \"j\"), (jlong)&" + cValue+");");
                                 */

        out.println(
                      "env->SetStaticObjectField(cls, " +
                              "env->GetStaticFieldID(cls, \"" + classVariable.getName() + "\", \"L" + context.getPackageName() + "/" + classVariable.getType() + ";\"), " +
                              "env->CallStaticObjectMethod(cls, getId, (jlong)&" + cValue + ")" +
                              ");");

        if (cClass.getName().equals("Position") || cClass.getName().equals("TilePosition") || cClass.getName().equals("WalkPosition") || cClass.getName().equals("Point")) {
            return;
        }
        out.println("table" + cClass.getName() + ".insert(std::pair<int, const " + cClass.getName() + "*>(" + cValue + ".getID(), &" + cValue + "));");
    }

    public void implementBind(List<CDeclaration> declarationList) {
        implementMirrorInit(declarationList);
    }

}
