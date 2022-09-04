/*
 * We have a C++ built-in function for sorting: std::sort().
 * It's defined in <algorithm> header.
 * Bubble sort, insertion sort and selection sort have O(N^2) time complex, but provided
 * by C++ sort algorithm has O(NlogN) time complexity.
 * Documentation:
 * https://en.cppreference.com/w/cpp/algorithm/sort
 */

#include <iostream>
#include <algorithm>

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	// To use this algorithm we need to define starting point and ending point.
	// As a start point we will use index 0, as a ending point we will use last index.
	// So we need to get number of elements inside an array
	int n{ std::size(arr) }; // n will be number of elements

	std::sort(arr, arr + n);

	std::cout << "Array after sorting:" << std::endl;
	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;

	//// Now to get array in descending order we can use a reverse function
	//// But it isn't a good idea. It's better to write own function as comparator
	//// or use built-in comparator. Examples below this block of code
	//std::reverse(arr, arr + n);
	//std::cout << "Array after reversing:" << std::endl;
	//for (const auto& e : arr)
	//	std::cout << e << " ";
	//std::cout << std::endl;

	// Sorting in descending order using own function (comment out one).
	// In this case we will pass a function as a parameter
	//std::sort(arr, arr + n, compare);
	// Sorting in descending order using built-in function (comment out one).
	std::sort(arr, arr + n, std::greater<>());

	std::cout << "Array after sorting:" << std::endl;
	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;



	return 0;
}