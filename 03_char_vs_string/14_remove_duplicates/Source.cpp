/*
 * Remove Duplicates
 * Given a string S, the task is to remove all the duplicates from the given string
 * and return the updated string in sorted order.
 *
 * Input Format:
 * In the function a string is passed.
 *
 * Output Format:
 * Return the updated string.
 *
 * Sample Input:
 * std::string s = "geeksforgeeks"
 *
 * Sample Output:
 * "efgkors"
 */

#include <iostream>
#include <string>
#include <set>

std::string removeDuplicate(std::string s)
{
	std::set<char> ss(s.begin(), s.end());

	std::string str{};
	for (const auto& e : ss)
		str += e;

	return str;
}

int main()
{
	std::string s{ "geeksforgeeks" };

	std::cout << removeDuplicate(s) << std::endl;

	return 0;
}