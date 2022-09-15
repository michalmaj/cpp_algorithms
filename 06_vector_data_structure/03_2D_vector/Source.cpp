#include <iostream>
#include <vector>

int main()
{
	// 2D vector, each row can have different number of elements
	std::vector<std::vector<int>> arr
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9, 10},
		{11, 12},
	};

	// Update a particular element
	arr[0][0] += 10;

	// Iterate using normal for loop through rows
	for(size_t i{0}; i < arr.size(); ++i)
	{
		// Iterate using range-based for loop through columns
		for (const size_t number : arr[i])
			std::cout << number << " ";
		std::cout << std::endl;
	}

	return 0;
}