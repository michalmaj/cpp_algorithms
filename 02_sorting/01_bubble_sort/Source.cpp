/*
 * Sorting algorithm takes an unsorted array, and sorts array in increasing
 * or decreasing order.
 *
 * First of sorting algorithms is Bubble Sort:
 * take largest element to the end by repeatedly swapping the adjacent elements.
 */

#include <iostream>

// check if values need to be swapped
bool compare(int a, int b)
{
	return a > b;
}

// sort elements in increasing order
template<size_t N>
void bubble_sort(int (&arr)[N])
{
	for(int times{1}; times <= N - 1; ++times)
	{
		// repeated swapping
		for(int j{0}; j <= N - times - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
				if(compare(arr[j], arr[j + 1]))
					std::swap(arr[j], arr[j + 1]);
		}
	}
}

int main()
{
	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	bubble_sort(arr);

	for(const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;

	return 0;
}