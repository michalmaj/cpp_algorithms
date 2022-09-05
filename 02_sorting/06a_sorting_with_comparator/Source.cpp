/*
 * Sorting with Comparator
 * Given an integer vector and a bool variable flag, your task is to sort the vector in
 * accordance to the boolean value. If the bool value passed is true then sort it in
 * non-decreasing order or vice versa.
 *
 * Input Format:
 *		In the function an integer vector and a boolean is passed.
 * Output Format:
 *		Return an integer vector.
 */

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> sortingWithComparator(std::vector<int> a, bool flag)
{
	if (flag)
		std::sort(a.begin(), a.end());
	else
		std::sort(a.begin(), a.end(), std::greater<>());

	return a;
}


int main()
{
	std::vector<int> vec{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	auto result = sortingWithComparator(vec, 0);
	for (const auto& e : result)
		std::cout << e << " ";
	std::cout << std::endl;

	return 0;
}