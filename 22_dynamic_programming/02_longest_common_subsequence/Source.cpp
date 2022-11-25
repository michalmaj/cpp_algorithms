#include <iostream>
#include <vector>

// Bottom Up Solution
int lis(std::vector<int> arr)
{
	size_t n = arr.size();
	std::vector<int> dp(n, 1);

	int len{ 1 };

	for(size_t i{1}; i < n; ++i)
	{
		for(size_t j{0}; j < i; ++j)
		{
			if (arr.at(i) > arr.at(j))
			{
				dp.at(i) = std::max(dp.at(i), 1 + dp.at(j));
				len = std::max(len, dp.at(i));
			}
		}
	}

	return len;
}

int main()
{
	std::vector<int> arr{ 50, 4, 10, 8, 30, 100 };

	std::cout << lis(arr) << std::endl;
	return 0;
}