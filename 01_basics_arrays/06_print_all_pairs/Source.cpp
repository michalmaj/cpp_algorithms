/*
 * Algorithm for print pairs from an array.
 * For example for an array that contains values: {1, 2, 3, 4}
 * we can make the following pairs:
 * (1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4)
 */

#include <iostream>

template<class T, size_t N>
void printAllPairs(T (&arr)[N])
{
	// Loop to pick up the first element (start from index 0)
	for(int i{0}; i < N; ++i)
	{
		T x{ arr[i] };

		// Loop to pick up elements to make a pair with element from first loop.
		// So j has an index greater by one than i.
		// For sake of completeness we can also print pairs in both direction.
		// For example we can have (1, 4) and (4, 1) pair.
		// Only you need to do is change j{i+1} to j{0}.
		for(int j{i+1}; j < N; ++j)
		{
			// If you want pairs in both direction but without repetition,
			// skip same indexes
			if(i == j)
				continue;

			T y{ arr[j] };

			std::cout << "(" << x << "," << y << ")" << std::endl;
		}
		std::cout << std::endl;
	}
}

int main()
{
	int arr[]{ 1, 2, 3, 4, 5, 6 };

	// print all elements from an array
	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl << std::endl;

	printAllPairs(arr);

	return 0;
}