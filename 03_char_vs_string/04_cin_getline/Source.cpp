/*
 * std::getline reads characters from an input stream and places them into a string.
 * So, instead of reading letters one by one, we can read whole sentence.
 */
#include <iostream>


int main()
{
	char sentence[1000];

	// It will automatically terminated when new line occurs.
	// As a parameters we need to use name of our array and how many
	// character we want to type
	std::cin.getline(sentence, 1000);

	std::cout << sentence << std::endl;

	return 0;
}