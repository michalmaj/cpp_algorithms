/*
 * Sorting Cabs!
 * Given a vector of pairs representing coordinates x and y of different cabs on a X-Y plane.
 * Sort them according to their distance from the origin in the non-decreasing order i.e. the
 * cab with shortest distance from the origin will be at first.
 *
 * Input Format:
 * In the function an integer vector of pairs is passed.
 *
 * Output Format
 * Return an integer vector of pairs in sorted order.
 *
 * Sample Input
 * { (2,3), (1,2), (3,4), (2,4), (1,4) }
 *
 * Sample Output
 * { (1, 2), (2, 3), (1, 4), (2, 4), (3, 4) }
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	for (const auto& e : vec)
		out << e << " ";
	return out;
}

double distance(const std::pair<int, int>& p)
{
	return sqrt(pow(p.first - 0, 2) + pow(p.second - 0, 2) * 1.0);
}

bool comparator(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
{
	return distance(p1) < distance(p2);
}


std::vector<std::pair<int, int>> sortCabs(std::vector<std::pair<int, int>> v)
{
	std::sort(v.begin(), v.end(), comparator);
	
	return v;
}

int main()
{
	std::vector<std::pair<int, int>> arr{ {2,3}, {1,2}, {3,4}, {2,4}, {1,4} };
	
	for (const auto& e : arr)
		std::cout << e.first << " " << e.second << std::endl;
	std::cout << std::endl;

	auto result = sortCabs(arr);
	for (const auto& e : result)
		std::cout << e.first << " " << e.second << std::endl;
	std::cout << std::endl;


	return 0;
}