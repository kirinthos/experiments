
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class A
{
public:
	virtual std::string get() { return "A, mane."; }
};

class B : public A
{
public:
	std::string get() override { return "B, homie."; }
};

int main()
{
	std::vector<std::shared_ptr<B> > bs;
	for (int i = 0; i < 3; i++)
		bs.push_back(std::make_shared<B>());

	std::vector<std::shared_ptr<A> > as = bs;
	return 0;
}
