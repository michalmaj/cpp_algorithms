#include <iostream>
#include <bitset> // To represent numbers in bits
#include <iomanip>

/**
 * \brief Function for change bit to 1 in given number.
 * \param n Number for change bit.
 * \param i Index of bit that we will change
 */
void setIthBit(int& n, int i)
{
	// Mask contains 1 at given index, rest will be 0's
	int mask{ 1 << i };
	std::cout << std::setw(20) << "Mask: " << std::setw(10) << std::bitset<8>(mask) << std::endl;
	std::cout << std::setw(20) << "Value: " << std::setw(10) << std::bitset<8>(n) << std::endl;
	std::cout << std::setw(20) << "Mask & value: " << std::setw(10) << std::bitset<8>(n | mask) << std::endl;
	// Because our mask has a 1 at index i, same bit index in given n will be turn on
	n = (n | mask);
}

int main()
{
	int n = 5;
	int i;
	std::cout << "Enter index of bit do you want to change: ";
	std::cin >> i;

	setIthBit(n, i);
	std::cout << "After set bit in index " << i << " we have: " << n << std::endl;

	return 0;
}