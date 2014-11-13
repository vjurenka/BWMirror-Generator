#include "../concat_header.h"
#include <BWAPI.h>
#include <BWAPI/Client.h>
#include <BWTA.h>
#include <jni.h>
#include <cstring>

using namespace BWAPI;

std::map<int, const Color*> tableColor;

using namespace std;

map<string, jclass> clsCache;
map<pair<jclass, pair<string, string>>, jmethodID> staticMethodCache;
map<pair<jclass, pair<string, string>>, jmethodID> methodCache;
map<pair<jclass, pair<string, string>>, jfieldID> fieldCache;


jclass FindCachedClass(JNIEnv * env, string name){
	if(clsCache.find(name) == clsCache.end()){
		clsCache.insert(pair<string, jclass>(name, (jclass)env->NewGlobalRef(env->FindClass(name.c_str()))));
	}
	 return clsCache.find(name)->second;
};

jmethodID FindCachedMethodStatic(JNIEnv * env, jclass clz, string name, string signature){
	pair<jclass, pair<string, string>> clsNameSig(clz, pair<string, string>(name, signature));
	if(staticMethodCache.find(clsNameSig) == staticMethodCache.end()){
		staticMethodCache.insert(pair<pair<jclass, pair<string, string>>, jmethodID> (clsNameSig, env->GetStaticMethodID(clz, name.c_str(), signature.c_str())));
	}
	 return staticMethodCache.find(clsNameSig)->second;
};

jmethodID FindCachedMethod(JNIEnv * env, jclass clz, string name, string signature){
	pair<jclass, pair<string, string>> clsNameSig(clz, pair<string, string>(name, signature));
	if(methodCache.find(clsNameSig) == methodCache.end()){
		methodCache.insert(pair<pair<jclass, pair<string, string>>, jmethodID>(clsNameSig, env->GetMethodID(clz, name.c_str(), signature.c_str())));
	}
	 return methodCache.find(clsNameSig)->second;
};

jfieldID FindCachedField(JNIEnv * env, jclass clz, string name, string signature){
	pair<jclass, pair<string, string>> clsNameSig(clz, pair<string, string>(name, signature));
	if(fieldCache.find(clsNameSig) == fieldCache.end()){
		fieldCache.insert(pair<pair<jclass, pair<string, string>>, jfieldID>(clsNameSig, env->GetFieldID(clz, name.c_str(), signature.c_str())));
	}
	 return fieldCache.find(clsNameSig)->second;
};

using namespace BWAPI;

