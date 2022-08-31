/*
 * Find max sum of sub-array of an array.
 * One element can be treat as a sub-array.
 * Because it's a brute-force approach our time complexity is O(N^3)
 * we have 3 nested loops.
 */
#include <iostream>

template<class T, size_t N>
void print_sub_arrays(T (&arr)[N])
{
	// declare variable for sum and for max sum
	int sum{ 0 };
	int max{ 0 };
	// iteration for start point of sub-array
	for(int i{0}; i < N; ++i)
	{
		// iteration for end point of sub-array
		for(int j{0}; j < N; ++j)
		{
			// set sum to 0 after every sub-array
			sum = 0;
			// iteration for elements in sub array
			for(int k{i}; k <= j; ++k)
			{
				std::cout << arr[k] << " ";
				sum += arr[k];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		// find biggest sum
		if (sum > max)
			max = sum;
	}
	std::cout << "Max sum of sub array: " << max << std::endl;
}


int main()
{

	int arr[]{ 1, 2, 3, 4, 5, 6 };

	print_sub_arrays(arr);

	return 0;
}