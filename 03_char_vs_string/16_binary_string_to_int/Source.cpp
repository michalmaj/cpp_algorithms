/*
 * Binary String to Number
 * Given a binary string as input, convert into its decimal form and return it as an integer.
 *
 * Input Format:
 * In the function a binary string is passed.
 *
 * Output Format:
 * Return an integer.
 *
 * Sample Input:
 *		111
 * Sample Output:
 *		7
 */

#include <iostream>
#include <string>

int binaryToDecimal(std::string s)
{
	// We can use std::stoi from string library, it's convert string to integer.
	// In addition we can set the base of given value inside string:
	// std::stoi(str, pos, base)
	int output = std::stoi(s, 0, 2); // s - given string, 0 starting pos, 2 base

	return output;
}

int main()
{

	std::string x{ "111" };

	std::cout << binaryToDecimal(x) << std::endl;
	return 0;
}