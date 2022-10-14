#include <iostream>

void printArray(int *arr, int n)
{
	// print our array
	for (int i{ 0 }; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

/**
 * \brief Function to put values into array from val to n-1.
 * \param arr Array to store values.
 * \param i Index.
 * \param n To which number we want to fill array.
 * \param val Started value.
 */
void fillArray(int* arr, int i, int n, int val)
{
	// base case
	if(i == n)
	{
		printArray(arr, n);
		return;
	}

	// recursive case
	arr[i] = val;
	fillArray(arr, i + 1, n, val + 1);

	// backtracking step
	arr[i] = -1 * arr[i]; // Printed array inside this function won't change
	
}


int main()
{

	int arr[100] = {0};
	int n;
	std::cout << "Enter to which number you want to fill array: ";
	std::cin >> n;

	fillArray(arr, 0, n, 1);

	printArray(arr, n);

	return 0;
}