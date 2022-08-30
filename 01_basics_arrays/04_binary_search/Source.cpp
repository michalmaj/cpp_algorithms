/*
 * This is another example of searching.
 * This algorithm works on sorted array.
 * First thing we need to do is define the first index and last index of our array.
 * Then we need to find the middle point (divide sum of starting and ending index by 2).
 * Check if middle point contains out searching value. If not check if middle point is
 * greater or smaller. If middle point is greater than our searching value, discard
 * right-hand side of an array (include middle point) by changing last index to point to
 * index of middle - 1. But if middle point is smaller than searching value, discard
 * left-hand side of an array (include middle point) by changing first index to point
 * to index of middle + 1.
 *
 * Time complexity of binary search:
 * In first iteration we have an array of size N, we can write this as N/2^0
 * In next iteration our array is reduced by 2, N/2, we can write N/2^1
 * In next iteration our array is reduced by 4, N/4, we can write N/2^2
 * In k-iteration our array will have only 1 element, we can write N/2^k = 1
 * So:
 * N/2^k = 1
 * N = 2^k
 * k = log2(N)
 * Finally time complexity of binary search is O(log2(N))
 */

#include <iostream>
#include <algorithm> // library that contains sort algorithm

template <class T, size_t N>
int binary_search(T (&arr)[N], T key)
{
	// Index of starting point of an array.
	int s{ 0 };
	// Index of ending point of an array.
	int e{ N - 1 };

	while(s <= e)
	{
		// First we need to find a middle point
		int mid = (s + e) / 2;

		// If we find the answer, we are going to return index of our value.
		if (arr[mid] == key)
			return mid;
		// If value to find is smaller than middle value,
		// we are going to discard right side of an array
		// (include middle point as well).
		// So our index of ending array point will move
		// to index of middle point minus 1 
		else if (arr[mid] > key)
			e = mid - 1;
		// If value to find is greater than middle value,
		// we are going to discard right side of an array
		// (include middle point).
		// So our index of starting array point will move
		// to index of middle point plus 1.
		else
			s = mid + 1;
	}

	// If item not found return -1
	return -1;
}


int main()
{
	// Our array.
	int arr[]{ 1, 2, 0, 10, 11, 9, 8, 8, 7 };
	// Value to find in an array.
	constexpr int key{ 9 };

	// Algorithm to sort an array (necessary for binary search).
	std::sort(std::begin(arr), std::end(arr));

	// print array after sorting
	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;

	auto res = binary_search(arr, key);
	std::cout << "index of key (" << key << ")  is: " << res << std::endl;

	return 0;
}