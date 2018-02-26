
#include <iostream>
#include <string>

void doIt(int& a) { a = 10; }

int main()
{
	int a = 4;
	int& b = a;
	doIt(a);

	printf("a: %d\n", a);
	a = 3;
	doIt(b);
	printf("b: %d\n", b);

	return 0;
}
