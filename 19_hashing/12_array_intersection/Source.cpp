#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {

	std::vector<int> output;
	std::set<int> s1(nums1.begin(), nums1.end());
	std::set<int> s2(nums2.begin(), nums2.end());

	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(output, output.begin()));

	return output;
}

int main()
{
	std::vector<int> n1{ 4,9,5 };
	std::vector<int> n2{ 9,4,9,8,4 };


	auto result = intersection(n1, n2);

	for (const auto& e : result)
		std::cout << e << " ";
	std::cout << std::endl;


	return 0;
}