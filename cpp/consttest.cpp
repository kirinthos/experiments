
#include <iostream>

class A
{
private:
	std::string _gear;

public:
	A() { }

	void gear() const
	{
		printf("const function\n");
	}

	void nongear()
	{
		printf("non const function\n");
	}
};
	

int main(int argc, char** argv)
{
	A a;
	a.gear();
	a.nongear();

	printf("\nconst A\n");
	const A a2;
	a2.gear();
	a2.nongear();
	return 0;
}
