
#include <iostream>
#include <string>

class A
{
private:
	std::string _test;
public:
	A(std::string t) : _test(t) { }

	std::string getTest() { return _test; }
};

std::shared_ptr<A> globalA;
void doIt(std::shared_ptr<A>& ref)
{
	ref = globalA;
}

int main()
{
	globalA = std::make_shared<A>("testing");
	std::shared_ptr<A> another;
	doIt(another);
	printf("another: %s\n", another->getTest().c_str());
	return 0;
}
