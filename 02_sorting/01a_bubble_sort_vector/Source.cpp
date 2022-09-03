/*
 * Same version as befor, but this time with vector
 */

#include <iostream>
#include <vector>

bool compare(int a, int b)
{
	return a > b;
}

std::vector<int> bubble_sort(std::vector<int> vec)
{;
	for(int times{1}; times <= vec.size() - 1; ++times)
	{
		for(int j{0}; j <= vec.size() - times - 1; ++j)
		{
			if(compare(vec[j], vec[j + 1]))
			{
				std::swap(vec[j], vec[j + 1]);
			}
		}
	}
	return vec;
}

int main()
{
	std::vector<int> vec{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	std::vector<int> temp = bubble_sort(vec);

	for (const auto& e : temp)
		std::cout << e << " ";
	std::cout << std::endl;

	return 0;
}