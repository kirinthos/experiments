

#include <iostream>
#include <string>
#include <map>


class A
{
public:
	A() { printf("A constructed\n"); }
	~A() { printf("A destructed\n"); }
};

class B
{
public:
	B() { printf("B constructed\n"); }
	~B() { printf("B destructed\n"); }

	void add(std::string key) { _map.insert(std::make_pair(key, std::make_shared<A>())); }

private:
	std::map<std::string, std::shared_ptr<A> > _map;
};

int main(int argc, char** argv) {
	
	B b;
	for (int i = 0; i < 10; i++)
		b.add(std::to_string(i));

	return 0;
}
