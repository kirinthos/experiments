
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

class B
{
public:
	B() { printf("constructing B\n"); }
	~B() { printf("deconstructing B\n"); }
};

class A
{
private:
	std::vector<std::unique_ptr<B>> _bs;
public:
	A() { printf("constructing A\n"); }
	~A() { printf("deconstructing A\n"); }

	void addB(B* b) { _bs.push_back(std::unique_ptr<B>(b)); }
};


class Parent
{
public:
	void print1() { printf("parent\n"); }
};

class Child : public Parent
{
public:
	void print2() { printf("child\n"); }
};

class Container
{
public:
	void process(std::unique_ptr<Parent>& p) { p->print1(); }
	void process(std::unique_ptr<Child>& c) { c->print2(); }
};

int main()
{
	/*A a;
	B* b1 = new B();
	B b2;
	a.addB(b1);*/

	std::unique_ptr<Parent> ptr(new Child());
	Container c;
	c.process(ptr);

	return 0;
}
