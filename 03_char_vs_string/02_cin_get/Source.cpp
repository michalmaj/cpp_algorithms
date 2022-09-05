/*
 * Using a space in std::cin for character array causes putting a
 * null character.
 * That's why in this case we have to use cin.get() method. It is able to read
 * any character.
 */

#include <iostream>


int main()
{
	char sentence[1000];

	// Let's create a char variable to read single character at the time
	// using cin.get().
	char ch = std::cin.get();

	// Loop until new line
	int i{ 0 };
	while (ch != '\n')
	{
		sentence[i++] = ch;
		ch = std::cin.get();
	}
	// Terminate sentence with a null character
	sentence[i] = '\0';

	std::cout << "Length: " << i << ", content: " << sentence << std::endl;

	// We can use cin.get() in anther form, but this time we need to know
	// how long our sentence is. Remember that value contains also space
	// for null character.
	std::cin.get(sentence, 4);
	std::cout << sentence << std::endl;

	return 0;
}