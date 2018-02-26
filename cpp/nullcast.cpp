
#include <iostream>

class A
{

};

class B : public A
{

};

int main(int argc, char** argv)
{
	A* b = new B();
	delete b;
	b = nullptr;
	B* bcast = static_cast<B*>(b);
	printf("success.\n");
	return 0;
}
