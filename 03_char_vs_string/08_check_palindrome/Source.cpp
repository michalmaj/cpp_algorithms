/*
 * Check Palindrome
 * Given a string, write a c function to check if it is palindrome or not.
 * A string is said to be palindrome if reverse of the string is same as string.
 * For example, “abba” is palindrome, but “abbc” is not palindrome.
 *
 * Input Format:
 *		In the function a string is passed.
 * Output Format:
 *		Return true if it is palindrome else false.
 * Sample Input:
 *		abcdcba
 * Sample Output:
 *		true
 */

#include <iostream>

bool isPalindrome(std::string str)
{
	bool is_palindrome{ true };
	for(int i{0}; i < (str.size() / 2); ++i)
	{
		if (str[i] != str[str.size() - i - 1])
			is_palindrome = false;
	}
	return is_palindrome;
}

int main()
{
	std::string str{ "abcdcba" };

	auto res = isPalindrome(str);
	std::cout << str << ((res) ? " is a palindrome" : " is not a palindrome") << std::endl;

	return 0;
}