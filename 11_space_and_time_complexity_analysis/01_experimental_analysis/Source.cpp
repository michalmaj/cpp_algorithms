#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


void bubbleSort(std::vector<int>& a)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (size_t i = 0; i < a.size() - 1; i++) {
			if (a[i] > a[i + 1]) {
				a[i] += a[i + 1];
				a[i + 1] = a[i] - a[i + 1];
				a[i] -= a[i + 1];
				swapp = true;
			}
		}
	}
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
	bubbleSort(arr); // Comment above or this
	auto end_time = std::clock();

	std::cout << "Time of sort algorithm: " << (end_time - start_time) << " ms." << std::endl;


	return 0;
}