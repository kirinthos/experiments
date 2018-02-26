
#include <iostream>
#include <string>

class A
{
public:
	template<typename Return, typename... Args>
	static void doSomething(const Return& ret, const Args&... args)
	{
		printf("return: ");
		printIt(ret);
		printf("args:\n");
		printArgs(args...);
	}

	template<typename Arg, typename... Args>
	static void printArgs(const Arg& arg, const Args&... args)
	{
		printf("\t");
		printIt(arg);
		printArgs(args...);
	}

	static void printIt(void) { printf ("void type\n"); }
	static void printIt(int i) { printf("int type\n"); }
	static void printIt(long i) { printf("long type\n"); }
	static void printIt(double i) { printf("double type\n"); }
	static void printIt(std::string i) { printf("string type\n"); }
};


int main(int argc, char** argv)
{
	int i = 0;
	std::string ret;
	A::doSomething((void)ret, i);
}
