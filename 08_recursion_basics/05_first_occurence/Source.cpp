#include <iostream>

/**
 * \brief Function to find recursively first occurrence of given value.
 * \param arr Array that we want to find first occurrence of given value.
 * \param n Size of the array.
 * \param key Value that we are looking for.
 * \return Index of given value or -1 if value is not present in the array.
 */
int firstOcc(int arr[], int n, int key)
{
	// base case
	if (n == 0)
		return -1;

	// recursive case

	// Check if value is not the first element in the array.
	if (arr[0] == key)
		return 0;

	// Recursive search.
	// Pass the address of next element (arr + 1) - pointers arithmetic
	// Decrease size of array by 1 at every recursion call.
	int subIndex = firstOcc(arr + 1, n - 1, key);
	// If there is a solution we have to add 1 to every recursive call to get final answer.
	if (subIndex != -1)
		return subIndex + 1;

	return -1;
}


int main()
{
	int arr[]{ 1, 3, 5, 7, 6, 2, 11, 21 };
	int n = std::size(arr);
	int key = 7;

	std::cout << firstOcc(arr, n, key);

	return 0;
}