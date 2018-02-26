
#include <iostream>
#include <string>

class Base
{
};

class Sub : public Base
{
};

class Processor
{
public:
	void process(Base* b) { printf("base\n"); }
	void process(Sub* s) { printf("sub\n"); }
};

int main(int argc, char** argv)
{
	Processor* p = new Processor();
	Base* b = new Base();
	Sub* s = new Sub();
    Base* bs = new Sub();
	p->process(b);
	p->process(s);
    p->process(bs);

	return 0;
}
