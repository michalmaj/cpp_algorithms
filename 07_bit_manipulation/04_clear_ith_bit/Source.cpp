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
	// Set bit to 1 at given index, rest will be 0's, then switch 1 to 0 and 0' to 1's
	int mask{ ~(1 << i) };

	std::cout << std::setw(20) << "Mask: " << std::setw(10) << std::bitset<8>(mask) << std::endl;
	std::cout << std::setw(20) << "Value: " << std::setw(10) << std::bitset<8>(n) << std::endl;
	std::cout << std::setw(20) << "Mask & value: " << std::setw(10) << std::bitset<8>(n & mask) << std::endl;

	// It will turn off bit at given index
	n = (n & mask);
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