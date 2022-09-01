#include <iostream>
#include <vector>

int maxSumSubarray(std::vector<int> A) {

	// sum contiguous elements
	int current_sum{ 0 };
	// set current biggest sum
	int max_sum{ 0 };

	// loop through vector
	for(int i{}; i < A.size(); ++i)
	{
		// add a new element
		current_sum = current_sum + A[i];
		// if sum is less than 0, set current sum as 0
		if (current_sum < 0)
			current_sum = 0;
		// check if current sum is bigger than actual biggest sum
		max_sum = std::max(current_sum, max_sum);
	}
	return max_sum;
}

int main()
{
	std::vector<int> v1{ 1, -2, 3, 4, 4, -2 };
	std::vector<int> v2{ 5, 0, -1, 0, 1, 2, -1 };

	std::cout << maxSumSubarray(v2) << std::endl;

	return 0;
}