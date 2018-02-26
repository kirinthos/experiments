
#include <iostream>
#include "SomeClass.h"

JNIEXPORT void JNICALL Java_SomeClass_doSomething
  (JNIEnv* env, jclass clazz)
{
	jmethodID sm = env->GetStaticMethodID(clazz, "someMethod", "()V");
	if (!sm)
		printf("cannot find method\n");
	else
		env->CallStaticVoidMethod(clazz, sm);
}
