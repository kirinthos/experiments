
#include <string>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A
{
protected:
	vector<int> _a;
public:
	A() : _a( { 10 } ) { }
	A(const A& copy) 
	{
		_a = vector<int>(copy._a);
	}

	A(A&& move)
	{
		_a = std::move(move._a);
	}

	vector<int> getA() const { return _a; }
	void add(int a) { _a.push_back(a); }
};

void printVector(vector<int> v)
{
	printf("vector: { ");
	for (int i : v)
		printf("%d, ", i);
	printf("}\n");
}

int main()
{
	A one;
	one.add(4);
	one.add(3);

	A two(one);
	two.add(7);

	printVector(one.getA());
	printVector(two.getA());

	A three(std::move(one));
	printVector(one.getA());
	printVector(three.getA());

	return 0;
}
