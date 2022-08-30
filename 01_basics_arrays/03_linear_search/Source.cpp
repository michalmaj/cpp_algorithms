/*
 * This is example of brute-force algorithm.
 * Searching for a given value in an array one by one.
 * This code in worst case (iterate through entire array) - number of operations
 * we have to execute is proportional to the length of an array. So the complexity is:
 * O(N) time.
 */
#include <iostream>

// Generic function for linear search.
template <class T, size_t N>
int linear_search(T (&arr)[N], T key)
{
	// If element doesn't exist in an array, index will be -1.
	int idx{ -1 };

	for(int i{0}; i < std::size(arr); ++i)
	{
		if (arr[i] == key)
			idx = i;
	}

	return idx;
}

int main()
{
	int arr[]{ 1, 2, 0, 10, 11, 9, 8, 8, 7 };
	constexpr int key{ 9 };
	auto result = linear_search(arr, key);
	std::cout << "Index of looking item is: " << result << std::endl;

	return 0;
}