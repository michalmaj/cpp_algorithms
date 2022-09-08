/*
 * Are Permutation
 * Given two strings A and B. Check if one string is permutation of the other.
 * A Permutation of a string is another string that contains same characters, only the
 * order of characters can be different. For example, “abcd” and “dabc” are Permutation of
 * each other.
 *
 * Input Format:
 * In the function two strings passed.
 *
 * Output Format
 * Return true if B is permutation of A else false.
 *
 * Sample Input:
 * std::string A = "test", B = "ttew"
 *
 * Sample Output:
 * NO
 */

#include <iostream>
#include <algorithm>

bool arePermutation(std::string A, std::string B)
{
	if (A.length() != B.length())
		return false;
	if (A == B)
		return true;
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	return A == B;
}

int main()
{
	std::string A = "test", B = "ttew";
	std::cout << arePermutation(A, B) << std::endl;

	return 0;
}