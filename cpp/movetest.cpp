
#include <iostream>
#include <string>
#include <vector>

class Take
{
public:
	std::vector< std::string > _strings;

	void take(std::vector< std::string > ref)
	{
		printf("taking by copy\n");
		_strings = ref;
	}

	void take(std::vector< std::string >&& ref)
	{
		printf("taking by move\n");
		_strings = std::move(ref);
	}
};

int main()
{
	Take t;
	std::vector< std::string > s = { "one", "two", "three" };
	t.take(std::move(s));
	printf("s: %s\n", s[0].c_str());
	return 0;
}
