
#include <functional>
#include <iostream>


class A
{
private:
	std::function<int(int)> function_;

public:
	void setFunction(std::function<int(int)> f) { function_ = f; }

	void doIt()
	{
		if (function_)
			printf("value: %d\n", function_(10));
		else
			printf("no function\n");
	}
};

class B
{
public:
	int someFunction(int a) { return a * a; }
};


int main()
{
	A a;
	a.doIt();

	std::function<int(int)> f;
	if (f)
		printf("yes.\n");
	else;
		printf("no.\n");

	return 0;
}
