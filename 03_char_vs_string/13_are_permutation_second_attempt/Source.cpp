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
	int a{};
	int b{};

	if (A.length() != B.length())
		return false;
	if (A == B)
		return true;

	for(size_t i{0}; i < A.length(); ++i)
	{
		a += static_cast<int>(A[i]);
		b += static_cast<int>(B[i]);
	}

	return a == b;
}

int main()
{
	std::string A = "test", B = "ttew";
	std::cout << arePermutation(A, B) << std::endl;

	return 0;
}