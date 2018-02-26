
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<string, int> umap;
	string key = "test";
	umap.insert(make_pair(key, 0));

	auto it = umap.find(key);
	it->second++;

	auto another = umap.find(key);
	printf("int: %d\n", another->second);

	it->second++;
	printf("int again: %d\n", another->second);

	return 0;
}
