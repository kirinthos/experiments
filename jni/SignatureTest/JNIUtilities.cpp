

#include "JNIUtilities.h"

JNIEnv* JNIUtilities::getEnvironment()
{
	return JNIWrapper::getInstance().getEnvironment();
}

jclass JNIUtilities::createReference(jclass clazz)
{
	JNIEnv* env = getEnvironment();
	return static_cast<jclass>(env->NewGlobalRef(clazz));
}

void JNIUtilities::deleteReference(jclass clazz)
{
	JNIEnv* env = getEnvironment();
	env->DeleteGlobalRef(clazz);
}

jobject JNIUtilities::createReference(jobject obj)
{
	JNIEnv* env = getEnvironment();
	return env->NewGlobalRef(obj);
}

void JNIUtilities::deleteReference(jobject obj)
{
	JNIEnv* env = getEnvironment();
	env->DeleteGlobalRef(obj);
}

