#include <iostream>

int lastOcc(int* arr, int n, int key)
{
	// Base case
	if (n == 0)
		return -1;

	// Recursive case
	int sub_index = lastOcc(arr + 1, n - 1, key);

	if (sub_index == -1)
	{
		if (arr[0] == key)
			return 0;
		else
			return -1;
	}
	else
		return sub_index + 1;
}

int main()
{
	int arr[]{ 1, 3, 5, 8, 7, 6, 2, 8, 7, 11, 21 };
	int n = std::size(arr);
	int key{ 7 };

	std::cout << lastOcc(arr, n, key) << std::endl;

	return 0;
}