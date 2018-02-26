
#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string test = "PAN_POSITION:$PAN_POS$";
	std::regex r("[$]([0-9A-Z_]+)[$]");
	std::smatch match;

	std::regex_search(test, r);
	printf("size: %d\n", (int)match.size());
	for (auto x : match)
		printf("match: %s\n", x);
	return 0;
}