JNIEXPORT void JNICALL Java_bwapi4_AIModule_onStart_1native(JNIEnv * env, jobject obj, jlong pointer){
AIModule* x_aIModule = (AIModule*)pointer;
x_aIModule->onStart();
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onEnd_1native(JNIEnv * env, jobject obj, jlong pointer, jboolean isWinner){
AIModule* x_aIModule = (AIModule*)pointer;
x_aIModule->onEnd((bool)isWinner);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onFrame_1native(JNIEnv * env, jobject obj, jlong pointer){
AIModule* x_aIModule = (AIModule*)pointer;
x_aIModule->onFrame();
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onSendText_1native(JNIEnv * env, jobject obj, jlong pointer, jstring text){
AIModule* x_aIModule = (AIModule*)pointer;
x_aIModule->onSendText(std::string(env->GetStringUTFChars(text, NULL)));
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onReceiveText_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_player, jstring text){
AIModule* x_aIModule = (AIModule*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
x_aIModule->onReceiveText(player, std::string(env->GetStringUTFChars(text, NULL)));
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onPlayerLeft_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
AIModule* x_aIModule = (AIModule*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
x_aIModule->onPlayerLeft(player);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onNukeDetect_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
AIModule* x_aIModule = (AIModule*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
x_aIModule->onNukeDetect(target);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitDiscover_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitDiscover(unit);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitEvade_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitEvade(unit);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitShow_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitShow(unit);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitHide_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitHide(unit);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitCreate_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitCreate(unit);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitDestroy_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitDestroy(unit);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitMorph_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitMorph(unit);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitRenegade_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitRenegade(unit);
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onSaveGame_1native(JNIEnv * env, jobject obj, jlong pointer, jstring gameName){
AIModule* x_aIModule = (AIModule*)pointer;
x_aIModule->onSaveGame(std::string(env->GetStringUTFChars(gameName, NULL)));
}
JNIEXPORT void JNICALL Java_bwapi4_AIModule_onUnitComplete_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
AIModule* x_aIModule = (AIModule*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
x_aIModule->onUnitComplete(unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Bullet_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getID();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Bullet_exists_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->exists();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Bullet_getPlayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
jlong resptr = (jlong)x_bullet->getPlayer();
jclass retcls = FindCachedClass(env, "bwapi4/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Bullet_getType_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
jlong resptr = (jlong)x_bullet->getType();
jclass retcls = FindCachedClass(env, "bwapi4/BulletType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/BulletType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Bullet_getSource_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
jlong resptr = (jlong)x_bullet->getSource();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Bullet_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
Position cresult = x_bullet->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Bullet_getAngle_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getAngle();
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Bullet_getVelocityX_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getVelocityX();
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Bullet_getVelocityY_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getVelocityY();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Bullet_getTarget_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
jlong resptr = (jlong)x_bullet->getTarget();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Bullet_getTargetPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
Position cresult = x_bullet->getTargetPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jint JNICALL Java_bwapi4_Bullet_getRemoveTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getRemoveTimer();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Bullet_isVisible_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->isVisible();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Bullet_isVisible_1native__JLbwapi4_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Bullet* x_bullet = (Bullet*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_bullet->isVisible(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Client_isConnected_1native(JNIEnv * env, jobject obj, jlong pointer){
Client* x_client = (Client*)pointer;
return x_client->isConnected();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Client_connect_1native(JNIEnv * env, jobject obj, jlong pointer){
Client* x_client = (Client*)pointer;
return x_client->connect();
}
JNIEXPORT void JNICALL Java_bwapi4_Client_disconnect_1native(JNIEnv * env, jobject obj, jlong pointer){
Client* x_client = (Client*)pointer;
x_client->disconnect();
}
JNIEXPORT void JNICALL Java_bwapi4_Client_update_1native(JNIEnv * env, jobject obj, jlong pointer){
Client* x_client = (Client*)pointer;
x_client->update();
}
JNIEXPORT jint JNICALL Java_bwapi4_Color_red_1native(JNIEnv * env, jobject obj, jlong pointer){
Color x_color((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "r", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "g", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "b", "I")));
return x_color.red();
}
JNIEXPORT jint JNICALL Java_bwapi4_Color_green_1native(JNIEnv * env, jobject obj, jlong pointer){
Color x_color((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "r", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "g", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "b", "I")));
return x_color.green();
}
JNIEXPORT jint JNICALL Java_bwapi4_Color_blue_1native(JNIEnv * env, jobject obj, jlong pointer){
Color x_color((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "r", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "g", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "b", "I")));
return x_color.blue();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Event_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
Position cresult = x_evt->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jstring JNICALL Java_bwapi4_Event_getText_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
return env->NewStringUTF(x_evt->getText().c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi4_Event_getUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
jlong resptr = (jlong)x_evt->getUnit();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Event_getPlayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
jlong resptr = (jlong)x_evt->getPlayer();
jclass retcls = FindCachedClass(env, "bwapi4/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Event_isWinner_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
return x_evt->isWinner();
}
JNIEXPORT jint JNICALL Java_bwapi4_Force_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Force* x_force = (Force*)pointer;
return x_force->getID();
}
JNIEXPORT jstring JNICALL Java_bwapi4_Force_getName_1native(JNIEnv * env, jobject obj, jlong pointer){
Force* x_force = (Force*)pointer;
return env->NewStringUTF(x_force->getName().c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi4_Force_getPlayers_1native(JNIEnv * env, jobject obj, jlong pointer){
Force* x_force = (Force*)pointer;
jlong resptr = (jlong)x_force->getPlayers();
jclass retcls = FindCachedClass(env, "bwapi4/Playerset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Playerset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Forceset_getPlayers_1native(JNIEnv * env, jobject obj, jlong pointer){
Forceset* x_forceset = (Forceset*)pointer;
jlong resptr = (jlong)x_forceset->getPlayers();
jclass retcls = FindCachedClass(env, "bwapi4/Playerset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Playerset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getForces_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getForces();
jclass retcls = FindCachedClass(env, "bwapi4/Forceset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Forceset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getPlayers_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getPlayers();
jclass retcls = FindCachedClass(env, "bwapi4/Playerset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Playerset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getAllUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getAllUnits();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getMinerals();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getGeysers_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getGeysers();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getNeutralUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getNeutralUnits();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getStaticMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getStaticMinerals();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getStaticGeysers_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getStaticGeysers();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getStaticNeutralUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getStaticNeutralUnits();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getBullets_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getBullets();
jclass retcls = FindCachedClass(env, "bwapi4/Bulletset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Bulletset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getForce_1native(JNIEnv * env, jobject obj, jlong pointer, jint forceID){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getForce(forceID);
jclass retcls = FindCachedClass(env, "bwapi4/Force");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Force;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getPlayer_1native(JNIEnv * env, jobject obj, jlong pointer, jint playerID){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getPlayer(playerID);
jclass retcls = FindCachedClass(env, "bwapi4/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getUnit_1native(JNIEnv * env, jobject obj, jlong pointer, jint unitID){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getUnit(unitID);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_indexToUnit_1native(JNIEnv * env, jobject obj, jlong pointer, jint unitIndex){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->indexToUnit(unitIndex);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getRegion_1native(JNIEnv * env, jobject obj, jlong pointer, jint regionID){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getRegion(regionID);
jclass retcls = FindCachedClass(env, "bwapi4/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getGameType_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)tableGameType.find(x_game->getGameType())->second;
jclass retcls = FindCachedClass(env, "bwapi4/GameType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/GameType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getLatency_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getLatency();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getFrameCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getFrameCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getReplayFrameCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getReplayFrameCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getFPS_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getFPS();
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Game_getAverageFPS_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getAverageFPS();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getMousePosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
Position cresult = x_game->getMousePosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_getMouseState_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_button){
Game* x_game = (Game*)pointer;
MouseButton button = (MouseButton)(int)env->GetIntField(p_button, FindCachedField(env, env->GetObjectClass(p_button), "value", "I"));
return x_game->getMouseState(button);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_getKeyState_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_key){
Game* x_game = (Game*)pointer;
Key key = (Key)(int)env->GetIntField(p_key, FindCachedField(env, env->GetObjectClass(p_key), "value", "I"));
return x_game->getKeyState(key);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getScreenPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
Position cresult = x_game->getScreenPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setScreenPosition_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y){
Game* x_game = (Game*)pointer;
x_game->setScreenPosition(x, y);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setScreenPosition_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
x_game->setScreenPosition(p);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_pingMinimap_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y){
Game* x_game = (Game*)pointer;
x_game->pingMinimap(x, y);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_pingMinimap_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
x_game->pingMinimap(p);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isFlagEnabled_1native(JNIEnv * env, jobject obj, jlong pointer, jint flag){
Game* x_game = (Game*)pointer;
return x_game->isFlagEnabled(flag);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_enableFlag_1native(JNIEnv * env, jobject obj, jlong pointer, jint flag){
Game* x_game = (Game*)pointer;
x_game->enableFlag(flag);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getUnitsOnTile_1native__JIILbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jobject p_pred){
Game* x_game = (Game*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getUnitsOnTile(tileX, tileY, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getUnitsOnTile_1native__JLbwapi4_TilePosition_2Lbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tile, jobject p_pred){
Game* x_game = (Game*)pointer;
TilePosition tile((int)env->GetIntField(p_tile, FindCachedField(env, env->GetObjectClass(p_tile), "x", "I")), (int)env->GetIntField(p_tile, FindCachedField(env, env->GetObjectClass(p_tile), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getUnitsOnTile(tile, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getUnitsInRectangle_1native__JIIIILbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_pred){
Game* x_game = (Game*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getUnitsInRectangle(left, top, right, bottom, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getUnitsInRectangle_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_topLeft, jobject p_bottomRight, jobject p_pred){
Game* x_game = (Game*)pointer;
Position topLeft((int)env->GetIntField(p_topLeft, FindCachedField(env, env->GetObjectClass(p_topLeft), "x", "I")), (int)env->GetIntField(p_topLeft, FindCachedField(env, env->GetObjectClass(p_topLeft), "y", "I")));
Position bottomRight((int)env->GetIntField(p_bottomRight, FindCachedField(env, env->GetObjectClass(p_bottomRight), "x", "I")), (int)env->GetIntField(p_bottomRight, FindCachedField(env, env->GetObjectClass(p_bottomRight), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getUnitsInRectangle(topLeft, bottomRight, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getUnitsInRadius_1native__JIIILbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_pred){
Game* x_game = (Game*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getUnitsInRadius(x, y, radius, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getUnitsInRadius_1native__JLbwapi4_Position_2ILbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jint radius, jobject p_pred){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getUnitsInRadius(center, radius, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getClosestUnit_1native__JLbwapi4_Position_2Lbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jobject p_pred){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getClosestUnit(center, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getClosestUnit_1native__JLbwapi4_Position_2Lbwapi4_UnitFilter_2I(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jobject p_pred, jint radius){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getClosestUnit(center, pred, radius);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getClosestUnitInRectangle_1native__JLbwapi4_Position_2Lbwapi4_UnitFilter_2III(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jobject p_pred, jint left, jint top, jint right){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getClosestUnitInRectangle(center, pred, left, top, right);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getClosestUnitInRectangle_1native__JLbwapi4_Position_2Lbwapi4_UnitFilter_2II(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jobject p_pred, jint left, jint top){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getClosestUnitInRectangle(center, pred, left, top);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getClosestUnitInRectangle_1native__JLbwapi4_Position_2Lbwapi4_UnitFilter_2I(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jobject p_pred, jint left){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getClosestUnitInRectangle(center, pred, left);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getClosestUnitInRectangle_1native__JLbwapi4_Position_2Lbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jobject p_pred){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getClosestUnitInRectangle(center, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getClosestUnitInRectangle_1native__JLbwapi4_Position_2Lbwapi4_UnitFilter_2IIII(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jobject p_pred, jint left, jint top, jint right, jint bottom){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getClosestUnitInRectangle(center, pred, left, top, right, bottom);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getBestUnit_1native__JLbwapi4_BestUnitFilter_2Lbwapi4_UnitFilter_2Lbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_best, jobject p_pred, jobject p_center){
Game* x_game = (Game*)pointer;
BestUnitFilter* best = (BestUnitFilter*)env->GetLongField(p_best, FindCachedField(env, env->GetObjectClass(p_best), "pointer", "J"));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
jlong resptr = (jlong)x_game->getBestUnit(best, pred, center);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getBestUnit_1native__JLbwapi4_BestUnitFilter_2Lbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_best, jobject p_pred){
Game* x_game = (Game*)pointer;
BestUnitFilter* best = (BestUnitFilter*)env->GetLongField(p_best, FindCachedField(env, env->GetObjectClass(p_best), "pointer", "J"));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_game->getBestUnit(best, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getBestUnit_1native__JLbwapi4_BestUnitFilter_2Lbwapi4_UnitFilter_2Lbwapi4_Position_2I(JNIEnv * env, jobject obj, jlong pointer, jobject p_best, jobject p_pred, jobject p_center, jint radius){
Game* x_game = (Game*)pointer;
BestUnitFilter* best = (BestUnitFilter*)env->GetLongField(p_best, FindCachedField(env, env->GetObjectClass(p_best), "pointer", "J"));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
jlong resptr = (jlong)x_game->getBestUnit(best, pred, center, radius);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getLastError_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)tableError.find(x_game->getLastError())->second;
jclass retcls = FindCachedClass(env, "bwapi4/Error");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Error;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setLastError_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->setLastError();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setLastError_1native__JLbwapi4_Error_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_e){
Game* x_game = (Game*)pointer;
Error* e = (Error*)env->GetLongField(p_e, FindCachedField(env, env->GetObjectClass(p_e), "pointer", "J"));
return x_game->setLastError(*e);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_mapWidth_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->mapWidth();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_mapHeight_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->mapHeight();
}
JNIEXPORT jstring JNICALL Java_bwapi4_Game_mapFileName_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return env->NewStringUTF(x_game->mapFileName().c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi4_Game_mapPathName_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return env->NewStringUTF(x_game->mapPathName().c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi4_Game_mapName_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return env->NewStringUTF(x_game->mapName().c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi4_Game_mapHash_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return env->NewStringUTF(x_game->mapHash().c_str());
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isWalkable_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint walkX, jint walkY){
Game* x_game = (Game*)pointer;
return x_game->isWalkable(walkX, walkY);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isWalkable_1native__JLbwapi4_WalkPosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
WalkPosition* position = (WalkPosition*)env->GetLongField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "pointer", "J"));
return x_game->isWalkable(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isBuildable_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->isBuildable(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isBuildable_1native__JIIZ(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jboolean includeBuildings){
Game* x_game = (Game*)pointer;
return x_game->isBuildable(tileX, tileY, (bool)includeBuildings);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isBuildable_1native__JLbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->isBuildable(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isBuildable_1native__JLbwapi4_TilePosition_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jboolean includeBuildings){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->isBuildable(position, (bool)includeBuildings);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isVisible_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->isVisible(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isVisible_1native__JLbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->isVisible(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isExplored_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->isExplored(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isExplored_1native__JLbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->isExplored(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasCreep_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->hasCreep(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasCreep_1native__JLbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->hasCreep(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPowerPrecise_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y){
Game* x_game = (Game*)pointer;
return x_game->hasPowerPrecise(x, y);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPowerPrecise_1native__JIILbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jobject p_unitType){
Game* x_game = (Game*)pointer;
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPowerPrecise(x, y, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPowerPrecise_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->hasPowerPrecise(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPowerPrecise_1native__JLbwapi4_Position_2Lbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jobject p_unitType){
Game* x_game = (Game*)pointer;
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPowerPrecise(position, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPower_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->hasPower(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPower_1native__JIILbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jobject p_unitType){
Game* x_game = (Game*)pointer;
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPower(tileX, tileY, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPower_1native__JLbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->hasPower(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPower_1native__JLbwapi4_TilePosition_2Lbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jobject p_unitType){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPower(position, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPower_1native__JIIII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jint tileWidth, jint tileHeight){
Game* x_game = (Game*)pointer;
return x_game->hasPower(tileX, tileY, tileWidth, tileHeight);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPower_1native__JIIIILbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jint tileWidth, jint tileHeight, jobject p_unitType){
Game* x_game = (Game*)pointer;
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPower(tileX, tileY, tileWidth, tileHeight, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPower_1native__JLbwapi4_TilePosition_2II(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jint tileWidth, jint tileHeight){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->hasPower(position, tileWidth, tileHeight);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPower_1native__JLbwapi4_TilePosition_2IILbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jint tileWidth, jint tileHeight, jobject p_unitType){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPower(position, tileWidth, tileHeight, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canBuildHere_1native__JLbwapi4_TilePosition_2Lbwapi4_UnitType_2Lbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jobject p_type, jobject p_builder){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
Unit* builder = (Unit*)env->GetLongField(p_builder, FindCachedField(env, env->GetObjectClass(p_builder), "pointer", "J"));
return x_game->canBuildHere(position, *type, builder);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canBuildHere_1native__JLbwapi4_TilePosition_2Lbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jobject p_type){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canBuildHere(position, *type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canBuildHere_1native__JLbwapi4_TilePosition_2Lbwapi4_UnitType_2Lbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jobject p_type, jobject p_builder, jboolean checkExplored){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
Unit* builder = (Unit*)env->GetLongField(p_builder, FindCachedField(env, env->GetObjectClass(p_builder), "pointer", "J"));
return x_game->canBuildHere(position, *type, builder, (bool)checkExplored);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canMake_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Game* x_game = (Game*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canMake(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canMake_1native__JLbwapi4_UnitType_2Lbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_builder){
Game* x_game = (Game*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
Unit* builder = (Unit*)env->GetLongField(p_builder, FindCachedField(env, env->GetObjectClass(p_builder), "pointer", "J"));
return x_game->canMake(*type, builder);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canResearch_1native__JLbwapi4_TechType_2Lbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_unit){
Game* x_game = (Game*)pointer;
TechType* type = (TechType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_game->canResearch(*type, unit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canResearch_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Game* x_game = (Game*)pointer;
TechType* type = (TechType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canResearch(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canResearch_1native__JLbwapi4_TechType_2Lbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_unit, jboolean checkCanIssueCommandType){
Game* x_game = (Game*)pointer;
TechType* type = (TechType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_game->canResearch(*type, unit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canUpgrade_1native__JLbwapi4_UpgradeType_2Lbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_unit){
Game* x_game = (Game*)pointer;
UpgradeType* type = (UpgradeType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_game->canUpgrade(*type, unit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canUpgrade_1native__JLbwapi4_UpgradeType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Game* x_game = (Game*)pointer;
UpgradeType* type = (UpgradeType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canUpgrade(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_canUpgrade_1native__JLbwapi4_UpgradeType_2Lbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_unit, jboolean checkCanIssueCommandType){
Game* x_game = (Game*)pointer;
UpgradeType* type = (UpgradeType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_game->canUpgrade(*type, unit, (bool)checkCanIssueCommandType);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_vPrintf_1native(JNIEnv * env, jobject obj, jlong pointer, jstring cstr_format, jobject p_...){
Game* x_game = (Game*)pointer;
Object* ... = (Object*)env->GetLongField(p_..., FindCachedField(env, env->GetObjectClass(p_...), "pointer", "J"));
x_game->vPrintf(std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str(), ...);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_vSendText_1native(JNIEnv * env, jobject obj, jlong pointer, jstring cstr_format, jobject p_...){
Game* x_game = (Game*)pointer;
Object* ... = (Object*)env->GetLongField(p_..., FindCachedField(env, env->GetObjectClass(p_...), "pointer", "J"));
x_game->vSendText(std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str(), ...);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_vSendTextEx_1native(JNIEnv * env, jobject obj, jlong pointer, jboolean toAllies, jstring cstr_format, jobject p_...){
Game* x_game = (Game*)pointer;
Object* ... = (Object*)env->GetLongField(p_..., FindCachedField(env, env->GetObjectClass(p_...), "pointer", "J"));
x_game->vSendTextEx((bool)toAllies, std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str(), ...);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isInGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isInGame();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isMultiplayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isMultiplayer();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isBattleNet_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isBattleNet();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isPaused_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isPaused();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isReplay_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isReplay();
}
JNIEXPORT void JNICALL Java_bwapi4_Game_pauseGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->pauseGame();
}
JNIEXPORT void JNICALL Java_bwapi4_Game_resumeGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->resumeGame();
}
JNIEXPORT void JNICALL Java_bwapi4_Game_leaveGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->leaveGame();
}
JNIEXPORT void JNICALL Java_bwapi4_Game_restartGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->restartGame();
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setLocalSpeed_1native(JNIEnv * env, jobject obj, jlong pointer, jint speed){
Game* x_game = (Game*)pointer;
x_game->setLocalSpeed(speed);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_issueCommand_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_units, jobject p_command){
Game* x_game = (Game*)pointer;
Unitset* units = (Unitset*)env->GetLongField(p_units, FindCachedField(env, env->GetObjectClass(p_units), "pointer", "J"));
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_game->issueCommand(units, *command);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getSelectedUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getSelectedUnits();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_self_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->self();
jclass retcls = FindCachedClass(env, "bwapi4/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_enemy_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->enemy();
jclass retcls = FindCachedClass(env, "bwapi4/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_neutral_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->neutral();
jclass retcls = FindCachedClass(env, "bwapi4/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_allies_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->allies();
jclass retcls = FindCachedClass(env, "bwapi4/Playerset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Playerset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_enemies_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->enemies();
jclass retcls = FindCachedClass(env, "bwapi4/Playerset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Playerset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_observers_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->observers();
jclass retcls = FindCachedClass(env, "bwapi4/Playerset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Playerset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setTextSize_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->setTextSize();
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setTextSize_1native__JLbwapi4_Text_Size_Enum_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_size){
Game* x_game = (Game*)pointer;
bwapi4.Text.Size.Enum* size = (bwapi4.Text.Size.Enum*)env->GetLongField(p_size, FindCachedField(env, env->GetObjectClass(p_size), "pointer", "J"));
x_game->setTextSize(size);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_vDrawText_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint x, jint y, jstring cstr_format, jobject p_...){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Object* ... = (Object*)env->GetLongField(p_..., FindCachedField(env, env->GetObjectClass(p_...), "pointer", "J"));
x_game->vDrawText(ctype, x, y, std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str(), ...);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBox_1native__JLbwapi4_CoordinateType_Enum_2IIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint left, jint top, jint right, jint bottom, jobject p_color){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBox(ctype, left, top, right, bottom, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBox_1native__JLbwapi4_CoordinateType_Enum_2IIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint left, jint top, jint right, jint bottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBox(ctype, left, top, right, bottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxMap_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMap(left, top, right, bottom, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxMap_1native__JIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMap(left, top, right, bottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxMap_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_leftTop, jobject p_rightBottom, jobject p_color){
Game* x_game = (Game*)pointer;
Position leftTop((int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "x", "I")), (int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "y", "I")));
Position rightBottom((int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "x", "I")), (int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMap(leftTop, rightBottom, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxMap_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_leftTop, jobject p_rightBottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position leftTop((int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "x", "I")), (int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "y", "I")));
Position rightBottom((int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "x", "I")), (int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMap(leftTop, rightBottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxMouse_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMouse(left, top, right, bottom, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxMouse_1native__JIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMouse(left, top, right, bottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxMouse_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_leftTop, jobject p_rightBottom, jobject p_color){
Game* x_game = (Game*)pointer;
Position leftTop((int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "x", "I")), (int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "y", "I")));
Position rightBottom((int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "x", "I")), (int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMouse(leftTop, rightBottom, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxMouse_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_leftTop, jobject p_rightBottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position leftTop((int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "x", "I")), (int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "y", "I")));
Position rightBottom((int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "x", "I")), (int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMouse(leftTop, rightBottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxScreen_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxScreen(left, top, right, bottom, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxScreen_1native__JIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxScreen(left, top, right, bottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxScreen_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_leftTop, jobject p_rightBottom, jobject p_color){
Game* x_game = (Game*)pointer;
Position leftTop((int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "x", "I")), (int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "y", "I")));
Position rightBottom((int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "x", "I")), (int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxScreen(leftTop, rightBottom, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawBoxScreen_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_leftTop, jobject p_rightBottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position leftTop((int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "x", "I")), (int)env->GetIntField(p_leftTop, FindCachedField(env, env->GetObjectClass(p_leftTop), "y", "I")));
Position rightBottom((int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "x", "I")), (int)env->GetIntField(p_rightBottom, FindCachedField(env, env->GetObjectClass(p_rightBottom), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxScreen(leftTop, rightBottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangle_1native__JLbwapi4_CoordinateType_Enum_2IIIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangle(ctype, ax, ay, bx, by, cx, cy, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangle_1native__JLbwapi4_CoordinateType_Enum_2IIIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangle(ctype, ax, ay, bx, by, cx, cy, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleMap_1native__JIIIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMap(ax, ay, bx, by, cx, cy, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleMap_1native__JIIIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMap(ax, ay, bx, by, cx, cy, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleMap_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_c, jobject p_color){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Position c((int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "x", "I")), (int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMap(a, b, c, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleMap_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_c, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Position c((int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "x", "I")), (int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMap(a, b, c, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleMouse_1native__JIIIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMouse(ax, ay, bx, by, cx, cy, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleMouse_1native__JIIIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMouse(ax, ay, bx, by, cx, cy, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleMouse_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_c, jobject p_color){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Position c((int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "x", "I")), (int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMouse(a, b, c, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleMouse_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_c, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Position c((int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "x", "I")), (int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMouse(a, b, c, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleScreen_1native__JIIIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleScreen(ax, ay, bx, by, cx, cy, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleScreen_1native__JIIIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleScreen(ax, ay, bx, by, cx, cy, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleScreen_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_c, jobject p_color){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Position c((int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "x", "I")), (int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleScreen(a, b, c, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawTriangleScreen_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_c, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Position c((int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "x", "I")), (int)env->GetIntField(p_c, FindCachedField(env, env->GetObjectClass(p_c), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleScreen(a, b, c, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircle_1native__JLbwapi4_CoordinateType_Enum_2IIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint x, jint y, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircle(ctype, x, y, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircle_1native__JLbwapi4_CoordinateType_Enum_2IIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint x, jint y, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircle(ctype, x, y, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleMap_1native__JIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMap(x, y, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleMap_1native__JIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMap(x, y, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleMap_1native__JLbwapi4_Position_2ILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMap(p, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleMap_1native__JLbwapi4_Position_2ILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMap(p, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleMouse_1native__JIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMouse(x, y, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleMouse_1native__JIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMouse(x, y, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleMouse_1native__JLbwapi4_Position_2ILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMouse(p, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleMouse_1native__JLbwapi4_Position_2ILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMouse(p, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleScreen_1native__JIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleScreen(x, y, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleScreen_1native__JIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleScreen(x, y, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleScreen_1native__JLbwapi4_Position_2ILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleScreen(p, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawCircleScreen_1native__JLbwapi4_Position_2ILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleScreen(p, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipse_1native__JLbwapi4_CoordinateType_Enum_2IIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint x, jint y, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipse(ctype, x, y, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipse_1native__JLbwapi4_CoordinateType_Enum_2IIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint x, jint y, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipse(ctype, x, y, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseMap_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMap(x, y, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseMap_1native__JIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMap(x, y, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseMap_1native__JLbwapi4_Position_2IILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMap(p, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseMap_1native__JLbwapi4_Position_2IILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMap(p, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseMouse_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMouse(x, y, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseMouse_1native__JIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMouse(x, y, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseMouse_1native__JLbwapi4_Position_2IILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMouse(p, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseMouse_1native__JLbwapi4_Position_2IILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMouse(p, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseScreen_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseScreen(x, y, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseScreen_1native__JIIIILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseScreen(x, y, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseScreen_1native__JLbwapi4_Position_2IILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseScreen(p, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawEllipseScreen_1native__JLbwapi4_Position_2IILbwapi4_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseScreen(p, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawDot_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint x, jint y, jobject p_color){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDot(ctype, x, y, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawDotMap_1native__JIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotMap(x, y, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawDotMap_1native__JLbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotMap(p, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawDotMouse_1native__JIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotMouse(x, y, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawDotMouse_1native__JLbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotMouse(p, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawDotScreen_1native__JIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotScreen(x, y, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawDotScreen_1native__JLbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p, jobject p_color){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotScreen(p, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawLine_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_ctype, jint x1, jint y1, jint x2, jint y2, jobject p_color){
Game* x_game = (Game*)pointer;
bwapi4.CoordinateType.Enum* ctype = (bwapi4.CoordinateType.Enum*)env->GetLongField(p_ctype, FindCachedField(env, env->GetObjectClass(p_ctype), "pointer", "J"));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLine(ctype, x1, y1, x2, y2, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawLineMap_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x1, jint y1, jint x2, jint y2, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineMap(x1, y1, x2, y2, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawLineMap_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_color){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineMap(a, b, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawLineMouse_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x1, jint y1, jint x2, jint y2, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineMouse(x1, y1, x2, y2, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawLineMouse_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_color){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineMouse(a, b, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawLineScreen_1native__JIIIILbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x1, jint y1, jint x2, jint y2, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineScreen(x1, y1, x2, y2, color);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_drawLineScreen_1native__JLbwapi4_Position_2Lbwapi4_Position_2Lbwapi4_Color_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_a, jobject p_b, jobject p_color){
Game* x_game = (Game*)pointer;
Position a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
Position b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineScreen(a, b, color);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getLatencyFrames_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getLatencyFrames();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getLatencyTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getLatencyTime();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getRemainingLatencyFrames_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getRemainingLatencyFrames();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getRemainingLatencyTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getRemainingLatencyTime();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getRevision_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getRevision();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isDebug_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isDebug();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isLatComEnabled_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isLatComEnabled();
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setLatCom_1native(JNIEnv * env, jobject obj, jlong pointer, jboolean isEnabled){
Game* x_game = (Game*)pointer;
x_game->setLatCom((bool)isEnabled);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_isGUIEnabled_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isGUIEnabled();
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setGUI_1native(JNIEnv * env, jobject obj, jlong pointer, jboolean enabled){
Game* x_game = (Game*)pointer;
x_game->setGUI((bool)enabled);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getInstanceNumber_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getInstanceNumber();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getAPM_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getAPM();
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getAPM_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean includeSelects){
Game* x_game = (Game*)pointer;
return x_game->getAPM((bool)includeSelects);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setMap_1native(JNIEnv * env, jobject obj, jlong pointer, jstring cstr_mapFileName){
Game* x_game = (Game*)pointer;
return x_game->setMap(std::string(env->GetStringUTFChars(cstr_mapFileName, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setFrameSkip_1native(JNIEnv * env, jobject obj, jlong pointer, jint frameSkip){
Game* x_game = (Game*)pointer;
x_game->setFrameSkip(frameSkip);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_hasPath_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_source, jobject p_destination){
Game* x_game = (Game*)pointer;
Position source((int)env->GetIntField(p_source, FindCachedField(env, env->GetObjectClass(p_source), "x", "I")), (int)env->GetIntField(p_source, FindCachedField(env, env->GetObjectClass(p_source), "y", "I")));
Position destination((int)env->GetIntField(p_destination, FindCachedField(env, env->GetObjectClass(p_destination), "x", "I")), (int)env->GetIntField(p_destination, FindCachedField(env, env->GetObjectClass(p_destination), "y", "I")));
return x_game->hasPath(source, destination);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setAlliance_1native__JLbwapi4_Player_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_player, jboolean allied){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setAlliance(player, (bool)allied);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setAlliance_1native__JLbwapi4_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setAlliance(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setAlliance_1native__JLbwapi4_Player_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_player, jboolean allied, jboolean alliedVictory){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setAlliance(player, (bool)allied, (bool)alliedVictory);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setVision_1native__JLbwapi4_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setVision(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setVision_1native__JLbwapi4_Player_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_player, jboolean enabled){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setVision(player, (bool)enabled);
}
JNIEXPORT void JNICALL Java_bwapi4_Game_setCommandOptimizationLevel_1native(JNIEnv * env, jobject obj, jlong pointer, jint level){
Game* x_game = (Game*)pointer;
x_game->setCommandOptimizationLevel(level);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_countdownTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->countdownTimer();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getRegionAt_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getRegionAt(x, y);
jclass retcls = FindCachedClass(env, "bwapi4/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getRegionAt_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
jlong resptr = (jlong)x_game->getRegionAt(position);
jclass retcls = FindCachedClass(env, "bwapi4/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getLastEventTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getLastEventTime();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setRevealAll_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->setRevealAll();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Game_setRevealAll_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean reveal){
Game* x_game = (Game*)pointer;
return x_game->setRevealAll((bool)reveal);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getBuildLocation_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2I(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_desiredPosition, jint maxRange){
Game* x_game = (Game*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
TilePosition desiredPosition((int)env->GetIntField(p_desiredPosition, FindCachedField(env, env->GetObjectClass(p_desiredPosition), "x", "I")), (int)env->GetIntField(p_desiredPosition, FindCachedField(env, env->GetObjectClass(p_desiredPosition), "y", "I")));
TilePosition cresult = x_game->getBuildLocation(*type, desiredPosition, maxRange);
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getBuildLocation_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_desiredPosition){
Game* x_game = (Game*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
TilePosition desiredPosition((int)env->GetIntField(p_desiredPosition, FindCachedField(env, env->GetObjectClass(p_desiredPosition), "x", "I")), (int)env->GetIntField(p_desiredPosition, FindCachedField(env, env->GetObjectClass(p_desiredPosition), "y", "I")));
TilePosition cresult = x_game->getBuildLocation(*type, desiredPosition);
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Game_getBuildLocation_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2IZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_desiredPosition, jint maxRange, jboolean creep){
Game* x_game = (Game*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
TilePosition desiredPosition((int)env->GetIntField(p_desiredPosition, FindCachedField(env, env->GetObjectClass(p_desiredPosition), "x", "I")), (int)env->GetIntField(p_desiredPosition, FindCachedField(env, env->GetObjectClass(p_desiredPosition), "y", "I")));
TilePosition cresult = x_game->getBuildLocation(*type, desiredPosition, maxRange, (bool)creep);
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getDamageFrom_1native__JLbwapi4_UnitType_2Lbwapi4_UnitType_2Lbwapi4_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_fromType, jobject p_toType, jobject p_fromPlayer){
Game* x_game = (Game*)pointer;
UnitType* fromType = (UnitType*)env->GetLongField(p_fromType, FindCachedField(env, env->GetObjectClass(p_fromType), "pointer", "J"));
UnitType* toType = (UnitType*)env->GetLongField(p_toType, FindCachedField(env, env->GetObjectClass(p_toType), "pointer", "J"));
Player* fromPlayer = (Player*)env->GetLongField(p_fromPlayer, FindCachedField(env, env->GetObjectClass(p_fromPlayer), "pointer", "J"));
return x_game->getDamageFrom(*fromType, *toType, fromPlayer);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getDamageFrom_1native__JLbwapi4_UnitType_2Lbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_fromType, jobject p_toType){
Game* x_game = (Game*)pointer;
UnitType* fromType = (UnitType*)env->GetLongField(p_fromType, FindCachedField(env, env->GetObjectClass(p_fromType), "pointer", "J"));
UnitType* toType = (UnitType*)env->GetLongField(p_toType, FindCachedField(env, env->GetObjectClass(p_toType), "pointer", "J"));
return x_game->getDamageFrom(*fromType, *toType);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getDamageFrom_1native__JLbwapi4_UnitType_2Lbwapi4_UnitType_2Lbwapi4_Player_2Lbwapi4_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_fromType, jobject p_toType, jobject p_fromPlayer, jobject p_toPlayer){
Game* x_game = (Game*)pointer;
UnitType* fromType = (UnitType*)env->GetLongField(p_fromType, FindCachedField(env, env->GetObjectClass(p_fromType), "pointer", "J"));
UnitType* toType = (UnitType*)env->GetLongField(p_toType, FindCachedField(env, env->GetObjectClass(p_toType), "pointer", "J"));
Player* fromPlayer = (Player*)env->GetLongField(p_fromPlayer, FindCachedField(env, env->GetObjectClass(p_fromPlayer), "pointer", "J"));
Player* toPlayer = (Player*)env->GetLongField(p_toPlayer, FindCachedField(env, env->GetObjectClass(p_toPlayer), "pointer", "J"));
return x_game->getDamageFrom(*fromType, *toType, fromPlayer, toPlayer);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getDamageTo_1native__JLbwapi4_UnitType_2Lbwapi4_UnitType_2Lbwapi4_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_toType, jobject p_fromType, jobject p_toPlayer){
Game* x_game = (Game*)pointer;
UnitType* toType = (UnitType*)env->GetLongField(p_toType, FindCachedField(env, env->GetObjectClass(p_toType), "pointer", "J"));
UnitType* fromType = (UnitType*)env->GetLongField(p_fromType, FindCachedField(env, env->GetObjectClass(p_fromType), "pointer", "J"));
Player* toPlayer = (Player*)env->GetLongField(p_toPlayer, FindCachedField(env, env->GetObjectClass(p_toPlayer), "pointer", "J"));
return x_game->getDamageTo(*toType, *fromType, toPlayer);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getDamageTo_1native__JLbwapi4_UnitType_2Lbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_toType, jobject p_fromType){
Game* x_game = (Game*)pointer;
UnitType* toType = (UnitType*)env->GetLongField(p_toType, FindCachedField(env, env->GetObjectClass(p_toType), "pointer", "J"));
UnitType* fromType = (UnitType*)env->GetLongField(p_fromType, FindCachedField(env, env->GetObjectClass(p_fromType), "pointer", "J"));
return x_game->getDamageTo(*toType, *fromType);
}
JNIEXPORT jint JNICALL Java_bwapi4_Game_getDamageTo_1native__JLbwapi4_UnitType_2Lbwapi4_UnitType_2Lbwapi4_Player_2Lbwapi4_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_toType, jobject p_fromType, jobject p_toPlayer, jobject p_fromPlayer){
Game* x_game = (Game*)pointer;
UnitType* toType = (UnitType*)env->GetLongField(p_toType, FindCachedField(env, env->GetObjectClass(p_toType), "pointer", "J"));
UnitType* fromType = (UnitType*)env->GetLongField(p_fromType, FindCachedField(env, env->GetObjectClass(p_fromType), "pointer", "J"));
Player* toPlayer = (Player*)env->GetLongField(p_toPlayer, FindCachedField(env, env->GetObjectClass(p_toPlayer), "pointer", "J"));
Player* fromPlayer = (Player*)env->GetLongField(p_fromPlayer, FindCachedField(env, env->GetObjectClass(p_fromPlayer), "pointer", "J"));
return x_game->getDamageTo(*toType, *fromType, toPlayer, fromPlayer);
}
JNIEXPORT void JNICALL Java_bwapi4_GameWrapper_flush_1native(JNIEnv * env, jobject obj, jlong pointer){
GameWrapper* x_gameWrapper = (GameWrapper*)pointer;
x_gameWrapper->flush();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_InterfaceEvent_isFinished_1native(JNIEnv * env, jobject obj, jlong pointer){
InterfaceEvent* x_interfaceEvent = (InterfaceEvent*)pointer;
return x_interfaceEvent->isFinished();
}
JNIEXPORT void JNICALL Java_bwapi4_InterfaceEvent_removeEvent_1native(JNIEnv * env, jobject obj, jlong pointer){
InterfaceEvent* x_interfaceEvent = (InterfaceEvent*)pointer;
x_interfaceEvent->removeEvent();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getID();
}
JNIEXPORT jstring JNICALL Java_bwapi4_Player_getName_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return env->NewStringUTF(x_player->getName().c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi4_Player_getRace_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
jlong resptr = (jlong)tableRace.find(x_player->getRace())->second;
jclass retcls = FindCachedClass(env, "bwapi4/Race");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Race;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Player_getType_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
jlong resptr = (jlong)x_player->getType();
jclass retcls = FindCachedClass(env, "bwapi4/PlayerType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/PlayerType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Player_getForce_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
jlong resptr = (jlong)x_player->getForce();
jclass retcls = FindCachedClass(env, "bwapi4/Force");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Force;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isAlly_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Player* x_player = (Player*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_player->isAlly(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isEnemy_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Player* x_player = (Player*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_player->isEnemy(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isNeutral_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->isNeutral();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Player_getStartLocation_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
TilePosition cresult = x_player->getStartLocation();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isVictorious_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->isVictorious();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isDefeated_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->isDefeated();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_leftGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->leftGame();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_minerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->minerals();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_gas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->gas();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_gatheredMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->gatheredMinerals();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_gatheredGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->gatheredGas();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_repairedMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->repairedMinerals();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_repairedGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->repairedGas();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_refundedMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->refundedMinerals();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_refundedGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->refundedGas();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_spentMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->spentMinerals();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_spentGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->spentGas();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_supplyTotal_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->supplyTotal();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_supplyTotal_1native__JLbwapi4_Race_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_race){
Player* x_player = (Player*)pointer;
Race* race = (Race*)env->GetLongField(p_race, FindCachedField(env, env->GetObjectClass(p_race), "pointer", "J"));
return x_player->supplyTotal(*race);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_supplyUsed_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->supplyUsed();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_supplyUsed_1native__JLbwapi4_Race_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_race){
Player* x_player = (Player*)pointer;
Race* race = (Race*)env->GetLongField(p_race, FindCachedField(env, env->GetObjectClass(p_race), "pointer", "J"));
return x_player->supplyUsed(*race);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_allUnitCount_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->allUnitCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_allUnitCount_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->allUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_visibleUnitCount_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->visibleUnitCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_visibleUnitCount_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->visibleUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_completedUnitCount_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->completedUnitCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_completedUnitCount_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->completedUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_incompleteUnitCount_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->incompleteUnitCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_incompleteUnitCount_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->incompleteUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_deadUnitCount_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->deadUnitCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_deadUnitCount_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->deadUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_killedUnitCount_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->killedUnitCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_killedUnitCount_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->killedUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_getUpgradeLevel_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_upgrade){
Player* x_player = (Player*)pointer;
UpgradeType* upgrade = (UpgradeType*)env->GetLongField(p_upgrade, FindCachedField(env, env->GetObjectClass(p_upgrade), "pointer", "J"));
return x_player->getUpgradeLevel(*upgrade);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_hasResearched_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Player* x_player = (Player*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_player->hasResearched(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isResearching_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Player* x_player = (Player*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_player->isResearching(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isUpgrading_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_upgrade){
Player* x_player = (Player*)pointer;
UpgradeType* upgrade = (UpgradeType*)env->GetLongField(p_upgrade, FindCachedField(env, env->GetObjectClass(p_upgrade), "pointer", "J"));
return x_player->isUpgrading(*upgrade);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Player_getColor_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
Color cresult = x_player->getColor();
jclass retcls = FindCachedClass(env, "bwapi4/Color");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(III)V");
jobject result = env->NewObject(retcls, retConsID, cresult.red(), cresult.green(), cresult.blue());
return result;
}
JNIEXPORT jchar JNICALL Java_bwapi4_Player_getTextColor_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getTextColor();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_maxEnergy_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->maxEnergy(*unit);
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Player_topSpeed_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->topSpeed(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_weaponMaxRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_weapon){
Player* x_player = (Player*)pointer;
WeaponType* weapon = (WeaponType*)env->GetLongField(p_weapon, FindCachedField(env, env->GetObjectClass(p_weapon), "pointer", "J"));
return x_player->weaponMaxRange(*weapon);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_sightRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->sightRange(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_weaponDamageCooldown_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->weaponDamageCooldown(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_armor_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->armor(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_damage_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_wpn){
Player* x_player = (Player*)pointer;
WeaponType* wpn = (WeaponType*)env->GetLongField(p_wpn, FindCachedField(env, env->GetObjectClass(p_wpn), "pointer", "J"));
return x_player->damage(*wpn);
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_getUnitScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getUnitScore();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_getKillScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getKillScore();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_getBuildingScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getBuildingScore();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_getRazingScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getRazingScore();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_getCustomScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getCustomScore();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isObserver_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->isObserver();
}
JNIEXPORT jint JNICALL Java_bwapi4_Player_getMaxUpgradeLevel_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_upgrade){
Player* x_player = (Player*)pointer;
UpgradeType* upgrade = (UpgradeType*)env->GetLongField(p_upgrade, FindCachedField(env, env->GetObjectClass(p_upgrade), "pointer", "J"));
return x_player->getMaxUpgradeLevel(*upgrade);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isResearchAvailable_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Player* x_player = (Player*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_player->isResearchAvailable(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Player_isUnitAvailable_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->isUnitAvailable(*unit);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Playerset_getUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Playerset* x_playerset = (Playerset*)pointer;
jlong resptr = (jlong)x_playerset->getUnits();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT void JNICALL Java_bwapi4_Playerset_setAlliance_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean allies){
Playerset* x_playerset = (Playerset*)pointer;
x_playerset->setAlliance((bool)allies);
}
JNIEXPORT void JNICALL Java_bwapi4_Playerset_setAlliance_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Playerset* x_playerset = (Playerset*)pointer;
x_playerset->setAlliance();
}
JNIEXPORT void JNICALL Java_bwapi4_Playerset_setAlliance_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean allies, jboolean alliedVictory){
Playerset* x_playerset = (Playerset*)pointer;
x_playerset->setAlliance((bool)allies, (bool)alliedVictory);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Point_isValid_1native(JNIEnv * env, jobject obj, jlong pointer){
Point* x_point = (Point*)pointer;
return x_point->isValid();
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Point_getLength_1native(JNIEnv * env, jobject obj, jlong pointer){
Point* x_point = (Point*)pointer;
return x_point->getLength();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Position_isValid(JNIEnv * env, jobject obj){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
return x_position.isValid();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Position_makeValid(JNIEnv * env, jobject obj){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
Position cresult = x_position.makeValid();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Position_getDistance(JNIEnv * env, jobject obj, jobject p_position){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_position.getDistance(position);
}
JNIEXPORT jint JNICALL Java_bwapi4_Position_getApproxDistance(JNIEnv * env, jobject obj, jobject p_position){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_position.getApproxDistance(position);
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Position_getLength(JNIEnv * env, jobject obj){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
return x_position.getLength();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Position_hasPath(JNIEnv * env, jobject obj, jobject p_position){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_position.hasPath(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_PositionOrUnit_isUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
PositionOrUnit* x_positionOrUnit = (PositionOrUnit*)pointer;
return x_positionOrUnit->isUnit();
}
JNIEXPORT jobject JNICALL Java_bwapi4_PositionOrUnit_getUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
PositionOrUnit* x_positionOrUnit = (PositionOrUnit*)pointer;
jlong resptr = (jlong)x_positionOrUnit->getUnit();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_PositionOrUnit_isPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
PositionOrUnit* x_positionOrUnit = (PositionOrUnit*)pointer;
return x_positionOrUnit->isPosition();
}
JNIEXPORT jobject JNICALL Java_bwapi4_PositionOrUnit_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
PositionOrUnit* x_positionOrUnit = (PositionOrUnit*)pointer;
Position cresult = x_positionOrUnit->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jint JNICALL Java_bwapi4_Region_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getID();
}
JNIEXPORT jint JNICALL Java_bwapi4_Region_getRegionGroupID_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getRegionGroupID();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Region_getCenter_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
Position cresult = x_region->getCenter();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Region_isHigherGround_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->isHigherGround();
}
JNIEXPORT jint JNICALL Java_bwapi4_Region_getDefensePriority_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getDefensePriority();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Region_isAccessible_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->isAccessible();
}
JNIEXPORT jint JNICALL Java_bwapi4_Region_getBoundsLeft_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getBoundsLeft();
}
JNIEXPORT jint JNICALL Java_bwapi4_Region_getBoundsTop_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getBoundsTop();
}
JNIEXPORT jint JNICALL Java_bwapi4_Region_getBoundsRight_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getBoundsRight();
}
JNIEXPORT jint JNICALL Java_bwapi4_Region_getBoundsBottom_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getBoundsBottom();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Region_getClosestAccessibleRegion_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
jlong resptr = (jlong)x_region->getClosestAccessibleRegion();
jclass retcls = FindCachedClass(env, "bwapi4/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Region_getClosestInaccessibleRegion_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
jlong resptr = (jlong)x_region->getClosestInaccessibleRegion();
jclass retcls = FindCachedClass(env, "bwapi4/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi4_Region_getDistance_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_other){
Region* x_region = (Region*)pointer;
Region* other = (Region*)env->GetLongField(p_other, FindCachedField(env, env->GetObjectClass(p_other), "pointer", "J"));
return x_region->getDistance(other);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Region_getUnits_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_pred){
Region* x_region = (Region*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_region->getUnits(pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Regionset_getCenter_1native(JNIEnv * env, jobject obj, jlong pointer){
Regionset* x_regionset = (Regionset*)pointer;
Position cresult = x_regionset->getCenter();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Regionset_getUnits_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_pred){
Regionset* x_regionset = (Regionset*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_regionset->getUnits(pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_TilePosition_hasPath(JNIEnv * env, jobject obj, jobject p_position){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_tilePosition.hasPath(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_TilePosition_isValid(JNIEnv * env, jobject obj){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
return x_tilePosition.isValid();
}
JNIEXPORT jobject JNICALL Java_bwapi4_TilePosition_makeValid(JNIEnv * env, jobject obj){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
TilePosition cresult = x_tilePosition.makeValid();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwapi4_TilePosition_getDistance(JNIEnv * env, jobject obj, jobject p_position){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_tilePosition.getDistance(position);
}
JNIEXPORT jdouble JNICALL Java_bwapi4_TilePosition_getLength(JNIEnv * env, jobject obj){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
return x_tilePosition.getLength();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getID();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_exists_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->exists();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getReplayID_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getReplayID();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getPlayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getPlayer();
jclass retcls = FindCachedClass(env, "bwapi4/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getType_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_unit->getType())->second;
jclass retcls = FindCachedClass(env, "bwapi4/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getTilePosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
TilePosition cresult = x_unit->getTilePosition();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Unit_getAngle_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getAngle();
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Unit_getVelocityX_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getVelocityX();
}
JNIEXPORT jdouble JNICALL Java_bwapi4_Unit_getVelocityY_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getVelocityY();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getRegion_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getRegion();
jclass retcls = FindCachedClass(env, "bwapi4/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getLeft_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getLeft();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getTop_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getTop();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getRight_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRight();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getBottom_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getBottom();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getHitPoints_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getHitPoints();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getShields_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getShields();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getEnergy_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getEnergy();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getResources_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getResources();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getResourceGroup_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getResourceGroup();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getDistance_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->getDistance(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_hasPath_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->hasPath(target);
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getLastCommandFrame_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getLastCommandFrame();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getLastAttackingPlayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getLastAttackingPlayer();
jclass retcls = FindCachedClass(env, "bwapi4/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getInitialType_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_unit->getInitialType())->second;
jclass retcls = FindCachedClass(env, "bwapi4/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getInitialPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getInitialPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getInitialTilePosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
TilePosition cresult = x_unit->getInitialTilePosition();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getInitialHitPoints_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getInitialHitPoints();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getInitialResources_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getInitialResources();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getKillCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getKillCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getAcidSporeCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getAcidSporeCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getInterceptorCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getInterceptorCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getScarabCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getScarabCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getSpiderMineCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getSpiderMineCount();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getGroundWeaponCooldown_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getGroundWeaponCooldown();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getAirWeaponCooldown_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getAirWeaponCooldown();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getSpellCooldown_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getSpellCooldown();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getDefenseMatrixPoints_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getDefenseMatrixPoints();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getDefenseMatrixTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getDefenseMatrixTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getEnsnareTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getEnsnareTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getIrradiateTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getIrradiateTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getLockdownTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getLockdownTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getMaelstromTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getMaelstromTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getOrderTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getOrderTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getPlagueTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getPlagueTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getRemoveTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemoveTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getStasisTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getStasisTimer();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getStimTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getStimTimer();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getBuildType_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_unit->getBuildType())->second;
jclass retcls = FindCachedClass(env, "bwapi4/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getTech_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableTechType.find(x_unit->getTech())->second;
jclass retcls = FindCachedClass(env, "bwapi4/TechType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/TechType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getUpgrade_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableUpgradeType.find(x_unit->getUpgrade())->second;
jclass retcls = FindCachedClass(env, "bwapi4/UpgradeType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/UpgradeType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getRemainingBuildTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemainingBuildTime();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getRemainingTrainTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemainingTrainTime();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getRemainingResearchTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemainingResearchTime();
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getRemainingUpgradeTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemainingUpgradeTime();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getBuildUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getBuildUnit();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getTarget_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getTarget();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getTargetPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getTargetPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getOrder_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableOrder.find(x_unit->getOrder())->second;
jclass retcls = FindCachedClass(env, "bwapi4/Order");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Order;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getSecondaryOrder_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableOrder.find(x_unit->getSecondaryOrder())->second;
jclass retcls = FindCachedClass(env, "bwapi4/Order");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Order;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getOrderTarget_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getOrderTarget();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getOrderTargetPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getOrderTargetPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getRallyPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getRallyPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getRallyUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getRallyUnit();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getAddon_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getAddon();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getNydusExit_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getNydusExit();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getPowerUp_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getPowerUp();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getTransport_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getTransport();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getLoadedUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getLoadedUnits();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi4_Unit_getSpaceRemaining_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getSpaceRemaining();
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getCarrier_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getCarrier();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getInterceptors_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getInterceptors();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getHatchery_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getHatchery();
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getLarva_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getLarva();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getUnitsInRadius_1native(JNIEnv * env, jobject obj, jlong pointer, jint radius, jobject p_pred){
Unit* x_unit = (Unit*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_unit->getUnitsInRadius(radius, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getUnitsInWeaponRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_weapon, jobject p_pred){
Unit* x_unit = (Unit*)pointer;
WeaponType* weapon = (WeaponType*)env->GetLongField(p_weapon, FindCachedField(env, env->GetObjectClass(p_weapon), "pointer", "J"));
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_unit->getUnitsInWeaponRange(*weapon, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getClosestUnit_1native__JLbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_pred){
Unit* x_unit = (Unit*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_unit->getClosestUnit(pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unit_getClosestUnit_1native__JLbwapi4_UnitFilter_2I(JNIEnv * env, jobject obj, jlong pointer, jobject p_pred, jint radius){
Unit* x_unit = (Unit*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_unit->getClosestUnit(pred, radius);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_hasNuke_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->hasNuke();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isAccelerating_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isAccelerating();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isAttacking_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isAttacking();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isAttackFrame_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isAttackFrame();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isBeingConstructed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBeingConstructed();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isBeingGathered_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBeingGathered();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isBeingHealed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBeingHealed();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isBlind_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBlind();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isBraking_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBraking();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isBurrowed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBurrowed();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isCarryingGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isCarryingGas();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isCarryingMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isCarryingMinerals();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isCloaked_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isCloaked();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isCompleted_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isCompleted();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isConstructing_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isConstructing();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isDefenseMatrixed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isDefenseMatrixed();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isDetected_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isDetected();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isEnsnared_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isEnsnared();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isFlying_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isFlying();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isFollowing_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isFollowing();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isGatheringGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isGatheringGas();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isGatheringMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isGatheringMinerals();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isHallucination_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isHallucination();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isHoldingPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isHoldingPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isIdle_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isIdle();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isInterruptible_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isInterruptible();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isInvincible_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isInvincible();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isInWeaponRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->isInWeaponRange(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isIrradiated_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isIrradiated();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isLifted_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isLifted();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isLoaded_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isLoaded();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isLockedDown_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isLockedDown();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isMaelstrommed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isMaelstrommed();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isMorphing_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isMorphing();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isMoving_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isMoving();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isParasited_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isParasited();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isPatrolling_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isPatrolling();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isPlagued_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isPlagued();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isRepairing_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isRepairing();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isResearching_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isResearching();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isSelected_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isSelected();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isSieged_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isSieged();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isStartingAttack_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isStartingAttack();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isStasised_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isStasised();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isStimmed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isStimmed();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isStuck_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isStuck();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isTraining_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isTraining();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isUnderAttack_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnderAttack();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isUnderDarkSwarm_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnderDarkSwarm();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isUnderDisruptionWeb_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnderDisruptionWeb();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isUnderStorm_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnderStorm();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isPowered_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isPowered();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isUpgrading_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUpgrading();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isVisible_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isVisible();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isVisible_1native__JLbwapi4_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Unit* x_unit = (Unit*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_unit->isVisible(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_isTargetable_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isTargetable();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_issueCommand_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_command){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->issueCommand(*command);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_attack_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->attack(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_attack_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->attack(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_build_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->build(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_build_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_target){
Unit* x_unit = (Unit*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->build(*type, target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_buildAddon_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->buildAddon(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_train_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->train();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_train_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->train(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_morph_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->morph(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_research_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->research(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_upgrade_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_upgrade){
Unit* x_unit = (Unit*)pointer;
UpgradeType* upgrade = (UpgradeType*)env->GetLongField(p_upgrade, FindCachedField(env, env->GetObjectClass(p_upgrade), "pointer", "J"));
return x_unit->upgrade(*upgrade);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_setRallyPoint_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->setRallyPoint(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_move_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->move(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_move_1native__JLbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->move(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_patrol_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->patrol(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_patrol_1native__JLbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->patrol(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_holdPosition_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->holdPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_holdPosition_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
return x_unit->holdPosition((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_stop_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->stop();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_stop_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
return x_unit->stop((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_follow_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->follow(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_follow_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->follow(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_gather_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->gather(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_gather_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->gather(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_returnCargo_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->returnCargo();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_returnCargo_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
return x_unit->returnCargo((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_repair_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->repair(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_repair_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->repair(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_burrow_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->burrow();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_unburrow_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->unburrow();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_cloak_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_decloak_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->decloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_siege_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->siege();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_unsiege_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->unsiege();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_lift_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->lift();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_land_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->land(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_load_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->load(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_load_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->load(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_unload_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->unload(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_unloadAll_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->unloadAll();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_unloadAll_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
return x_unit->unloadAll((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_unloadAll_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->unloadAll(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_unloadAll_1native__JLbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->unloadAll(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_rightClick_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->rightClick(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_rightClick_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->rightClick(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_haltConstruction_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->haltConstruction();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_cancelConstruction_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelConstruction();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_cancelAddon_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelAddon();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_cancelTrain_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelTrain();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_cancelTrain_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint slot){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelTrain(slot);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_cancelMorph_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelMorph();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_cancelResearch_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelResearch();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_cancelUpgrade_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelUpgrade();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_useTech_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->useTech(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_useTech_1native__JLbwapi4_TechType_2Lbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->useTech(*tech, target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_placeCOP_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->placeCOP(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommand_1native__JLbwapi4_UnitCommand_2ZZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits, jboolean checkCanBuildUnitType, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommand(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits, (bool)checkCanBuildUnitType, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommand_1native__JLbwapi4_UnitCommand_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits, jboolean checkCanBuildUnitType, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommand(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits, (bool)checkCanBuildUnitType, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommand_1native__JLbwapi4_UnitCommand_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits, jboolean checkCanBuildUnitType){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommand(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits, (bool)checkCanBuildUnitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommand_1native__JLbwapi4_UnitCommand_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommand(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommand_1native__JLbwapi4_UnitCommand_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommand(*command, (bool)checkCanUseTechPositionOnPositions);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommand_1native__JLbwapi4_UnitCommand_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_command){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommand(*command);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommand_1native__JLbwapi4_UnitCommand_2ZZZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits, jboolean checkCanBuildUnitType, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommand(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits, (bool)checkCanBuildUnitType, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandGrouped_1native__JLbwapi4_UnitCommand_2ZZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommandGrouped(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandGrouped_1native__JLbwapi4_UnitCommand_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommandGrouped(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandGrouped_1native__JLbwapi4_UnitCommand_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommandGrouped(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandGrouped_1native__JLbwapi4_UnitCommand_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommandGrouped(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandGrouped_1native__JLbwapi4_UnitCommand_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommandGrouped(*command, (bool)checkCanUseTechPositionOnPositions);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandGrouped_1native__JLbwapi4_UnitCommand_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_command){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommandGrouped(*command);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandGrouped_1native__JLbwapi4_UnitCommand_2ZZZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_command, jboolean checkCanUseTechPositionOnPositions, jboolean checkCanUseTechUnitOnUnits, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommandGrouped(*command, (bool)checkCanUseTechPositionOnPositions, (bool)checkCanUseTechUnitOnUnits, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCommand_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCommand();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCommandGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCommandGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCommandGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCommandGrouped((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandType_1native__JLbwapi4_UnitCommandType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_ct){
Unit* x_unit = (Unit*)pointer;
UnitCommandType* ct = (UnitCommandType*)env->GetLongField(p_ct, FindCachedField(env, env->GetObjectClass(p_ct), "pointer", "J"));
return x_unit->canIssueCommandType(ct);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandType_1native__JLbwapi4_UnitCommandType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_ct, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitCommandType* ct = (UnitCommandType*)env->GetLongField(p_ct, FindCachedField(env, env->GetObjectClass(p_ct), "pointer", "J"));
return x_unit->canIssueCommandType(ct, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandTypeGrouped_1native__JLbwapi4_UnitCommandType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_ct, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
UnitCommandType* ct = (UnitCommandType*)env->GetLongField(p_ct, FindCachedField(env, env->GetObjectClass(p_ct), "pointer", "J"));
return x_unit->canIssueCommandTypeGrouped(ct, (bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandTypeGrouped_1native__JLbwapi4_UnitCommandType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_ct){
Unit* x_unit = (Unit*)pointer;
UnitCommandType* ct = (UnitCommandType*)env->GetLongField(p_ct, FindCachedField(env, env->GetObjectClass(p_ct), "pointer", "J"));
return x_unit->canIssueCommandTypeGrouped(ct);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canIssueCommandTypeGrouped_1native__JLbwapi4_UnitCommandType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_ct, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitCommandType* ct = (UnitCommandType*)env->GetLongField(p_ct, FindCachedField(env, env->GetObjectClass(p_ct), "pointer", "J"));
return x_unit->canIssueCommandTypeGrouped(ct, (bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canTargetUnit_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canTargetUnit(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canTargetUnit_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canTargetUnit(targetUnit, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttack_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttack();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttack_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttack((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttack_1native__JLbwapi4_PositionOrUnit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttack(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttack_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttack(target, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttack_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttack(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttack_1native__JLbwapi4_PositionOrUnit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttack(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackGrouped((bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackGrouped_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackGrouped((bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackGrouped_1native__JLbwapi4_PositionOrUnit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttackGrouped(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackGrouped_1native__JLbwapi4_PositionOrUnit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttackGrouped(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackGrouped_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttackGrouped(target, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackGrouped_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttackGrouped(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackGrouped_1native__JLbwapi4_PositionOrUnit_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canAttackGrouped(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackMove_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackMove();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackMove_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackMove((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackMoveGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackMoveGrouped((bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackMoveGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackMoveGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackMoveGrouped_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackMoveGrouped((bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnit_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackUnit();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnit_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackUnit((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnit_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnit(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnit_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnit(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnit_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnit(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnit_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnit(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnitGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackUnitGrouped((bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnitGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackUnitGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnitGrouped_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canAttackUnitGrouped((bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnitGrouped_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnitGrouped(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnitGrouped_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnitGrouped(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnitGrouped_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnitGrouped(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnitGrouped_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnitGrouped(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canAttackUnitGrouped_1native__JLbwapi4_Unit_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canAttackUnitGrouped(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canBuild();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canBuild((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__JLbwapi4_UnitType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canBuild(*uType, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canBuild(*uType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__JLbwapi4_UnitType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canBuild(*uType, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jobject p_tilePos, jboolean checkTargetUnitType, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
TilePosition tilePos((int)env->GetIntField(p_tilePos, FindCachedField(env, env->GetObjectClass(p_tilePos), "x", "I")), (int)env->GetIntField(p_tilePos, FindCachedField(env, env->GetObjectClass(p_tilePos), "y", "I")));
return x_unit->canBuild(*uType, tilePos, (bool)checkTargetUnitType, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jobject p_tilePos, jboolean checkTargetUnitType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
TilePosition tilePos((int)env->GetIntField(p_tilePos, FindCachedField(env, env->GetObjectClass(p_tilePos), "x", "I")), (int)env->GetIntField(p_tilePos, FindCachedField(env, env->GetObjectClass(p_tilePos), "y", "I")));
return x_unit->canBuild(*uType, tilePos, (bool)checkTargetUnitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jobject p_tilePos){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
TilePosition tilePos((int)env->GetIntField(p_tilePos, FindCachedField(env, env->GetObjectClass(p_tilePos), "x", "I")), (int)env->GetIntField(p_tilePos, FindCachedField(env, env->GetObjectClass(p_tilePos), "y", "I")));
return x_unit->canBuild(*uType, tilePos);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuild_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jobject p_tilePos, jboolean checkTargetUnitType, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
TilePosition tilePos((int)env->GetIntField(p_tilePos, FindCachedField(env, env->GetObjectClass(p_tilePos), "x", "I")), (int)env->GetIntField(p_tilePos, FindCachedField(env, env->GetObjectClass(p_tilePos), "y", "I")));
return x_unit->canBuild(*uType, tilePos, (bool)checkTargetUnitType, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuildAddon_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canBuildAddon();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuildAddon_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canBuildAddon((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuildAddon_1native__JLbwapi4_UnitType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canBuildAddon(*uType, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuildAddon_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canBuildAddon(*uType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBuildAddon_1native__JLbwapi4_UnitType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canBuildAddon(*uType, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canTrain_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canTrain();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canTrain_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canTrain((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canTrain_1native__JLbwapi4_UnitType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canTrain(*uType, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canTrain_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canTrain(*uType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canTrain_1native__JLbwapi4_UnitType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canTrain(*uType, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMorph_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canMorph();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMorph_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canMorph((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMorph_1native__JLbwapi4_UnitType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canMorph(*uType, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMorph_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canMorph(*uType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMorph_1native__JLbwapi4_UnitType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_uType, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
UnitType* uType = (UnitType*)env->GetLongField(p_uType, FindCachedField(env, env->GetObjectClass(p_uType), "pointer", "J"));
return x_unit->canMorph(*uType, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canResearch_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canResearch();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canResearch_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canResearch((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canResearch_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
TechType* type = (TechType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->canResearch(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canResearch_1native__JLbwapi4_TechType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TechType* type = (TechType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->canResearch(*type, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUpgrade_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUpgrade();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUpgrade_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUpgrade((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUpgrade_1native__JLbwapi4_UpgradeType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
UpgradeType* type = (UpgradeType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->canUpgrade(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUpgrade_1native__JLbwapi4_UpgradeType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
UpgradeType* type = (UpgradeType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->canUpgrade(*type, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyPoint_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canSetRallyPoint();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyPoint_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canSetRallyPoint((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyPoint_1native__JLbwapi4_PositionOrUnit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canSetRallyPoint(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyPoint_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canSetRallyPoint(target, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyPoint_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canSetRallyPoint(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyPoint_1native__JLbwapi4_PositionOrUnit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canSetRallyPoint(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyPosition_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canSetRallyPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyPosition_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canSetRallyPosition((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyUnit_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canSetRallyUnit();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyUnit_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canSetRallyUnit((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyUnit_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canSetRallyUnit(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyUnit_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canSetRallyUnit(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyUnit_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canSetRallyUnit(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSetRallyUnit_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canSetRallyUnit(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMove_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canMove();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMove_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canMove((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMoveGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
return x_unit->canMoveGrouped((bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMoveGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canMoveGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canMoveGrouped_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canMoveGrouped((bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPatrol_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canPatrol();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPatrol_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canPatrol((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPatrolGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
return x_unit->canPatrolGrouped((bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPatrolGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canPatrolGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPatrolGrouped_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canPatrolGrouped((bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canFollow_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canFollow();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canFollow_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canFollow((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canFollow_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canFollow(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canFollow_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canFollow(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canFollow_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canFollow(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canFollow_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canFollow(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canGather_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canGather();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canGather_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canGather((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canGather_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canGather(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canGather_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canGather(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canGather_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canGather(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canGather_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canGather(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canReturnCargo_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canReturnCargo();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canReturnCargo_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canReturnCargo((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canHoldPosition_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canHoldPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canHoldPosition_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canHoldPosition((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canStop_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canStop();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canStop_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canStop((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRepair_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRepair();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRepair_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRepair((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRepair_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRepair(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRepair_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRepair(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRepair_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRepair(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRepair_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRepair(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBurrow_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canBurrow();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canBurrow_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canBurrow((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnburrow_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnburrow();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnburrow_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnburrow((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCloak_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCloak_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCloak((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canDecloak_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canDecloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canDecloak_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canDecloak((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSiege_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canSiege();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canSiege_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canSiege((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnsiege_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnsiege();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnsiege_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnsiege((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLift_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canLift();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLift_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canLift((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLand_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canLand();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLand_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canLand((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLand_1native__JLbwapi4_TilePosition_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canLand(target, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLand_1native__JLbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canLand(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLand_1native__JLbwapi4_TilePosition_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canLand(target, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLoad_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canLoad();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLoad_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canLoad((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLoad_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canLoad(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLoad_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canLoad(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLoad_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canLoad(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canLoad_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canLoad(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadWithOrWithoutTarget_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnloadWithOrWithoutTarget();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadWithOrWithoutTarget_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnloadWithOrWithoutTarget((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAtPosition_1native__JLbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targDropPos, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Position targDropPos((int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "x", "I")), (int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "y", "I")));
return x_unit->canUnloadAtPosition(targDropPos, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAtPosition_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targDropPos){
Unit* x_unit = (Unit*)pointer;
Position targDropPos((int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "x", "I")), (int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "y", "I")));
return x_unit->canUnloadAtPosition(targDropPos);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAtPosition_1native__JLbwapi4_Position_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targDropPos, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Position targDropPos((int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "x", "I")), (int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "y", "I")));
return x_unit->canUnloadAtPosition(targDropPos, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnload_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnload();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnload_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnload((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnload_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkPosition, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUnload(targetUnit, (bool)checkCanTargetUnit, (bool)checkPosition, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnload_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkPosition){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUnload(targetUnit, (bool)checkCanTargetUnit, (bool)checkPosition);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnload_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUnload(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnload_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUnload(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnload_1native__JLbwapi4_Unit_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkPosition, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUnload(targetUnit, (bool)checkCanTargetUnit, (bool)checkPosition, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAll_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnloadAll();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAll_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnloadAll((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAllPosition_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnloadAllPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAllPosition_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUnloadAllPosition((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAllPosition_1native__JLbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targDropPos, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Position targDropPos((int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "x", "I")), (int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "y", "I")));
return x_unit->canUnloadAllPosition(targDropPos, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAllPosition_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targDropPos){
Unit* x_unit = (Unit*)pointer;
Position targDropPos((int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "x", "I")), (int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "y", "I")));
return x_unit->canUnloadAllPosition(targDropPos);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUnloadAllPosition_1native__JLbwapi4_Position_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targDropPos, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Position targDropPos((int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "x", "I")), (int)env->GetIntField(p_targDropPos, FindCachedField(env, env->GetObjectClass(p_targDropPos), "y", "I")));
return x_unit->canUnloadAllPosition(targDropPos, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClick_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClick();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClick_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClick((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClick_1native__JLbwapi4_PositionOrUnit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClick(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClick_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClick(target, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClick_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClick(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClick_1native__JLbwapi4_PositionOrUnit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClick(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickGrouped((bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickGrouped_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickGrouped((bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickGrouped_1native__JLbwapi4_PositionOrUnit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClickGrouped(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickGrouped_1native__JLbwapi4_PositionOrUnit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClickGrouped(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickGrouped_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClickGrouped(target, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickGrouped_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClickGrouped(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickGrouped_1native__JLbwapi4_PositionOrUnit_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canRightClickGrouped(target, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickPosition_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickPosition_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickPosition((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickPositionGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickPositionGrouped((bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickPositionGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickPositionGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickPositionGrouped_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickPositionGrouped((bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnit_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickUnit();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnit_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickUnit((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnit_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnit(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnit_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnit(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnit_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnit(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnit_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnit(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnitGrouped_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickUnitGrouped((bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnitGrouped_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickUnitGrouped();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnitGrouped_1native__JZZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canRightClickUnitGrouped((bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnitGrouped_1native__JLbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnitGrouped(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnitGrouped_1native__JLbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnitGrouped(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnitGrouped_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnitGrouped(targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnitGrouped_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnitGrouped(targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canRightClickUnitGrouped_1native__JLbwapi4_Unit_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkCanIssueCommandType, jboolean checkCommandibilityGrouped, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canRightClickUnitGrouped(targetUnit, (bool)checkCanTargetUnit, (bool)checkCanIssueCommandType, (bool)checkCommandibilityGrouped, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canHaltConstruction_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canHaltConstruction();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canHaltConstruction_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canHaltConstruction((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelConstruction_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelConstruction();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelConstruction_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelConstruction((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelAddon_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelAddon();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelAddon_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelAddon((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelTrain_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelTrain();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelTrain_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelTrain((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelTrainSlot_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelTrainSlot();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelTrainSlot_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelTrainSlot((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelTrainSlot_1native__JIZ(JNIEnv * env, jobject obj, jlong pointer, jint slot, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelTrainSlot(slot, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelTrainSlot_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint slot){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelTrainSlot(slot);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelTrainSlot_1native__JIZZ(JNIEnv * env, jobject obj, jlong pointer, jint slot, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelTrainSlot(slot, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelMorph_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelMorph();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelMorph_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelMorph((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelResearch_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelResearch();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelResearch_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelResearch((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelUpgrade_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelUpgrade();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canCancelUpgrade_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canCancelUpgrade((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechWithOrWithoutTarget_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUseTechWithOrWithoutTarget();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechWithOrWithoutTarget_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canUseTechWithOrWithoutTarget((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechWithOrWithoutTarget_1native__JLbwapi4_TechType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechWithOrWithoutTarget(*tech, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechWithOrWithoutTarget_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechWithOrWithoutTarget(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechWithOrWithoutTarget_1native__JLbwapi4_TechType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechWithOrWithoutTarget(*tech, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTech_1native__JLbwapi4_TechType_2Lbwapi4_PositionOrUnit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target, jboolean checkCanTargetUnit, jboolean checkTargetsType, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canUseTech(*tech, target, (bool)checkCanTargetUnit, (bool)checkTargetsType, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTech_1native__JLbwapi4_TechType_2Lbwapi4_PositionOrUnit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target, jboolean checkCanTargetUnit, jboolean checkTargetsType){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canUseTech(*tech, target, (bool)checkCanTargetUnit, (bool)checkTargetsType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTech_1native__JLbwapi4_TechType_2Lbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canUseTech(*tech, target, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTech_1native__JLbwapi4_TechType_2Lbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canUseTech(*tech, target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTech_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTech(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTech_1native__JLbwapi4_TechType_2Lbwapi4_PositionOrUnit_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target, jboolean checkCanTargetUnit, jboolean checkTargetsType, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->canUseTech(*tech, target, (bool)checkCanTargetUnit, (bool)checkTargetsType, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechWithoutTarget_1native__JLbwapi4_TechType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechWithoutTarget(*tech, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechWithoutTarget_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechWithoutTarget(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechWithoutTarget_1native__JLbwapi4_TechType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechWithoutTarget(*tech, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechUnit_1native__JLbwapi4_TechType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechUnit(*tech, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechUnit_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechUnit(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechUnit_1native__JLbwapi4_TechType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechUnit(*tech, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechUnit_1native__JLbwapi4_TechType_2Lbwapi4_Unit_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkTargetsUnits, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUseTechUnit(*tech, targetUnit, (bool)checkCanTargetUnit, (bool)checkTargetsUnits, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechUnit_1native__JLbwapi4_TechType_2Lbwapi4_Unit_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkTargetsUnits){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUseTechUnit(*tech, targetUnit, (bool)checkCanTargetUnit, (bool)checkTargetsUnits);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechUnit_1native__JLbwapi4_TechType_2Lbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_targetUnit, jboolean checkCanTargetUnit){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUseTechUnit(*tech, targetUnit, (bool)checkCanTargetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechUnit_1native__JLbwapi4_TechType_2Lbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_targetUnit){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUseTechUnit(*tech, targetUnit);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechUnit_1native__JLbwapi4_TechType_2Lbwapi4_Unit_2ZZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_targetUnit, jboolean checkCanTargetUnit, jboolean checkTargetsUnits, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Unit* targetUnit = (Unit*)env->GetLongField(p_targetUnit, FindCachedField(env, env->GetObjectClass(p_targetUnit), "pointer", "J"));
return x_unit->canUseTechUnit(*tech, targetUnit, (bool)checkCanTargetUnit, (bool)checkTargetsUnits, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechPosition_1native__JLbwapi4_TechType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechPosition(*tech, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechPosition_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechPosition(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechPosition_1native__JLbwapi4_TechType_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->canUseTechPosition(*tech, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechPosition_1native__JLbwapi4_TechType_2Lbwapi4_Position_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target, jboolean checkTargetsPositions, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canUseTechPosition(*tech, target, (bool)checkTargetsPositions, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechPosition_1native__JLbwapi4_TechType_2Lbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target, jboolean checkTargetsPositions){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canUseTechPosition(*tech, target, (bool)checkTargetsPositions);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechPosition_1native__JLbwapi4_TechType_2Lbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canUseTechPosition(*tech, target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canUseTechPosition_1native__JLbwapi4_TechType_2Lbwapi4_Position_2ZZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target, jboolean checkTargetsPositions, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canUseTechPosition(*tech, target, (bool)checkTargetsPositions, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPlaceCOP_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->canPlaceCOP();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPlaceCOP_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
return x_unit->canPlaceCOP((bool)checkCommandibility);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPlaceCOP_1native__JLbwapi4_TilePosition_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanIssueCommandType){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canPlaceCOP(target, (bool)checkCanIssueCommandType);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPlaceCOP_1native__JLbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canPlaceCOP(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unit_canPlaceCOP_1native__JLbwapi4_TilePosition_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean checkCanIssueCommandType, jboolean checkCommandibility){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->canPlaceCOP(target, (bool)checkCanIssueCommandType, (bool)checkCommandibility);
}
JNIEXPORT jobject JNICALL Java_bwapi4_UnitCommand_getType_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitCommand* x_unitCommand = (UnitCommand*)pointer;
jlong resptr = (jlong)x_unitCommand->getType();
jclass retcls = FindCachedClass(env, "bwapi4/UnitCommandType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/UnitCommandType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unitset_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
Position cresult = x_unitset->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unitset_getLoadedUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
jlong resptr = (jlong)x_unitset->getLoadedUnits();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unitset_getInterceptors_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
jlong resptr = (jlong)x_unitset->getInterceptors();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unitset_getLarva_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
jlong resptr = (jlong)x_unitset->getLarva();
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT void JNICALL Java_bwapi4_Unitset_setClientInfo_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint clientInfo){
Unitset* x_unitset = (Unitset*)pointer;
x_unitset->setClientInfo(clientInfo);
}
JNIEXPORT void JNICALL Java_bwapi4_Unitset_setClientInfo_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
x_unitset->setClientInfo();
}
JNIEXPORT void JNICALL Java_bwapi4_Unitset_setClientInfo_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint clientInfo, jint index){
Unitset* x_unitset = (Unitset*)pointer;
x_unitset->setClientInfo(clientInfo, index);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unitset_getUnitsInRadius_1native(JNIEnv * env, jobject obj, jlong pointer, jint radius, jobject p_pred){
Unitset* x_unitset = (Unitset*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_unitset->getUnitsInRadius(radius, pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unitset");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unitset;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unitset_getClosestUnit_1native__JLbwapi4_UnitFilter_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_pred){
Unitset* x_unitset = (Unitset*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_unitset->getClosestUnit(pred);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi4_Unitset_getClosestUnit_1native__JLbwapi4_UnitFilter_2I(JNIEnv * env, jobject obj, jlong pointer, jobject p_pred, jint radius){
Unitset* x_unitset = (Unitset*)pointer;
UnitFilter* pred = (UnitFilter*)env->GetLongField(p_pred, FindCachedField(env, env->GetObjectClass(p_pred), "pointer", "J"));
jlong resptr = (jlong)x_unitset->getClosestUnit(pred, radius);
jclass retcls = FindCachedClass(env, "bwapi4/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_issueCommand_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_command){
Unitset* x_unitset = (Unitset*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unitset->issueCommand(*command);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_attack_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->attack(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_attack_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->attack(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_build_1native__JLbwapi4_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unitset* x_unitset = (Unitset*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unitset->build(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_build_1native__JLbwapi4_UnitType_2Lbwapi4_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_type, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unitset->build(*type, target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_buildAddon_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unitset* x_unitset = (Unitset*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unitset->buildAddon(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_train_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unitset* x_unitset = (Unitset*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unitset->train(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_morph_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unitset* x_unitset = (Unitset*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unitset->morph(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_setRallyPoint_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->setRallyPoint(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_move_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unitset->move(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_move_1native__JLbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unitset->move(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_patrol_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unitset->patrol(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_patrol_1native__JLbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unitset->patrol(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_holdPosition_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->holdPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_holdPosition_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->holdPosition((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_stop_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->stop();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_stop_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->stop((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_follow_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->follow(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_follow_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->follow(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_gather_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->gather(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_gather_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->gather(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_returnCargo_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->returnCargo();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_returnCargo_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->returnCargo((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_repair_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->repair(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_repair_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->repair(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_burrow_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->burrow();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_unburrow_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->unburrow();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_cloak_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->cloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_decloak_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->decloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_siege_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->siege();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_unsiege_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->unsiege();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_lift_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->lift();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_load_1native__JLbwapi4_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->load(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_load_1native__JLbwapi4_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->load(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_unloadAll_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->unloadAll();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_unloadAll_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->unloadAll((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_unloadAll_1native__JLbwapi4_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unitset->unloadAll(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_unloadAll_1native__JLbwapi4_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unitset->unloadAll(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_rightClick_1native__JLbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->rightClick(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_rightClick_1native__JLbwapi4_PositionOrUnit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unitset* x_unitset = (Unitset*)pointer;
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->rightClick(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_haltConstruction_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->haltConstruction();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_cancelConstruction_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->cancelConstruction();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_cancelAddon_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->cancelAddon();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_cancelTrain_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->cancelTrain();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_cancelTrain_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint slot){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->cancelTrain(slot);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_cancelMorph_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->cancelMorph();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_cancelResearch_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->cancelResearch();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_cancelUpgrade_1native(JNIEnv * env, jobject obj, jlong pointer){
Unitset* x_unitset = (Unitset*)pointer;
return x_unitset->cancelUpgrade();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_useTech_1native__JLbwapi4_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unitset* x_unitset = (Unitset*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unitset->useTech(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_Unitset_useTech_1native__JLbwapi4_TechType_2Lbwapi4_PositionOrUnit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target){
Unitset* x_unitset = (Unitset*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
PositionOrUnit* target = (PositionOrUnit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unitset->useTech(*tech, target);
}
JNIEXPORT jboolean JNICALL Java_bwapi4_WalkPosition_isValid(JNIEnv * env, jobject obj){
WalkPosition* x_walkPosition = (WalkPosition*)pointer;
return x_walkPosition->isValid();
}
JNIEXPORT jobject JNICALL Java_bwapi4_WalkPosition_makeValid(JNIEnv * env, jobject obj){
WalkPosition* x_walkPosition = (WalkPosition*)pointer;
jlong resptr = (jlong)x_walkPosition->makeValid();
jclass retcls = FindCachedClass(env, "bwapi4/WalkPosition");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi4/WalkPosition;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jdouble JNICALL Java_bwapi4_WalkPosition_getDistance(JNIEnv * env, jobject obj, jobject p_position){
WalkPosition* x_walkPosition = (WalkPosition*)pointer;
WalkPosition* position = (WalkPosition*)env->GetLongField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "pointer", "J"));
return x_walkPosition->getDistance(position);
}
JNIEXPORT jint JNICALL Java_bwapi4_WalkPosition_getApproxDistance(JNIEnv * env, jobject obj, jobject p_position){
WalkPosition* x_walkPosition = (WalkPosition*)pointer;
WalkPosition* position = (WalkPosition*)env->GetLongField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "pointer", "J"));
return x_walkPosition->getApproxDistance(position);
}
JNIEXPORT jdouble JNICALL Java_bwapi4_WalkPosition_getLength(JNIEnv * env, jobject obj){
WalkPosition* x_walkPosition = (WalkPosition*)pointer;
return x_walkPosition->getLength();
}
JNIEXPORT jboolean JNICALL Java_bwapi4_WalkPosition_hasPath(JNIEnv * env, jobject obj, jobject p_position){
WalkPosition* x_walkPosition = (WalkPosition*)pointer;
WalkPosition* position = (WalkPosition*)env->GetLongField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "pointer", "J"));
return x_walkPosition->hasPath(position);
}
void reconnect()
{
	while (!BWAPIClient.connect()) {
            Sleep(1000);
    }
}



void flushPrint(const char * text){
	printf(text);
	fflush(stdout); 
}

void println(const char * text){
	printf(text);
	flushPrint("\n");
}

JNIEXPORT void JNICALL Java_bwapi_Mirror_startGame(JNIEnv * env, jobject obj){
println("Attempting to init BWAPI...");
		BWAPI_init();
		println("BWAPI ready.");
jclass cls;
jmethodID getId;
cls = env->FindClass("Lbwapi/Color;");
getId = env->GetMethodID(cls,"<init>", "(III)V");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Red", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Red.red(), Colors::Red.green(), Colors::Red.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Blue", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Blue.red(), Colors::Blue.green(), Colors::Blue.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Teal", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Teal.red(), Colors::Teal.green(), Colors::Teal.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Purple", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Purple.red(), Colors::Purple.green(), Colors::Purple.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Orange", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Orange.red(), Colors::Orange.green(), Colors::Orange.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Brown", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Brown.red(), Colors::Brown.green(), Colors::Brown.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "White", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::White.red(), Colors::White.green(), Colors::White.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Yellow", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Yellow.red(), Colors::Yellow.green(), Colors::Yellow.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Green", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Green.red(), Colors::Green.green(), Colors::Green.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cyan", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Cyan.red(), Colors::Cyan.green(), Colors::Cyan.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Black", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Black.red(), Colors::Black.green(), Colors::Black.blue()));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Grey", "Lbwapi/Color;"), env->NewObject(cls, getId, Colors::Grey.red(), Colors::Grey.green(), Colors::Grey.blue()));
println("Connecting to Broodwar...");
		reconnect();
		println("Connection successful, starting match...");

		cls = env->GetObjectClass(obj);
		jclass gamecls = env->FindClass("Lbwapi/Game;");
		jclass unitCls = env->FindClass("Lbwapi/Unit;");
		jclass playerCls = env->FindClass("Lbwapi/Player;");
		jclass posCls = env->FindClass("Lbwapi/Position;");
		jobject moduleObj = env->GetObjectField(obj, env->GetFieldID(cls, "module", "Lbwapi/AIModule;"));
		jclass moduleCls = env->GetObjectClass(moduleObj);
		env->SetObjectField(obj, env->GetFieldID(cls, "game", "Lbwapi/Game;"), env->CallStaticObjectMethod(gamecls, env->GetStaticMethodID(gamecls, "get", "(J)Lbwapi/Game;"), (long)Broodwar));

		jmethodID updateMethodID = env->GetMethodID(env->GetObjectClass(obj), "update", "()V");
		jmethodID matchStartCallback = env->GetMethodID(moduleCls, "onStart", "()V");
		jmethodID matchEndCallback = env->GetMethodID(moduleCls, "onEnd", "(Z)V");
		jmethodID matchFrameCallback = env->GetMethodID(moduleCls, "onFrame", "()V");
		jmethodID sendTextCallback = env->GetMethodID(moduleCls, "onSendText", "(Ljava/lang/String;)V");
		jmethodID receiveTextCallback = env->GetMethodID(moduleCls, "onReceiveText", "(Lbwapi/Player;Ljava/lang/String;)V");
		jmethodID playerLeftCallback = env->GetMethodID(moduleCls, "onPlayerLeft", "(Lbwapi/Player;)V");
		jmethodID nukeDetectCallback = env->GetMethodID(moduleCls, "onNukeDetect", "(Lbwapi/Position;)V");
		jmethodID unitDiscoverCallback = env->GetMethodID(moduleCls, "onUnitDiscover", "(Lbwapi/Unit;)V");
		jmethodID unitEvadeCallback = env->GetMethodID(moduleCls, "onUnitEvade", "(Lbwapi/Unit;)V");
		jmethodID unitShowCallback = env->GetMethodID(moduleCls, "onUnitShow", "(Lbwapi/Unit;)V");
		jmethodID unitHideCallback = env->GetMethodID(moduleCls, "onUnitHide", "(Lbwapi/Unit;)V");
		jmethodID unitCreateCallback = env->GetMethodID(moduleCls, "onUnitCreate", "(Lbwapi/Unit;)V");
		jmethodID unitDestroyCallback = env->GetMethodID(moduleCls, "onUnitDestroy", "(Lbwapi/Unit;)V");
		jmethodID unitMorphCallback = env->GetMethodID(moduleCls, "onUnitMorph", "(Lbwapi/Unit;)V");
		jmethodID unitRenegadeCallback = env->GetMethodID(moduleCls, "onUnitRenegade", "(Lbwapi/Unit;)V");
		jmethodID saveGameCallback = env->GetMethodID(moduleCls, "onSaveGame", "(Ljava/lang/String;)V");
		jmethodID unitCompleteCallback = env->GetMethodID(moduleCls, "onUnitComplete", "(Lbwapi/Unit;)V");
		jmethodID playerDroppedCallback = env->GetMethodID(moduleCls, "onPlayerDropped", "(Lbwapi/Player;)V");
		while (true) {
            if (Broodwar != NULL) {
				println("Waiting...");
                while (!Broodwar->isInGame()) {
                    BWAPIClient.update();
					if (Broodwar == NULL) {
                            println("Match ended.");
                            return;
                    }
                }
            }

			println("Game ready!!!");

			while (Broodwar->isInGame()) {
				
				env->CallVoidMethod(obj, updateMethodID);


				for(std::list<Event>::iterator it = Broodwar->getEvents().begin(); it!=Broodwar->getEvents().end(); it++)
				  {
					  switch (it->getType()) {
						  case EventType::MatchStart:
							  env->CallVoidMethod(moduleObj, matchStartCallback);
						  break;
						  case EventType::MatchEnd:
							  env->CallVoidMethod(moduleObj, matchEndCallback, it->isWinner());
						  break;
						  case EventType::MatchFrame:
							  env->CallVoidMethod(moduleObj, matchFrameCallback);
						  break;
						  case EventType::SendText:
							  env->CallVoidMethod(moduleObj, sendTextCallback,  env->NewStringUTF(it->getText().c_str()));
						  break;
						  case EventType::ReceiveText:
							  env->CallVoidMethod(moduleObj, receiveTextCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, "get", "(J)Lbwapi/Player;"), (jlong)it->getPlayer()), env->NewStringUTF(it->getText().c_str()));
						  break;
						  case EventType::PlayerLeft:
							  env->CallVoidMethod(moduleObj, playerLeftCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, "get", "(J)Lbwapi/Player;"), (jlong)it->getPlayer()));
						  break;
						  case EventType::NukeDetect:
							  env->CallVoidMethod(moduleObj, nukeDetectCallback, env->NewObject(posCls, env->GetMethodID(posCls,"<init>", "(II)V"), it->getPosition().x(), it->getPosition().y()));
						  break;
						  case EventType::UnitDiscover:
							  env->CallVoidMethod(moduleObj, unitDiscoverCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						  case EventType::UnitEvade:
							  env->CallVoidMethod(moduleObj, unitEvadeCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						   case EventType::UnitShow:
							  env->CallVoidMethod(moduleObj, unitShowCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						  case EventType::UnitHide:
							  env->CallVoidMethod(moduleObj, unitHideCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						  case EventType::UnitCreate:
							  env->CallVoidMethod(moduleObj, unitCreateCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						  case EventType::UnitDestroy:
							  env->CallVoidMethod(moduleObj, unitDestroyCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						  case EventType::UnitMorph:
							  env->CallVoidMethod(moduleObj, unitMorphCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						  case EventType::UnitRenegade:
							  env->CallVoidMethod(moduleObj, unitRenegadeCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						  case EventType::SaveGame:
							  env->CallVoidMethod(moduleObj, saveGameCallback, env->NewStringUTF(it->getText().c_str()));
						  break;
						  case EventType::UnitComplete:
							  env->CallVoidMethod(moduleObj, unitCompleteCallback, env->CallStaticObjectMethod(unitCls, env->GetStaticMethodID(unitCls, "get", "(J)Lbwapi/Unit;"), (jlong)it->getUnit()));
						  break;
						  case EventType::PlayerDropped:
							  env->CallVoidMethod(moduleObj, playerDroppedCallback, env->CallStaticObjectMethod(playerCls, env->GetStaticMethodID(playerCls, "get", "(J)Lbwapi/Player;")));
						  break;

					  }
				  }
				BWAPIClient.update();
				if (!BWAPI::BWAPIClient.isConnected()) {
						println("Reconnecting...");
						reconnect();
				}
			}
		}
}

