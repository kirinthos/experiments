
#include <iostream>
#include "Gear.h"

JNIEXPORT void JNICALL Java_gear_Gear_doSomething
  (JNIEnv* env, jobject ob)
{
	printf("did it\n");
}
