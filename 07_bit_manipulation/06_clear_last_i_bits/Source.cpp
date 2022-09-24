#include <iostream>
#include <bitset> // To represent numbers in bits
#include <iomanip>


/**
 * \brief Function to clear bit from index 0 to i (exclusive).
 * \param n Number where we want to turn off bits.
 * \param i Index to we want to clear bits.
 */
void clearLastIBits(int& n, int i)
{
	// We can represent a mask in two ways:
	// 1) as ~0 (all bits will be 1's)
	// 2) as -1 (all bits are 1's)
	// So if we move by i to the left, these number of bits will be 0's
	int mask{ -1 << i};
	std::cout << std::setw(20) << "Mask: " << std::setw(10) << std::bitset<8>(mask) << std::endl;
	std::cout << std::setw(20) << "Value: " << std::setw(10) << std::bitset<8>(n) << std::endl;
	std::cout << std::setw(20) << "Mask & value: " << std::setw(10) << std::bitset<8>(mask & n) << std::endl;

	// Positions from 0 index to index i-1 will cleared
	n = (n & mask);
}

int main()
{
	int n = 5;
	int i;
	std::cout << "Enter which bit do you want to change: ";
	std::cin >> i;

	clearLastIBits(n, i);

	std::cout << n << std::endl;

	return 0;
}