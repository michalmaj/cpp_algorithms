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
	// Set bit to 1 at given index, rest will be 0's, then switch 1 to 0 and 0' to 1's.
	int mask{ ~(1 << i) };

	std::cout << std::setw(20) << "Mask: " << std::setw(10) << std::bitset<8>(mask) << std::endl;
	std::cout << std::setw(20) << "Value: " << std::setw(10) << std::bitset<8>(n) << std::endl;
	std::cout << std::setw(20) << "Mask & value: " << std::setw(10) << std::bitset<8>(n & mask) << std::endl;

	// It will turn off bit at given index
	n = (n & mask);
}

/**
 * \brief Function for change bit in given index by value v.
 * \param n Number where we want to change bit.
 * \param i Index of bit that we want to change.
 * \param v Value that we want to replace bit at given index (0 or 1).
 */
void updateIthBit(int& n, int i, int v)
{
	// First we need to turn off given bit. Given bit will be 0.
	clearIthBit(n, i);

	// Create mask and set bit at given index to 1 or 0 (value of v decide)
	int mask{ v << i }; // If v is 0, everything will be 0

	// If v=1 mask will have 1 at index i so n also will change bit at given index to 1,
	// otherwise for v=0 mask at given index will have 0, so n also will have 0 at this index.
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