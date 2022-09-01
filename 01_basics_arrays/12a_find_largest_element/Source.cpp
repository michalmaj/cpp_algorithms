#include <iostream>
#include <vector>
#include <algorithm> // library that contains for example max_elemet


int largestElement(std::vector<int> arr)
{
	// set first vector element as largest
	int max_elemet = arr[0];

	// iterate through vector
	for(int i{1}; i < arr.size(); ++i)
	{
		// if value in next index is bigger change max_element
		max_elemet = std::max(arr[i], max_elemet);
	}

	return max_elemet;
}

// simply use the C++ algorithm for containers
int largestElement2(std::vector<int> arr)
{
	return *std::ranges::max_element(arr);
}

int main()
{
	std::vector<int> vec1{ -3, 4, 1, 2, 3 };
	std::vector<int> vec2{ -1, -2, -3, -3, 8 };

	auto res1 = largestElement(vec1);
	std::cout << "Largest element in vec1: " << res1 << std::endl;

	auto res2 = largestElement2(vec2);
	std::cout << "Largest element in vec2: " << res2 << std::endl;

	return  0;
}