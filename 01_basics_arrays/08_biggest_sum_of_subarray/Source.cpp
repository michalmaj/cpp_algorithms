/*
 * Algorithm to find max sum of sub-array of an array.
 * This is brute-force approach, we are going to iterate through
 * with three nested loops (O(N^3)).
 */
#include <iostream>

template<class T, size_t N>
int largest_subarray_sum(T (&arr)[N])
{
	int largest_sum{ 0 };

	// loop for start point of sub-array
	for(int i{0}; i < N; ++i)
	{
		// loop for end point of sub-array
		for(int j{i}; j < N; ++j)
		{
			int subarray_sum = 0;

			// loop for elements in sub-array
			for(int k{i}; k <= j; ++k)
			{
				subarray_sum += arr[k];
			}

			// check if current sub-array > largest_sum
			// here we are using the std::max that returns the greater of the given values
			largest_sum = std::max(largest_sum, subarray_sum);
		}
	}
	return largest_sum;
}

int main()
{

	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	auto res = largest_subarray_sum(arr);
	std::cout << "Largest sum: " << res << std::endl;


	return 0;
}