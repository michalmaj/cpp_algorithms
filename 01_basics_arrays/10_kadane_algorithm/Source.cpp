/*
 * Another algorithm to sum subarray and find biggest sum.
 * Kadane's algorithm check all positive contiguous elements of the array and keeps tracking
 * the maximum sum.
 */

#include <iostream>


template <class T, size_t N>
int maximum_subarray_sum(T (&arr)[N])
{
	// check sum in all positive values in contiguous array 
	int current_sum{ 0 };
	// track max sum
	int largest_sum{ 0 };

	// loop through array
	for(int i{}; i < N; ++i)
	{
		// add next element from an array
		current_sum = current_sum + arr[i];
		// if next element is negative, set current sum to 0
		if (current_sum < 0)
			current_sum = 0;

		// check which sum is bigger, current or largest
		largest_sum = std::max(current_sum, largest_sum);
	}
	return largest_sum;
}


int main()
{
	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	auto result = maximum_subarray_sum(arr);
	std::cout << "Largest sum of sub-array: " << result << std::endl;


	return 0;
}