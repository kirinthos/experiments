
#ifndef __SOME_CLASS_H__
#define __SOME_CLASS_H__

#include <string>

class SomeClass
{
private:
	std::string _name;

public:
	SomeClass(std::string&& name) : _name(name) { }

	std::string getName() { return _name; }
	void print();
};

#endif
