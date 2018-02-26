
#include <iostream>


class A
{
};

class B : public A
{
};

class C : public A
{
};

int main(int argc, char** argv)
{
	std::shared_ptr<B> spb = std::make_shared<B>();
	std::shared_ptr<A> spa = spb;
	std::shared_ptr<A> spa2 = std::make_shared<C>();


	return 0;
}
