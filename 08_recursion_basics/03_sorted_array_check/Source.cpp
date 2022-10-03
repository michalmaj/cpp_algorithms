#include <iostream>

/**
 * \brief Function for checking if given array is sorted.
 * \param arr An array to check if sorted.
 * \param size Size of given array.
 * \return true or false.
 */
bool isSorted(int arr[], int size)
{
	// base case
	if (size == 1 or size == 0)
		return true;

	// recursive case
	if (arr[0] < arr[1] and isSorted(arr + 1, size - 1))
		return true;

	return false;
}

/**
 * \brief Second version of function for checking if given array is sorted.
 * \param arr An array to check if sorted.
 * \param idx If we don't want to use pointer arithmetic we can use indexes.
 * \param size Size of given array.
 * \return true or false.
 */
bool isSorted(int arr[], int idx, int size)
{
	// base case
	if (idx == size - 1)
		return true;

	// recursive case
	if (arr[idx] < arr[idx + 1] and isSorted(arr, idx + 1, size))
		return true;

	return false;
}

int main()
{
	int arr[]{ 1, 2, 3, 4, 5 };
	int size = std::size(arr);

	std::cout << std::boolalpha << isSorted(arr, 0, size) << std::endl;

	return 0;
}