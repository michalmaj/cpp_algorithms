/*
 * String Compression:
 * Given an array of characters chars, compress it using the following algorithm:
 * Begin with an empty string s. For each group of consecutive repeating
 * characters in chars:
 *		- If the group's length is 1, append the character to s.
 *		- Otherwise, append the character followed by the group's length.
 * The compressed string s should not be returned separately, but instead be stored in
 * the input character array chars. Note that group lengths that are 10 or longer will be
 * split into multiple characters in chars.
 * After you are done modifying the input array, return the new length of the array.
 * You must write an algorithm that uses only constant extra space.
 *
 * Input Format:
 *		In the function a vector of characters is passed.
 * Output Format:
 *		Return the updated vector
 *
 * Example 1:
 * Input: chars = ["a","a","b","b","c","c","c"]
 * Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
 * Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
 *
 * Example 2:
 * Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
 * Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 */

#include <iostream>
#include <string>
#include <vector>

int compress(std::vector<char>& chars)
{
	// Create new vector for output
	std::vector<char> s;

	// Loop for elements inside chars
	for(int i{0}; i < chars.size(); ++i)
	{
		// How many times of consecutive repeating characters
		int count{ 1 };
		// Start from next index than i
		int j = i + 1;
		// Loop from index i + 1
		while (j < chars.size())
		{
			// If characters are the same
			if (chars[i] == chars[j])
			{
				// Increment count
				count++;
				// Change current indexes
				i++;
				j++;
			}
			else
				break;
		}

		// Insert elements into new vector
		// If char showed once just insert character
		if (count == 1)
			s.push_back(chars[i]);
		// If more than once add number of times
		if(count > 1)
		{
			s.push_back(chars[i]);

			// Change number to string
			std::string num = std::to_string(count);
			for (const auto& e : num)
				s.push_back(e);
		}
	}
	// For testing purpose show content of new vector
	for (auto& e : s)
		std::cout << e << "";
	std::cout << std::endl;
    
	return s.size();
}

int main()
{
	char a1[1000]{ "aabbccc" };
	char a2[1000]{ "abbbbbbbbbbbb" };
	char a3[1000]{ "aaabbccddee" };
	std::vector<char> vec;

	for (const auto& e : a3)
	{
		if(e == '\0')
			break;
		vec.push_back(e);
	}

	compress(vec);


	
	return 0;
}