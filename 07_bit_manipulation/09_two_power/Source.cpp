#include <iostream>

int main()
{
	int n;
	std::cout << "Enter number to check if its power of 2: ";
	std::cin >> n;

	if ((n & (n - 1)) == 0)
		std::cout << "Power of 2!\n";
	else
		std::cout << "Not a power of 2!\n";

	return 0;
}