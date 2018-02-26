
#include <memory>
#include <mutex>
#include <stdio.h>
#include <string>

static std::mutex g_objectCountMutex;
static int g_objectCount = 0;
using lock = std::lock_guard<std::mutex>;

class Base
{
protected:
	std::string _name;

public:
	Base(const std::string& name): _name(name) { }
	Base(const Base& b)
	{
		lock l(g_objectCountMutex);
		_name = b._name + " clone " + std::to_string(++g_objectCount);
	}
	virtual ~Base()
	{
		printf("base destructed name: %s\n", _name.c_str());
	}

	virtual void print() { printf("Base -- name: %s\n", _name.c_str()); }

	virtual Base* clone() = 0;
};

template<typename T>
class CloneableBase : public Base
{
public:
	CloneableBase(const std::string& name): Base(name) { }

	virtual Base* clone() { return new T(dynamic_cast<const T&>(*this)); }
};

template<typename T>
class CloneableOne : public CloneableBase<T>
{
protected:
	std::string _one;

public:
	CloneableOne(const std::string& name, const std::string& one)
		: CloneableBase<T>(name)
	{
		_one = one;
	}

	virtual void print() { printf("Base -- name: %s, one: %s\n", this->_name.c_str(), this->_one.c_str()); }
};

class One : public CloneableOne<One>
{
public:
	One(const std::string& name, const std::string& one)
		: CloneableOne<One>(name, one)
	{
	}
};

class Two : public CloneableOne<Two>
{
protected:
	std::string _two;

public:
	Two(const std::string& name, const std::string& one, const std::string& two)
		: CloneableOne(name, one),
		_two(two)
	{
	}
	Two(const Two& t)
		: CloneableOne(t)
	{
		_two = "HAHA GOT YOU";
	}

	virtual void print() { printf("Base -- name: %s, one: %s, two: %s\n", this->_name.c_str(), this->_one.c_str(), this->_two.c_str()); }
};

int main()
{
	std::shared_ptr<Base> one, two;
	one = std::make_shared<One>("testing", "one");
	two = std::make_shared<Two>("two", "two4real", "reallytwo");

	auto oneclone = one->clone();
	auto twoclone = two->clone();

	one->print();
	two->print();
	oneclone->print();
	twoclone->print();
	one.reset();
	two.reset();
	oneclone->print();
	twoclone->print();


	return 0;
}
