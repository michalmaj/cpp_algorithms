/*
 * Selection sort
 * Repeatedly find the minimum element in unsorted part of the array.
 * Then put this element at the beginning.
 * So, in other words we get the first element as our minimum value, and then we compare
 * with other values in array. If we find smaller we take it as our new smallest value,
 * and continue search to the end. If we find the lost value we put it in the beginning
 * and then move to the second element and look for smallest number in rest of the array
 * (from this point 1st item is sorted - smallest value is on the proper index).
 * Continue until whole array is sorted.
 */

#include <iostream>

template<size_t N>
void selection_sort(int (&arr)[N])
{
	// loop to second last element
	for(int pos{0}; pos <= N - 2; ++pos)
	{
		// current variable is value under examined index
		int current{ arr[pos] };

		// current index of minimum value
		int min_pos{ pos };

		// find the minimum element in array
		for(int j{pos}; j < N; ++j)
		{
			if (arr[j] < arr[min_pos])
				min_pos = j;
		}
		// swap outside the loop
		std::swap(arr[min_pos], arr[pos]);
	}
}

int main()
{
	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	selection_sort(arr);

	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;
	return 0;
}