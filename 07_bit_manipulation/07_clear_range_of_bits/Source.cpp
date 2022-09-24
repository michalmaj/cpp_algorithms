#include <iostream>
#include <bitset>
#include <iomanip>


/**
 * \brief Function to clear bits from index i to index j
 * \param n Number in which we want to clear bits
 * \param i Lowest index from which we want to clear bits
 * \param j Highest index to which we want to clear bits.
 */
void clearBitsInRange(int& n, int i, int j)
{
	// Set all bits to 1's using ~0, then move to the left by j+1
	int a{ (~0) << (j + 1)};

	// to turn on bits from 0 to i we need to left shift 1 by i and then subtract 1
	int b{ (1 << i) - 1 };

	std::cout << "a: " << std::setw(12) << std::bitset<8>(a) << std::endl;
	std::cout << "b: " << std::setw(12) << std::bitset<8>(b) << std::endl;

	// Mask will be created from 1's from j to the end, and 1's from 0 to i,
	// rest will be 0's
	int mask{ a | b };
	std::cout << "mask: " << std::setw(9) << std::bitset<8>(mask) << std::endl;
	n = n & mask;

}

int main()
{
	int n = 31;
	int i{ 2 };
	int j{ 3 };

	clearBitsInRange(n, i, j);
	std::cout << "n " << std::bitset<8>(n) << ", with value: " << n << std::endl;

	return 0;
}