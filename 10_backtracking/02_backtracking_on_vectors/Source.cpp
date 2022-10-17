#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr)
{
	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;
}

void fillArray(std::vector<int>& arr, int i, int n, int val)
{
	// base case
	if(i == n)
	{
		printArray(arr);
		return;
	}

	// rec case
	arr.insert(arr.begin() + i, val); // You can either use insert
	//arr.push_back(val); // or push back
	fillArray(arr, i + 1, n, val + 1);

	// backtracking step
	arr.at(i) = -1 * arr.at(i);
}

int main()
{
	std::vector<int> arr;
	int n;
	std::cout << "Enter to which number you want to fill array: ";
	std::cin >> n;

	fillArray(arr, 0, n, 1);

	printArray(arr);

	return 0;
}