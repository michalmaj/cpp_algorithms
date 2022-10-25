#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


void bubbleSort(std::vector<int>& arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already
		// in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

int main()
{
	int n;
	std::cout << "Enter how many elements do you put into a vector: ";
	std::cin >> n;
	std::vector<int> arr(n, 0);

	for(size_t i{0}; i < n; ++i)
	{
		arr[i] = n - 1;
	}

	auto start_time = std::clock();
	//std::sort(arr.begin(), arr.end()); // Builtin sort algorithm
	bubbleSort(arr, n); // Comment above line or this line
	auto end_time = std::clock();

	std::cout << "Time of sort algorithm: " << (end_time - start_time) << " ms." << std::endl;


	return 0;
}