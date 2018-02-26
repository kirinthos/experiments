
#include <string>

using namespace std;

void printStringTest(string tmp)
{
	printf("testing: \"%s\"\n", tmp.c_str());
	printf(tmp.empty() ? "null\n" : "not null\n");
}

int main(int argc, char** argv)
{
	string tmp;
	printStringTest(tmp);

	tmp = "gear";
	printStringTest(tmp);

	tmp = "";
	printStringTest(tmp);


	return 0;
}
