#include <iostream>
#include <bitset> // To represent numbers in bits
#include <iomanip>

/**
 * \brief Function to get i-th bit of given number.
 * \param n Number.
 * \param i Position of the bit.
 * \return 1 or 0.
 */
int getIthBIt(int n, int i)
{
	// Set the mask where bit at given position will be 1 and the rest will be 0
	int mask{ 1 << i };
	std::cout << std::setw(20) << "Mask: " << std::setw(10) << std::bitset<8>(mask) << std::endl;
	std::cout << std::setw(20) << "Value: " << std::setw(10) << std::bitset<8>(n) << std::endl;
	std::cout << std::setw(20) << "Mask & value: " << std::setw(10) << std::bitset<8>(mask & n) << std::endl;

	// If our value and mask have 1's at the same position it means we need to return 1.
	// Otherwise return 0.
	return ((n & mask) > 0)? 1 : 0;
}

int main()
{
	int n = 5;
	int i;
	std::cout << "Enter which bit do you want to see: ";
	std::cin >> i;

	auto result = getIthBIt(n, i);
	std::cout << "\n\nBit in " << i << " index: " << result << std::endl;;

	return 0;
}