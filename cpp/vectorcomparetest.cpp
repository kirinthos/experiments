
#include <vector>
#include <iostream>

class A
{

};

int main(int argc, char** argv)
{
	std::vector< std::shared_ptr<A> > list;
	A* a;
	for (int i = 0; i < 10; i++)
	{
		list.push_back(std::make_shared<A>());
		if (i == 5)
			a = list.back().get();
	}

	auto it = std::find_if(list.begin(), list.end(), [a](std::shared_ptr<A> const& comp) { return comp.get() == a; });
	if (*it)
		printf("found it!\n");
	else 
		printf("not found.\n");

	return 0;
}
