/*
 * Insertion sort is similar to playing cards.
 * Insert the card in its correct position in a sorted part
 */

#include <iostream>

template<size_t N>
void insertion_sort(int (&arr)[N])
{
	for(int i{1}; i < N; ++i)
	{
		int current{ arr[i] };
		int prev{ i - 1 };

		while(prev >= 0 and arr[prev] > current)
		{
			arr[prev + 1] = arr[prev];
			prev--;
		}
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