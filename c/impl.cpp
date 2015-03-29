#include "../concat_header.h"
#include <BWAPI.h>
#include <BWAPI/Client.h>
#include <BWTA.h>
#include <jni.h>
#include <cstring>
#include "../BWTA_Result.h"

using namespace BWAPI;

std::map<int, const BulletType*> tableBulletType;
std::map<int, const Color*> tableColor;
std::map<int, const DamageType*> tableDamageType;
std::map<int, const Error*> tableError;
std::map<int, const ExplosionType*> tableExplosionType;
std::map<int, const GameType*> tableGameType;
std::map<int, const Order*> tableOrder;
std::map<int, const PlayerType*> tablePlayerType;
std::map<int, const Race*> tableRace;
std::map<int, const TechType*> tableTechType;
std::map<int, const UnitCommandType*> tableUnitCommandType;
std::map<int, const UnitSizeType*> tableUnitSizeType;
std::map<int, const UnitType*> tableUnitType;
std::map<int, const UpgradeType*> tableUpgradeType;
std::map<int, const WeaponType*> tableWeaponType;

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

JNIEXPORT jint JNICALL Java_bwapi_Bullet_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getID();
}
JNIEXPORT jobject JNICALL Java_bwapi_Bullet_getPlayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
jlong resptr = (jlong)x_bullet->getPlayer();
jclass retcls = FindCachedClass(env, "bwapi/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Bullet_getType_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
jlong resptr = (jlong)x_bullet->getType();
jclass retcls = FindCachedClass(env, "bwapi/BulletType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/BulletType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Bullet_getSource_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
jlong resptr = (jlong)x_bullet->getSource();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Bullet_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
Position cresult = x_bullet->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwapi_Bullet_getAngle_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getAngle();
}
JNIEXPORT jdouble JNICALL Java_bwapi_Bullet_getVelocityX_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getVelocityX();
}
JNIEXPORT jdouble JNICALL Java_bwapi_Bullet_getVelocityY_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getVelocityY();
}
JNIEXPORT jobject JNICALL Java_bwapi_Bullet_getTarget_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
jlong resptr = (jlong)x_bullet->getTarget();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Bullet_getTargetPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
Position cresult = x_bullet->getTargetPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jint JNICALL Java_bwapi_Bullet_getRemoveTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->getRemoveTimer();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Bullet_exists_1native(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->exists();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Bullet_isVisible_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Bullet* x_bullet = (Bullet*)pointer;
return x_bullet->isVisible();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Bullet_isVisible_1native__JLbwapi_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Bullet* x_bullet = (Bullet*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_bullet->isVisible(player);
}
JNIEXPORT jstring JNICALL Java_bwapi_BulletType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
BulletType* x_bulletType = (BulletType*)pointer;
return env->NewStringUTF(x_bulletType->c_str());
}
JNIEXPORT jboolean JNICALL Java_bwapi_Client_isConnected_1native(JNIEnv * env, jobject obj, jlong pointer){
Client* x_client = (Client*)pointer;
return x_client->isConnected();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Client_connect_1native(JNIEnv * env, jobject obj, jlong pointer){
Client* x_client = (Client*)pointer;
return x_client->connect();
}
JNIEXPORT void JNICALL Java_bwapi_Client_disconnect_1native(JNIEnv * env, jobject obj, jlong pointer){
Client* x_client = (Client*)pointer;
x_client->disconnect();
}
JNIEXPORT void JNICALL Java_bwapi_Client_update_1native(JNIEnv * env, jobject obj, jlong pointer){
Client* x_client = (Client*)pointer;
x_client->update();
}
JNIEXPORT jstring JNICALL Java_bwapi_DamageType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
DamageType* x_damageType = (DamageType*)pointer;
return env->NewStringUTF(x_damageType->c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi_Error_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
Error* x_error = (Error*)pointer;
return env->NewStringUTF(x_error->c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_Event_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
Position cresult = x_evt->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jstring JNICALL Java_bwapi_Event_getText_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
return env->NewStringUTF(x_evt->getText().c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_Event_getUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
jlong resptr = (jlong)x_evt->getUnit();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Event_getPlayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
jlong resptr = (jlong)x_evt->getPlayer();
jclass retcls = FindCachedClass(env, "bwapi/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Event_isWinner_1native(JNIEnv * env, jobject obj, jlong pointer){
Event* x_evt = (Event*)pointer;
return x_evt->isWinner();
}
JNIEXPORT jstring JNICALL Java_bwapi_ExplosionType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
ExplosionType* x_explosionType = (ExplosionType*)pointer;
return env->NewStringUTF(x_explosionType->c_str());
}
JNIEXPORT jint JNICALL Java_bwapi_Force_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Force* x_force = (Force*)pointer;
return x_force->getID();
}
JNIEXPORT jstring JNICALL Java_bwapi_Force_getName_1native(JNIEnv * env, jobject obj, jlong pointer){
Force* x_force = (Force*)pointer;
return env->NewStringUTF(x_force->getName().c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_Force_getPlayers_1native(JNIEnv * env, jobject obj, jlong pointer){
Force* x_force = (Force*)pointer;
std::set<Player*> cresult = x_force->getPlayers();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Player");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Player;");
for(std::set<Player*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Player* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getForces_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Force*> cresult = x_game->getForces();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Force");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Force;");
for(std::set<Force*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Force* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getPlayers_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Player*> cresult = x_game->getPlayers();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Player");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Player;");
for(std::set<Player*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Player* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getAllUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getAllUnits();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getMinerals();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getGeysers_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getGeysers();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getNeutralUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getNeutralUnits();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getStaticMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getStaticMinerals();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getStaticGeysers_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getStaticGeysers();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getStaticNeutralUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getStaticNeutralUnits();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getBullets_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Bullet*> cresult = x_game->getBullets();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Bullet");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Bullet;");
for(std::set<Bullet*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Bullet* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getNukeDots_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Position> cresult = x_game->getNukeDots();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Position");
jmethodID elemConsID = FindCachedMethod(env, elemClass, "<init>", "(II)V");
for(std::set<Position>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Position elem_ptr = *it;
jobject elem = env->NewObject(elemClass, elemConsID, elem_ptr.x(), elem_ptr.y());
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getForce_1native(JNIEnv * env, jobject obj, jlong pointer, jint forceID){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getForce(forceID);
jclass retcls = FindCachedClass(env, "bwapi/Force");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Force;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getPlayer_1native(JNIEnv * env, jobject obj, jlong pointer, jint playerID){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getPlayer(playerID);
jclass retcls = FindCachedClass(env, "bwapi/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getUnit_1native(JNIEnv * env, jobject obj, jlong pointer, jint unitID){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getUnit(unitID);
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_indexToUnit_1native(JNIEnv * env, jobject obj, jlong pointer, jint unitIndex){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->indexToUnit(unitIndex);
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getRegion_1native(JNIEnv * env, jobject obj, jlong pointer, jint regionID){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getRegion(regionID);
jclass retcls = FindCachedClass(env, "bwapi/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getGameType_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)tableGameType.find(x_game->getGameType())->second;
jclass retcls = FindCachedClass(env, "bwapi/GameType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/GameType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getLatency_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getLatency();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getFrameCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getFrameCount();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getFPS_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getFPS();
}
JNIEXPORT jdouble JNICALL Java_bwapi_Game_getAverageFPS_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getAverageFPS();
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getMousePosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
Position cresult = x_game->getMousePosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_getMouseState_1native__JLbwapi_MouseButton_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_button){
Game* x_game = (Game*)pointer;
MouseButton button = (MouseButton)(int)env->GetIntField(p_button, FindCachedField(env, env->GetObjectClass(p_button), "value", "I"));
return x_game->getMouseState(button);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_getMouseState_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint button){
Game* x_game = (Game*)pointer;
return x_game->getMouseState(button);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_getKeyState_1native__JLbwapi_Key_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_key){
Game* x_game = (Game*)pointer;
Key key = (Key)(int)env->GetIntField(p_key, FindCachedField(env, env->GetObjectClass(p_key), "value", "I"));
return x_game->getKeyState(key);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_getKeyState_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint key){
Game* x_game = (Game*)pointer;
return x_game->getKeyState(key);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getScreenPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
Position cresult = x_game->getScreenPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT void JNICALL Java_bwapi_Game_setScreenPosition_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y){
Game* x_game = (Game*)pointer;
x_game->setScreenPosition(x, y);
}
JNIEXPORT void JNICALL Java_bwapi_Game_setScreenPosition_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
x_game->setScreenPosition(p);
}
JNIEXPORT void JNICALL Java_bwapi_Game_pingMinimap_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y){
Game* x_game = (Game*)pointer;
x_game->pingMinimap(x, y);
}
JNIEXPORT void JNICALL Java_bwapi_Game_pingMinimap_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_p){
Game* x_game = (Game*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
x_game->pingMinimap(p);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isFlagEnabled_1native(JNIEnv * env, jobject obj, jlong pointer, jint flag){
Game* x_game = (Game*)pointer;
return x_game->isFlagEnabled(flag);
}
JNIEXPORT void JNICALL Java_bwapi_Game_enableFlag_1native(JNIEnv * env, jobject obj, jlong pointer, jint flag){
Game* x_game = (Game*)pointer;
x_game->enableFlag(flag);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getUnitsOnTile_1native(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getUnitsOnTile(tileX, tileY);
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getUnitsInRectangle_1native__JIIII(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getUnitsInRectangle(left, top, right, bottom);
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getUnitsInRectangle_1native__JLbwapi_Position_2Lbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_topLeft, jobject p_bottomRight){
Game* x_game = (Game*)pointer;
Position topLeft((int)env->GetIntField(p_topLeft, FindCachedField(env, env->GetObjectClass(p_topLeft), "x", "I")), (int)env->GetIntField(p_topLeft, FindCachedField(env, env->GetObjectClass(p_topLeft), "y", "I")));
Position bottomRight((int)env->GetIntField(p_bottomRight, FindCachedField(env, env->GetObjectClass(p_bottomRight), "x", "I")), (int)env->GetIntField(p_bottomRight, FindCachedField(env, env->GetObjectClass(p_bottomRight), "y", "I")));
std::set<Unit*> cresult = x_game->getUnitsInRectangle(topLeft, bottomRight);
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getUnitsInRadius_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_center, jint radius){
Game* x_game = (Game*)pointer;
Position center((int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "x", "I")), (int)env->GetIntField(p_center, FindCachedField(env, env->GetObjectClass(p_center), "y", "I")));
std::set<Unit*> cresult = x_game->getUnitsInRadius(center, radius);
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getLastError_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)tableError.find(x_game->getLastError())->second;
jclass retcls = FindCachedClass(env, "bwapi/Error");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Error;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setLastError_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_e){
Game* x_game = (Game*)pointer;
Error* e = (Error*)env->GetLongField(p_e, FindCachedField(env, env->GetObjectClass(p_e), "pointer", "J"));
return x_game->setLastError(*e);
}
JNIEXPORT jint JNICALL Java_bwapi_Game_mapWidth_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->mapWidth();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_mapHeight_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->mapHeight();
}
JNIEXPORT jstring JNICALL Java_bwapi_Game_mapFileName_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return env->NewStringUTF(x_game->mapFileName().c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi_Game_mapPathName_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return env->NewStringUTF(x_game->mapPathName().c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi_Game_mapName_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return env->NewStringUTF(x_game->mapName().c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi_Game_mapHash_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return env->NewStringUTF(x_game->mapHash().c_str());
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isWalkable_1native(JNIEnv * env, jobject obj, jlong pointer, jint walkX, jint walkY){
Game* x_game = (Game*)pointer;
return x_game->isWalkable(walkX, walkY);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isBuildable_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->isBuildable(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isBuildable_1native__JIIZ(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jboolean includeBuildings){
Game* x_game = (Game*)pointer;
return x_game->isBuildable(tileX, tileY, (bool)includeBuildings);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isBuildable_1native__JLbwapi_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->isBuildable(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isBuildable_1native__JLbwapi_TilePosition_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jboolean includeBuildings){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->isBuildable(position, (bool)includeBuildings);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isVisible_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->isVisible(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isVisible_1native__JLbwapi_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->isVisible(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isExplored_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->isExplored(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isExplored_1native__JLbwapi_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->isExplored(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasCreep_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->hasCreep(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasCreep_1native__JLbwapi_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->hasCreep(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPower_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY){
Game* x_game = (Game*)pointer;
return x_game->hasPower(tileX, tileY);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPower_1native__JIILbwapi_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jobject p_unitType){
Game* x_game = (Game*)pointer;
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPower(tileX, tileY, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPower_1native__JLbwapi_TilePosition_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->hasPower(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPower_1native__JLbwapi_TilePosition_2Lbwapi_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jobject p_unitType){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPower(position, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPower_1native__JIIII(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jint tileWidth, jint tileHeight){
Game* x_game = (Game*)pointer;
return x_game->hasPower(tileX, tileY, tileWidth, tileHeight);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPower_1native__JIIIILbwapi_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jint tileX, jint tileY, jint tileWidth, jint tileHeight, jobject p_unitType){
Game* x_game = (Game*)pointer;
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPower(tileX, tileY, tileWidth, tileHeight, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPower_1native__JLbwapi_TilePosition_2II(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jint tileWidth, jint tileHeight){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->hasPower(position, tileWidth, tileHeight);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPower_1native__JLbwapi_TilePosition_2IILbwapi_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jint tileWidth, jint tileHeight, jobject p_unitType){
Game* x_game = (Game*)pointer;
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPower(position, tileWidth, tileHeight, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPowerPrecise_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y){
Game* x_game = (Game*)pointer;
return x_game->hasPowerPrecise(x, y);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPowerPrecise_1native__JIILbwapi_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jobject p_unitType){
Game* x_game = (Game*)pointer;
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPowerPrecise(x, y, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPowerPrecise_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_game->hasPowerPrecise(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPowerPrecise_1native__JLbwapi_Position_2Lbwapi_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position, jobject p_unitType){
Game* x_game = (Game*)pointer;
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* unitType = (UnitType*)env->GetLongField(p_unitType, FindCachedField(env, env->GetObjectClass(p_unitType), "pointer", "J"));
return x_game->hasPowerPrecise(position, *unitType);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_canBuildHere_1native__JLbwapi_Unit_2Lbwapi_TilePosition_2Lbwapi_UnitType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_builder, jobject p_position, jobject p_type){
Game* x_game = (Game*)pointer;
Unit* builder = (Unit*)env->GetLongField(p_builder, FindCachedField(env, env->GetObjectClass(p_builder), "pointer", "J"));
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canBuildHere(builder, position, *type);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_canBuildHere_1native__JLbwapi_Unit_2Lbwapi_TilePosition_2Lbwapi_UnitType_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_builder, jobject p_position, jobject p_type, jboolean checkExplored){
Game* x_game = (Game*)pointer;
Unit* builder = (Unit*)env->GetLongField(p_builder, FindCachedField(env, env->GetObjectClass(p_builder), "pointer", "J"));
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canBuildHere(builder, position, *type, (bool)checkExplored);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_canMake_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_builder, jobject p_type){
Game* x_game = (Game*)pointer;
Unit* builder = (Unit*)env->GetLongField(p_builder, FindCachedField(env, env->GetObjectClass(p_builder), "pointer", "J"));
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canMake(builder, *type);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_canResearch_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit, jobject p_type){
Game* x_game = (Game*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
TechType* type = (TechType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canResearch(unit, *type);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_canUpgrade_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit, jobject p_type){
Game* x_game = (Game*)pointer;
Unit* unit = (Unit*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
UpgradeType* type = (UpgradeType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_game->canUpgrade(unit, *type);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getStartLocations_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<TilePosition> cresult = x_game->getStartLocations();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/TilePosition");
jmethodID elemConsID = FindCachedMethod(env, elemClass, "<init>", "(II)V");
for(std::set<TilePosition>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const TilePosition elem_ptr = *it;
jobject elem = env->NewObject(elemClass, elemConsID, elem_ptr.x(), elem_ptr.y());
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT void JNICALL Java_bwapi_Game_printf_1native(JNIEnv * env, jobject obj, jlong pointer, jstring cstr_format){
Game* x_game = (Game*)pointer;
x_game->printf(std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi_Game_sendText_1native(JNIEnv * env, jobject obj, jlong pointer, jstring cstr_format){
Game* x_game = (Game*)pointer;
x_game->sendText(std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi_Game_sendTextEx_1native(JNIEnv * env, jobject obj, jlong pointer, jboolean toAllies, jstring cstr_format){
Game* x_game = (Game*)pointer;
x_game->sendTextEx((bool)toAllies, std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi_Game_changeRace_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_race){
Game* x_game = (Game*)pointer;
Race* race = (Race*)env->GetLongField(p_race, FindCachedField(env, env->GetObjectClass(p_race), "pointer", "J"));
x_game->changeRace(*race);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isInGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isInGame();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isMultiplayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isMultiplayer();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isBattleNet_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isBattleNet();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isPaused_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isPaused();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isReplay_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isReplay();
}
JNIEXPORT void JNICALL Java_bwapi_Game_startGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->startGame();
}
JNIEXPORT void JNICALL Java_bwapi_Game_pauseGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->pauseGame();
}
JNIEXPORT void JNICALL Java_bwapi_Game_resumeGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->resumeGame();
}
JNIEXPORT void JNICALL Java_bwapi_Game_leaveGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->leaveGame();
}
JNIEXPORT void JNICALL Java_bwapi_Game_restartGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->restartGame();
}
JNIEXPORT void JNICALL Java_bwapi_Game_setLocalSpeed_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->setLocalSpeed();
}
JNIEXPORT void JNICALL Java_bwapi_Game_setLocalSpeed_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint speed){
Game* x_game = (Game*)pointer;
x_game->setLocalSpeed(speed);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_issueCommand_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_units, jobject p_command){
Game* x_game = (Game*)pointer;
std::set<Unit*> units;
jclass colClass = env->GetObjectClass(p_units);
jmethodID sizeMethodId = FindCachedMethod(env, colClass, "size", "()I");
jmethodID getMethodId = FindCachedMethod(env, colClass, "get", "(I)Ljava/lang/Object;");
int size = (int)env->CallIntMethod(p_units, sizeMethodId);
for( int i = 0; i < size; i++ ) {
jobject jobj  = env->CallObjectMethod(p_units,getMethodId);
units.insert((Unit*)env->GetLongField(jobj, FindCachedField(env, env->GetObjectClass(jobj), "pointer", "J")));
}
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_game->issueCommand(units, *command);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getSelectedUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Unit*> cresult = x_game->getSelectedUnits();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_self_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->self();
jclass retcls = FindCachedClass(env, "bwapi/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_enemy_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->enemy();
jclass retcls = FindCachedClass(env, "bwapi/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_neutral_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->neutral();
jclass retcls = FindCachedClass(env, "bwapi/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_allies_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Player*> cresult = x_game->allies();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Player");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Player;");
for(std::set<Player*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Player* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_enemies_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Player*> cresult = x_game->enemies();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Player");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Player;");
for(std::set<Player*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Player* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_observers_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
std::set<Player*> cresult = x_game->observers();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Player");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Player;");
for(std::set<Player*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Player* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT void JNICALL Java_bwapi_Game_setTextSize_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->setTextSize();
}
JNIEXPORT void JNICALL Java_bwapi_Game_setTextSize_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint size){
Game* x_game = (Game*)pointer;
x_game->setTextSize(size);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawText_1native(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint x, jint y, jstring cstr_format){
Game* x_game = (Game*)pointer;
x_game->drawText(ctype, x, y, std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTextMap_1native(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jstring cstr_format){
Game* x_game = (Game*)pointer;
x_game->drawTextMap(x, y, std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTextMouse_1native(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jstring cstr_format){
Game* x_game = (Game*)pointer;
x_game->drawTextMouse(x, y, std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTextScreen_1native(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jstring cstr_format){
Game* x_game = (Game*)pointer;
x_game->drawTextScreen(x, y, std::string(env->GetStringUTFChars(cstr_format, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawBox_1native__JIIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint left, jint top, jint right, jint bottom, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBox(ctype, left, top, right, bottom, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawBox_1native__JIIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint left, jint top, jint right, jint bottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBox(ctype, left, top, right, bottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawBoxMap_1native__JIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMap(left, top, right, bottom, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawBoxMap_1native__JIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMap(left, top, right, bottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawBoxMouse_1native__JIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMouse(left, top, right, bottom, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawBoxMouse_1native__JIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxMouse(left, top, right, bottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawBoxScreen_1native__JIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxScreen(left, top, right, bottom, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawBoxScreen_1native__JIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint left, jint top, jint right, jint bottom, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawBoxScreen(left, top, right, bottom, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTriangle_1native__JIIIIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangle(ctype, ax, ay, bx, by, cx, cy, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTriangle_1native__JIIIIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangle(ctype, ax, ay, bx, by, cx, cy, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTriangleMap_1native__JIIIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMap(ax, ay, bx, by, cx, cy, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTriangleMap_1native__JIIIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMap(ax, ay, bx, by, cx, cy, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTriangleMouse_1native__JIIIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMouse(ax, ay, bx, by, cx, cy, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTriangleMouse_1native__JIIIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleMouse(ax, ay, bx, by, cx, cy, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTriangleScreen_1native__JIIIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleScreen(ax, ay, bx, by, cx, cy, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawTriangleScreen_1native__JIIIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ax, jint ay, jint bx, jint by, jint cx, jint cy, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawTriangleScreen(ax, ay, bx, by, cx, cy, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawCircle_1native__JIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint x, jint y, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircle(ctype, x, y, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawCircle_1native__JIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint x, jint y, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircle(ctype, x, y, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawCircleMap_1native__JIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMap(x, y, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawCircleMap_1native__JIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMap(x, y, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawCircleMouse_1native__JIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMouse(x, y, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawCircleMouse_1native__JIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleMouse(x, y, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawCircleScreen_1native__JIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleScreen(x, y, radius, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawCircleScreen_1native__JIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint radius, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawCircleScreen(x, y, radius, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawEllipse_1native__JIIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint x, jint y, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipse(ctype, x, y, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawEllipse_1native__JIIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint x, jint y, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipse(ctype, x, y, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawEllipseMap_1native__JIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMap(x, y, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawEllipseMap_1native__JIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMap(x, y, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawEllipseMouse_1native__JIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMouse(x, y, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawEllipseMouse_1native__JIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseMouse(x, y, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawEllipseScreen_1native__JIIIILbwapi_Color_2(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseScreen(x, y, xrad, yrad, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawEllipseScreen_1native__JIIIILbwapi_Color_2Z(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jint xrad, jint yrad, jobject p_color, jboolean isSolid){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawEllipseScreen(x, y, xrad, yrad, color, (bool)isSolid);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawDot_1native(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint x, jint y, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDot(ctype, x, y, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawDotMap_1native(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotMap(x, y, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawDotMouse_1native(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotMouse(x, y, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawDotScreen_1native(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawDotScreen(x, y, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawLine_1native(JNIEnv * env, jobject obj, jlong pointer, jint ctype, jint x1, jint y1, jint x2, jint y2, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLine(ctype, x1, y1, x2, y2, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawLineMap_1native(JNIEnv * env, jobject obj, jlong pointer, jint x1, jint y1, jint x2, jint y2, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineMap(x1, y1, x2, y2, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawLineMouse_1native(JNIEnv * env, jobject obj, jlong pointer, jint x1, jint y1, jint x2, jint y2, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineMouse(x1, y1, x2, y2, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_drawLineScreen_1native(JNIEnv * env, jobject obj, jlong pointer, jint x1, jint y1, jint x2, jint y2, jobject p_color){
Game* x_game = (Game*)pointer;
Color color((int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "r", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "g", "I")), (int)env->GetIntField(p_color, FindCachedField(env, env->GetObjectClass(p_color), "b", "I")));
x_game->drawLineScreen(x1, y1, x2, y2, color);
}
JNIEXPORT void JNICALL Java_bwapi_Game_getScreenBuffer_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->getScreenBuffer();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getLatencyFrames_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getLatencyFrames();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getLatencyTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getLatencyTime();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getRemainingLatencyFrames_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getRemainingLatencyFrames();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getRemainingLatencyTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getRemainingLatencyTime();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getRevision_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getRevision();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isDebug_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isDebug();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_isLatComEnabled_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->isLatComEnabled();
}
JNIEXPORT void JNICALL Java_bwapi_Game_setLatCom_1native(JNIEnv * env, jobject obj, jlong pointer, jboolean isEnabled){
Game* x_game = (Game*)pointer;
x_game->setLatCom((bool)isEnabled);
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getReplayFrameCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getReplayFrameCount();
}
JNIEXPORT void JNICALL Java_bwapi_Game_setGUI_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->setGUI();
}
JNIEXPORT void JNICALL Java_bwapi_Game_setGUI_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean enabled){
Game* x_game = (Game*)pointer;
x_game->setGUI((bool)enabled);
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getAPM_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getAPM();
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getAPM_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean includeSelects){
Game* x_game = (Game*)pointer;
return x_game->getAPM((bool)includeSelects);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setMap_1native(JNIEnv * env, jobject obj, jlong pointer, jstring cstr_mapFileName){
Game* x_game = (Game*)pointer;
return x_game->setMap(std::string(env->GetStringUTFChars(cstr_mapFileName, NULL)).c_str());
}
JNIEXPORT void JNICALL Java_bwapi_Game_setFrameSkip_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->setFrameSkip();
}
JNIEXPORT void JNICALL Java_bwapi_Game_setFrameSkip_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint frameSkip){
Game* x_game = (Game*)pointer;
x_game->setFrameSkip(frameSkip);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_hasPath_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_source, jobject p_destination){
Game* x_game = (Game*)pointer;
Position source((int)env->GetIntField(p_source, FindCachedField(env, env->GetObjectClass(p_source), "x", "I")), (int)env->GetIntField(p_source, FindCachedField(env, env->GetObjectClass(p_source), "y", "I")));
Position destination((int)env->GetIntField(p_destination, FindCachedField(env, env->GetObjectClass(p_destination), "x", "I")), (int)env->GetIntField(p_destination, FindCachedField(env, env->GetObjectClass(p_destination), "y", "I")));
return x_game->hasPath(source, destination);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setAlliance_1native__JLbwapi_Player_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_player, jboolean allied){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setAlliance(player, (bool)allied);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setAlliance_1native__JLbwapi_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setAlliance(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setAlliance_1native__JLbwapi_Player_2ZZ(JNIEnv * env, jobject obj, jlong pointer, jobject p_player, jboolean allied, jboolean alliedVictory){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setAlliance(player, (bool)allied, (bool)alliedVictory);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setVision_1native__JLbwapi_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setVision(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setVision_1native__JLbwapi_Player_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_player, jboolean enabled){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setVision(player, (bool)enabled);
}
JNIEXPORT void JNICALL Java_bwapi_Game_setCommandOptimizationLevel_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
x_game->setCommandOptimizationLevel();
}
JNIEXPORT void JNICALL Java_bwapi_Game_setCommandOptimizationLevel_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint level){
Game* x_game = (Game*)pointer;
x_game->setCommandOptimizationLevel(level);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getRegionAt_1native__JII(JNIEnv * env, jobject obj, jlong pointer, jint x, jint y){
Game* x_game = (Game*)pointer;
jlong resptr = (jlong)x_game->getRegionAt(x, y);
jclass retcls = FindCachedClass(env, "bwapi/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Game_getRegionAt_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_position){
Game* x_game = (Game*)pointer;
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
jlong resptr = (jlong)x_game->getRegionAt(position);
jclass retcls = FindCachedClass(env, "bwapi/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_Game_getLastEventTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->getLastEventTime();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setReplayVision_1native__JLbwapi_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setReplayVision(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setReplayVision_1native__JLbwapi_Player_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_player, jboolean enabled){
Game* x_game = (Game*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_game->setReplayVision(player, (bool)enabled);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setRevealAll_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Game* x_game = (Game*)pointer;
return x_game->setRevealAll();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Game_setRevealAll_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean reveal){
Game* x_game = (Game*)pointer;
return x_game->setRevealAll((bool)reveal);
}
JNIEXPORT jstring JNICALL Java_bwapi_GameType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
GameType* x_gameType = (GameType*)pointer;
return env->NewStringUTF(x_gameType->c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi_Order_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
Order* x_order = (Order*)pointer;
return env->NewStringUTF(x_order->c_str());
}
JNIEXPORT jint JNICALL Java_bwapi_Player_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getID();
}
JNIEXPORT jstring JNICALL Java_bwapi_Player_getName_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return env->NewStringUTF(x_player->getName().c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_Player_getUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
std::set<Unit*> cresult = x_player->getUnits();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Player_getRace_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
jlong resptr = (jlong)tableRace.find(x_player->getRace())->second;
jclass retcls = FindCachedClass(env, "bwapi/Race");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Race;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Player_getType_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
jlong resptr = (jlong)x_player->getType();
jclass retcls = FindCachedClass(env, "bwapi/PlayerType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/PlayerType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Player_getForce_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
jlong resptr = (jlong)x_player->getForce();
jclass retcls = FindCachedClass(env, "bwapi/Force");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Force;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isAlly_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Player* x_player = (Player*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_player->isAlly(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isEnemy_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Player* x_player = (Player*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_player->isEnemy(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isNeutral_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->isNeutral();
}
JNIEXPORT jobject JNICALL Java_bwapi_Player_getStartLocation_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
TilePosition cresult = x_player->getStartLocation();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isVictorious_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->isVictorious();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isDefeated_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->isDefeated();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_leftGame_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->leftGame();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_minerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->minerals();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_gas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->gas();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_gatheredMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->gatheredMinerals();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_gatheredGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->gatheredGas();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_repairedMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->repairedMinerals();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_repairedGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->repairedGas();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_refundedMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->refundedMinerals();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_refundedGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->refundedGas();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_spentMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->spentMinerals();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_spentGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->spentGas();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_supplyTotal_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->supplyTotal();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_supplyTotal_1native__JLbwapi_Race_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_race){
Player* x_player = (Player*)pointer;
Race* race = (Race*)env->GetLongField(p_race, FindCachedField(env, env->GetObjectClass(p_race), "pointer", "J"));
return x_player->supplyTotal(*race);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_supplyUsed_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->supplyUsed();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_supplyUsed_1native__JLbwapi_Race_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_race){
Player* x_player = (Player*)pointer;
Race* race = (Race*)env->GetLongField(p_race, FindCachedField(env, env->GetObjectClass(p_race), "pointer", "J"));
return x_player->supplyUsed(*race);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_allUnitCount_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->allUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_visibleUnitCount_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->visibleUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_completedUnitCount_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->completedUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_incompleteUnitCount_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->incompleteUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_deadUnitCount_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->deadUnitCount(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_killedUnitCount_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->killedUnitCount(*unit);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_hasResearched_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Player* x_player = (Player*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_player->hasResearched(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isResearching_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Player* x_player = (Player*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_player->isResearching(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isUpgrading_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_upgrade){
Player* x_player = (Player*)pointer;
UpgradeType* upgrade = (UpgradeType*)env->GetLongField(p_upgrade, FindCachedField(env, env->GetObjectClass(p_upgrade), "pointer", "J"));
return x_player->isUpgrading(*upgrade);
}
JNIEXPORT jobject JNICALL Java_bwapi_Player_getColor_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
Color cresult = x_player->getColor();
jclass retcls = FindCachedClass(env, "bwapi/Color");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(III)V");
jobject result = env->NewObject(retcls, retConsID, cresult.red(), cresult.green(), cresult.blue());
return result;
}
JNIEXPORT jint JNICALL Java_bwapi_Player_getTextColor_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getTextColor();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_maxEnergy_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->maxEnergy(*unit);
}
JNIEXPORT jdouble JNICALL Java_bwapi_Player_topSpeed_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->topSpeed(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_groundWeaponMaxRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->groundWeaponMaxRange(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_airWeaponMaxRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->airWeaponMaxRange(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_weaponMaxRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_weapon){
Player* x_player = (Player*)pointer;
WeaponType* weapon = (WeaponType*)env->GetLongField(p_weapon, FindCachedField(env, env->GetObjectClass(p_weapon), "pointer", "J"));
return x_player->weaponMaxRange(*weapon);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_sightRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->sightRange(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_groundWeaponDamageCooldown_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->groundWeaponDamageCooldown(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_armor_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->armor(*unit);
}
JNIEXPORT jint JNICALL Java_bwapi_Player_getUnitScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getUnitScore();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_getKillScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getKillScore();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_getBuildingScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getBuildingScore();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_getRazingScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getRazingScore();
}
JNIEXPORT jint JNICALL Java_bwapi_Player_getCustomScore_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->getCustomScore();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isObserver_1native(JNIEnv * env, jobject obj, jlong pointer){
Player* x_player = (Player*)pointer;
return x_player->isObserver();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isResearchAvailable_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Player* x_player = (Player*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_player->isResearchAvailable(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Player_isUnitAvailable_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_unit){
Player* x_player = (Player*)pointer;
UnitType* unit = (UnitType*)env->GetLongField(p_unit, FindCachedField(env, env->GetObjectClass(p_unit), "pointer", "J"));
return x_player->isUnitAvailable(*unit);
}
JNIEXPORT jstring JNICALL Java_bwapi_PlayerType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
PlayerType* x_playerType = (PlayerType*)pointer;
return env->NewStringUTF(x_playerType->c_str());
}
JNIEXPORT jboolean JNICALL Java_bwapi_Position_isValid(JNIEnv * env, jobject obj){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
return x_position.isValid();
}
JNIEXPORT jobject JNICALL Java_bwapi_Position_makeValid(JNIEnv * env, jobject obj){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
Position cresult = x_position.makeValid();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwapi_Position_getDistance(JNIEnv * env, jobject obj, jobject p_position){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_position.getDistance(position);
}
JNIEXPORT jint JNICALL Java_bwapi_Position_getApproxDistance(JNIEnv * env, jobject obj, jobject p_position){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_position.getApproxDistance(position);
}
JNIEXPORT jdouble JNICALL Java_bwapi_Position_getLength(JNIEnv * env, jobject obj){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
return x_position.getLength();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Position_hasPath(JNIEnv * env, jobject obj, jobject p_position){
Position x_position((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_position.hasPath(position);
}
JNIEXPORT jstring JNICALL Java_bwapi_Race_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
Race* x_race = (Race*)pointer;
return env->NewStringUTF(x_race->c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_Race_getWorker_1native(JNIEnv * env, jobject obj, jlong pointer){
Race* x_race = (Race*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_race->getWorker())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Race_getCenter_1native(JNIEnv * env, jobject obj, jlong pointer){
Race* x_race = (Race*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_race->getCenter())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Race_getRefinery_1native(JNIEnv * env, jobject obj, jlong pointer){
Race* x_race = (Race*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_race->getRefinery())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Race_getTransport_1native(JNIEnv * env, jobject obj, jlong pointer){
Race* x_race = (Race*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_race->getTransport())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Race_getSupplyProvider_1native(JNIEnv * env, jobject obj, jlong pointer){
Race* x_race = (Race*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_race->getSupplyProvider())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_Region_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getID();
}
JNIEXPORT jint JNICALL Java_bwapi_Region_getRegionGroupID_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getRegionGroupID();
}
JNIEXPORT jobject JNICALL Java_bwapi_Region_getCenter_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
Position cresult = x_region->getCenter();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jboolean JNICALL Java_bwapi_Region_isHigherGround_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->isHigherGround();
}
JNIEXPORT jint JNICALL Java_bwapi_Region_getDefensePriority_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getDefensePriority();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Region_isWalkable_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->isWalkable();
}
JNIEXPORT jint JNICALL Java_bwapi_Region_getBoundsLeft_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getBoundsLeft();
}
JNIEXPORT jint JNICALL Java_bwapi_Region_getBoundsTop_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getBoundsTop();
}
JNIEXPORT jint JNICALL Java_bwapi_Region_getBoundsRight_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getBoundsRight();
}
JNIEXPORT jint JNICALL Java_bwapi_Region_getBoundsBottom_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
return x_region->getBoundsBottom();
}
JNIEXPORT jobject JNICALL Java_bwapi_Region_getClosestAccessibleRegion_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
jlong resptr = (jlong)x_region->getClosestAccessibleRegion();
jclass retcls = FindCachedClass(env, "bwapi/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Region_getClosestInaccessibleRegion_1native(JNIEnv * env, jobject obj, jlong pointer){
Region* x_region = (Region*)pointer;
jlong resptr = (jlong)x_region->getClosestInaccessibleRegion();
jclass retcls = FindCachedClass(env, "bwapi/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_Region_getDistance_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_other){
Region* x_region = (Region*)pointer;
Region* other = (Region*)env->GetLongField(p_other, FindCachedField(env, env->GetObjectClass(p_other), "pointer", "J"));
return x_region->getDistance(other);
}
JNIEXPORT jstring JNICALL Java_bwapi_TechType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
return env->NewStringUTF(x_techType->c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_TechType_getRace_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
jlong resptr = (jlong)tableRace.find(x_techType->getRace())->second;
jclass retcls = FindCachedClass(env, "bwapi/Race");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Race;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_TechType_mineralPrice_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
return x_techType->mineralPrice();
}
JNIEXPORT jint JNICALL Java_bwapi_TechType_gasPrice_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
return x_techType->gasPrice();
}
JNIEXPORT jint JNICALL Java_bwapi_TechType_researchTime_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
return x_techType->researchTime();
}
JNIEXPORT jint JNICALL Java_bwapi_TechType_energyUsed_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
return x_techType->energyUsed();
}
JNIEXPORT jobject JNICALL Java_bwapi_TechType_whatResearches_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_techType->whatResearches())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_TechType_getWeapon_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
jlong resptr = (jlong)tableWeaponType.find(x_techType->getWeapon())->second;
jclass retcls = FindCachedClass(env, "bwapi/WeaponType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/WeaponType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi_TechType_targetsUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
return x_techType->targetsUnit();
}
JNIEXPORT jboolean JNICALL Java_bwapi_TechType_targetsPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
return x_techType->targetsPosition();
}
JNIEXPORT jobject JNICALL Java_bwapi_TechType_whatUses_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
std::set<UnitType> cresult = x_techType->whatUses();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/UnitType");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/UnitType;");
for(std::set<UnitType>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const UnitType* elem_ptr = tableUnitType.find((*it).getID())->second;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_TechType_getOrder_1native(JNIEnv * env, jobject obj, jlong pointer){
TechType* x_techType = (TechType*)pointer;
jlong resptr = (jlong)tableOrder.find(x_techType->getOrder())->second;
jclass retcls = FindCachedClass(env, "bwapi/Order");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Order;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jboolean JNICALL Java_bwapi_TilePosition_hasPath(JNIEnv * env, jobject obj, jobject p_position){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_tilePosition.hasPath(position);
}
JNIEXPORT jboolean JNICALL Java_bwapi_TilePosition_isValid(JNIEnv * env, jobject obj){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
return x_tilePosition.isValid();
}
JNIEXPORT jobject JNICALL Java_bwapi_TilePosition_makeValid(JNIEnv * env, jobject obj){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
TilePosition cresult = x_tilePosition.makeValid();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwapi_TilePosition_getDistance(JNIEnv * env, jobject obj, jobject p_position){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
TilePosition position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
return x_tilePosition.getDistance(position);
}
JNIEXPORT jdouble JNICALL Java_bwapi_TilePosition_getLength(JNIEnv * env, jobject obj){
TilePosition x_tilePosition((int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "x", "I")), (int)env->GetIntField(obj, FindCachedField(env, env->GetObjectClass(obj), "y", "I")));
return x_tilePosition.getLength();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getID_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getID();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getReplayID_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getReplayID();
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getPlayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getPlayer();
jclass retcls = FindCachedClass(env, "bwapi/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getType_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_unit->getType())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getTilePosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
TilePosition cresult = x_unit->getTilePosition();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwapi_Unit_getAngle_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getAngle();
}
JNIEXPORT jdouble JNICALL Java_bwapi_Unit_getVelocityX_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getVelocityX();
}
JNIEXPORT jdouble JNICALL Java_bwapi_Unit_getVelocityY_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getVelocityY();
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getRegion_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getRegion();
jclass retcls = FindCachedClass(env, "bwapi/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getLeft_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getLeft();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getTop_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getTop();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getRight_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRight();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getBottom_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getBottom();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getHitPoints_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getHitPoints();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getShields_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getShields();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getEnergy_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getEnergy();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getResources_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getResources();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getResourceGroup_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getResourceGroup();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getDistance_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->getDistance(target);
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getDistance_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->getDistance(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_hasPath_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->hasPath(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_hasPath_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->hasPath(target);
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getLastCommandFrame_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getLastCommandFrame();
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getLastAttackingPlayer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getLastAttackingPlayer();
jclass retcls = FindCachedClass(env, "bwapi/Player");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Player;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getUpgradeLevel_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_upgrade){
Unit* x_unit = (Unit*)pointer;
UpgradeType* upgrade = (UpgradeType*)env->GetLongField(p_upgrade, FindCachedField(env, env->GetObjectClass(p_upgrade), "pointer", "J"));
return x_unit->getUpgradeLevel(*upgrade);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getInitialType_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_unit->getInitialType())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getInitialPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getInitialPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getInitialTilePosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
TilePosition cresult = x_unit->getInitialTilePosition();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getInitialHitPoints_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getInitialHitPoints();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getInitialResources_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getInitialResources();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getKillCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getKillCount();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getAcidSporeCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getAcidSporeCount();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getInterceptorCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getInterceptorCount();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getScarabCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getScarabCount();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getSpiderMineCount_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getSpiderMineCount();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getGroundWeaponCooldown_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getGroundWeaponCooldown();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getAirWeaponCooldown_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getAirWeaponCooldown();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getSpellCooldown_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getSpellCooldown();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getDefenseMatrixPoints_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getDefenseMatrixPoints();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getDefenseMatrixTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getDefenseMatrixTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getEnsnareTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getEnsnareTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getIrradiateTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getIrradiateTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getLockdownTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getLockdownTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getMaelstromTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getMaelstromTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getOrderTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getOrderTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getPlagueTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getPlagueTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getRemoveTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemoveTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getStasisTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getStasisTimer();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getStimTimer_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getStimTimer();
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getBuildType_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_unit->getBuildType())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getTech_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableTechType.find(x_unit->getTech())->second;
jclass retcls = FindCachedClass(env, "bwapi/TechType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/TechType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getUpgrade_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableUpgradeType.find(x_unit->getUpgrade())->second;
jclass retcls = FindCachedClass(env, "bwapi/UpgradeType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UpgradeType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getRemainingBuildTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemainingBuildTime();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getRemainingTrainTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemainingTrainTime();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getRemainingResearchTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemainingResearchTime();
}
JNIEXPORT jint JNICALL Java_bwapi_Unit_getRemainingUpgradeTime_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->getRemainingUpgradeTime();
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getBuildUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getBuildUnit();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getTarget_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getTarget();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getTargetPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getTargetPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getOrder_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableOrder.find(x_unit->getOrder())->second;
jclass retcls = FindCachedClass(env, "bwapi/Order");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Order;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getSecondaryOrder_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)tableOrder.find(x_unit->getSecondaryOrder())->second;
jclass retcls = FindCachedClass(env, "bwapi/Order");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Order;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getOrderTarget_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getOrderTarget();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getOrderTargetPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getOrderTargetPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getRallyPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
Position cresult = x_unit->getRallyPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getRallyUnit_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getRallyUnit();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getAddon_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getAddon();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getNydusExit_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getNydusExit();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getPowerUp_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getPowerUp();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getTransport_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getTransport();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getLoadedUnits_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
std::set<Unit*> cresult = x_unit->getLoadedUnits();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getCarrier_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getCarrier();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getInterceptors_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
std::set<Unit*> cresult = x_unit->getInterceptors();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getHatchery_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
jlong resptr = (jlong)x_unit->getHatchery();
jclass retcls = FindCachedClass(env, "bwapi/Unit");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Unit;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getLarva_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
std::set<Unit*> cresult = x_unit->getLarva();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getUnitsInRadius_1native(JNIEnv * env, jobject obj, jlong pointer, jint radius){
Unit* x_unit = (Unit*)pointer;
std::set<Unit*> cresult = x_unit->getUnitsInRadius(radius);
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_Unit_getUnitsInWeaponRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_weapon){
Unit* x_unit = (Unit*)pointer;
WeaponType* weapon = (WeaponType*)env->GetLongField(p_weapon, FindCachedField(env, env->GetObjectClass(p_weapon), "pointer", "J"));
std::set<Unit*> cresult = x_unit->getUnitsInWeaponRange(*weapon);
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/Unit");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/Unit;");
for(std::set<Unit*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const Unit* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_exists_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->exists();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_hasNuke_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->hasNuke();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isAccelerating_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isAccelerating();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isAttacking_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isAttacking();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isAttackFrame_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isAttackFrame();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isBeingConstructed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBeingConstructed();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isBeingGathered_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBeingGathered();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isBeingHealed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBeingHealed();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isBlind_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBlind();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isBraking_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBraking();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isBurrowed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isBurrowed();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isCarryingGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isCarryingGas();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isCarryingMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isCarryingMinerals();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isCloaked_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isCloaked();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isCompleted_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isCompleted();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isConstructing_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isConstructing();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isDefenseMatrixed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isDefenseMatrixed();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isDetected_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isDetected();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isEnsnared_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isEnsnared();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isFollowing_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isFollowing();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isGatheringGas_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isGatheringGas();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isGatheringMinerals_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isGatheringMinerals();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isHallucination_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isHallucination();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isHoldingPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isHoldingPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isIdle_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isIdle();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isInterruptible_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isInterruptible();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isInvincible_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isInvincible();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isInWeaponRange_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->isInWeaponRange(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isIrradiated_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isIrradiated();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isLifted_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isLifted();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isLoaded_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isLoaded();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isLockedDown_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isLockedDown();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isMaelstrommed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isMaelstrommed();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isMorphing_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isMorphing();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isMoving_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isMoving();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isParasited_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isParasited();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isPatrolling_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isPatrolling();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isPlagued_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isPlagued();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isRepairing_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isRepairing();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isResearching_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isResearching();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isSelected_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isSelected();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isSieged_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isSieged();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isStartingAttack_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isStartingAttack();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isStasised_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isStasised();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isStimmed_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isStimmed();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isStuck_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isStuck();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isTraining_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isTraining();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isUnderAttack_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnderAttack();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isUnderDarkSwarm_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnderDarkSwarm();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isUnderDisruptionWeb_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnderDisruptionWeb();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isUnderStorm_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnderStorm();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isUnpowered_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUnpowered();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isUpgrading_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isUpgrading();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isVisible_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->isVisible();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_isVisible_1native__JLbwapi_Player_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_player){
Unit* x_unit = (Unit*)pointer;
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
return x_unit->isVisible(player);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_canIssueCommand_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_command){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->canIssueCommand(*command);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_issueCommand_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_command){
Unit* x_unit = (Unit*)pointer;
UnitCommand* command = (UnitCommand*)env->GetLongField(p_command, FindCachedField(env, env->GetObjectClass(p_command), "pointer", "J"));
return x_unit->issueCommand(*command);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_attack_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->attack(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_attack_1native__JLbwapi_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->attack(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_attack_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->attack(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_attack_1native__JLbwapi_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->attack(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_build_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jobject p_type){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->build(target, *type);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_buildAddon_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->buildAddon(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_train_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->train(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_morph_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_type){
Unit* x_unit = (Unit*)pointer;
UnitType* type = (UnitType*)env->GetLongField(p_type, FindCachedField(env, env->GetObjectClass(p_type), "pointer", "J"));
return x_unit->morph(*type);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_research_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->research(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_upgrade_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_upgrade){
Unit* x_unit = (Unit*)pointer;
UpgradeType* upgrade = (UpgradeType*)env->GetLongField(p_upgrade, FindCachedField(env, env->GetObjectClass(p_upgrade), "pointer", "J"));
return x_unit->upgrade(*upgrade);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_setRallyPoint_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->setRallyPoint(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_setRallyPoint_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->setRallyPoint(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_move_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->move(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_move_1native__JLbwapi_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->move(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_patrol_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->patrol(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_patrol_1native__JLbwapi_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->patrol(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_holdPosition_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->holdPosition();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_holdPosition_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
return x_unit->holdPosition((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_stop_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->stop();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_stop_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
return x_unit->stop((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_follow_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->follow(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_follow_1native__JLbwapi_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->follow(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_gather_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->gather(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_gather_1native__JLbwapi_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->gather(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_returnCargo_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->returnCargo();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_returnCargo_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
return x_unit->returnCargo((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_repair_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->repair(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_repair_1native__JLbwapi_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->repair(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_burrow_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->burrow();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_unburrow_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->unburrow();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_cloak_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_decloak_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->decloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_siege_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->siege();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_unsiege_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->unsiege();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_lift_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->lift();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_land_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->land(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_load_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->load(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_load_1native__JLbwapi_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->load(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_unload_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->unload(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_unloadAll_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->unloadAll();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_unloadAll_1native__JZ(JNIEnv * env, jobject obj, jlong pointer, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
return x_unit->unloadAll((bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_unloadAll_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->unloadAll(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_unloadAll_1native__JLbwapi_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->unloadAll(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_rightClick_1native__JLbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->rightClick(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_rightClick_1native__JLbwapi_Position_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->rightClick(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_rightClick_1native__JLbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->rightClick(target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_rightClick_1native__JLbwapi_Unit_2Z(JNIEnv * env, jobject obj, jlong pointer, jobject p_target, jboolean shiftQueueCommand){
Unit* x_unit = (Unit*)pointer;
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->rightClick(target, (bool)shiftQueueCommand);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_haltConstruction_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->haltConstruction();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_cancelConstruction_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelConstruction();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_cancelAddon_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelAddon();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_cancelTrain_1native__J(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelTrain();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_cancelTrain_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint slot){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelTrain(slot);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_cancelMorph_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelMorph();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_cancelResearch_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelResearch();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_cancelUpgrade_1native(JNIEnv * env, jobject obj, jlong pointer){
Unit* x_unit = (Unit*)pointer;
return x_unit->cancelUpgrade();
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_useTech_1native__JLbwapi_TechType_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
return x_unit->useTech(*tech);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_useTech_1native__JLbwapi_TechType_2Lbwapi_Position_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Position target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->useTech(*tech, target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_useTech_1native__JLbwapi_TechType_2Lbwapi_Unit_2(JNIEnv * env, jobject obj, jlong pointer, jobject p_tech, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TechType* tech = (TechType*)env->GetLongField(p_tech, FindCachedField(env, env->GetObjectClass(p_tech), "pointer", "J"));
Unit* target = (Unit*)env->GetLongField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "pointer", "J"));
return x_unit->useTech(*tech, target);
}
JNIEXPORT jboolean JNICALL Java_bwapi_Unit_placeCOP_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_target){
Unit* x_unit = (Unit*)pointer;
TilePosition target((int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "x", "I")), (int)env->GetIntField(p_target, FindCachedField(env, env->GetObjectClass(p_target), "y", "I")));
return x_unit->placeCOP(target);
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitCommand_getType_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitCommand* x_unitCommand = (UnitCommand*)pointer;
jlong resptr = (jlong)x_unitCommand->getType();
jclass retcls = FindCachedClass(env, "bwapi/UnitCommandType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitCommandType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jstring JNICALL Java_bwapi_UnitCommandType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitCommandType* x_unitCommandType = (UnitCommandType*)pointer;
return env->NewStringUTF(x_unitCommandType->c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi_UnitSizeType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitSizeType* x_unitSizeType = (UnitSizeType*)pointer;
return env->NewStringUTF(x_unitSizeType->c_str());
}
JNIEXPORT jstring JNICALL Java_bwapi_UnitType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return env->NewStringUTF(x_unitType->c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_getRace_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
jlong resptr = (jlong)tableRace.find(x_unitType->getRace())->second;
jclass retcls = FindCachedClass(env, "bwapi/Race");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Race;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_requiredTech_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
jlong resptr = (jlong)tableTechType.find(x_unitType->requiredTech())->second;
jclass retcls = FindCachedClass(env, "bwapi/TechType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/TechType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_cloakingTech_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
jlong resptr = (jlong)tableTechType.find(x_unitType->cloakingTech())->second;
jclass retcls = FindCachedClass(env, "bwapi/TechType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/TechType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_abilities_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
std::set<TechType> cresult = x_unitType->abilities();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/TechType");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/TechType;");
for(std::set<TechType>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const TechType* elem_ptr = tableTechType.find((*it).getID())->second;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_upgrades_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
std::set<UpgradeType> cresult = x_unitType->upgrades();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/UpgradeType");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/UpgradeType;");
for(std::set<UpgradeType>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const UpgradeType* elem_ptr = tableUpgradeType.find((*it).getID())->second;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_armorUpgrade_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
jlong resptr = (jlong)tableUpgradeType.find(x_unitType->armorUpgrade())->second;
jclass retcls = FindCachedClass(env, "bwapi/UpgradeType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UpgradeType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_maxHitPoints_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->maxHitPoints();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_maxShields_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->maxShields();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_maxEnergy_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->maxEnergy();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_armor_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->armor();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_mineralPrice_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->mineralPrice();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_gasPrice_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->gasPrice();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_buildTime_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->buildTime();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_supplyRequired_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->supplyRequired();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_supplyProvided_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->supplyProvided();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_spaceRequired_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->spaceRequired();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_spaceProvided_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->spaceProvided();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_buildScore_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->buildScore();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_destroyScore_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->destroyScore();
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_size_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
jlong resptr = (jlong)x_unitType->size();
jclass retcls = FindCachedClass(env, "bwapi/UnitSizeType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitSizeType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_tileWidth_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->tileWidth();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_tileHeight_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->tileHeight();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_dimensionLeft_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->dimensionLeft();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_dimensionUp_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->dimensionUp();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_dimensionRight_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->dimensionRight();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_dimensionDown_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->dimensionDown();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_seekRange_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->seekRange();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_sightRange_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->sightRange();
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_groundWeapon_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
jlong resptr = (jlong)tableWeaponType.find(x_unitType->groundWeapon())->second;
jclass retcls = FindCachedClass(env, "bwapi/WeaponType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/WeaponType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_maxGroundHits_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->maxGroundHits();
}
JNIEXPORT jobject JNICALL Java_bwapi_UnitType_airWeapon_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
jlong resptr = (jlong)tableWeaponType.find(x_unitType->airWeapon())->second;
jclass retcls = FindCachedClass(env, "bwapi/WeaponType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/WeaponType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_maxAirHits_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->maxAirHits();
}
JNIEXPORT jdouble JNICALL Java_bwapi_UnitType_topSpeed_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->topSpeed();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_acceleration_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->acceleration();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_haltDistance_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->haltDistance();
}
JNIEXPORT jint JNICALL Java_bwapi_UnitType_turnRadius_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->turnRadius();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_canProduce_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->canProduce();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_canAttack_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->canAttack();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_canMove_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->canMove();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isFlyer_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isFlyer();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_regeneratesHP_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->regeneratesHP();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isSpellcaster_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isSpellcaster();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_hasPermanentCloak_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->hasPermanentCloak();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isInvincible_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isInvincible();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isOrganic_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isOrganic();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isMechanical_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isMechanical();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isRobotic_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isRobotic();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isDetector_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isDetector();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isResourceContainer_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isResourceContainer();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isResourceDepot_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isResourceDepot();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isRefinery_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isRefinery();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isWorker_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isWorker();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_requiresPsi_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->requiresPsi();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_requiresCreep_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->requiresCreep();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isTwoUnitsInOneEgg_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isTwoUnitsInOneEgg();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isBurrowable_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isBurrowable();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isCloakable_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isCloakable();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isBuilding_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isBuilding();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isAddon_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isAddon();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isFlyingBuilding_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isFlyingBuilding();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isNeutral_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isNeutral();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isHero_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isHero();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isPowerup_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isPowerup();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isBeacon_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isBeacon();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isFlagBeacon_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isFlagBeacon();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isSpecialBuilding_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isSpecialBuilding();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isSpell_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isSpell();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_producesLarva_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->producesLarva();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_isMineralField_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->isMineralField();
}
JNIEXPORT jboolean JNICALL Java_bwapi_UnitType_canBuildAddon_1native(JNIEnv * env, jobject obj, jlong pointer){
UnitType* x_unitType = (UnitType*)pointer;
return x_unitType->canBuildAddon();
}
JNIEXPORT jstring JNICALL Java_bwapi_UpgradeType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return env->NewStringUTF(x_upgradeType->c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_UpgradeType_getRace_1native(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
jlong resptr = (jlong)tableRace.find(x_upgradeType->getRace())->second;
jclass retcls = FindCachedClass(env, "bwapi/Race");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/Race;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_mineralPrice_1native__J(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->mineralPrice();
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_mineralPrice_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint level){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->mineralPrice(level);
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_mineralPriceFactor_1native(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->mineralPriceFactor();
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_gasPrice_1native__J(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->gasPrice();
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_gasPrice_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint level){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->gasPrice(level);
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_gasPriceFactor_1native(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->gasPriceFactor();
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_upgradeTime_1native__J(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->upgradeTime();
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_upgradeTime_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint level){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->upgradeTime(level);
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_upgradeTimeFactor_1native(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->upgradeTimeFactor();
}
JNIEXPORT jint JNICALL Java_bwapi_UpgradeType_maxRepeats_1native(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
return x_upgradeType->maxRepeats();
}
JNIEXPORT jobject JNICALL Java_bwapi_UpgradeType_whatUpgrades_1native(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_upgradeType->whatUpgrades())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_UpgradeType_whatsRequired_1native__J(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_upgradeType->whatsRequired())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_UpgradeType_whatsRequired_1native__JI(JNIEnv * env, jobject obj, jlong pointer, jint level){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_upgradeType->whatsRequired(level))->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_UpgradeType_whatUses_1native(JNIEnv * env, jobject obj, jlong pointer){
UpgradeType* x_upgradeType = (UpgradeType*)pointer;
std::set<UnitType> cresult = x_upgradeType->whatUses();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwapi/UnitType");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwapi/UnitType;");
for(std::set<UnitType>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const UnitType* elem_ptr = tableUnitType.find((*it).getID())->second;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jstring JNICALL Java_bwapi_WeaponType_c_1str_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return env->NewStringUTF(x_weaponType->c_str());
}
JNIEXPORT jobject JNICALL Java_bwapi_WeaponType_getTech_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
jlong resptr = (jlong)tableTechType.find(x_weaponType->getTech())->second;
jclass retcls = FindCachedClass(env, "bwapi/TechType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/TechType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_WeaponType_whatUses_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
jlong resptr = (jlong)tableUnitType.find(x_weaponType->whatUses())->second;
jclass retcls = FindCachedClass(env, "bwapi/UnitType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UnitType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_damageAmount_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->damageAmount();
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_damageBonus_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->damageBonus();
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_damageCooldown_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->damageCooldown();
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_damageFactor_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->damageFactor();
}
JNIEXPORT jobject JNICALL Java_bwapi_WeaponType_upgradeType_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
jlong resptr = (jlong)tableUpgradeType.find(x_weaponType->upgradeType())->second;
jclass retcls = FindCachedClass(env, "bwapi/UpgradeType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/UpgradeType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_WeaponType_damageType_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
jlong resptr = (jlong)x_weaponType->damageType();
jclass retcls = FindCachedClass(env, "bwapi/DamageType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/DamageType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwapi_WeaponType_explosionType_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
jlong resptr = (jlong)x_weaponType->explosionType();
jclass retcls = FindCachedClass(env, "bwapi/ExplosionType");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwapi/ExplosionType;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_minRange_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->minRange();
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_maxRange_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->maxRange();
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_innerSplashRadius_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->innerSplashRadius();
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_medianSplashRadius_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->medianSplashRadius();
}
JNIEXPORT jint JNICALL Java_bwapi_WeaponType_outerSplashRadius_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->outerSplashRadius();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsAir_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsAir();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsGround_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsGround();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsMechanical_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsMechanical();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsOrganic_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsOrganic();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsNonBuilding_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsNonBuilding();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsNonRobotic_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsNonRobotic();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsTerrain_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsTerrain();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsOrgOrMech_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsOrgOrMech();
}
JNIEXPORT jboolean JNICALL Java_bwapi_WeaponType_targetsOwn_1native(JNIEnv * env, jobject obj, jlong pointer){
WeaponType* x_weaponType = (WeaponType*)pointer;
return x_weaponType->targetsOwn();
}
JNIEXPORT jobject JNICALL Java_bwta_BaseLocation_getPosition_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
Position cresult = x_baseLocation->getPosition();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_BaseLocation_getTilePosition_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
TilePosition cresult = x_baseLocation->getTilePosition();
jclass retcls = FindCachedClass(env, "bwapi/TilePosition");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_BaseLocation_getRegion_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
jlong resptr = (jlong)x_baseLocation->getRegion();
jclass retcls = FindCachedClass(env, "bwta/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jint JNICALL Java_bwta_BaseLocation_minerals_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
return x_baseLocation->minerals();
}
JNIEXPORT jint JNICALL Java_bwta_BaseLocation_gas_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
return x_baseLocation->gas();
}
JNIEXPORT jdouble JNICALL Java_bwta_BaseLocation_getGroundDistance_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_other){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
BWTA::BaseLocation* other = (BWTA::BaseLocation*)env->GetLongField(p_other, FindCachedField(env, env->GetObjectClass(p_other), "pointer", "J"));
return x_baseLocation->getGroundDistance(other);
}
JNIEXPORT jdouble JNICALL Java_bwta_BaseLocation_getAirDistance_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_other){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
BWTA::BaseLocation* other = (BWTA::BaseLocation*)env->GetLongField(p_other, FindCachedField(env, env->GetObjectClass(p_other), "pointer", "J"));
return x_baseLocation->getAirDistance(other);
}
JNIEXPORT jboolean JNICALL Java_bwta_BaseLocation_isIsland_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
return x_baseLocation->isIsland();
}
JNIEXPORT jboolean JNICALL Java_bwta_BaseLocation_isMineralOnly_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
return x_baseLocation->isMineralOnly();
}
JNIEXPORT jboolean JNICALL Java_bwta_BaseLocation_isStartLocation_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::BaseLocation* x_baseLocation = (BWTA::BaseLocation*)pointer;
return x_baseLocation->isStartLocation();
}
JNIEXPORT void JNICALL Java_bwta_BWTA_readMap(JNIEnv * env, jclass jclz){
BWTA::readMap();
}
JNIEXPORT void JNICALL Java_bwta_BWTA_analyze(JNIEnv * env, jclass jclz){
BWTA::analyze();
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getRegions(JNIEnv * env, jclass jclz){
std::set<BWTA::Region*> cresult = BWTA::getRegions();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwta/Region");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwta/Region;");
for(std::set<BWTA::Region*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const BWTA::Region* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getChokepoints(JNIEnv * env, jclass jclz){
std::set<BWTA::Chokepoint*> cresult = BWTA::getChokepoints();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwta/Chokepoint");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwta/Chokepoint;");
for(std::set<BWTA::Chokepoint*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const BWTA::Chokepoint* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getBaseLocations(JNIEnv * env, jclass jclz){
std::set<BWTA::BaseLocation*> cresult = BWTA::getBaseLocations();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwta/BaseLocation");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwta/BaseLocation;");
for(std::set<BWTA::BaseLocation*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const BWTA::BaseLocation* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getStartLocations(JNIEnv * env, jclass jclz){
std::set<BWTA::BaseLocation*> cresult = BWTA::getStartLocations();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwta/BaseLocation");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwta/BaseLocation;");
for(std::set<BWTA::BaseLocation*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const BWTA::BaseLocation* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getUnwalkablePolygons(JNIEnv * env, jclass jclz){
std::set<BWTA::Polygon*> cresult = BWTA::getUnwalkablePolygons();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwta/Polygon");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwta/Polygon;");
for(std::set<BWTA::Polygon*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const BWTA::Polygon* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getStartLocation(JNIEnv * env, jclass jclz, jobject p_player){
Player* player = (Player*)env->GetLongField(p_player, FindCachedField(env, env->GetObjectClass(p_player), "pointer", "J"));
jlong resptr = (jlong)BWTA::getStartLocation(player);
jclass retcls = FindCachedClass(env, "bwta/BaseLocation");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/BaseLocation;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getRegion__II(JNIEnv * env, jclass jclz, jint x, jint y){
jlong resptr = (jlong)BWTA::getRegion(x, y);
jclass retcls = FindCachedClass(env, "bwta/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getRegion__Lbwapi_TilePosition_2(JNIEnv * env, jclass jclz, jobject p_tileposition){
TilePosition tileposition((int)env->GetIntField(p_tileposition, FindCachedField(env, env->GetObjectClass(p_tileposition), "x", "I")), (int)env->GetIntField(p_tileposition, FindCachedField(env, env->GetObjectClass(p_tileposition), "y", "I")));
jlong resptr = (jlong)BWTA::getRegion(tileposition);
jclass retcls = FindCachedClass(env, "bwta/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getRegion__Lbwapi_Position_2(JNIEnv * env, jclass jclz, jobject p_position){
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
jlong resptr = (jlong)BWTA::getRegion(position);
jclass retcls = FindCachedClass(env, "bwta/Region");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Region;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestChokepoint__II(JNIEnv * env, jclass jclz, jint x, jint y){
jlong resptr = (jlong)BWTA::getNearestChokepoint(x, y);
jclass retcls = FindCachedClass(env, "bwta/Chokepoint");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Chokepoint;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestChokepoint__Lbwapi_TilePosition_2(JNIEnv * env, jclass jclz, jobject p_tileposition){
TilePosition tileposition((int)env->GetIntField(p_tileposition, FindCachedField(env, env->GetObjectClass(p_tileposition), "x", "I")), (int)env->GetIntField(p_tileposition, FindCachedField(env, env->GetObjectClass(p_tileposition), "y", "I")));
jlong resptr = (jlong)BWTA::getNearestChokepoint(tileposition);
jclass retcls = FindCachedClass(env, "bwta/Chokepoint");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Chokepoint;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestChokepoint__Lbwapi_Position_2(JNIEnv * env, jclass jclz, jobject p_position){
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
jlong resptr = (jlong)BWTA::getNearestChokepoint(position);
jclass retcls = FindCachedClass(env, "bwta/Chokepoint");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Chokepoint;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestBaseLocation__II(JNIEnv * env, jclass jclz, jint x, jint y){
jlong resptr = (jlong)BWTA::getNearestBaseLocation(x, y);
jclass retcls = FindCachedClass(env, "bwta/BaseLocation");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/BaseLocation;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestBaseLocation__Lbwapi_TilePosition_2(JNIEnv * env, jclass jclz, jobject p_tileposition){
TilePosition tileposition((int)env->GetIntField(p_tileposition, FindCachedField(env, env->GetObjectClass(p_tileposition), "x", "I")), (int)env->GetIntField(p_tileposition, FindCachedField(env, env->GetObjectClass(p_tileposition), "y", "I")));
jlong resptr = (jlong)BWTA::getNearestBaseLocation(tileposition);
jclass retcls = FindCachedClass(env, "bwta/BaseLocation");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/BaseLocation;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestBaseLocation__Lbwapi_Position_2(JNIEnv * env, jclass jclz, jobject p_position){
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
jlong resptr = (jlong)BWTA::getNearestBaseLocation(position);
jclass retcls = FindCachedClass(env, "bwta/BaseLocation");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/BaseLocation;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestUnwalkablePolygon__II(JNIEnv * env, jclass jclz, jint x, jint y){
jlong resptr = (jlong)BWTA::getNearestUnwalkablePolygon(x, y);
jclass retcls = FindCachedClass(env, "bwta/Polygon");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Polygon;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestUnwalkablePolygon__Lbwapi_TilePosition_2(JNIEnv * env, jclass jclz, jobject p_tileposition){
TilePosition tileposition((int)env->GetIntField(p_tileposition, FindCachedField(env, env->GetObjectClass(p_tileposition), "x", "I")), (int)env->GetIntField(p_tileposition, FindCachedField(env, env->GetObjectClass(p_tileposition), "y", "I")));
jlong resptr = (jlong)BWTA::getNearestUnwalkablePolygon(tileposition);
jclass retcls = FindCachedClass(env, "bwta/Polygon");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Polygon;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getNearestUnwalkablePosition(JNIEnv * env, jclass jclz, jobject p_position){
Position position((int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "x", "I")), (int)env->GetIntField(p_position, FindCachedField(env, env->GetObjectClass(p_position), "y", "I")));
Position cresult = BWTA::getNearestUnwalkablePosition(position);
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jboolean JNICALL Java_bwta_BWTA_isConnected__IIII(JNIEnv * env, jclass jclz, jint x1, jint y1, jint x2, jint y2){
return BWTA::isConnected(x1, y1, x2, y2);
}
JNIEXPORT jboolean JNICALL Java_bwta_BWTA_isConnected__Lbwapi_TilePosition_2Lbwapi_TilePosition_2(JNIEnv * env, jclass jclz, jobject p_a, jobject p_b){
TilePosition a((int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "x", "I")), (int)env->GetIntField(p_a, FindCachedField(env, env->GetObjectClass(p_a), "y", "I")));
TilePosition b((int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "x", "I")), (int)env->GetIntField(p_b, FindCachedField(env, env->GetObjectClass(p_b), "y", "I")));
return BWTA::isConnected(a, b);
}
JNIEXPORT jdouble JNICALL Java_bwta_BWTA_getGroundDistance(JNIEnv * env, jclass jclz, jobject p_start, jobject p_end){
TilePosition start((int)env->GetIntField(p_start, FindCachedField(env, env->GetObjectClass(p_start), "x", "I")), (int)env->GetIntField(p_start, FindCachedField(env, env->GetObjectClass(p_start), "y", "I")));
TilePosition end((int)env->GetIntField(p_end, FindCachedField(env, env->GetObjectClass(p_end), "x", "I")), (int)env->GetIntField(p_end, FindCachedField(env, env->GetObjectClass(p_end), "y", "I")));
return BWTA::getGroundDistance(start, end);
}
JNIEXPORT jobject JNICALL Java_bwta_Chokepoint_getCenter_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Chokepoint* x_chokepoint = (BWTA::Chokepoint*)pointer;
Position cresult = x_chokepoint->getCenter();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jdouble JNICALL Java_bwta_Chokepoint_getWidth_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Chokepoint* x_chokepoint = (BWTA::Chokepoint*)pointer;
return x_chokepoint->getWidth();
}
JNIEXPORT jdouble JNICALL Java_bwta_Polygon_getArea_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Polygon* x_polygon = (BWTA::Polygon*)pointer;
return x_polygon->getArea();
}
JNIEXPORT jobject JNICALL Java_bwta_BWTA_getPositions(JNIEnv * env, jclass jclz){
    jclass listCls = FindCachedClass(env, "java/util/ArrayList");
    jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
    jobject result = env->NewObject(listCls, listConsID);
}
JNIEXPORT jdouble JNICALL Java_bwta_Polygon_getPerimeter_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Polygon* x_polygon = (BWTA::Polygon*)pointer;
return x_polygon->getPerimeter();
}
JNIEXPORT jobject JNICALL Java_bwta_Polygon_getCenter_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Polygon* x_polygon = (BWTA::Polygon*)pointer;
Position cresult = x_polygon->getCenter();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jboolean JNICALL Java_bwta_Polygon_isInside_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_p){
BWTA::Polygon* x_polygon = (BWTA::Polygon*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
return x_polygon->isInside(p);
}
JNIEXPORT jobject JNICALL Java_bwta_Polygon_getNearestPoint_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_p){
BWTA::Polygon* x_polygon = (BWTA::Polygon*)pointer;
Position p((int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "x", "I")), (int)env->GetIntField(p_p, FindCachedField(env, env->GetObjectClass(p_p), "y", "I")));
Position cresult = x_polygon->getNearestPoint(p);
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_Region_getPolygon_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Region* x_region = (BWTA::Region*)pointer;
jlong resptr = (jlong)&x_region->getPolygon();
jclass retcls = FindCachedClass(env, "bwta/Polygon");
jmethodID mid = FindCachedMethodStatic(env, retcls, "get", "(J)Lbwta/Polygon;");
return env->CallStaticObjectMethod(retcls, mid, resptr);
}
JNIEXPORT jobject JNICALL Java_bwta_Region_getCenter_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Region* x_region = (BWTA::Region*)pointer;
Position cresult = x_region->getCenter();
jclass retcls = FindCachedClass(env, "bwapi/Position");
jmethodID retConsID = FindCachedMethod(env, retcls, "<init>", "(II)V");
jobject result = env->NewObject(retcls, retConsID, cresult.x(), cresult.y());
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_Region_getChokepoints_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Region* x_region = (BWTA::Region*)pointer;
std::set<BWTA::Chokepoint*> cresult = x_region->getChokepoints();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwta/Chokepoint");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwta/Chokepoint;");
for(std::set<BWTA::Chokepoint*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const BWTA::Chokepoint* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jobject JNICALL Java_bwta_Region_getBaseLocations_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Region* x_region = (BWTA::Region*)pointer;
std::set<BWTA::BaseLocation*> cresult = x_region->getBaseLocations();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwta/BaseLocation");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwta/BaseLocation;");
for(std::set<BWTA::BaseLocation*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const BWTA::BaseLocation* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
}
JNIEXPORT jboolean JNICALL Java_bwta_Region_isReachable_1native(JNIEnv * env, jobject obj, jlong pointer, jobject p_region){
BWTA::Region* x_region = (BWTA::Region*)pointer;
BWTA::Region* region = (BWTA::Region*)env->GetLongField(p_region, FindCachedField(env, env->GetObjectClass(p_region), "pointer", "J"));
return x_region->isReachable(region);
}
JNIEXPORT jobject JNICALL Java_bwta_Region_getReachableRegions_1native(JNIEnv * env, jobject obj, jlong pointer){
BWTA::Region* x_region = (BWTA::Region*)pointer;
std::set<BWTA::Region*> cresult = x_region->getReachableRegions();
jclass listCls = FindCachedClass(env, "java/util/ArrayList");
jmethodID listConsID = FindCachedMethod(env, listCls, "<init>", "()V");
jobject result = env->NewObject(listCls, listConsID);
jmethodID addMethodID = FindCachedMethod(env, listCls, "add", "(Ljava/lang/Object;)Z");
jclass elemClass = FindCachedClass(env, "bwta/Region");
jmethodID getMethodID = FindCachedMethodStatic(env, elemClass, "get", "(J)Lbwta/Region;");
for(std::set<BWTA::Region*>::const_iterator it = cresult.begin(); it != cresult.end(); it++ ){
const BWTA::Region* elem_ptr = *it;
jobject elem = env->CallStaticObjectMethod(elemClass, getMethodID, (long)elem_ptr) ;
env->CallVoidMethod(result, addMethodID, elem);
}
return result;
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
cls = env->FindClass("Lbwapi/BulletType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/BulletType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Melee", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Melee));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Melee.getID(), &BulletTypes::Melee));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Fusion_Cutter_Hit", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Fusion_Cutter_Hit));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Fusion_Cutter_Hit.getID(), &BulletTypes::Fusion_Cutter_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gauss_Rifle_Hit", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Gauss_Rifle_Hit));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Gauss_Rifle_Hit.getID(), &BulletTypes::Gauss_Rifle_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "C_10_Canister_Rifle_Hit", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::C_10_Canister_Rifle_Hit));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::C_10_Canister_Rifle_Hit.getID(), &BulletTypes::C_10_Canister_Rifle_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gemini_Missiles", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Gemini_Missiles));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Gemini_Missiles.getID(), &BulletTypes::Gemini_Missiles));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Fragmentation_Grenade", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Fragmentation_Grenade));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Fragmentation_Grenade.getID(), &BulletTypes::Fragmentation_Grenade));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Longbolt_Missile", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Longbolt_Missile));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Longbolt_Missile.getID(), &BulletTypes::Longbolt_Missile));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ATS_ATA_Laser_Battery", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::ATS_ATA_Laser_Battery));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::ATS_ATA_Laser_Battery.getID(), &BulletTypes::ATS_ATA_Laser_Battery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Burst_Lasers", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Burst_Lasers));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Burst_Lasers.getID(), &BulletTypes::Burst_Lasers));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Arclite_Shock_Cannon_Hit", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Arclite_Shock_Cannon_Hit));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Arclite_Shock_Cannon_Hit.getID(), &BulletTypes::Arclite_Shock_Cannon_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "EMP_Missile", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::EMP_Missile));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::EMP_Missile.getID(), &BulletTypes::EMP_Missile));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Dual_Photon_Blasters_Hit", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Dual_Photon_Blasters_Hit));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Dual_Photon_Blasters_Hit.getID(), &BulletTypes::Dual_Photon_Blasters_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Particle_Beam_Hit", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Particle_Beam_Hit));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Particle_Beam_Hit.getID(), &BulletTypes::Particle_Beam_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Anti_Matter_Missile", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Anti_Matter_Missile));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Anti_Matter_Missile.getID(), &BulletTypes::Anti_Matter_Missile));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Pulse_Cannon", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Pulse_Cannon));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Pulse_Cannon.getID(), &BulletTypes::Pulse_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psionic_Shockwave_Hit", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Psionic_Shockwave_Hit));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Psionic_Shockwave_Hit.getID(), &BulletTypes::Psionic_Shockwave_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psionic_Storm", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Psionic_Storm));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Psionic_Storm.getID(), &BulletTypes::Psionic_Storm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Yamato_Gun", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Yamato_Gun));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Yamato_Gun.getID(), &BulletTypes::Yamato_Gun));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Phase_Disruptor", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Phase_Disruptor));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Phase_Disruptor.getID(), &BulletTypes::Phase_Disruptor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "STA_STS_Cannon_Overlay", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::STA_STS_Cannon_Overlay));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::STA_STS_Cannon_Overlay.getID(), &BulletTypes::STA_STS_Cannon_Overlay));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Sunken_Colony_Tentacle", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Sunken_Colony_Tentacle));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Sunken_Colony_Tentacle.getID(), &BulletTypes::Sunken_Colony_Tentacle));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Acid_Spore", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Acid_Spore));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Acid_Spore.getID(), &BulletTypes::Acid_Spore));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Glave_Wurm", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Glave_Wurm));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Glave_Wurm.getID(), &BulletTypes::Glave_Wurm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Seeker_Spores", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Seeker_Spores));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Seeker_Spores.getID(), &BulletTypes::Seeker_Spores));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Queen_Spell_Carrier", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Queen_Spell_Carrier));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Queen_Spell_Carrier.getID(), &BulletTypes::Queen_Spell_Carrier));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Plague_Cloud", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Plague_Cloud));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Plague_Cloud.getID(), &BulletTypes::Plague_Cloud));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Consume", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Consume));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Consume.getID(), &BulletTypes::Consume));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ensnare", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Ensnare));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Ensnare.getID(), &BulletTypes::Ensnare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Needle_Spine_Hit", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Needle_Spine_Hit));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Needle_Spine_Hit.getID(), &BulletTypes::Needle_Spine_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Invisible", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Invisible));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Invisible.getID(), &BulletTypes::Invisible));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Optical_Flare_Grenade", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Optical_Flare_Grenade));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Optical_Flare_Grenade.getID(), &BulletTypes::Optical_Flare_Grenade));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Halo_Rockets", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Halo_Rockets));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Halo_Rockets.getID(), &BulletTypes::Halo_Rockets));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Subterranean_Spines", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Subterranean_Spines));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Subterranean_Spines.getID(), &BulletTypes::Subterranean_Spines));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Corrosive_Acid_Shot", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Corrosive_Acid_Shot));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Corrosive_Acid_Shot.getID(), &BulletTypes::Corrosive_Acid_Shot));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Neutron_Flare", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Neutron_Flare));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Neutron_Flare.getID(), &BulletTypes::Neutron_Flare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::None));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::None.getID(), &BulletTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/BulletType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&BulletTypes::Unknown));
tableBulletType.insert(std::pair<int, const BulletType*>(BulletTypes::Unknown.getID(), &BulletTypes::Unknown));
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
cls = env->FindClass("Lbwapi/DamageType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/DamageType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Independent", "Lbwapi/DamageType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&DamageTypes::Independent));
tableDamageType.insert(std::pair<int, const DamageType*>(DamageTypes::Independent.getID(), &DamageTypes::Independent));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Explosive", "Lbwapi/DamageType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&DamageTypes::Explosive));
tableDamageType.insert(std::pair<int, const DamageType*>(DamageTypes::Explosive.getID(), &DamageTypes::Explosive));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Concussive", "Lbwapi/DamageType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&DamageTypes::Concussive));
tableDamageType.insert(std::pair<int, const DamageType*>(DamageTypes::Concussive.getID(), &DamageTypes::Concussive));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Normal", "Lbwapi/DamageType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&DamageTypes::Normal));
tableDamageType.insert(std::pair<int, const DamageType*>(DamageTypes::Normal.getID(), &DamageTypes::Normal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ignore_Armor", "Lbwapi/DamageType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&DamageTypes::Ignore_Armor));
tableDamageType.insert(std::pair<int, const DamageType*>(DamageTypes::Ignore_Armor.getID(), &DamageTypes::Ignore_Armor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/DamageType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&DamageTypes::None));
tableDamageType.insert(std::pair<int, const DamageType*>(DamageTypes::None.getID(), &DamageTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/DamageType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&DamageTypes::Unknown));
tableDamageType.insert(std::pair<int, const DamageType*>(DamageTypes::Unknown.getID(), &DamageTypes::Unknown));
cls = env->FindClass("Lbwapi/Error;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/Error;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unit_Does_Not_Exist", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Unit_Does_Not_Exist));
tableError.insert(std::pair<int, const Error*>(Errors::Unit_Does_Not_Exist.getID(), &Errors::Unit_Does_Not_Exist));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unit_Not_Visible", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Unit_Not_Visible));
tableError.insert(std::pair<int, const Error*>(Errors::Unit_Not_Visible.getID(), &Errors::Unit_Not_Visible));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unit_Not_Owned", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Unit_Not_Owned));
tableError.insert(std::pair<int, const Error*>(Errors::Unit_Not_Owned.getID(), &Errors::Unit_Not_Owned));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unit_Busy", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Unit_Busy));
tableError.insert(std::pair<int, const Error*>(Errors::Unit_Busy.getID(), &Errors::Unit_Busy));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Incompatible_UnitType", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Incompatible_UnitType));
tableError.insert(std::pair<int, const Error*>(Errors::Incompatible_UnitType.getID(), &Errors::Incompatible_UnitType));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Incompatible_TechType", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Incompatible_TechType));
tableError.insert(std::pair<int, const Error*>(Errors::Incompatible_TechType.getID(), &Errors::Incompatible_TechType));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Incompatible_State", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Incompatible_State));
tableError.insert(std::pair<int, const Error*>(Errors::Incompatible_State.getID(), &Errors::Incompatible_State));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Already_Researched", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Already_Researched));
tableError.insert(std::pair<int, const Error*>(Errors::Already_Researched.getID(), &Errors::Already_Researched));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Fully_Upgraded", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Fully_Upgraded));
tableError.insert(std::pair<int, const Error*>(Errors::Fully_Upgraded.getID(), &Errors::Fully_Upgraded));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Currently_Researching", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Currently_Researching));
tableError.insert(std::pair<int, const Error*>(Errors::Currently_Researching.getID(), &Errors::Currently_Researching));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Currently_Upgrading", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Currently_Upgrading));
tableError.insert(std::pair<int, const Error*>(Errors::Currently_Upgrading.getID(), &Errors::Currently_Upgrading));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Insufficient_Minerals", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Insufficient_Minerals));
tableError.insert(std::pair<int, const Error*>(Errors::Insufficient_Minerals.getID(), &Errors::Insufficient_Minerals));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Insufficient_Gas", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Insufficient_Gas));
tableError.insert(std::pair<int, const Error*>(Errors::Insufficient_Gas.getID(), &Errors::Insufficient_Gas));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Insufficient_Supply", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Insufficient_Supply));
tableError.insert(std::pair<int, const Error*>(Errors::Insufficient_Supply.getID(), &Errors::Insufficient_Supply));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Insufficient_Energy", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Insufficient_Energy));
tableError.insert(std::pair<int, const Error*>(Errors::Insufficient_Energy.getID(), &Errors::Insufficient_Energy));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Insufficient_Tech", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Insufficient_Tech));
tableError.insert(std::pair<int, const Error*>(Errors::Insufficient_Tech.getID(), &Errors::Insufficient_Tech));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Insufficient_Ammo", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Insufficient_Ammo));
tableError.insert(std::pair<int, const Error*>(Errors::Insufficient_Ammo.getID(), &Errors::Insufficient_Ammo));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Insufficient_Space", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Insufficient_Space));
tableError.insert(std::pair<int, const Error*>(Errors::Insufficient_Space.getID(), &Errors::Insufficient_Space));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Invalid_Tile_Position", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Invalid_Tile_Position));
tableError.insert(std::pair<int, const Error*>(Errors::Invalid_Tile_Position.getID(), &Errors::Invalid_Tile_Position));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unbuildable_Location", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Unbuildable_Location));
tableError.insert(std::pair<int, const Error*>(Errors::Unbuildable_Location.getID(), &Errors::Unbuildable_Location));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unreachable_Location", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Unreachable_Location));
tableError.insert(std::pair<int, const Error*>(Errors::Unreachable_Location.getID(), &Errors::Unreachable_Location));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Out_Of_Range", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Out_Of_Range));
tableError.insert(std::pair<int, const Error*>(Errors::Out_Of_Range.getID(), &Errors::Out_Of_Range));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unable_To_Hit", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Unable_To_Hit));
tableError.insert(std::pair<int, const Error*>(Errors::Unable_To_Hit.getID(), &Errors::Unable_To_Hit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Access_Denied", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Access_Denied));
tableError.insert(std::pair<int, const Error*>(Errors::Access_Denied.getID(), &Errors::Access_Denied));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "File_Not_Found", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::File_Not_Found));
tableError.insert(std::pair<int, const Error*>(Errors::File_Not_Found.getID(), &Errors::File_Not_Found));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Invalid_Parameter", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Invalid_Parameter));
tableError.insert(std::pair<int, const Error*>(Errors::Invalid_Parameter.getID(), &Errors::Invalid_Parameter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::None));
tableError.insert(std::pair<int, const Error*>(Errors::None.getID(), &Errors::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/Error;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Errors::Unknown));
tableError.insert(std::pair<int, const Error*>(Errors::Unknown.getID(), &Errors::Unknown));
cls = env->FindClass("Lbwapi/ExplosionType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/ExplosionType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::None));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::None.getID(), &ExplosionTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Normal", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Normal));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Normal.getID(), &ExplosionTypes::Normal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Radial_Splash", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Radial_Splash));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Radial_Splash.getID(), &ExplosionTypes::Radial_Splash));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Enemy_Splash", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Enemy_Splash));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Enemy_Splash.getID(), &ExplosionTypes::Enemy_Splash));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Lockdown", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Lockdown));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Lockdown.getID(), &ExplosionTypes::Lockdown));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Nuclear_Missile", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Nuclear_Missile));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Nuclear_Missile.getID(), &ExplosionTypes::Nuclear_Missile));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Parasite", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Parasite));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Parasite.getID(), &ExplosionTypes::Parasite));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Broodlings", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Broodlings));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Broodlings.getID(), &ExplosionTypes::Broodlings));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "EMP_Shockwave", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::EMP_Shockwave));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::EMP_Shockwave.getID(), &ExplosionTypes::EMP_Shockwave));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Irradiate", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Irradiate));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Irradiate.getID(), &ExplosionTypes::Irradiate));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ensnare", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Ensnare));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Ensnare.getID(), &ExplosionTypes::Ensnare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Plague", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Plague));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Plague.getID(), &ExplosionTypes::Plague));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Stasis_Field", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Stasis_Field));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Stasis_Field.getID(), &ExplosionTypes::Stasis_Field));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Dark_Swarm", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Dark_Swarm));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Dark_Swarm.getID(), &ExplosionTypes::Dark_Swarm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Consume", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Consume));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Consume.getID(), &ExplosionTypes::Consume));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Yamato_Gun", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Yamato_Gun));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Yamato_Gun.getID(), &ExplosionTypes::Yamato_Gun));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Restoration", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Restoration));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Restoration.getID(), &ExplosionTypes::Restoration));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Disruption_Web", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Disruption_Web));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Disruption_Web.getID(), &ExplosionTypes::Disruption_Web));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Corrosive_Acid", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Corrosive_Acid));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Corrosive_Acid.getID(), &ExplosionTypes::Corrosive_Acid));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Mind_Control", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Mind_Control));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Mind_Control.getID(), &ExplosionTypes::Mind_Control));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Feedback", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Feedback));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Feedback.getID(), &ExplosionTypes::Feedback));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Optical_Flare", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Optical_Flare));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Optical_Flare.getID(), &ExplosionTypes::Optical_Flare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Maelstrom", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Maelstrom));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Maelstrom.getID(), &ExplosionTypes::Maelstrom));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Air_Splash", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Air_Splash));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Air_Splash.getID(), &ExplosionTypes::Air_Splash));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/ExplosionType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&ExplosionTypes::Unknown));
tableExplosionType.insert(std::pair<int, const ExplosionType*>(ExplosionTypes::Unknown.getID(), &ExplosionTypes::Unknown));
cls = env->FindClass("Lbwapi/GameType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/GameType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Melee", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Melee));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Melee.getID(), &GameTypes::Melee));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Free_For_All", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Free_For_All));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Free_For_All.getID(), &GameTypes::Free_For_All));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "One_on_One", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::One_on_One));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::One_on_One.getID(), &GameTypes::One_on_One));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Capture_The_Flag", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Capture_The_Flag));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Capture_The_Flag.getID(), &GameTypes::Capture_The_Flag));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Greed", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Greed));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Greed.getID(), &GameTypes::Greed));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Slaughter", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Slaughter));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Slaughter.getID(), &GameTypes::Slaughter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Sudden_Death", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Sudden_Death));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Sudden_Death.getID(), &GameTypes::Sudden_Death));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ladder", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Ladder));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Ladder.getID(), &GameTypes::Ladder));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Use_Map_Settings", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Use_Map_Settings));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Use_Map_Settings.getID(), &GameTypes::Use_Map_Settings));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Team_Melee", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Team_Melee));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Team_Melee.getID(), &GameTypes::Team_Melee));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Team_Free_For_All", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Team_Free_For_All));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Team_Free_For_All.getID(), &GameTypes::Team_Free_For_All));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Team_Capture_The_Flag", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Team_Capture_The_Flag));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Team_Capture_The_Flag.getID(), &GameTypes::Team_Capture_The_Flag));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Top_vs_Bottom", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Top_vs_Bottom));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Top_vs_Bottom.getID(), &GameTypes::Top_vs_Bottom));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Pro_Gamer_League", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Pro_Gamer_League));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Pro_Gamer_League.getID(), &GameTypes::Pro_Gamer_League));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::None));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::None.getID(), &GameTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/GameType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&GameTypes::Unknown));
tableGameType.insert(std::pair<int, const GameType*>(GameTypes::Unknown.getID(), &GameTypes::Unknown));
cls = env->FindClass("Lbwapi/Order;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/Order;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Die", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Die));
tableOrder.insert(std::pair<int, const Order*>(Orders::Die.getID(), &Orders::Die));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Stop", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Stop));
tableOrder.insert(std::pair<int, const Order*>(Orders::Stop.getID(), &Orders::Stop));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Guard", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Guard));
tableOrder.insert(std::pair<int, const Order*>(Orders::Guard.getID(), &Orders::Guard));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PlayerGuard", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::PlayerGuard));
tableOrder.insert(std::pair<int, const Order*>(Orders::PlayerGuard.getID(), &Orders::PlayerGuard));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "TurretGuard", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::TurretGuard));
tableOrder.insert(std::pair<int, const Order*>(Orders::TurretGuard.getID(), &Orders::TurretGuard));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "BunkerGuard", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::BunkerGuard));
tableOrder.insert(std::pair<int, const Order*>(Orders::BunkerGuard.getID(), &Orders::BunkerGuard));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Move", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Move));
tableOrder.insert(std::pair<int, const Order*>(Orders::Move.getID(), &Orders::Move));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "AttackUnit", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::AttackUnit));
tableOrder.insert(std::pair<int, const Order*>(Orders::AttackUnit.getID(), &Orders::AttackUnit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "AttackTile", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::AttackTile));
tableOrder.insert(std::pair<int, const Order*>(Orders::AttackTile.getID(), &Orders::AttackTile));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hover", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Hover));
tableOrder.insert(std::pair<int, const Order*>(Orders::Hover.getID(), &Orders::Hover));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "AttackMove", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::AttackMove));
tableOrder.insert(std::pair<int, const Order*>(Orders::AttackMove.getID(), &Orders::AttackMove));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "InfestedCommandCenter", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::InfestedCommandCenter));
tableOrder.insert(std::pair<int, const Order*>(Orders::InfestedCommandCenter.getID(), &Orders::InfestedCommandCenter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "UnusedNothing", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::UnusedNothing));
tableOrder.insert(std::pair<int, const Order*>(Orders::UnusedNothing.getID(), &Orders::UnusedNothing));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "UnusedPowerup", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::UnusedPowerup));
tableOrder.insert(std::pair<int, const Order*>(Orders::UnusedPowerup.getID(), &Orders::UnusedPowerup));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "TowerGuard", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::TowerGuard));
tableOrder.insert(std::pair<int, const Order*>(Orders::TowerGuard.getID(), &Orders::TowerGuard));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "VultureMine", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::VultureMine));
tableOrder.insert(std::pair<int, const Order*>(Orders::VultureMine.getID(), &Orders::VultureMine));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Nothing", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Nothing));
tableOrder.insert(std::pair<int, const Order*>(Orders::Nothing.getID(), &Orders::Nothing));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Nothing3", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Nothing3));
tableOrder.insert(std::pair<int, const Order*>(Orders::Nothing3.getID(), &Orders::Nothing3));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastInfestation", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastInfestation));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastInfestation.getID(), &Orders::CastInfestation));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "InfestingCommandCenter", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::InfestingCommandCenter));
tableOrder.insert(std::pair<int, const Order*>(Orders::InfestingCommandCenter.getID(), &Orders::InfestingCommandCenter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PlaceBuilding", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::PlaceBuilding));
tableOrder.insert(std::pair<int, const Order*>(Orders::PlaceBuilding.getID(), &Orders::PlaceBuilding));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "BuildProtoss2", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::BuildProtoss2));
tableOrder.insert(std::pair<int, const Order*>(Orders::BuildProtoss2.getID(), &Orders::BuildProtoss2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ConstructingBuilding", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ConstructingBuilding));
tableOrder.insert(std::pair<int, const Order*>(Orders::ConstructingBuilding.getID(), &Orders::ConstructingBuilding));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Repair", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Repair));
tableOrder.insert(std::pair<int, const Order*>(Orders::Repair.getID(), &Orders::Repair));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PlaceAddon", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::PlaceAddon));
tableOrder.insert(std::pair<int, const Order*>(Orders::PlaceAddon.getID(), &Orders::PlaceAddon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "BuildAddon", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::BuildAddon));
tableOrder.insert(std::pair<int, const Order*>(Orders::BuildAddon.getID(), &Orders::BuildAddon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Train", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Train));
tableOrder.insert(std::pair<int, const Order*>(Orders::Train.getID(), &Orders::Train));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "RallyPointUnit", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::RallyPointUnit));
tableOrder.insert(std::pair<int, const Order*>(Orders::RallyPointUnit.getID(), &Orders::RallyPointUnit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "RallyPointTile", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::RallyPointTile));
tableOrder.insert(std::pair<int, const Order*>(Orders::RallyPointTile.getID(), &Orders::RallyPointTile));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ZergBirth", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ZergBirth));
tableOrder.insert(std::pair<int, const Order*>(Orders::ZergBirth.getID(), &Orders::ZergBirth));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ZergUnitMorph", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ZergUnitMorph));
tableOrder.insert(std::pair<int, const Order*>(Orders::ZergUnitMorph.getID(), &Orders::ZergUnitMorph));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ZergBuildingMorph", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ZergBuildingMorph));
tableOrder.insert(std::pair<int, const Order*>(Orders::ZergBuildingMorph.getID(), &Orders::ZergBuildingMorph));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "IncompleteBuilding", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::IncompleteBuilding));
tableOrder.insert(std::pair<int, const Order*>(Orders::IncompleteBuilding.getID(), &Orders::IncompleteBuilding));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "BuildNydusExit", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::BuildNydusExit));
tableOrder.insert(std::pair<int, const Order*>(Orders::BuildNydusExit.getID(), &Orders::BuildNydusExit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "EnterNydusCanal", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::EnterNydusCanal));
tableOrder.insert(std::pair<int, const Order*>(Orders::EnterNydusCanal.getID(), &Orders::EnterNydusCanal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Follow", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Follow));
tableOrder.insert(std::pair<int, const Order*>(Orders::Follow.getID(), &Orders::Follow));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Carrier", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Carrier));
tableOrder.insert(std::pair<int, const Order*>(Orders::Carrier.getID(), &Orders::Carrier));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ReaverCarrierMove", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ReaverCarrierMove));
tableOrder.insert(std::pair<int, const Order*>(Orders::ReaverCarrierMove.getID(), &Orders::ReaverCarrierMove));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CarrierIgnore2", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CarrierIgnore2));
tableOrder.insert(std::pair<int, const Order*>(Orders::CarrierIgnore2.getID(), &Orders::CarrierIgnore2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Reaver", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Reaver));
tableOrder.insert(std::pair<int, const Order*>(Orders::Reaver.getID(), &Orders::Reaver));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "TrainFighter", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::TrainFighter));
tableOrder.insert(std::pair<int, const Order*>(Orders::TrainFighter.getID(), &Orders::TrainFighter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "InterceptorAttack", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::InterceptorAttack));
tableOrder.insert(std::pair<int, const Order*>(Orders::InterceptorAttack.getID(), &Orders::InterceptorAttack));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ScarabAttack", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ScarabAttack));
tableOrder.insert(std::pair<int, const Order*>(Orders::ScarabAttack.getID(), &Orders::ScarabAttack));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "RechargeShieldsUnit", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::RechargeShieldsUnit));
tableOrder.insert(std::pair<int, const Order*>(Orders::RechargeShieldsUnit.getID(), &Orders::RechargeShieldsUnit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "RechargeShieldsBattery", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::RechargeShieldsBattery));
tableOrder.insert(std::pair<int, const Order*>(Orders::RechargeShieldsBattery.getID(), &Orders::RechargeShieldsBattery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ShieldBattery", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ShieldBattery));
tableOrder.insert(std::pair<int, const Order*>(Orders::ShieldBattery.getID(), &Orders::ShieldBattery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "InterceptorReturn", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::InterceptorReturn));
tableOrder.insert(std::pair<int, const Order*>(Orders::InterceptorReturn.getID(), &Orders::InterceptorReturn));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "BuildingLand", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::BuildingLand));
tableOrder.insert(std::pair<int, const Order*>(Orders::BuildingLand.getID(), &Orders::BuildingLand));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "BuildingLiftOff", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::BuildingLiftOff));
tableOrder.insert(std::pair<int, const Order*>(Orders::BuildingLiftOff.getID(), &Orders::BuildingLiftOff));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "DroneLiftOff", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::DroneLiftOff));
tableOrder.insert(std::pair<int, const Order*>(Orders::DroneLiftOff.getID(), &Orders::DroneLiftOff));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "LiftingOff", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::LiftingOff));
tableOrder.insert(std::pair<int, const Order*>(Orders::LiftingOff.getID(), &Orders::LiftingOff));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ResearchTech", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ResearchTech));
tableOrder.insert(std::pair<int, const Order*>(Orders::ResearchTech.getID(), &Orders::ResearchTech));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Upgrade", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Upgrade));
tableOrder.insert(std::pair<int, const Order*>(Orders::Upgrade.getID(), &Orders::Upgrade));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Larva", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Larva));
tableOrder.insert(std::pair<int, const Order*>(Orders::Larva.getID(), &Orders::Larva));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "SpawningLarva", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::SpawningLarva));
tableOrder.insert(std::pair<int, const Order*>(Orders::SpawningLarva.getID(), &Orders::SpawningLarva));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Harvest1", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Harvest1));
tableOrder.insert(std::pair<int, const Order*>(Orders::Harvest1.getID(), &Orders::Harvest1));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Harvest2", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Harvest2));
tableOrder.insert(std::pair<int, const Order*>(Orders::Harvest2.getID(), &Orders::Harvest2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "MoveToGas", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::MoveToGas));
tableOrder.insert(std::pair<int, const Order*>(Orders::MoveToGas.getID(), &Orders::MoveToGas));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "WaitForGas", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::WaitForGas));
tableOrder.insert(std::pair<int, const Order*>(Orders::WaitForGas.getID(), &Orders::WaitForGas));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "HarvestGas", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::HarvestGas));
tableOrder.insert(std::pair<int, const Order*>(Orders::HarvestGas.getID(), &Orders::HarvestGas));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ReturnGas", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ReturnGas));
tableOrder.insert(std::pair<int, const Order*>(Orders::ReturnGas.getID(), &Orders::ReturnGas));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "MoveToMinerals", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::MoveToMinerals));
tableOrder.insert(std::pair<int, const Order*>(Orders::MoveToMinerals.getID(), &Orders::MoveToMinerals));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "WaitForMinerals", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::WaitForMinerals));
tableOrder.insert(std::pair<int, const Order*>(Orders::WaitForMinerals.getID(), &Orders::WaitForMinerals));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "MiningMinerals", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::MiningMinerals));
tableOrder.insert(std::pair<int, const Order*>(Orders::MiningMinerals.getID(), &Orders::MiningMinerals));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Harvest3", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Harvest3));
tableOrder.insert(std::pair<int, const Order*>(Orders::Harvest3.getID(), &Orders::Harvest3));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Harvest4", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Harvest4));
tableOrder.insert(std::pair<int, const Order*>(Orders::Harvest4.getID(), &Orders::Harvest4));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ReturnMinerals", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ReturnMinerals));
tableOrder.insert(std::pair<int, const Order*>(Orders::ReturnMinerals.getID(), &Orders::ReturnMinerals));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Interrupted", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Interrupted));
tableOrder.insert(std::pair<int, const Order*>(Orders::Interrupted.getID(), &Orders::Interrupted));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "EnterTransport", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::EnterTransport));
tableOrder.insert(std::pair<int, const Order*>(Orders::EnterTransport.getID(), &Orders::EnterTransport));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PickupIdle", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::PickupIdle));
tableOrder.insert(std::pair<int, const Order*>(Orders::PickupIdle.getID(), &Orders::PickupIdle));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PickupTransport", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::PickupTransport));
tableOrder.insert(std::pair<int, const Order*>(Orders::PickupTransport.getID(), &Orders::PickupTransport));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PickupBunker", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::PickupBunker));
tableOrder.insert(std::pair<int, const Order*>(Orders::PickupBunker.getID(), &Orders::PickupBunker));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Pickup4", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Pickup4));
tableOrder.insert(std::pair<int, const Order*>(Orders::Pickup4.getID(), &Orders::Pickup4));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PowerupIdle", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::PowerupIdle));
tableOrder.insert(std::pair<int, const Order*>(Orders::PowerupIdle.getID(), &Orders::PowerupIdle));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Sieging", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Sieging));
tableOrder.insert(std::pair<int, const Order*>(Orders::Sieging.getID(), &Orders::Sieging));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unsieging", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Unsieging));
tableOrder.insert(std::pair<int, const Order*>(Orders::Unsieging.getID(), &Orders::Unsieging));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "InitCreepGrowth", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::InitCreepGrowth));
tableOrder.insert(std::pair<int, const Order*>(Orders::InitCreepGrowth.getID(), &Orders::InitCreepGrowth));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "SpreadCreep", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::SpreadCreep));
tableOrder.insert(std::pair<int, const Order*>(Orders::SpreadCreep.getID(), &Orders::SpreadCreep));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "StoppingCreepGrowth", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::StoppingCreepGrowth));
tableOrder.insert(std::pair<int, const Order*>(Orders::StoppingCreepGrowth.getID(), &Orders::StoppingCreepGrowth));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "GuardianAspect", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::GuardianAspect));
tableOrder.insert(std::pair<int, const Order*>(Orders::GuardianAspect.getID(), &Orders::GuardianAspect));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ArchonWarp", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ArchonWarp));
tableOrder.insert(std::pair<int, const Order*>(Orders::ArchonWarp.getID(), &Orders::ArchonWarp));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CompletingArchonsummon", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CompletingArchonsummon));
tableOrder.insert(std::pair<int, const Order*>(Orders::CompletingArchonsummon.getID(), &Orders::CompletingArchonsummon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "HoldPosition", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::HoldPosition));
tableOrder.insert(std::pair<int, const Order*>(Orders::HoldPosition.getID(), &Orders::HoldPosition));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cloak", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Cloak));
tableOrder.insert(std::pair<int, const Order*>(Orders::Cloak.getID(), &Orders::Cloak));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Decloak", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Decloak));
tableOrder.insert(std::pair<int, const Order*>(Orders::Decloak.getID(), &Orders::Decloak));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unload", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Unload));
tableOrder.insert(std::pair<int, const Order*>(Orders::Unload.getID(), &Orders::Unload));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "MoveUnload", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::MoveUnload));
tableOrder.insert(std::pair<int, const Order*>(Orders::MoveUnload.getID(), &Orders::MoveUnload));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "FireYamatoGun", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::FireYamatoGun));
tableOrder.insert(std::pair<int, const Order*>(Orders::FireYamatoGun.getID(), &Orders::FireYamatoGun));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastLockdown", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastLockdown));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastLockdown.getID(), &Orders::CastLockdown));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Burrowing", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Burrowing));
tableOrder.insert(std::pair<int, const Order*>(Orders::Burrowing.getID(), &Orders::Burrowing));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Burrowed", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Burrowed));
tableOrder.insert(std::pair<int, const Order*>(Orders::Burrowed.getID(), &Orders::Burrowed));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unburrowing", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Unburrowing));
tableOrder.insert(std::pair<int, const Order*>(Orders::Unburrowing.getID(), &Orders::Unburrowing));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastDarkSwarm", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastDarkSwarm));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastDarkSwarm.getID(), &Orders::CastDarkSwarm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastParasite", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastParasite));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastParasite.getID(), &Orders::CastParasite));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastSpawnBroodlings", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastSpawnBroodlings));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastSpawnBroodlings.getID(), &Orders::CastSpawnBroodlings));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastEMPShockwave", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastEMPShockwave));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastEMPShockwave.getID(), &Orders::CastEMPShockwave));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "NukeWait", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::NukeWait));
tableOrder.insert(std::pair<int, const Order*>(Orders::NukeWait.getID(), &Orders::NukeWait));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "NukeTrain", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::NukeTrain));
tableOrder.insert(std::pair<int, const Order*>(Orders::NukeTrain.getID(), &Orders::NukeTrain));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "NukeLaunch", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::NukeLaunch));
tableOrder.insert(std::pair<int, const Order*>(Orders::NukeLaunch.getID(), &Orders::NukeLaunch));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "NukePaint", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::NukePaint));
tableOrder.insert(std::pair<int, const Order*>(Orders::NukePaint.getID(), &Orders::NukePaint));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "NukeUnit", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::NukeUnit));
tableOrder.insert(std::pair<int, const Order*>(Orders::NukeUnit.getID(), &Orders::NukeUnit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastNuclearStrike", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastNuclearStrike));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastNuclearStrike.getID(), &Orders::CastNuclearStrike));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "NukeTrack", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::NukeTrack));
tableOrder.insert(std::pair<int, const Order*>(Orders::NukeTrack.getID(), &Orders::NukeTrack));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CloakNearbyUnits", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CloakNearbyUnits));
tableOrder.insert(std::pair<int, const Order*>(Orders::CloakNearbyUnits.getID(), &Orders::CloakNearbyUnits));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PlaceMine", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::PlaceMine));
tableOrder.insert(std::pair<int, const Order*>(Orders::PlaceMine.getID(), &Orders::PlaceMine));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "RightClickAction", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::RightClickAction));
tableOrder.insert(std::pair<int, const Order*>(Orders::RightClickAction.getID(), &Orders::RightClickAction));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastRecall", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastRecall));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastRecall.getID(), &Orders::CastRecall));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "TeleporttoLocation", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::TeleporttoLocation));
tableOrder.insert(std::pair<int, const Order*>(Orders::TeleporttoLocation.getID(), &Orders::TeleporttoLocation));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastScannerSweep", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastScannerSweep));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastScannerSweep.getID(), &Orders::CastScannerSweep));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Scanner", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Scanner));
tableOrder.insert(std::pair<int, const Order*>(Orders::Scanner.getID(), &Orders::Scanner));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastDefensiveMatrix", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastDefensiveMatrix));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastDefensiveMatrix.getID(), &Orders::CastDefensiveMatrix));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastPsionicStorm", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastPsionicStorm));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastPsionicStorm.getID(), &Orders::CastPsionicStorm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastIrradiate", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastIrradiate));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastIrradiate.getID(), &Orders::CastIrradiate));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastPlague", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastPlague));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastPlague.getID(), &Orders::CastPlague));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastConsume", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastConsume));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastConsume.getID(), &Orders::CastConsume));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastEnsnare", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastEnsnare));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastEnsnare.getID(), &Orders::CastEnsnare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastStasisField", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastStasisField));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastStasisField.getID(), &Orders::CastStasisField));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastHallucination", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastHallucination));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastHallucination.getID(), &Orders::CastHallucination));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hallucination2", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Hallucination2));
tableOrder.insert(std::pair<int, const Order*>(Orders::Hallucination2.getID(), &Orders::Hallucination2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ResetCollision", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ResetCollision));
tableOrder.insert(std::pair<int, const Order*>(Orders::ResetCollision.getID(), &Orders::ResetCollision));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Patrol", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Patrol));
tableOrder.insert(std::pair<int, const Order*>(Orders::Patrol.getID(), &Orders::Patrol));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CTFCOPInit", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CTFCOPInit));
tableOrder.insert(std::pair<int, const Order*>(Orders::CTFCOPInit.getID(), &Orders::CTFCOPInit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CTFCOPStarted", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CTFCOPStarted));
tableOrder.insert(std::pair<int, const Order*>(Orders::CTFCOPStarted.getID(), &Orders::CTFCOPStarted));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CTFCOP2", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CTFCOP2));
tableOrder.insert(std::pair<int, const Order*>(Orders::CTFCOP2.getID(), &Orders::CTFCOP2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ComputerAI", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ComputerAI));
tableOrder.insert(std::pair<int, const Order*>(Orders::ComputerAI.getID(), &Orders::ComputerAI));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "AtkMoveEP", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::AtkMoveEP));
tableOrder.insert(std::pair<int, const Order*>(Orders::AtkMoveEP.getID(), &Orders::AtkMoveEP));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "HarassMove", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::HarassMove));
tableOrder.insert(std::pair<int, const Order*>(Orders::HarassMove.getID(), &Orders::HarassMove));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "AIPatrol", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::AIPatrol));
tableOrder.insert(std::pair<int, const Order*>(Orders::AIPatrol.getID(), &Orders::AIPatrol));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "GuardPost", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::GuardPost));
tableOrder.insert(std::pair<int, const Order*>(Orders::GuardPost.getID(), &Orders::GuardPost));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "RescuePassive", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::RescuePassive));
tableOrder.insert(std::pair<int, const Order*>(Orders::RescuePassive.getID(), &Orders::RescuePassive));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Neutral", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Neutral));
tableOrder.insert(std::pair<int, const Order*>(Orders::Neutral.getID(), &Orders::Neutral));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ComputerReturn", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::ComputerReturn));
tableOrder.insert(std::pair<int, const Order*>(Orders::ComputerReturn.getID(), &Orders::ComputerReturn));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "SelfDestrucing", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::SelfDestrucing));
tableOrder.insert(std::pair<int, const Order*>(Orders::SelfDestrucing.getID(), &Orders::SelfDestrucing));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Critter", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Critter));
tableOrder.insert(std::pair<int, const Order*>(Orders::Critter.getID(), &Orders::Critter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "HiddenGun", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::HiddenGun));
tableOrder.insert(std::pair<int, const Order*>(Orders::HiddenGun.getID(), &Orders::HiddenGun));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "OpenDoor", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::OpenDoor));
tableOrder.insert(std::pair<int, const Order*>(Orders::OpenDoor.getID(), &Orders::OpenDoor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CloseDoor", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CloseDoor));
tableOrder.insert(std::pair<int, const Order*>(Orders::CloseDoor.getID(), &Orders::CloseDoor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "HideTrap", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::HideTrap));
tableOrder.insert(std::pair<int, const Order*>(Orders::HideTrap.getID(), &Orders::HideTrap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "RevealTrap", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::RevealTrap));
tableOrder.insert(std::pair<int, const Order*>(Orders::RevealTrap.getID(), &Orders::RevealTrap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Enabledoodad", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Enabledoodad));
tableOrder.insert(std::pair<int, const Order*>(Orders::Enabledoodad.getID(), &Orders::Enabledoodad));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Disabledoodad", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Disabledoodad));
tableOrder.insert(std::pair<int, const Order*>(Orders::Disabledoodad.getID(), &Orders::Disabledoodad));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Warpin", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Warpin));
tableOrder.insert(std::pair<int, const Order*>(Orders::Warpin.getID(), &Orders::Warpin));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Medic", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Medic));
tableOrder.insert(std::pair<int, const Order*>(Orders::Medic.getID(), &Orders::Medic));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "MedicHeal1", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::MedicHeal1));
tableOrder.insert(std::pair<int, const Order*>(Orders::MedicHeal1.getID(), &Orders::MedicHeal1));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "HealMove", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::HealMove));
tableOrder.insert(std::pair<int, const Order*>(Orders::HealMove.getID(), &Orders::HealMove));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "MedicHeal2", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::MedicHeal2));
tableOrder.insert(std::pair<int, const Order*>(Orders::MedicHeal2.getID(), &Orders::MedicHeal2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastRestoration", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastRestoration));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastRestoration.getID(), &Orders::CastRestoration));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastDisruptionWeb", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastDisruptionWeb));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastDisruptionWeb.getID(), &Orders::CastDisruptionWeb));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastMindControl", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastMindControl));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastMindControl.getID(), &Orders::CastMindControl));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "DarkArchonMeld", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::DarkArchonMeld));
tableOrder.insert(std::pair<int, const Order*>(Orders::DarkArchonMeld.getID(), &Orders::DarkArchonMeld));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastFeedback", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastFeedback));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastFeedback.getID(), &Orders::CastFeedback));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastOpticalFlare", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastOpticalFlare));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastOpticalFlare.getID(), &Orders::CastOpticalFlare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "CastMaelstrom", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::CastMaelstrom));
tableOrder.insert(std::pair<int, const Order*>(Orders::CastMaelstrom.getID(), &Orders::CastMaelstrom));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "JunkYardDog", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::JunkYardDog));
tableOrder.insert(std::pair<int, const Order*>(Orders::JunkYardDog.getID(), &Orders::JunkYardDog));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Fatal", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Fatal));
tableOrder.insert(std::pair<int, const Order*>(Orders::Fatal.getID(), &Orders::Fatal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::None));
tableOrder.insert(std::pair<int, const Order*>(Orders::None.getID(), &Orders::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/Order;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Orders::Unknown));
tableOrder.insert(std::pair<int, const Order*>(Orders::Unknown.getID(), &Orders::Unknown));
cls = env->FindClass("Lbwapi/PlayerType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/PlayerType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::None));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::None.getID(), &PlayerTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Computer", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::Computer));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::Computer.getID(), &PlayerTypes::Computer));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Player", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::Player));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::Player.getID(), &PlayerTypes::Player));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "RescuePassive", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::RescuePassive));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::RescuePassive.getID(), &PlayerTypes::RescuePassive));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "EitherPreferComputer", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::EitherPreferComputer));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::EitherPreferComputer.getID(), &PlayerTypes::EitherPreferComputer));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "EitherPreferHuman", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::EitherPreferHuman));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::EitherPreferHuman.getID(), &PlayerTypes::EitherPreferHuman));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Neutral", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::Neutral));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::Neutral.getID(), &PlayerTypes::Neutral));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Closed", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::Closed));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::Closed.getID(), &PlayerTypes::Closed));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "PlayerLeft", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::PlayerLeft));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::PlayerLeft.getID(), &PlayerTypes::PlayerLeft));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ComputerLeft", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::ComputerLeft));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::ComputerLeft.getID(), &PlayerTypes::ComputerLeft));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/PlayerType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&PlayerTypes::Unknown));
tablePlayerType.insert(std::pair<int, const PlayerType*>(PlayerTypes::Unknown.getID(), &PlayerTypes::Unknown));
cls = env->FindClass("Lbwapi/Position;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/Position;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Invalid", "Lbwapi/Position;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Positions::Invalid));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/Position;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Positions::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/Position;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Positions::Unknown));
cls = env->FindClass("Lbwapi/Race;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/Race;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg", "Lbwapi/Race;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Races::Zerg));
tableRace.insert(std::pair<int, const Race*>(Races::Zerg.getID(), &Races::Zerg));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran", "Lbwapi/Race;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Races::Terran));
tableRace.insert(std::pair<int, const Race*>(Races::Terran.getID(), &Races::Terran));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss", "Lbwapi/Race;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Races::Protoss));
tableRace.insert(std::pair<int, const Race*>(Races::Protoss.getID(), &Races::Protoss));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Random", "Lbwapi/Race;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Races::Random));
tableRace.insert(std::pair<int, const Race*>(Races::Random.getID(), &Races::Random));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Other", "Lbwapi/Race;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Races::Other));
tableRace.insert(std::pair<int, const Race*>(Races::Other.getID(), &Races::Other));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/Race;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Races::None));
tableRace.insert(std::pair<int, const Race*>(Races::None.getID(), &Races::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/Race;"), env->CallStaticObjectMethod(cls, getId, (jlong)&Races::Unknown));
tableRace.insert(std::pair<int, const Race*>(Races::Unknown.getID(), &Races::Unknown));
cls = env->FindClass("Lbwapi/TechType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/TechType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Stim_Packs", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Stim_Packs));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Stim_Packs.getID(), &TechTypes::Stim_Packs));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Lockdown", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Lockdown));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Lockdown.getID(), &TechTypes::Lockdown));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "EMP_Shockwave", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::EMP_Shockwave));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::EMP_Shockwave.getID(), &TechTypes::EMP_Shockwave));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Spider_Mines", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Spider_Mines));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Spider_Mines.getID(), &TechTypes::Spider_Mines));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Scanner_Sweep", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Scanner_Sweep));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Scanner_Sweep.getID(), &TechTypes::Scanner_Sweep));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Tank_Siege_Mode", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Tank_Siege_Mode));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Tank_Siege_Mode.getID(), &TechTypes::Tank_Siege_Mode));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Defensive_Matrix", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Defensive_Matrix));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Defensive_Matrix.getID(), &TechTypes::Defensive_Matrix));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Irradiate", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Irradiate));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Irradiate.getID(), &TechTypes::Irradiate));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Yamato_Gun", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Yamato_Gun));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Yamato_Gun.getID(), &TechTypes::Yamato_Gun));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cloaking_Field", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Cloaking_Field));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Cloaking_Field.getID(), &TechTypes::Cloaking_Field));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Personnel_Cloaking", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Personnel_Cloaking));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Personnel_Cloaking.getID(), &TechTypes::Personnel_Cloaking));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Burrowing", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Burrowing));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Burrowing.getID(), &TechTypes::Burrowing));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Infestation", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Infestation));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Infestation.getID(), &TechTypes::Infestation));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Spawn_Broodlings", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Spawn_Broodlings));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Spawn_Broodlings.getID(), &TechTypes::Spawn_Broodlings));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Dark_Swarm", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Dark_Swarm));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Dark_Swarm.getID(), &TechTypes::Dark_Swarm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Plague", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Plague));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Plague.getID(), &TechTypes::Plague));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Consume", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Consume));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Consume.getID(), &TechTypes::Consume));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ensnare", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Ensnare));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Ensnare.getID(), &TechTypes::Ensnare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Parasite", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Parasite));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Parasite.getID(), &TechTypes::Parasite));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psionic_Storm", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Psionic_Storm));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Psionic_Storm.getID(), &TechTypes::Psionic_Storm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hallucination", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Hallucination));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Hallucination.getID(), &TechTypes::Hallucination));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Recall", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Recall));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Recall.getID(), &TechTypes::Recall));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Stasis_Field", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Stasis_Field));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Stasis_Field.getID(), &TechTypes::Stasis_Field));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Archon_Warp", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Archon_Warp));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Archon_Warp.getID(), &TechTypes::Archon_Warp));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Restoration", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Restoration));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Restoration.getID(), &TechTypes::Restoration));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Disruption_Web", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Disruption_Web));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Disruption_Web.getID(), &TechTypes::Disruption_Web));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Mind_Control", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Mind_Control));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Mind_Control.getID(), &TechTypes::Mind_Control));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Dark_Archon_Meld", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Dark_Archon_Meld));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Dark_Archon_Meld.getID(), &TechTypes::Dark_Archon_Meld));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Feedback", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Feedback));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Feedback.getID(), &TechTypes::Feedback));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Optical_Flare", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Optical_Flare));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Optical_Flare.getID(), &TechTypes::Optical_Flare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Maelstrom", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Maelstrom));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Maelstrom.getID(), &TechTypes::Maelstrom));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Lurker_Aspect", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Lurker_Aspect));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Lurker_Aspect.getID(), &TechTypes::Lurker_Aspect));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Healing", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Healing));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Healing.getID(), &TechTypes::Healing));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::None));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::None.getID(), &TechTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Unknown));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Unknown.getID(), &TechTypes::Unknown));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Nuclear_Strike", "Lbwapi/TechType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TechTypes::Nuclear_Strike));
tableTechType.insert(std::pair<int, const TechType*>(TechTypes::Nuclear_Strike.getID(), &TechTypes::Nuclear_Strike));
cls = env->FindClass("Lbwapi/TilePosition;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/TilePosition;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Invalid", "Lbwapi/TilePosition;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TilePositions::Invalid));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/TilePosition;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TilePositions::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/TilePosition;"), env->CallStaticObjectMethod(cls, getId, (jlong)&TilePositions::Unknown));
cls = env->FindClass("Lbwapi/UnitCommandType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/UnitCommandType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Attack_Move", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Attack_Move));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Attack_Move.getID(), &UnitCommandTypes::Attack_Move));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Attack_Unit", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Attack_Unit));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Attack_Unit.getID(), &UnitCommandTypes::Attack_Unit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Build", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Build));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Build.getID(), &UnitCommandTypes::Build));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Build_Addon", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Build_Addon));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Build_Addon.getID(), &UnitCommandTypes::Build_Addon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Train", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Train));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Train.getID(), &UnitCommandTypes::Train));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Morph", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Morph));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Morph.getID(), &UnitCommandTypes::Morph));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Research", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Research));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Research.getID(), &UnitCommandTypes::Research));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Upgrade", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Upgrade));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Upgrade.getID(), &UnitCommandTypes::Upgrade));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Set_Rally_Position", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Set_Rally_Position));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Set_Rally_Position.getID(), &UnitCommandTypes::Set_Rally_Position));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Set_Rally_Unit", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Set_Rally_Unit));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Set_Rally_Unit.getID(), &UnitCommandTypes::Set_Rally_Unit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Move", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Move));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Move.getID(), &UnitCommandTypes::Move));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Patrol", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Patrol));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Patrol.getID(), &UnitCommandTypes::Patrol));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hold_Position", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Hold_Position));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Hold_Position.getID(), &UnitCommandTypes::Hold_Position));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Stop", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Stop));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Stop.getID(), &UnitCommandTypes::Stop));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Follow", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Follow));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Follow.getID(), &UnitCommandTypes::Follow));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gather", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Gather));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Gather.getID(), &UnitCommandTypes::Gather));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Return_Cargo", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Return_Cargo));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Return_Cargo.getID(), &UnitCommandTypes::Return_Cargo));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Repair", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Repair));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Repair.getID(), &UnitCommandTypes::Repair));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Burrow", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Burrow));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Burrow.getID(), &UnitCommandTypes::Burrow));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unburrow", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Unburrow));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Unburrow.getID(), &UnitCommandTypes::Unburrow));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cloak", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Cloak));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Cloak.getID(), &UnitCommandTypes::Cloak));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Decloak", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Decloak));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Decloak.getID(), &UnitCommandTypes::Decloak));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Siege", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Siege));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Siege.getID(), &UnitCommandTypes::Siege));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unsiege", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Unsiege));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Unsiege.getID(), &UnitCommandTypes::Unsiege));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Lift", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Lift));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Lift.getID(), &UnitCommandTypes::Lift));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Land", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Land));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Land.getID(), &UnitCommandTypes::Land));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Load", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Load));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Load.getID(), &UnitCommandTypes::Load));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unload", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Unload));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Unload.getID(), &UnitCommandTypes::Unload));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unload_All", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Unload_All));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Unload_All.getID(), &UnitCommandTypes::Unload_All));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unload_All_Position", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Unload_All_Position));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Unload_All_Position.getID(), &UnitCommandTypes::Unload_All_Position));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Right_Click_Position", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Right_Click_Position));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Right_Click_Position.getID(), &UnitCommandTypes::Right_Click_Position));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Right_Click_Unit", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Right_Click_Unit));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Right_Click_Unit.getID(), &UnitCommandTypes::Right_Click_Unit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Halt_Construction", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Halt_Construction));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Halt_Construction.getID(), &UnitCommandTypes::Halt_Construction));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cancel_Construction", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Cancel_Construction));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Cancel_Construction.getID(), &UnitCommandTypes::Cancel_Construction));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cancel_Addon", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Cancel_Addon));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Cancel_Addon.getID(), &UnitCommandTypes::Cancel_Addon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cancel_Train", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Cancel_Train));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Cancel_Train.getID(), &UnitCommandTypes::Cancel_Train));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cancel_Train_Slot", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Cancel_Train_Slot));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Cancel_Train_Slot.getID(), &UnitCommandTypes::Cancel_Train_Slot));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cancel_Morph", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Cancel_Morph));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Cancel_Morph.getID(), &UnitCommandTypes::Cancel_Morph));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cancel_Research", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Cancel_Research));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Cancel_Research.getID(), &UnitCommandTypes::Cancel_Research));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Cancel_Upgrade", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Cancel_Upgrade));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Cancel_Upgrade.getID(), &UnitCommandTypes::Cancel_Upgrade));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Use_Tech", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Use_Tech));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Use_Tech.getID(), &UnitCommandTypes::Use_Tech));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Use_Tech_Position", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Use_Tech_Position));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Use_Tech_Position.getID(), &UnitCommandTypes::Use_Tech_Position));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Use_Tech_Unit", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Use_Tech_Unit));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Use_Tech_Unit.getID(), &UnitCommandTypes::Use_Tech_Unit));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Place_COP", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Place_COP));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Place_COP.getID(), &UnitCommandTypes::Place_COP));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::None));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::None.getID(), &UnitCommandTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/UnitCommandType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitCommandTypes::Unknown));
tableUnitCommandType.insert(std::pair<int, const UnitCommandType*>(UnitCommandTypes::Unknown.getID(), &UnitCommandTypes::Unknown));
cls = env->FindClass("Lbwapi/UnitSizeType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/UnitSizeType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Independent", "Lbwapi/UnitSizeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitSizeTypes::Independent));
tableUnitSizeType.insert(std::pair<int, const UnitSizeType*>(UnitSizeTypes::Independent.getID(), &UnitSizeTypes::Independent));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Small", "Lbwapi/UnitSizeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitSizeTypes::Small));
tableUnitSizeType.insert(std::pair<int, const UnitSizeType*>(UnitSizeTypes::Small.getID(), &UnitSizeTypes::Small));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Medium", "Lbwapi/UnitSizeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitSizeTypes::Medium));
tableUnitSizeType.insert(std::pair<int, const UnitSizeType*>(UnitSizeTypes::Medium.getID(), &UnitSizeTypes::Medium));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Large", "Lbwapi/UnitSizeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitSizeTypes::Large));
tableUnitSizeType.insert(std::pair<int, const UnitSizeType*>(UnitSizeTypes::Large.getID(), &UnitSizeTypes::Large));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/UnitSizeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitSizeTypes::None));
tableUnitSizeType.insert(std::pair<int, const UnitSizeType*>(UnitSizeTypes::None.getID(), &UnitSizeTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/UnitSizeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitSizeTypes::Unknown));
tableUnitSizeType.insert(std::pair<int, const UnitSizeType*>(UnitSizeTypes::Unknown.getID(), &UnitSizeTypes::Unknown));
cls = env->FindClass("Lbwapi/UnitType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/UnitType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Marine", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Marine));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Marine.getID(), &UnitTypes::Terran_Marine));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Jim_Raynor_Marine", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Jim_Raynor_Marine));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Jim_Raynor_Marine.getID(), &UnitTypes::Hero_Jim_Raynor_Marine));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Ghost", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Ghost));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Ghost.getID(), &UnitTypes::Terran_Ghost));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Sarah_Kerrigan", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Sarah_Kerrigan));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Sarah_Kerrigan.getID(), &UnitTypes::Hero_Sarah_Kerrigan));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Samir_Duran", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Samir_Duran));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Samir_Duran.getID(), &UnitTypes::Hero_Samir_Duran));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Infested_Duran", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Infested_Duran));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Infested_Duran.getID(), &UnitTypes::Hero_Infested_Duran));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Alexei_Stukov", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Alexei_Stukov));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Alexei_Stukov.getID(), &UnitTypes::Hero_Alexei_Stukov));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Vulture", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Vulture));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Vulture.getID(), &UnitTypes::Terran_Vulture));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Jim_Raynor_Vulture", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Jim_Raynor_Vulture));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Jim_Raynor_Vulture.getID(), &UnitTypes::Hero_Jim_Raynor_Vulture));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Goliath", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Goliath));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Goliath.getID(), &UnitTypes::Terran_Goliath));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Alan_Schezar", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Alan_Schezar));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Alan_Schezar.getID(), &UnitTypes::Hero_Alan_Schezar));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Siege_Tank_Tank_Mode", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Siege_Tank_Tank_Mode));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Siege_Tank_Tank_Mode.getID(), &UnitTypes::Terran_Siege_Tank_Tank_Mode));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Edmund_Duke_Tank_Mode", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Edmund_Duke_Tank_Mode));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Edmund_Duke_Tank_Mode.getID(), &UnitTypes::Hero_Edmund_Duke_Tank_Mode));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_SCV", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_SCV));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_SCV.getID(), &UnitTypes::Terran_SCV));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Wraith", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Wraith));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Wraith.getID(), &UnitTypes::Terran_Wraith));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Tom_Kazansky", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Tom_Kazansky));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Tom_Kazansky.getID(), &UnitTypes::Hero_Tom_Kazansky));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Science_Vessel", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Science_Vessel));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Science_Vessel.getID(), &UnitTypes::Terran_Science_Vessel));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Magellan", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Magellan));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Magellan.getID(), &UnitTypes::Hero_Magellan));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Dropship", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Dropship));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Dropship.getID(), &UnitTypes::Terran_Dropship));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Battlecruiser", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Battlecruiser));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Battlecruiser.getID(), &UnitTypes::Terran_Battlecruiser));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Arcturus_Mengsk", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Arcturus_Mengsk));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Arcturus_Mengsk.getID(), &UnitTypes::Hero_Arcturus_Mengsk));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Hyperion", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Hyperion));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Hyperion.getID(), &UnitTypes::Hero_Hyperion));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Norad_II", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Norad_II));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Norad_II.getID(), &UnitTypes::Hero_Norad_II));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Gerard_DuGalle", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Gerard_DuGalle));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Gerard_DuGalle.getID(), &UnitTypes::Hero_Gerard_DuGalle));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Vulture_Spider_Mine", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Vulture_Spider_Mine));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Vulture_Spider_Mine.getID(), &UnitTypes::Terran_Vulture_Spider_Mine));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Nuclear_Missile", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Nuclear_Missile));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Nuclear_Missile.getID(), &UnitTypes::Terran_Nuclear_Missile));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Siege_Tank_Siege_Mode", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Siege_Tank_Siege_Mode));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Siege_Tank_Siege_Mode.getID(), &UnitTypes::Terran_Siege_Tank_Siege_Mode));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Edmund_Duke_Siege_Mode", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Edmund_Duke_Siege_Mode));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Edmund_Duke_Siege_Mode.getID(), &UnitTypes::Hero_Edmund_Duke_Siege_Mode));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Firebat", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Firebat));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Firebat.getID(), &UnitTypes::Terran_Firebat));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Gui_Montag", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Gui_Montag));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Gui_Montag.getID(), &UnitTypes::Hero_Gui_Montag));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Spell_Scanner_Sweep", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Spell_Scanner_Sweep));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Spell_Scanner_Sweep.getID(), &UnitTypes::Spell_Scanner_Sweep));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Medic", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Medic));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Medic.getID(), &UnitTypes::Terran_Medic));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Civilian", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Civilian));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Civilian.getID(), &UnitTypes::Terran_Civilian));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Larva", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Larva));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Larva.getID(), &UnitTypes::Zerg_Larva));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Egg", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Egg));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Egg.getID(), &UnitTypes::Zerg_Egg));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Zergling", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Zergling));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Zergling.getID(), &UnitTypes::Zerg_Zergling));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Devouring_One", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Devouring_One));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Devouring_One.getID(), &UnitTypes::Hero_Devouring_One));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Infested_Kerrigan", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Infested_Kerrigan));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Infested_Kerrigan.getID(), &UnitTypes::Hero_Infested_Kerrigan));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Hydralisk", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Hydralisk));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Hydralisk.getID(), &UnitTypes::Zerg_Hydralisk));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Hunter_Killer", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Hunter_Killer));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Hunter_Killer.getID(), &UnitTypes::Hero_Hunter_Killer));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Ultralisk", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Ultralisk));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Ultralisk.getID(), &UnitTypes::Zerg_Ultralisk));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Torrasque", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Torrasque));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Torrasque.getID(), &UnitTypes::Hero_Torrasque));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Broodling", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Broodling));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Broodling.getID(), &UnitTypes::Zerg_Broodling));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Drone", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Drone));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Drone.getID(), &UnitTypes::Zerg_Drone));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Overlord", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Overlord));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Overlord.getID(), &UnitTypes::Zerg_Overlord));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Yggdrasill", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Yggdrasill));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Yggdrasill.getID(), &UnitTypes::Hero_Yggdrasill));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Mutalisk", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Mutalisk));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Mutalisk.getID(), &UnitTypes::Zerg_Mutalisk));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Kukulza_Mutalisk", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Kukulza_Mutalisk));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Kukulza_Mutalisk.getID(), &UnitTypes::Hero_Kukulza_Mutalisk));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Guardian", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Guardian));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Guardian.getID(), &UnitTypes::Zerg_Guardian));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Kukulza_Guardian", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Kukulza_Guardian));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Kukulza_Guardian.getID(), &UnitTypes::Hero_Kukulza_Guardian));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Queen", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Queen));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Queen.getID(), &UnitTypes::Zerg_Queen));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Matriarch", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Matriarch));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Matriarch.getID(), &UnitTypes::Hero_Matriarch));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Defiler", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Defiler));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Defiler.getID(), &UnitTypes::Zerg_Defiler));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Unclean_One", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Unclean_One));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Unclean_One.getID(), &UnitTypes::Hero_Unclean_One));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Scourge", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Scourge));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Scourge.getID(), &UnitTypes::Zerg_Scourge));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Infested_Terran", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Infested_Terran));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Infested_Terran.getID(), &UnitTypes::Zerg_Infested_Terran));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Valkyrie", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Valkyrie));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Valkyrie.getID(), &UnitTypes::Terran_Valkyrie));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Cocoon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Cocoon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Cocoon.getID(), &UnitTypes::Zerg_Cocoon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Corsair", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Corsair));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Corsair.getID(), &UnitTypes::Protoss_Corsair));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Raszagal", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Raszagal));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Raszagal.getID(), &UnitTypes::Hero_Raszagal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Dark_Templar", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Dark_Templar));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Dark_Templar.getID(), &UnitTypes::Protoss_Dark_Templar));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Dark_Templar", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Dark_Templar));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Dark_Templar.getID(), &UnitTypes::Hero_Dark_Templar));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Zeratul", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Zeratul));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Zeratul.getID(), &UnitTypes::Hero_Zeratul));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Devourer", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Devourer));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Devourer.getID(), &UnitTypes::Zerg_Devourer));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Dark_Archon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Dark_Archon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Dark_Archon.getID(), &UnitTypes::Protoss_Dark_Archon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Probe", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Probe));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Probe.getID(), &UnitTypes::Protoss_Probe));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Zealot", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Zealot));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Zealot.getID(), &UnitTypes::Protoss_Zealot));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Fenix_Zealot", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Fenix_Zealot));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Fenix_Zealot.getID(), &UnitTypes::Hero_Fenix_Zealot));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Dragoon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Dragoon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Dragoon.getID(), &UnitTypes::Protoss_Dragoon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Fenix_Dragoon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Fenix_Dragoon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Fenix_Dragoon.getID(), &UnitTypes::Hero_Fenix_Dragoon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_High_Templar", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_High_Templar));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_High_Templar.getID(), &UnitTypes::Protoss_High_Templar));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Tassadar", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Tassadar));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Tassadar.getID(), &UnitTypes::Hero_Tassadar));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Aldaris", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Aldaris));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Aldaris.getID(), &UnitTypes::Hero_Aldaris));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Archon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Archon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Archon.getID(), &UnitTypes::Protoss_Archon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Tassadar_Zeratul_Archon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Tassadar_Zeratul_Archon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Tassadar_Zeratul_Archon.getID(), &UnitTypes::Hero_Tassadar_Zeratul_Archon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Shuttle", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Shuttle));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Shuttle.getID(), &UnitTypes::Protoss_Shuttle));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Scout", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Scout));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Scout.getID(), &UnitTypes::Protoss_Scout));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Mojo", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Mojo));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Mojo.getID(), &UnitTypes::Hero_Mojo));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Artanis", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Artanis));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Artanis.getID(), &UnitTypes::Hero_Artanis));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Arbiter", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Arbiter));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Arbiter.getID(), &UnitTypes::Protoss_Arbiter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Danimoth", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Danimoth));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Danimoth.getID(), &UnitTypes::Hero_Danimoth));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Carrier", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Carrier));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Carrier.getID(), &UnitTypes::Protoss_Carrier));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Gantrithor", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Gantrithor));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Gantrithor.getID(), &UnitTypes::Hero_Gantrithor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Interceptor", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Interceptor));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Interceptor.getID(), &UnitTypes::Protoss_Interceptor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Reaver", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Reaver));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Reaver.getID(), &UnitTypes::Protoss_Reaver));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hero_Warbringer", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Hero_Warbringer));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Hero_Warbringer.getID(), &UnitTypes::Hero_Warbringer));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Observer", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Observer));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Observer.getID(), &UnitTypes::Protoss_Observer));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Scarab", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Scarab));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Scarab.getID(), &UnitTypes::Protoss_Scarab));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Critter_Rhynadon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Critter_Rhynadon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Critter_Rhynadon.getID(), &UnitTypes::Critter_Rhynadon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Critter_Bengalaas", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Critter_Bengalaas));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Critter_Bengalaas.getID(), &UnitTypes::Critter_Bengalaas));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Cargo_Ship", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Cargo_Ship));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Cargo_Ship.getID(), &UnitTypes::Special_Cargo_Ship));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Mercenary_Gunship", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Mercenary_Gunship));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Mercenary_Gunship.getID(), &UnitTypes::Special_Mercenary_Gunship));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Critter_Scantid", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Critter_Scantid));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Critter_Scantid.getID(), &UnitTypes::Critter_Scantid));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Critter_Kakaru", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Critter_Kakaru));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Critter_Kakaru.getID(), &UnitTypes::Critter_Kakaru));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Critter_Ragnasaur", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Critter_Ragnasaur));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Critter_Ragnasaur.getID(), &UnitTypes::Critter_Ragnasaur));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Critter_Ursadon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Critter_Ursadon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Critter_Ursadon.getID(), &UnitTypes::Critter_Ursadon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Lurker_Egg", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Lurker_Egg));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Lurker_Egg.getID(), &UnitTypes::Zerg_Lurker_Egg));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Lurker", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Lurker));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Lurker.getID(), &UnitTypes::Zerg_Lurker));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Spell_Disruption_Web", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Spell_Disruption_Web));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Spell_Disruption_Web.getID(), &UnitTypes::Spell_Disruption_Web));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Command_Center", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Command_Center));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Command_Center.getID(), &UnitTypes::Terran_Command_Center));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Comsat_Station", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Comsat_Station));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Comsat_Station.getID(), &UnitTypes::Terran_Comsat_Station));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Nuclear_Silo", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Nuclear_Silo));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Nuclear_Silo.getID(), &UnitTypes::Terran_Nuclear_Silo));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Supply_Depot", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Supply_Depot));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Supply_Depot.getID(), &UnitTypes::Terran_Supply_Depot));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Refinery", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Refinery));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Refinery.getID(), &UnitTypes::Terran_Refinery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Barracks", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Barracks));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Barracks.getID(), &UnitTypes::Terran_Barracks));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Academy", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Academy));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Academy.getID(), &UnitTypes::Terran_Academy));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Factory", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Factory));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Factory.getID(), &UnitTypes::Terran_Factory));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Starport", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Starport));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Starport.getID(), &UnitTypes::Terran_Starport));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Control_Tower", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Control_Tower));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Control_Tower.getID(), &UnitTypes::Terran_Control_Tower));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Science_Facility", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Science_Facility));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Science_Facility.getID(), &UnitTypes::Terran_Science_Facility));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Covert_Ops", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Covert_Ops));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Covert_Ops.getID(), &UnitTypes::Terran_Covert_Ops));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Physics_Lab", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Physics_Lab));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Physics_Lab.getID(), &UnitTypes::Terran_Physics_Lab));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Machine_Shop", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Machine_Shop));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Machine_Shop.getID(), &UnitTypes::Terran_Machine_Shop));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Engineering_Bay", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Engineering_Bay));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Engineering_Bay.getID(), &UnitTypes::Terran_Engineering_Bay));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Armory", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Armory));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Armory.getID(), &UnitTypes::Terran_Armory));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Missile_Turret", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Missile_Turret));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Missile_Turret.getID(), &UnitTypes::Terran_Missile_Turret));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Bunker", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Terran_Bunker));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Terran_Bunker.getID(), &UnitTypes::Terran_Bunker));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Crashed_Norad_II", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Crashed_Norad_II));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Crashed_Norad_II.getID(), &UnitTypes::Special_Crashed_Norad_II));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Ion_Cannon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Ion_Cannon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Ion_Cannon.getID(), &UnitTypes::Special_Ion_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Infested_Command_Center", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Infested_Command_Center));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Infested_Command_Center.getID(), &UnitTypes::Zerg_Infested_Command_Center));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Hatchery", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Hatchery));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Hatchery.getID(), &UnitTypes::Zerg_Hatchery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Lair", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Lair));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Lair.getID(), &UnitTypes::Zerg_Lair));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Hive", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Hive));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Hive.getID(), &UnitTypes::Zerg_Hive));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Nydus_Canal", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Nydus_Canal));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Nydus_Canal.getID(), &UnitTypes::Zerg_Nydus_Canal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Hydralisk_Den", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Hydralisk_Den));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Hydralisk_Den.getID(), &UnitTypes::Zerg_Hydralisk_Den));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Defiler_Mound", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Defiler_Mound));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Defiler_Mound.getID(), &UnitTypes::Zerg_Defiler_Mound));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Greater_Spire", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Greater_Spire));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Greater_Spire.getID(), &UnitTypes::Zerg_Greater_Spire));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Queens_Nest", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Queens_Nest));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Queens_Nest.getID(), &UnitTypes::Zerg_Queens_Nest));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Evolution_Chamber", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Evolution_Chamber));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Evolution_Chamber.getID(), &UnitTypes::Zerg_Evolution_Chamber));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Ultralisk_Cavern", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Ultralisk_Cavern));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Ultralisk_Cavern.getID(), &UnitTypes::Zerg_Ultralisk_Cavern));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Spire", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Spire));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Spire.getID(), &UnitTypes::Zerg_Spire));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Spawning_Pool", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Spawning_Pool));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Spawning_Pool.getID(), &UnitTypes::Zerg_Spawning_Pool));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Creep_Colony", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Creep_Colony));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Creep_Colony.getID(), &UnitTypes::Zerg_Creep_Colony));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Spore_Colony", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Spore_Colony));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Spore_Colony.getID(), &UnitTypes::Zerg_Spore_Colony));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Sunken_Colony", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Sunken_Colony));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Sunken_Colony.getID(), &UnitTypes::Zerg_Sunken_Colony));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Overmind_With_Shell", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Overmind_With_Shell));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Overmind_With_Shell.getID(), &UnitTypes::Special_Overmind_With_Shell));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Overmind", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Overmind));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Overmind.getID(), &UnitTypes::Special_Overmind));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Extractor", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Zerg_Extractor));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Zerg_Extractor.getID(), &UnitTypes::Zerg_Extractor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Mature_Chrysalis", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Mature_Chrysalis));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Mature_Chrysalis.getID(), &UnitTypes::Special_Mature_Chrysalis));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Cerebrate", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Cerebrate));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Cerebrate.getID(), &UnitTypes::Special_Cerebrate));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Cerebrate_Daggoth", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Cerebrate_Daggoth));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Cerebrate_Daggoth.getID(), &UnitTypes::Special_Cerebrate_Daggoth));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Nexus", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Nexus));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Nexus.getID(), &UnitTypes::Protoss_Nexus));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Robotics_Facility", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Robotics_Facility));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Robotics_Facility.getID(), &UnitTypes::Protoss_Robotics_Facility));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Pylon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Pylon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Pylon.getID(), &UnitTypes::Protoss_Pylon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Assimilator", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Assimilator));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Assimilator.getID(), &UnitTypes::Protoss_Assimilator));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Observatory", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Observatory));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Observatory.getID(), &UnitTypes::Protoss_Observatory));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Gateway", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Gateway));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Gateway.getID(), &UnitTypes::Protoss_Gateway));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Photon_Cannon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Photon_Cannon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Photon_Cannon.getID(), &UnitTypes::Protoss_Photon_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Citadel_of_Adun", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Citadel_of_Adun));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Citadel_of_Adun.getID(), &UnitTypes::Protoss_Citadel_of_Adun));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Cybernetics_Core", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Cybernetics_Core));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Cybernetics_Core.getID(), &UnitTypes::Protoss_Cybernetics_Core));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Templar_Archives", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Templar_Archives));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Templar_Archives.getID(), &UnitTypes::Protoss_Templar_Archives));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Forge", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Forge));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Forge.getID(), &UnitTypes::Protoss_Forge));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Stargate", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Stargate));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Stargate.getID(), &UnitTypes::Protoss_Stargate));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Stasis_Cell_Prison", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Stasis_Cell_Prison));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Stasis_Cell_Prison.getID(), &UnitTypes::Special_Stasis_Cell_Prison));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Fleet_Beacon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Fleet_Beacon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Fleet_Beacon.getID(), &UnitTypes::Protoss_Fleet_Beacon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Arbiter_Tribunal", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Arbiter_Tribunal));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Arbiter_Tribunal.getID(), &UnitTypes::Protoss_Arbiter_Tribunal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Robotics_Support_Bay", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Robotics_Support_Bay));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Robotics_Support_Bay.getID(), &UnitTypes::Protoss_Robotics_Support_Bay));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Shield_Battery", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Protoss_Shield_Battery));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Protoss_Shield_Battery.getID(), &UnitTypes::Protoss_Shield_Battery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Khaydarin_Crystal_Form", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Khaydarin_Crystal_Form));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Khaydarin_Crystal_Form.getID(), &UnitTypes::Special_Khaydarin_Crystal_Form));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Protoss_Temple", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Protoss_Temple));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Protoss_Temple.getID(), &UnitTypes::Special_Protoss_Temple));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_XelNaga_Temple", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_XelNaga_Temple));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_XelNaga_Temple.getID(), &UnitTypes::Special_XelNaga_Temple));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Resource_Mineral_Field", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Resource_Mineral_Field));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Resource_Mineral_Field.getID(), &UnitTypes::Resource_Mineral_Field));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Resource_Mineral_Field_Type_2", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Resource_Mineral_Field_Type_2));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Resource_Mineral_Field_Type_2.getID(), &UnitTypes::Resource_Mineral_Field_Type_2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Resource_Mineral_Field_Type_3", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Resource_Mineral_Field_Type_3));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Resource_Mineral_Field_Type_3.getID(), &UnitTypes::Resource_Mineral_Field_Type_3));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Independant_Starport", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Independant_Starport));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Independant_Starport.getID(), &UnitTypes::Special_Independant_Starport));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Resource_Vespene_Geyser", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Resource_Vespene_Geyser));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Resource_Vespene_Geyser.getID(), &UnitTypes::Resource_Vespene_Geyser));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Warp_Gate", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Warp_Gate));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Warp_Gate.getID(), &UnitTypes::Special_Warp_Gate));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Psi_Disrupter", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Psi_Disrupter));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Psi_Disrupter.getID(), &UnitTypes::Special_Psi_Disrupter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Power_Generator", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Power_Generator));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Power_Generator.getID(), &UnitTypes::Special_Power_Generator));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Overmind_Cocoon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Overmind_Cocoon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Overmind_Cocoon.getID(), &UnitTypes::Special_Overmind_Cocoon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Zerg_Beacon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Zerg_Beacon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Zerg_Beacon.getID(), &UnitTypes::Special_Zerg_Beacon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Terran_Beacon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Terran_Beacon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Terran_Beacon.getID(), &UnitTypes::Special_Terran_Beacon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Protoss_Beacon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Protoss_Beacon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Protoss_Beacon.getID(), &UnitTypes::Special_Protoss_Beacon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Zerg_Flag_Beacon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Zerg_Flag_Beacon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Zerg_Flag_Beacon.getID(), &UnitTypes::Special_Zerg_Flag_Beacon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Terran_Flag_Beacon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Terran_Flag_Beacon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Terran_Flag_Beacon.getID(), &UnitTypes::Special_Terran_Flag_Beacon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Protoss_Flag_Beacon", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Protoss_Flag_Beacon));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Protoss_Flag_Beacon.getID(), &UnitTypes::Special_Protoss_Flag_Beacon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Spell_Dark_Swarm", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Spell_Dark_Swarm));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Spell_Dark_Swarm.getID(), &UnitTypes::Spell_Dark_Swarm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Uraj_Crystal", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Uraj_Crystal));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Uraj_Crystal.getID(), &UnitTypes::Powerup_Uraj_Crystal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Khalis_Crystal", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Khalis_Crystal));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Khalis_Crystal.getID(), &UnitTypes::Powerup_Khalis_Crystal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Flag", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Flag));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Flag.getID(), &UnitTypes::Powerup_Flag));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Young_Chrysalis", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Young_Chrysalis));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Young_Chrysalis.getID(), &UnitTypes::Powerup_Young_Chrysalis));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Psi_Emitter", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Psi_Emitter));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Psi_Emitter.getID(), &UnitTypes::Powerup_Psi_Emitter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Data_Disk", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Data_Disk));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Data_Disk.getID(), &UnitTypes::Powerup_Data_Disk));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Khaydarin_Crystal", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Khaydarin_Crystal));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Khaydarin_Crystal.getID(), &UnitTypes::Powerup_Khaydarin_Crystal));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Mineral_Cluster_Type_1", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Mineral_Cluster_Type_1));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Mineral_Cluster_Type_1.getID(), &UnitTypes::Powerup_Mineral_Cluster_Type_1));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Mineral_Cluster_Type_2", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Mineral_Cluster_Type_2));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Mineral_Cluster_Type_2.getID(), &UnitTypes::Powerup_Mineral_Cluster_Type_2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Protoss_Gas_Orb_Type_1", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Protoss_Gas_Orb_Type_1));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Protoss_Gas_Orb_Type_1.getID(), &UnitTypes::Powerup_Protoss_Gas_Orb_Type_1));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Protoss_Gas_Orb_Type_2", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Protoss_Gas_Orb_Type_2));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Protoss_Gas_Orb_Type_2.getID(), &UnitTypes::Powerup_Protoss_Gas_Orb_Type_2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Zerg_Gas_Sac_Type_1", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Zerg_Gas_Sac_Type_1));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Zerg_Gas_Sac_Type_1.getID(), &UnitTypes::Powerup_Zerg_Gas_Sac_Type_1));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Zerg_Gas_Sac_Type_2", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Zerg_Gas_Sac_Type_2));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Zerg_Gas_Sac_Type_2.getID(), &UnitTypes::Powerup_Zerg_Gas_Sac_Type_2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Terran_Gas_Tank_Type_1", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Terran_Gas_Tank_Type_1));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Terran_Gas_Tank_Type_1.getID(), &UnitTypes::Powerup_Terran_Gas_Tank_Type_1));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Powerup_Terran_Gas_Tank_Type_2", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Powerup_Terran_Gas_Tank_Type_2));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Powerup_Terran_Gas_Tank_Type_2.getID(), &UnitTypes::Powerup_Terran_Gas_Tank_Type_2));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Map_Revealer", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Map_Revealer));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Map_Revealer.getID(), &UnitTypes::Special_Map_Revealer));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Floor_Missile_Trap", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Floor_Missile_Trap));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Floor_Missile_Trap.getID(), &UnitTypes::Special_Floor_Missile_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Floor_Hatch", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Floor_Hatch));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Floor_Hatch.getID(), &UnitTypes::Special_Floor_Hatch));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Upper_Level_Door", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Upper_Level_Door));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Upper_Level_Door.getID(), &UnitTypes::Special_Upper_Level_Door));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Right_Upper_Level_Door", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Right_Upper_Level_Door));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Right_Upper_Level_Door.getID(), &UnitTypes::Special_Right_Upper_Level_Door));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Pit_Door", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Pit_Door));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Pit_Door.getID(), &UnitTypes::Special_Pit_Door));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Right_Pit_Door", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Right_Pit_Door));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Right_Pit_Door.getID(), &UnitTypes::Special_Right_Pit_Door));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Floor_Gun_Trap", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Floor_Gun_Trap));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Floor_Gun_Trap.getID(), &UnitTypes::Special_Floor_Gun_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Wall_Missile_Trap", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Wall_Missile_Trap));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Wall_Missile_Trap.getID(), &UnitTypes::Special_Wall_Missile_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Wall_Flame_Trap", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Wall_Flame_Trap));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Wall_Flame_Trap.getID(), &UnitTypes::Special_Wall_Flame_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Right_Wall_Missile_Trap", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Right_Wall_Missile_Trap));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Right_Wall_Missile_Trap.getID(), &UnitTypes::Special_Right_Wall_Missile_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Right_Wall_Flame_Trap", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Right_Wall_Flame_Trap));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Right_Wall_Flame_Trap.getID(), &UnitTypes::Special_Right_Wall_Flame_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Special_Start_Location", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Special_Start_Location));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Special_Start_Location.getID(), &UnitTypes::Special_Start_Location));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::None));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::None.getID(), &UnitTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "AllUnits", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::AllUnits));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::AllUnits.getID(), &UnitTypes::AllUnits));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Men", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Men));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Men.getID(), &UnitTypes::Men));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Buildings", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Buildings));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Buildings.getID(), &UnitTypes::Buildings));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Factories", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Factories));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Factories.getID(), &UnitTypes::Factories));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/UnitType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UnitTypes::Unknown));
tableUnitType.insert(std::pair<int, const UnitType*>(UnitTypes::Unknown.getID(), &UnitTypes::Unknown));
cls = env->FindClass("Lbwapi/UpgradeType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/UpgradeType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Infantry_Armor", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Terran_Infantry_Armor));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Terran_Infantry_Armor.getID(), &UpgradeTypes::Terran_Infantry_Armor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Vehicle_Plating", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Terran_Vehicle_Plating));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Terran_Vehicle_Plating.getID(), &UpgradeTypes::Terran_Vehicle_Plating));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Ship_Plating", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Terran_Ship_Plating));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Terran_Ship_Plating.getID(), &UpgradeTypes::Terran_Ship_Plating));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Carapace", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Zerg_Carapace));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Zerg_Carapace.getID(), &UpgradeTypes::Zerg_Carapace));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Flyer_Carapace", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Zerg_Flyer_Carapace));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Zerg_Flyer_Carapace.getID(), &UpgradeTypes::Zerg_Flyer_Carapace));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Ground_Armor", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Protoss_Ground_Armor));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Protoss_Ground_Armor.getID(), &UpgradeTypes::Protoss_Ground_Armor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Air_Armor", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Protoss_Air_Armor));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Protoss_Air_Armor.getID(), &UpgradeTypes::Protoss_Air_Armor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Infantry_Weapons", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Terran_Infantry_Weapons));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Terran_Infantry_Weapons.getID(), &UpgradeTypes::Terran_Infantry_Weapons));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Vehicle_Weapons", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Terran_Vehicle_Weapons));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Terran_Vehicle_Weapons.getID(), &UpgradeTypes::Terran_Vehicle_Weapons));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Terran_Ship_Weapons", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Terran_Ship_Weapons));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Terran_Ship_Weapons.getID(), &UpgradeTypes::Terran_Ship_Weapons));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Melee_Attacks", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Zerg_Melee_Attacks));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Zerg_Melee_Attacks.getID(), &UpgradeTypes::Zerg_Melee_Attacks));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Missile_Attacks", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Zerg_Missile_Attacks));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Zerg_Missile_Attacks.getID(), &UpgradeTypes::Zerg_Missile_Attacks));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Zerg_Flyer_Attacks", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Zerg_Flyer_Attacks));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Zerg_Flyer_Attacks.getID(), &UpgradeTypes::Zerg_Flyer_Attacks));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Ground_Weapons", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Protoss_Ground_Weapons));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Protoss_Ground_Weapons.getID(), &UpgradeTypes::Protoss_Ground_Weapons));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Air_Weapons", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Protoss_Air_Weapons));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Protoss_Air_Weapons.getID(), &UpgradeTypes::Protoss_Air_Weapons));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Protoss_Plasma_Shields", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Protoss_Plasma_Shields));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Protoss_Plasma_Shields.getID(), &UpgradeTypes::Protoss_Plasma_Shields));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "U_238_Shells", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::U_238_Shells));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::U_238_Shells.getID(), &UpgradeTypes::U_238_Shells));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ion_Thrusters", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Ion_Thrusters));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Ion_Thrusters.getID(), &UpgradeTypes::Ion_Thrusters));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Titan_Reactor", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Titan_Reactor));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Titan_Reactor.getID(), &UpgradeTypes::Titan_Reactor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ocular_Implants", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Ocular_Implants));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Ocular_Implants.getID(), &UpgradeTypes::Ocular_Implants));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Moebius_Reactor", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Moebius_Reactor));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Moebius_Reactor.getID(), &UpgradeTypes::Moebius_Reactor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Apollo_Reactor", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Apollo_Reactor));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Apollo_Reactor.getID(), &UpgradeTypes::Apollo_Reactor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Colossus_Reactor", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Colossus_Reactor));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Colossus_Reactor.getID(), &UpgradeTypes::Colossus_Reactor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ventral_Sacs", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Ventral_Sacs));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Ventral_Sacs.getID(), &UpgradeTypes::Ventral_Sacs));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Antennae", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Antennae));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Antennae.getID(), &UpgradeTypes::Antennae));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Pneumatized_Carapace", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Pneumatized_Carapace));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Pneumatized_Carapace.getID(), &UpgradeTypes::Pneumatized_Carapace));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Metabolic_Boost", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Metabolic_Boost));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Metabolic_Boost.getID(), &UpgradeTypes::Metabolic_Boost));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Adrenal_Glands", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Adrenal_Glands));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Adrenal_Glands.getID(), &UpgradeTypes::Adrenal_Glands));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Muscular_Augments", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Muscular_Augments));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Muscular_Augments.getID(), &UpgradeTypes::Muscular_Augments));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Grooved_Spines", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Grooved_Spines));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Grooved_Spines.getID(), &UpgradeTypes::Grooved_Spines));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gamete_Meiosis", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Gamete_Meiosis));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Gamete_Meiosis.getID(), &UpgradeTypes::Gamete_Meiosis));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Metasynaptic_Node", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Metasynaptic_Node));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Metasynaptic_Node.getID(), &UpgradeTypes::Metasynaptic_Node));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Singularity_Charge", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Singularity_Charge));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Singularity_Charge.getID(), &UpgradeTypes::Singularity_Charge));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Leg_Enhancements", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Leg_Enhancements));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Leg_Enhancements.getID(), &UpgradeTypes::Leg_Enhancements));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Scarab_Damage", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Scarab_Damage));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Scarab_Damage.getID(), &UpgradeTypes::Scarab_Damage));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Reaver_Capacity", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Reaver_Capacity));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Reaver_Capacity.getID(), &UpgradeTypes::Reaver_Capacity));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gravitic_Drive", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Gravitic_Drive));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Gravitic_Drive.getID(), &UpgradeTypes::Gravitic_Drive));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Sensor_Array", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Sensor_Array));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Sensor_Array.getID(), &UpgradeTypes::Sensor_Array));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gravitic_Boosters", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Gravitic_Boosters));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Gravitic_Boosters.getID(), &UpgradeTypes::Gravitic_Boosters));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Khaydarin_Amulet", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Khaydarin_Amulet));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Khaydarin_Amulet.getID(), &UpgradeTypes::Khaydarin_Amulet));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Apial_Sensors", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Apial_Sensors));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Apial_Sensors.getID(), &UpgradeTypes::Apial_Sensors));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gravitic_Thrusters", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Gravitic_Thrusters));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Gravitic_Thrusters.getID(), &UpgradeTypes::Gravitic_Thrusters));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Carrier_Capacity", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Carrier_Capacity));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Carrier_Capacity.getID(), &UpgradeTypes::Carrier_Capacity));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Khaydarin_Core", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Khaydarin_Core));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Khaydarin_Core.getID(), &UpgradeTypes::Khaydarin_Core));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Argus_Jewel", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Argus_Jewel));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Argus_Jewel.getID(), &UpgradeTypes::Argus_Jewel));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Argus_Talisman", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Argus_Talisman));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Argus_Talisman.getID(), &UpgradeTypes::Argus_Talisman));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Caduceus_Reactor", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Caduceus_Reactor));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Caduceus_Reactor.getID(), &UpgradeTypes::Caduceus_Reactor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Chitinous_Plating", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Chitinous_Plating));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Chitinous_Plating.getID(), &UpgradeTypes::Chitinous_Plating));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Anabolic_Synthesis", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Anabolic_Synthesis));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Anabolic_Synthesis.getID(), &UpgradeTypes::Anabolic_Synthesis));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Charon_Boosters", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Charon_Boosters));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Charon_Boosters.getID(), &UpgradeTypes::Charon_Boosters));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::None));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::None.getID(), &UpgradeTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/UpgradeType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&UpgradeTypes::Unknown));
tableUpgradeType.insert(std::pair<int, const UpgradeType*>(UpgradeTypes::Unknown.getID(), &UpgradeTypes::Unknown));
cls = env->FindClass("Lbwapi/WeaponType;");
getId = env->GetStaticMethodID(cls, "get", "(J)Lbwapi/WeaponType;");
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gauss_Rifle", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Gauss_Rifle));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Gauss_Rifle.getID(), &WeaponTypes::Gauss_Rifle));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gauss_Rifle_Jim_Raynor", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Gauss_Rifle_Jim_Raynor));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Gauss_Rifle_Jim_Raynor.getID(), &WeaponTypes::Gauss_Rifle_Jim_Raynor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "C_10_Canister_Rifle", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::C_10_Canister_Rifle));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::C_10_Canister_Rifle.getID(), &WeaponTypes::C_10_Canister_Rifle));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "C_10_Canister_Rifle_Sarah_Kerrigan", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::C_10_Canister_Rifle_Sarah_Kerrigan));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::C_10_Canister_Rifle_Sarah_Kerrigan.getID(), &WeaponTypes::C_10_Canister_Rifle_Sarah_Kerrigan));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "C_10_Canister_Rifle_Samir_Duran", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::C_10_Canister_Rifle_Samir_Duran));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::C_10_Canister_Rifle_Samir_Duran.getID(), &WeaponTypes::C_10_Canister_Rifle_Samir_Duran));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "C_10_Canister_Rifle_Infested_Duran", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::C_10_Canister_Rifle_Infested_Duran));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::C_10_Canister_Rifle_Infested_Duran.getID(), &WeaponTypes::C_10_Canister_Rifle_Infested_Duran));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "C_10_Canister_Rifle_Alexei_Stukov", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::C_10_Canister_Rifle_Alexei_Stukov));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::C_10_Canister_Rifle_Alexei_Stukov.getID(), &WeaponTypes::C_10_Canister_Rifle_Alexei_Stukov));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Fragmentation_Grenade", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Fragmentation_Grenade));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Fragmentation_Grenade.getID(), &WeaponTypes::Fragmentation_Grenade));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Fragmentation_Grenade_Jim_Raynor", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Fragmentation_Grenade_Jim_Raynor));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Fragmentation_Grenade_Jim_Raynor.getID(), &WeaponTypes::Fragmentation_Grenade_Jim_Raynor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Spider_Mines", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Spider_Mines));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Spider_Mines.getID(), &WeaponTypes::Spider_Mines));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Twin_Autocannons", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Twin_Autocannons));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Twin_Autocannons.getID(), &WeaponTypes::Twin_Autocannons));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Twin_Autocannons_Alan_Schezar", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Twin_Autocannons_Alan_Schezar));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Twin_Autocannons_Alan_Schezar.getID(), &WeaponTypes::Twin_Autocannons_Alan_Schezar));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hellfire_Missile_Pack", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Hellfire_Missile_Pack));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Hellfire_Missile_Pack.getID(), &WeaponTypes::Hellfire_Missile_Pack));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hellfire_Missile_Pack_Alan_Schezar", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Hellfire_Missile_Pack_Alan_Schezar));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Hellfire_Missile_Pack_Alan_Schezar.getID(), &WeaponTypes::Hellfire_Missile_Pack_Alan_Schezar));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Arclite_Cannon", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Arclite_Cannon));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Arclite_Cannon.getID(), &WeaponTypes::Arclite_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Arclite_Cannon_Edmund_Duke", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Arclite_Cannon_Edmund_Duke));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Arclite_Cannon_Edmund_Duke.getID(), &WeaponTypes::Arclite_Cannon_Edmund_Duke));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Fusion_Cutter", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Fusion_Cutter));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Fusion_Cutter.getID(), &WeaponTypes::Fusion_Cutter));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gemini_Missiles", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Gemini_Missiles));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Gemini_Missiles.getID(), &WeaponTypes::Gemini_Missiles));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Gemini_Missiles_Tom_Kazansky", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Gemini_Missiles_Tom_Kazansky));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Gemini_Missiles_Tom_Kazansky.getID(), &WeaponTypes::Gemini_Missiles_Tom_Kazansky));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Burst_Lasers", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Burst_Lasers));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Burst_Lasers.getID(), &WeaponTypes::Burst_Lasers));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Burst_Lasers_Tom_Kazansky", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Burst_Lasers_Tom_Kazansky));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Burst_Lasers_Tom_Kazansky.getID(), &WeaponTypes::Burst_Lasers_Tom_Kazansky));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ATS_Laser_Battery", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::ATS_Laser_Battery));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::ATS_Laser_Battery.getID(), &WeaponTypes::ATS_Laser_Battery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ATS_Laser_Battery_Hero", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::ATS_Laser_Battery_Hero));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::ATS_Laser_Battery_Hero.getID(), &WeaponTypes::ATS_Laser_Battery_Hero));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ATS_Laser_Battery_Hyperion", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::ATS_Laser_Battery_Hyperion));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::ATS_Laser_Battery_Hyperion.getID(), &WeaponTypes::ATS_Laser_Battery_Hyperion));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ATA_Laser_Battery", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::ATA_Laser_Battery));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::ATA_Laser_Battery.getID(), &WeaponTypes::ATA_Laser_Battery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ATA_Laser_Battery_Hero", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::ATA_Laser_Battery_Hero));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::ATA_Laser_Battery_Hero.getID(), &WeaponTypes::ATA_Laser_Battery_Hero));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "ATA_Laser_Battery_Hyperion", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::ATA_Laser_Battery_Hyperion));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::ATA_Laser_Battery_Hyperion.getID(), &WeaponTypes::ATA_Laser_Battery_Hyperion));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Flame_Thrower", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Flame_Thrower));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Flame_Thrower.getID(), &WeaponTypes::Flame_Thrower));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Flame_Thrower_Gui_Montag", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Flame_Thrower_Gui_Montag));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Flame_Thrower_Gui_Montag.getID(), &WeaponTypes::Flame_Thrower_Gui_Montag));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Arclite_Shock_Cannon", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Arclite_Shock_Cannon));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Arclite_Shock_Cannon.getID(), &WeaponTypes::Arclite_Shock_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Arclite_Shock_Cannon_Edmund_Duke", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Arclite_Shock_Cannon_Edmund_Duke));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Arclite_Shock_Cannon_Edmund_Duke.getID(), &WeaponTypes::Arclite_Shock_Cannon_Edmund_Duke));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Longbolt_Missile", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Longbolt_Missile));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Longbolt_Missile.getID(), &WeaponTypes::Longbolt_Missile));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Claws", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Claws));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Claws.getID(), &WeaponTypes::Claws));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Claws_Devouring_One", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Claws_Devouring_One));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Claws_Devouring_One.getID(), &WeaponTypes::Claws_Devouring_One));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Claws_Infested_Kerrigan", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Claws_Infested_Kerrigan));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Claws_Infested_Kerrigan.getID(), &WeaponTypes::Claws_Infested_Kerrigan));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Needle_Spines", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Needle_Spines));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Needle_Spines.getID(), &WeaponTypes::Needle_Spines));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Needle_Spines_Hunter_Killer", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Needle_Spines_Hunter_Killer));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Needle_Spines_Hunter_Killer.getID(), &WeaponTypes::Needle_Spines_Hunter_Killer));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Kaiser_Blades", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Kaiser_Blades));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Kaiser_Blades.getID(), &WeaponTypes::Kaiser_Blades));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Kaiser_Blades_Torrasque", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Kaiser_Blades_Torrasque));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Kaiser_Blades_Torrasque.getID(), &WeaponTypes::Kaiser_Blades_Torrasque));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Toxic_Spores", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Toxic_Spores));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Toxic_Spores.getID(), &WeaponTypes::Toxic_Spores));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Spines", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Spines));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Spines.getID(), &WeaponTypes::Spines));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Acid_Spore", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Acid_Spore));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Acid_Spore.getID(), &WeaponTypes::Acid_Spore));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Acid_Spore_Kukulza", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Acid_Spore_Kukulza));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Acid_Spore_Kukulza.getID(), &WeaponTypes::Acid_Spore_Kukulza));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Glave_Wurm", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Glave_Wurm));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Glave_Wurm.getID(), &WeaponTypes::Glave_Wurm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Glave_Wurm_Kukulza", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Glave_Wurm_Kukulza));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Glave_Wurm_Kukulza.getID(), &WeaponTypes::Glave_Wurm_Kukulza));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Seeker_Spores", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Seeker_Spores));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Seeker_Spores.getID(), &WeaponTypes::Seeker_Spores));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Subterranean_Tentacle", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Subterranean_Tentacle));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Subterranean_Tentacle.getID(), &WeaponTypes::Subterranean_Tentacle));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Suicide_Infested_Terran", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Suicide_Infested_Terran));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Suicide_Infested_Terran.getID(), &WeaponTypes::Suicide_Infested_Terran));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Suicide_Scourge", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Suicide_Scourge));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Suicide_Scourge.getID(), &WeaponTypes::Suicide_Scourge));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Particle_Beam", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Particle_Beam));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Particle_Beam.getID(), &WeaponTypes::Particle_Beam));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psi_Blades", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Psi_Blades));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Psi_Blades.getID(), &WeaponTypes::Psi_Blades));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psi_Blades_Fenix", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Psi_Blades_Fenix));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Psi_Blades_Fenix.getID(), &WeaponTypes::Psi_Blades_Fenix));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Phase_Disruptor", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Phase_Disruptor));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Phase_Disruptor.getID(), &WeaponTypes::Phase_Disruptor));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Phase_Disruptor_Fenix", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Phase_Disruptor_Fenix));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Phase_Disruptor_Fenix.getID(), &WeaponTypes::Phase_Disruptor_Fenix));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psi_Assault", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Psi_Assault));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Psi_Assault.getID(), &WeaponTypes::Psi_Assault));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psionic_Shockwave", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Psionic_Shockwave));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Psionic_Shockwave.getID(), &WeaponTypes::Psionic_Shockwave));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psionic_Shockwave_TZ_Archon", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Psionic_Shockwave_TZ_Archon));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Psionic_Shockwave_TZ_Archon.getID(), &WeaponTypes::Psionic_Shockwave_TZ_Archon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Dual_Photon_Blasters", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Dual_Photon_Blasters));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Dual_Photon_Blasters.getID(), &WeaponTypes::Dual_Photon_Blasters));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Dual_Photon_Blasters_Mojo", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Dual_Photon_Blasters_Mojo));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Dual_Photon_Blasters_Mojo.getID(), &WeaponTypes::Dual_Photon_Blasters_Mojo));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Dual_Photon_Blasters_Artanis", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Dual_Photon_Blasters_Artanis));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Dual_Photon_Blasters_Artanis.getID(), &WeaponTypes::Dual_Photon_Blasters_Artanis));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Anti_Matter_Missiles", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Anti_Matter_Missiles));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Anti_Matter_Missiles.getID(), &WeaponTypes::Anti_Matter_Missiles));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Anti_Matter_Missiles_Mojo", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Anti_Matter_Missiles_Mojo));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Anti_Matter_Missiles_Mojo.getID(), &WeaponTypes::Anti_Matter_Missiles_Mojo));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Anti_Matter_Missiles_Artanis", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Anti_Matter_Missiles_Artanis));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Anti_Matter_Missiles_Artanis.getID(), &WeaponTypes::Anti_Matter_Missiles_Artanis));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Phase_Disruptor_Cannon", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Phase_Disruptor_Cannon));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Phase_Disruptor_Cannon.getID(), &WeaponTypes::Phase_Disruptor_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Phase_Disruptor_Cannon_Danimoth", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Phase_Disruptor_Cannon_Danimoth));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Phase_Disruptor_Cannon_Danimoth.getID(), &WeaponTypes::Phase_Disruptor_Cannon_Danimoth));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Pulse_Cannon", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Pulse_Cannon));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Pulse_Cannon.getID(), &WeaponTypes::Pulse_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "STS_Photon_Cannon", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::STS_Photon_Cannon));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::STS_Photon_Cannon.getID(), &WeaponTypes::STS_Photon_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "STA_Photon_Cannon", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::STA_Photon_Cannon));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::STA_Photon_Cannon.getID(), &WeaponTypes::STA_Photon_Cannon));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Scarab", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Scarab));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Scarab.getID(), &WeaponTypes::Scarab));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Neutron_Flare", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Neutron_Flare));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Neutron_Flare.getID(), &WeaponTypes::Neutron_Flare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Halo_Rockets", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Halo_Rockets));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Halo_Rockets.getID(), &WeaponTypes::Halo_Rockets));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Corrosive_Acid", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Corrosive_Acid));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Corrosive_Acid.getID(), &WeaponTypes::Corrosive_Acid));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Subterranean_Spines", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Subterranean_Spines));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Subterranean_Spines.getID(), &WeaponTypes::Subterranean_Spines));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Warp_Blades", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Warp_Blades));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Warp_Blades.getID(), &WeaponTypes::Warp_Blades));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Warp_Blades_Hero", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Warp_Blades_Hero));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Warp_Blades_Hero.getID(), &WeaponTypes::Warp_Blades_Hero));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Warp_Blades_Zeratul", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Warp_Blades_Zeratul));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Warp_Blades_Zeratul.getID(), &WeaponTypes::Warp_Blades_Zeratul));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Independant_Laser_Battery", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Independant_Laser_Battery));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Independant_Laser_Battery.getID(), &WeaponTypes::Independant_Laser_Battery));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Twin_Autocannons_Floor_Trap", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Twin_Autocannons_Floor_Trap));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Twin_Autocannons_Floor_Trap.getID(), &WeaponTypes::Twin_Autocannons_Floor_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hellfire_Missile_Pack_Wall_Trap", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Hellfire_Missile_Pack_Wall_Trap));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Hellfire_Missile_Pack_Wall_Trap.getID(), &WeaponTypes::Hellfire_Missile_Pack_Wall_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Flame_Thrower_Wall_Trap", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Flame_Thrower_Wall_Trap));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Flame_Thrower_Wall_Trap.getID(), &WeaponTypes::Flame_Thrower_Wall_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Hellfire_Missile_Pack_Floor_Trap", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Hellfire_Missile_Pack_Floor_Trap));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Hellfire_Missile_Pack_Floor_Trap.getID(), &WeaponTypes::Hellfire_Missile_Pack_Floor_Trap));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Yamato_Gun", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Yamato_Gun));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Yamato_Gun.getID(), &WeaponTypes::Yamato_Gun));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Nuclear_Strike", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Nuclear_Strike));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Nuclear_Strike.getID(), &WeaponTypes::Nuclear_Strike));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Lockdown", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Lockdown));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Lockdown.getID(), &WeaponTypes::Lockdown));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "EMP_Shockwave", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::EMP_Shockwave));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::EMP_Shockwave.getID(), &WeaponTypes::EMP_Shockwave));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Irradiate", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Irradiate));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Irradiate.getID(), &WeaponTypes::Irradiate));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Parasite", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Parasite));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Parasite.getID(), &WeaponTypes::Parasite));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Spawn_Broodlings", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Spawn_Broodlings));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Spawn_Broodlings.getID(), &WeaponTypes::Spawn_Broodlings));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Ensnare", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Ensnare));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Ensnare.getID(), &WeaponTypes::Ensnare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Dark_Swarm", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Dark_Swarm));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Dark_Swarm.getID(), &WeaponTypes::Dark_Swarm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Plague", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Plague));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Plague.getID(), &WeaponTypes::Plague));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Consume", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Consume));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Consume.getID(), &WeaponTypes::Consume));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Stasis_Field", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Stasis_Field));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Stasis_Field.getID(), &WeaponTypes::Stasis_Field));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Psionic_Storm", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Psionic_Storm));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Psionic_Storm.getID(), &WeaponTypes::Psionic_Storm));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Disruption_Web", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Disruption_Web));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Disruption_Web.getID(), &WeaponTypes::Disruption_Web));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Restoration", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Restoration));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Restoration.getID(), &WeaponTypes::Restoration));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Mind_Control", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Mind_Control));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Mind_Control.getID(), &WeaponTypes::Mind_Control));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Feedback", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Feedback));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Feedback.getID(), &WeaponTypes::Feedback));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Optical_Flare", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Optical_Flare));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Optical_Flare.getID(), &WeaponTypes::Optical_Flare));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Maelstrom", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Maelstrom));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Maelstrom.getID(), &WeaponTypes::Maelstrom));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "None", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::None));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::None.getID(), &WeaponTypes::None));
env->SetStaticObjectField(cls, env->GetStaticFieldID(cls, "Unknown", "Lbwapi/WeaponType;"), env->CallStaticObjectMethod(cls, getId, (jlong)&WeaponTypes::Unknown));
tableWeaponType.insert(std::pair<int, const WeaponType*>(WeaponTypes::Unknown.getID(), &WeaponTypes::Unknown));
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

							 BWTA::BWTA_Result::regions.clear();
							 BWTA::BWTA_Result::baselocations.clear();
							 BWTA::BWTA_Result::startlocations.clear();
							 BWTA::BWTA_Result::chokepoints.clear();
							 BWTA::BWTA_Result::unwalkablePolygons.clear();


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

