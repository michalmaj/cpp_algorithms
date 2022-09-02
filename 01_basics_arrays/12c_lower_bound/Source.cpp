/*
 * Given an array of integers A (sorted) and a integer Val.
 * Implement a function that takes A and Val as input parameters
 * and returns the lower bound of Val.
 * Note : If Val is not present in array then Lower bound of a given integer
 * means integer which is just smaller than given integer.
 * Otherwise Val itself is the answer.
 * If Val is less than smallest element of array A then return '-1' in that case.
 */

#include <iostream>
#include <vector>

int lowerBound(std::vector<int> A, int Val)
{
	// loop in reverse (from last element to first)
	for(int i{static_cast<int>(A.size()-1)}; i >=0; --i)
	{
		// if current element is lower or equal to Val
		// return it
		if (A[i] <= Val)
			return A[i];
	}
	// if all elements are greater than Val return -1
	return -1;
}

int main()
{
	std::vector<int> vec1{ -1, -1, 2, 3, 5 };
	std::vector<int> vec2{ 1, 2, 3, 4, 5 };

	std::cout << lowerBound(vec1, 4) << std::endl;

	return 0;
}