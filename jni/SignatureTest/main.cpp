
#include <iostream>
#include <string>

#include "JNIUtilities.h"

int main(int argc, char** argv)
{
	std::string sig = JNIUtilities::buildVoidSignature(std::string(), true, 0L, 0, 11.0);
	printf("signature: %s\n", sig.c_str());

	sig = JNIUtilities::buildVoidSignature();
	printf("void signature: %s\n", sig.c_str());
}
