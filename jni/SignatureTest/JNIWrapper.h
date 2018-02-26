
#ifndef __JNI_H__
#define __JNI_H__

#include <jni.h>


#define JNI_VERSION JNI_VERSION_1_6

class JNIWrapper
{
private:
	JavaVM* _java;
	JNIEnv* _env;

	JNIWrapper() : _java(nullptr), _env(nullptr) { }

public:


	void setJVM(JavaVM* java) { _java = java; }

	static JNIWrapper& getInstance();
	JavaVM* getJVM() { return _java; }
	JNIEnv* getEnvironment();
	int getJNIVersion() { return JNI_VERSION; }

};

#endif // __JNI_H__
