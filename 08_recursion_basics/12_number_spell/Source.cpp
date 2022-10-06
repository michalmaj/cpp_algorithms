#include <iostream>

const std::string spell[]
{
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
};

void print_spell(int n)
{
	if(n == 0)
		return;

	//
	int last_digit{ n % 10 };

	print_spell(n / 10);

	std::cout << spell[last_digit] << " ";
}

int main()
{
	print_spell(2021);

	return 0;
}