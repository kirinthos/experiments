
#include <iostream>
#include <string>
#include <memory>

class Friendly
{
private:
	int _value;
public:
	Friendly(int v) : _value(v) { }
	int getValue() const { return _value; }

	friend class A;
};

class A
{
public:
	void doIt(Friendly& f) { f._value = 10; }
};

class B : public A
{
public:
};

int main(int argc, char** argv)
{
	Friendly f(4);
	B b;
	b.doIt(f);
	printf("Friendly value: %d\n", f.getValue());
	return 0;
}
