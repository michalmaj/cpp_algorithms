/*
 * Pair sum problem
 * For given array: {10, 5, 2, 3, -6, 9, 11, 1}
 * print pairs whose sum is equal to k.
 *
 * Possible approaches:
 *	1. Brute-force: two nested loops => O(n^2).
 *	2. Sorting + two pinter => O(NlogN).
 *	3. Sorting + binary search => O(NlogN)/
 *	4. Hashing => O(N)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::pair<int, int>> pairSum(const std::vector<int>& arr, int Sum)
{
	std::unordered_set<int> s;
	std::vector<std::pair<int, int>> result;

	for(int i{0}; i < arr.size(); ++i)
	{
		int x = Sum - arr[i];
		if (s.find(x) != s.end())
		{
			auto t = std::make_pair(x, arr[i]);
			result.push_back(t);
		}
		s.insert(arr[i]);
	}
	return result;
}

int main()
{
	std::vector<int> arr{ 10, 5, 2, 3, -6, 9, 11, 1 };
	int S = 4;

	auto p = pairSum(arr, S);
	if (p.size() == 0)
		std::cout << "No such pair!\n ";
	else
	{
		for (const auto& pair : p)
			std::cout << pair.first << " " << pair.second << std::endl;
	}

	return 0;
}