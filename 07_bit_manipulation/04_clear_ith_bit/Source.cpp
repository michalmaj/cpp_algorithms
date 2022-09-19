#include <iostream>
#include <bitset> // To represent numbers in bits
#include <iomanip>

/**
 * \brief Function to change bit at given index to 0.
 * \param n Number where we want to turn off bit a given index.
 * \param i Index of bit that we want to turn off.
 */
void clearIthBit(int& n, int i)
{
	int mask{ 1 << i };
	//std::cout << std::bitset<8>(~mask) << std::endl;
	n = (n & (~mask));
}

int main()
{
	int n = 5;
	int i;
	std::cout << "Enter which bit do you want to turn off: ";
	std::cin >> i;

	clearIthBit(n, i);

	std::cout << n << std::endl;

	return 0;
}