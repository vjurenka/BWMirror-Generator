package generator.c;

import c.CClass;
import c.CDeclaration;
import c.DeclarationType;
import c.Field;
import generator.CJavaPipeline;
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

    private void implementBWAPIInit() {
        out.println("println(\"Attempting to init BWAPI...\");");
        out.println("\t\tBWAPI_init();");
        out.println("\t\tprintln(\"BWAPI ready.\");");
    }

    private String broodwarPtrSuffix() {
        if (!CJavaPipeline.isBWAPI3()) {
            return "ptr";
        }
        return "";
    }

    private void implementGameStart() {
        out.println("println(\"Connecting to Broodwar...\");\n" +
                "\t\treconnect();\n" +
                "\t\tprintln(\"Connection successful, starting match...\");\n" +
                "\n" +
                "\t\tcls = env->GetObjectClass(obj);\n" +
                "\t\tjclass gamecls = env->FindClass(\"Lbwapi/Game;\");\n" +
                "\t\tjclass unitCls = env->FindClass(\"Lbwapi/Unit;\");\n" +
                "\t\tjclass playerCls = env->FindClass(\"Lbwapi/Player;\");\n" +
                "\t\tjclass posCls = env->FindClass(\"Lbwapi/Position;\");\n" +
                "\t\tjobject moduleObj = env->GetObjectField(obj, env->GetFieldID(cls, \"module\", \"Lbwapi/AIModule;\"));\n" +
                "\t\tjclass moduleCls = env->GetObjectClass(moduleObj);\n" +
                "\t\tenv->SetObjectField(obj, env->GetFieldID(cls, \"game\", \"Lbwapi/Game;\"), " +
                "env->CallStaticObjectMethod(gamecls, env->GetStaticMethodID(gamecls, \"get\", \"(J)Lbwapi/Game;\"), (long)Broodwar" + broodwarPtrSuffix() + "));\n" +
                "\n" +
                "\t\tjmethodID updateMethodID = env->GetMethodID(env->GetObjectClass(obj), \"update\", \"()V\");");

        out.println("\t\tjmethodID matchStartCallback = env->GetMethodID(moduleCls, \"onStart\", \"()V\");\n" +
                "\t\tjmethodID matchEndCallback = env->GetMethodID(moduleCls, \"onEnd\", \"(Z)V\");\n" +
                "\t\tjmethodID matchFrameCallback = env->GetMethodID(moduleCls, \"onFrame\", \"()V\");\n" +
                "\t\tjmethodID sendTextCallback = env->GetMethodID(moduleCls, \"onSendText\", \"(Ljava/lang/String;)V\");\n" +
                "\t\tjmethodID receiveTextCallback = env->GetMethodID(moduleCls, \"onReceiveText\", \"(Lbwapi/Player;Ljava/lang/String;)V\");\n" +
                "\t\tjmethodID playerLeftCallback = env->GetMethodID(moduleCls, \"onPlayerLeft\", \"(Lbwapi/Player;)V\");\n" +
                "\t\tjmethodID nukeDetectCallback = env->GetMethodID(moduleCls, \"onNukeDetect\", \"(Lbwapi/Position;)V\");\n" +
                "\t\tjmethodID unitDiscoverCallback = env->GetMethodID(moduleCls, \"onUnitDiscover\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID unitEvadeCallback = env->GetMethodID(moduleCls, \"onUnitEvade\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID unitShowCallback = env->GetMethodID(moduleCls, \"onUnitShow\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID unitHideCallback = env->GetMethodID(moduleCls, \"onUnitHide\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID unitCreateCallback = env->GetMethodID(moduleCls, \"onUnitCreate\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID unitDestroyCallback = env->GetMethodID(moduleCls, \"onUnitDestroy\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID unitMorphCallback = env->GetMethodID(moduleCls, \"onUnitMorph\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID unitRenegadeCallback = env->GetMethodID(moduleCls, \"onUnitRenegade\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID saveGameCallback = env->GetMethodID(moduleCls, \"onSaveGame\", \"(Ljava/lang/String;)V\");\n" +
                "\t\tjmethodID unitCompleteCallback = env->GetMethodID(moduleCls, \"onUnitComplete\", \"(Lbwapi/Unit;)V\");\n" +
                "\t\tjmethodID playerDroppedCallback = env->GetMethodID(moduleCls, \"onPlayerDropped\", \"(Lbwapi/Player;)V\");");

        out.println(
                "\t\twhile (true) {\n" +
                        "            if (Broodwar" + broodwarPtrSuffix() + " != NULL) {\n" +
                        "\t\t\t\tprintln(\"Waiting...\");\n" +
                        "                while (!Broodwar" + broodwarPtrSuffix() + "->isInGame()) {\n" +
                        "                    BWAPIClient.update();\n" +
                        "\t\t\t\t\tif (Broodwar" + broodwarPtrSuffix() + " == NULL) {\n" +
                        "                            println(\"Match ended.\");\n" +
                        "                            return;\n" +
                        "                    }\n" +
                        "                }\n" +
                        "            }\n" +
                        "\n" +
                        "\t\t\tprintln(\"Game ready!!!\");\n" +
                        "\n" +
                        "\t\t\twhile (Broodwar->isInGame()) {\n" +
                        "\t\t\t\t\n" +
                        "\t\t\t\tenv->CallVoidMethod(obj, updateMethodID);\n");
        out.println("\n" +
                "\t\t\t\tfor(std::list<Event>::const_iterator it = Broodwar->getEvents().begin(); it!=Broodwar->getEvents().end(); it++)\n" +
                "\t\t\t\t  {\n" +
                "\t\t\t\t\t  switch (it->getType()) {\n" +
                "\t\t\t\t\t\t  case EventType::MatchStart:\n" +
                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::regions.clear();\n" +
                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::baselocations.clear();\n" +
                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::startlocations.clear();\n" +
                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::chokepoints.clear();\n" +
                "\t\t\t\t\t\t\t  BWTA::BWTA_Result::unwalkablePolygons.clear();\n" +
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
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, receiveTextCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, \"get\", \"(J)Lbwapi/Player;\"), (jlong)it->getPlayer()), env->NewStringUTF(it->getText().c_str()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::PlayerLeft:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, playerLeftCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, \"get\", \"(J)Lbwapi/Player;\"), (jlong)it->getPlayer()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::NukeDetect:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, nukeDetectCallback, env->NewObject(posCls, env->GetMethodID(posCls,\"<init>\", \"(II)V\"), it->getPosition().x" + checkBWAPI3brackets() + ", it->getPosition().y" + checkBWAPI3brackets() + "));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitDiscover:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitDiscoverCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitEvade:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitEvadeCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t   case EventType::UnitShow:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitShowCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitHide:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitHideCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitCreate:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitCreateCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitDestroy:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitDestroyCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitMorph:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitMorphCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitRenegade:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitRenegadeCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::SaveGame:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, saveGameCallback, env->NewStringUTF(it->getText().c_str()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                "\t\t\t\t\t\t  case EventType::UnitComplete:\n" +
                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, unitCompleteCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, \"get\", \"(J)Lbwapi/Unit;\"), (jlong)it->getUnit()));\n" +
                "\t\t\t\t\t\t  break;\n" +
                (CJavaPipeline.isBWAPI3() ?
                        "\t\t\t\t\t\t  case EventType::PlayerDropped:\n" +
                                "\t\t\t\t\t\t\t  env->CallVoidMethod(moduleObj, playerDroppedCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, \"get\", \"(J)Lbwapi/Player;\")));\n" +
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
                        "\t\t}");
    }

    private void implementHelpers() {
        out.println("void reconnect()\n" +
                "{\n" +
                "\twhile (!BWAPIClient.connect()) {\n" +
                "            Sleep(1000);\n" +
                "    }\n" +
                "}\n" +
                "\n" +
                "\n" +
                "\n" +
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
        out.println("JNIEXPORT void JNICALL Java_bwapi_Mirror_startGame(JNIEnv * env, jobject obj){");
        implementBWAPIInit();
        implementVariablesBind(declarationList);
        implementGameStart();
        out.println("}");
        out.println();
    }

    private void implementVariablesBind(List<CDeclaration> declarationList) {
        out.println("jclass cls;");
        out.println("jmethodID getId;");
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
                    out.println("cls = env->FindClass(\"Lbwapi/" + cClass.getName() + ";\");");
                    if (cClass.getName().equals("Color")) {
                        out.println("getId = env->GetMethodID(cls,\"<init>\", \"(III)V\");");
                    } else {
                        out.println("getId = env->GetStaticMethodID(cls, \"get\", \"(J)Lbwapi/" + cClass.getName() + ";\");");
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
                            "env->GetStaticFieldID(cls, \"" + classVariable.getName() + "\", \"Lbwapi/" + classVariable.getType() + ";\"), " +
                            "env->NewObject(cls, getId, " + cValue + ".red(), " + cValue + ".green(), " + cValue + ".blue())" +
                            ");");
            return;
        }
        out.println(
                "env->SetStaticObjectField(cls, " +
                        "env->GetStaticFieldID(cls, \"" + classVariable.getName() + "\", \"Lbwapi/" + classVariable.getType() + ";\"), " +
                        "env->CallStaticObjectMethod(cls, getId, (jlong)&" + cValue + ")" +
                        ");");
        if (cClass.getName().equals("Position") || cClass.getName().equals("TilePosition")) {
            return;
        }
        out.println("table" + cClass.getName() + ".insert(std::pair<int, const " + cClass.getName() + "*>(" + cValue + ".getID(), &" + cValue + "));");
    }

    public void implementBind(List<CDeclaration> declarationList) {
        implementMirrorInit(declarationList);
    }

}
