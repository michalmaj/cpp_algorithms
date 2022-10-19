#include <iostream>
#include <vector>

void findSubset(char* input, char* output, int i, int j)
{
	// base case
	if(input[i] == '\0')
	{
		output[j] = '\0';
		if (output[0] == '\0')
			std::cout << "NULL\n";
		std::cout << output << std::endl;
		return;
	}

	// rec case
	// include the ith letter
	output[j] = input[i];
	findSubset(input, output, i + 1, j + 1);

	// exclude the ith letter
	// Overwriting
	findSubset(input, output, i + 1, j);
}

int main()
{
	char input[]{ "abc" };
	char output[100];

	findSubset(input, output, 0, 0);
	std::cout << output << std::endl;

	return 0;
}