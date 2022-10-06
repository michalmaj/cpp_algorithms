#include <iostream>

bool compare(int a, int b)
{
	return a > b;
}

/**
 * \brief Sort array using bubble sort algorithm.
 * \param a Array to sort.
 * \param n Size of the array.
 */
void bubble_sort(int a[], int n)
{
	for(int times{1}; times < n; ++times)
	{
		// swapping items
		for(int j{0}; j < n - times; ++j)
		{
			if (compare(a[j], a[j + 1]))
				std::swap(a[j], a[j + 1]);
		}
	}
}

void bubble_sort_rec(int a[], int n, int j)
{
	// base case
	if (n == 1 or n == 0)
		return;

	if(j == n-1)
	{
		// reduce the problem size
		bubble_sort_rec(a, n - 1, 0);
		return;
	}

	if (a[j] > a[j + 1])
		std::swap(a[j], a[j + 1]);

	bubble_sort_rec(a, n, j + 1);

}

int main()
{
	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };
	int n{ std::size(arr) };

	bubble_sort_rec(arr, n, 0);

	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;

	return 0;
}