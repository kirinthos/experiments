
#ifndef __JNI_UTILITIES_H__
#define __JNI_UTILITIES_H__

#include "JNIWrapper.h"

#include <jni.h>
#include <string>

class JNIUtilities
{
private:
	static JNIEnv* getEnvironment();

	template<typename Arg, typename... Args>
	static std::string buildSignature_(const Arg& arg, const Args&... args);
	static std::string buildSignature_() { return ""; }

	//type signature conversions
	static std::string getSignaturePart(const bool& b) { return "Z"; }
	static std::string getSignaturePart(const unsigned char& b) { return "B"; }
	static std::string getSignaturePart(const char& c) { return "C"; }
	static std::string getSignaturePart(const short& s) { return "S"; }
	static std::string getSignaturePart(const int& i) { return "I"; }
	static std::string getSignaturePart(const long& i) { return "J"; }
	static std::string getSignaturePart(const float& f) { return "F"; }
	static std::string getSignaturePart(const double& d) { return "D"; }
	static std::string getSignaturePart(const std::string& s) { return "Ljava/lang/String;"; }
	static std::string getSignaturePart() { return "V"; } //void

public:
	
	template<typename Return, typename... Args>
	static std::string buildSignature(const Return& ret, const Args&... args);

	template<typename... Args>
	static std::string buildVoidSignature(const Args&... args);

	template<typename Return, typename... Args>
	static jmethodID getStaticMethodID(jclass clazz, std::string name, const Return& ret, const Args&... args);

	template<typename... Args>
	static jmethodID getStaticVoidMethodID(jclass clazz, std::string name, const Args&... args);

	template<typename Return, typename... Args>
	static jmethodID getObjectMethodID(jobject obj, std::string name, const Return& ret, const Args&... args);

	template<typename... Args>
	static jmethodID getObjectVoidMethodID(jobject obj, std::string name, const Args&... args);

	template<typename Type>
	static jfieldID getStaticFieldID(jclass clazz, std::string name, const Type& type);

	template<typename Type>
	static jfieldID getFieldID(jobject obj, std::string name, const Type& type);

	static jclass createReference(jclass clazz);
	static void deleteReference(jclass clazz);

	static jobject createReference(jobject obj);
	static void deleteReference(jobject obj);

};

template<typename Return, typename... Args>
std::string JNIUtilities::buildSignature(const Return& ret, const Args&... args)
{
	return "(" + buildSignature_(args...) + ")" + getSignaturePart(ret);
}

template<typename... Args>
std::string JNIUtilities::buildVoidSignature(const Args&... args)
{
	return "(" + buildSignature_(args...) + ")" + getSignaturePart();
}

template<typename Arg, typename... Args>
std::string JNIUtilities::buildSignature_(const Arg& arg, const Args&... args)
{
	return getSignaturePart(arg) + buildSignature_(args...);
}

template<typename Return, typename... Args>
jmethodID JNIUtilities::getStaticMethodID(jclass clazz, std::string name, const Return& ret, const Args&... args)
{
	JNIEnv* env = getEnvironment();
	return env->GetStaticMethodID(clazz, name.c_str(), buildSignature(ret, args...));
}

template<typename... Args>
jmethodID JNIUtilities::getStaticVoidMethodID(jclass clazz, std::string name, const Args&... args)
{
	JNIEnv* env = getEnvironment();
	return env->GetStaticMethodID(clazz, name.c_str(), buildVoidSignature(args...));
}

template<typename Return, typename... Args>
jmethodID JNIUtilities::getObjectMethodID(jobject obj, std::string name, const Return& ret, const Args&... args)
{
	JNIEnv* env = getEnvironment();
	return env->GetMethodID(obj, name.c_str(), buildSignature(ret, args...));
}

template<typename... Args>
jmethodID JNIUtilities::getObjectVoidMethodID(jobject obj, std::string name, const Args&... args)
{
	JNIEnv* env = getEnvironment();
	return env->GetMethodID(obj, name.c_str(), buildSignature(args...));
}

template<typename Type>
jfieldID JNIUtilities::getStaticFieldID(jclass clazz, std::string name, const Type& type)
{
	JNIEnv* env = getEnvironment();
	return env->GetStaticFieldID(clazz, name.c_str(), getSignaturePart(type));
}

template<typename Type>
jfieldID JNIUtilities::getFieldID(jobject obj, std::string name, const Type& type)
{
	JNIEnv* env = getEnvironment();
	return env->GetFieldID(obj, name.c_str(), getSignaturePart(type));
}


#endif // __JNI_UTILITIES_H__
