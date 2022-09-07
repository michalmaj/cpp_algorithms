/*
 * Problem:
 * Read N strings and print the largest string. Each string can have up to 1000 characters.
 */

#define _CRT_SECURE_NO_WARNINGS // directive - some compilers won't let us using std::strcpy

#include <iostream>
#include <cstring>

int main()
{
	// We need to create two character arrays
	// One for store maximum length sentence and one for reading data purpose.
	char sentence[1000]{};
	char temp[1000];

	// Also we need a variable for storing maximum length.
	int largest{ 0 };

	// For reading sentences in while loop we have many options, but we are going
	// to consider two:
	// 1) Set the variable for number of sentences
	// 2) Read sentences as long they contains at least 1 character

	//// Uncomment and modify while loop below if you want this method
	//int number_of_sentences{};
	//std::cout << "Enter how many sentences you want to read: ";
	//std::cin >> number_of_sentences;
	//// Because we press enter after type the number in console, we need to clean up
	//// and catch this new line character by std::cin.get();
	//std::cin.get();

	// Loop until sentence has at least 1 character, if empty break the loop
	// If you want to use method one replace with:
	// while(number_of_sentences--)
	// and comment out first if
	while(true)
	{
		std::cout << "Enter your sentence:\n";
		std::cin.getline(temp, 1000);
		// Check current length of string
		int current = std::strlen(temp);

		// If sentence has no character, end the while loop
		if(current == 0)
			break;

		if(current > largest)
		{
			std::strcpy(sentence, temp);
			largest = std::strlen(temp);
		}
	}

	std::cout << "Largest sentence: " << sentence << ", contains: "
		<< largest << " characters\n";


	return 0;
}