/*
 * Algorithm to find max sum of sub-array of an array.
 * But this time we are going to use prefix sum.
 * We will create a new array, prefix array, to store
 * cumulative sum from starting array.
 */
#include <iostream>

template<class T, size_t N>
int largest_subarray_sum(T (&arr)[N])
{
	// Calculate prefix sum
	int* prefix;
	prefix = new int[N];

	// push value from index 0 of arr to prefix[0] array
	prefix[0] = arr[0];
	for(int i{1}; i < N; ++i)
	{
		prefix[i] = prefix[i - 1] + arr[i];
	}

	std::cout << "Newly created array (prefix) contains:" << std::endl;
	for(int i{0}; i < N; ++i)
	{
		std::cout << prefix[i] << " ";
	}
	std::cout << std::endl;

	int largest_sum{ 0 };
	// compute largest sum
	for(int i{0}; i < N; ++i)
	{
		for(int j{i}; j < N; ++j)
		{
			int sub_array_sum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];
			largest_sum = std::max(largest_sum, sub_array_sum);
		}
	}

	delete[] prefix;
	return largest_sum;
}

int main()
{
	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };
	auto result = largest_subarray_sum(arr);

	std::cout << "Largest sum: " << result << std::endl;

	return 0;
}