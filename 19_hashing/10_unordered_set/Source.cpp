#include <iostream>
#include <unordered_set>


int main()
{
	// any insertion O(1)
	std::unordered_set<int> s{ 1, 2, 3, 8, 11, 15, 0 };

	int key{ 3 };

	// insert
	s.insert(111);

	//erase O(1)
	s.erase(11);

	// 0(1)
	if (s.find(key) != s.end())
		std::cout << key << " is present\n";
	else
		std::cout << "Not found\n";


	// print all elements
	for (const auto& e : s)
		std::cout << e << " ";

	std::cout << std::endl;
	return 0;
}