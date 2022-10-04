/*
 * Print Increasing Numbers:
 * Given an integer N. Your task is to return an integer vector containing numbers from 1 to N
 * in increasing order.
 *
 * Sample Input:
 *	5
 * Sample Output:
 *	1 2 3 4 5
 */

#include <iostream>
#include <vector>
void increasing(int n, std::vector<int>& vec)
{
	if(n == 0)
		return;
	increasing(n - 1, vec);
	vec.push_back(n);
}

std::vector<int> increasingNumbers(int N) {
	std::vector<int> output;
	increasing(N, output);

	return output;
}

int main()
{
	int value{ 5 };

	auto res = increasingNumbers(value);

	for (const auto& e : res)
		std::cout << e << " ";
	std::cout << std::endl;

	return 0;
}