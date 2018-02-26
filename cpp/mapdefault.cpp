
#include <iostream>
#include <map>
#include <memory>
#include <string>

using namespace std;

class A
{
private:
	int a_;
public:
	A() { }
	A(int a) : a_(a) { }
	virtual ~A() { }
	int getA() const { return a_; }
	void setA(const int& a) { a_ = a; }
};

int main()
{
	map<string, shared_ptr<A>> As;
	for (int i = 0; i < 10; i++)
		As.insert(make_pair(to_string(i), make_shared<A>(i)));

	shared_ptr<A> ptr = As["20"];

	if (ptr)
		printf("good\n");
	else
		printf("bad\n");

	return 0;
}
