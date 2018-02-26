
#include "JNIWrapper.h"

#include <cassert>

JNIWrapper& JNIWrapper::getInstance()
{
	static JNIWrapper jni;
	return jni;
}

JNIEnv* JNIWrapper::getEnvironment()
{
	if (!_env)
	{
		assert(_java); //breakdown if no jvm handle
		_java->GetEnv((void**)&_env, getJNIVersion());
		_java->AttachCurrentThread((void**)&_env, nullptr);
	}
	assert(_env);
	return _env;
}
