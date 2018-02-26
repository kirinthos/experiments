
#include <memory>
#include <vector>

using namespace std;

class A
{
public:
	A() { printf("A constructed\n"); }
	~A() { printf("A deconstructed\n"); }
};

int main (int argc, char** argv)
{
	A* a = new A();
	shared_ptr<A> sp(a);
	vector< shared_ptr<A> > pointers;

	pointers.push_back(sp);
	pointers.push_back(sp);
	pointers.push_back(sp);
	
	printf("use count: %d\n", sp.use_count());

	auto it = std::find(pointers.begin(), pointers.end(), sp);
	pointers.erase(it);
	printf("use count: %d\n", sp.use_count());

	it = pointers.end();
	pointers.erase(it);

	return 0;
}
