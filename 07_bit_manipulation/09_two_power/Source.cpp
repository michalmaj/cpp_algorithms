#include <iostream>
#include <bitset>
#include <iomanip>

int main()
{
	int n;
	std::cout << "Enter number to check if its power of 2: ";
	std::cin >> n;

	// For number, that is power of 2, if we take a number one less than our examined number
	// and do the AND operation we get a 0 as the result
	std::cout << "n: " << std::setw(12) << std::bitset<8>(n) << std::endl;
	std::cout << "n - 1: " << std::bitset<8>(n-1) << std::endl;


	if ((n & (n - 1)) == 0)
		std::cout << "Power of 2!\n";
	else
		std::cout << "Not a power of 2!\n";

	return 0;
}