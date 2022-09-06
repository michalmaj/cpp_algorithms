/*
 * Given a sentence, count the number of letters, digits, and spaces in the sentence.
 */

#include <iostream>

int main()
{
	// There are two ways to solve this problem, we can either store then count
	// or read one character by one and count

	char ch;

	ch = std::cin.get();

	int num_letters{};
	int num_digits{};
	int num_spaces{};
	int num_special{};

	while(ch != '\n')
	{
		if (ch >= '0' and ch <= '9')
			num_digits++;
		else if (ch >= 'a' and ch <= 'z' or ch >= 'A' and ch <= 'Z')
			num_letters++;
		else if (ch == ' ' or ch == '\t')
			num_spaces++;
		else
			num_special++;

		ch = std::cin.get();
	}

	std::cout << "Total letters: " << num_letters
		<< ", total digits: " << num_digits
		<< ", total spaces: " << num_spaces
		<< ", total special characters: " << num_special << std::endl;


	return 0;
}