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

/**
 * \brief Function for change bit in given index by value v.
 * \param n Number where we want to change bit.
 * \param i Index of bit that we want to change.
 * \param v Value that we want to replace bit at given index (0 or 1).
 */
void updateIthBit(int& n, int i, int v)
{
	// First we need to turn off given bit.
	clearIthBit(n, i);
	int mask{ v << i }; // If v is 0, everything will be 0

	n = (n | mask);
}

int main()
{
	int n = 5;
	int i;
	std::cout << "Enter which bit do you want to change: ";
	std::cin >> i;

	updateIthBit(n, i, 1);
	std::cout << n << std::endl;

	return 0;
}