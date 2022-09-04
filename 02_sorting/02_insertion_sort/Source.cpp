/*
 * Insertion sort is similar to playing cards.
 * Insert the card in its correct position in a sorted part
 */

#include <iostream>

template<size_t N>
void insertion_sort(int (&arr)[N])
{
	// start loop from index 1
	for(int i{1}; i < N; ++i)
	{
		// set the current value to value in examined index 
		int current{ arr[i] };
		// set prev to previous index
		int prev{ i - 1 };

		// loop until prev is not smaller than 0, and
		// last value is greater than current
		// check subsequent elements
		while(prev >= 0 and arr[prev] > current)
		{
			// we need to move examined value to the right by 1 
			arr[prev + 1] = arr[prev];
			// decrement by 1
			prev--;
		}
		// put the current element to last free spot after
		// moving elements to the right
		arr[prev + 1] = current;
	}
}

int main()
{
	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	insertion_sort(arr);

	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;
	return 0;
}