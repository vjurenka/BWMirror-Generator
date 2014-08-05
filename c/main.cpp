#include "../runner.h"
#include <BWAPI.h>
#include <BWAPI/Client.h>
#include <BWTA.h>
#include <jni.h>
/*
JNIEnv *jEnv;

using namespace BWAPI;

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


JNIEXPORT void JNICALL Java_runner_Runner_startGame
	(JNIEnv * env, jobject obj){

		jEnv = env;

		println("Attempting to init BWAPI...");
		BWAPI_init();
		println("BWAPI READY!!!");

		println("Connecting to Startcraft...");
		reconnect();
		println("Connected :)");

		jclass cls = env->GetObjectClass(obj);
		jmethodID mid = env->GetMethodID(cls, "setGame", "(J)V");

		env->CallVoidMethod(obj, mid, (long)Broodwar);

		while (true) {
            if (Broodwar != NULL) {
				println("Waiting...");
                while (!Broodwar->isInGame()) {
                    BWAPIClient.update();
					if (Broodwar == NULL) {
                            println("GG");
                            return;
                    }
                }
            }

			println("Game ready!!!");

			while (Broodwar->isInGame()) {
				

				BWAPIClient.update();
				if (!BWAPI::BWAPIClient.isConnected()) {
						println("Reconnecting...");
						reconnect();
				}
			}
		}
}

*/