#include <iostream>

int main()
{

	char words[][10]
	{
		"one",
		"two",
		"three",
		"forty",
		"eighty",
		"hundred",
	};

	for (const auto& w : words)
		std::cout << w << " ";
	std::cout << std::endl;

	return 0;
}