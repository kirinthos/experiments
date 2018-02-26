
#include <stdio.h>
#include <string>
#include <vector>

void p(const std::string& name, bool construct)
{
	printf("%s %s\n", name.c_str(), construct ? "constructed" : "destructed");
}

class A
{
public:
	A() { p("A", true); }
	A(const A&) { p("A", true); }
	virtual ~A() { p("A", false); }
};

class B : public A
{
public:
	B() { p("B", true); }
	B(const B&) { p("B", true); }
	virtual ~B() { p("B", false); }

	std::vector<int> vals;
};

class C : public B
{
public:
	C() { p("C", true); }
	C(const C&) { p("C", true); }
	virtual ~C() { p("C", false); }
};

int main()
{
	printf("default constructors\n");
	printf("\nA\n");
	A a;
	printf("\nB\n");
	B b;
	printf("\nC\n");
	C c;

	printf("\ncopy constructors\n");
	printf("\nA\n");
	A a2(a);
	printf("\nB\n");
	B b2(b);
	printf("\nC\n");
	C c2(c);

	printf("checking vector copy\n");
	c.vals.push_back(0);
	c.vals.push_back(1);
	c.vals.push_back(2);
	C c3(c);

	return 0;
}
