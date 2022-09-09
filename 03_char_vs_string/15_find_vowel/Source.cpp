/*
 * Vowel Find
 * Given a string consisting of lowercase English alphabets, return a string containing all
 * the vowels present in S in serial order.
 *
 * Input Format:
 * In the function a string S is passed.
 *
 * Output Format:
 * Return a string.
 *
 * Sample Input
 *		S = "aeoibsddaeioudb"
 * Sample Output:
 *		"aeoiaeiou"
 */

#include <iostream>
#include <string>



std::string vowel(std::string S)
{
	// String that contains vowels
	std::string vowels{ "aeiou" };
	// String that will be return from function
	std::string output{};

	// Loop for given string
	for(int i{0}; i < S.size(); ++i)
	{
		// Check if letter from the string is in vowels string
		// string.find() returns npos if failed to find
		if (vowels.find(S[i]) != std::string::npos)
			output += S[i];
	}

	return output;
}

int main()
{
	std::string S = "aeoibsddaeioudb";

	std::cout << vowel(S) << std::endl;

	return 0;
}