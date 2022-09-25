/*
 * Replace bits in N by M
 * We have two 32-bit numbers, N and M, and two bit positions i and j. We need to write a method
 * to set all bits between i and j in N equal to M. (M becomes a substring of N from j to i)
 */

#include <iostream>
#include <bitset>


 /**
  * \brief Function to clear bits from index i to index j
  * \param n Number in which we want to clear bits
  * \param i Lowest index from which we want to clear bits
  * \param j Highest index to which we want to clear bits.
  */
void clearBitsInRange(int& n, int i, int j)
{
	// Set all bits to 1 (using ~0) and then shift to the left by j + 1. 
	int a{ (~0) << (j + 1) };
	// Move 1 by i and fill this distance by 1's
	int b{ (1 << i) - 1 };

	// Make mask that has 0 from i to j
	int mask{ a | b };

	// So we can turn off bits in given number n i range from i to j
	n = n & mask;
}

/**
 * \brief Function to replace bits in given number n by bits from number m in given range from i to j
 * \param n Number that we want to replace bits.
 * \param i Number from which we copy bits to n.
 * \param j Farthest index in range.
 * \param m Closest index in range.
 */
void replaceBits(int& n, int i, int j, int m)
{
	// First we need to clear bits from i to j
	clearBitsInRange(n, i, j);

	// Then we need to move our bits closest index
	int mask{ m << i };

	n = n | mask;
}


int main()
{
	int n = 15;
	int m = 2;
	int i{ 1 };
	int j{ 3 };

	std::cout << "Before replace:" << std::endl;
	
	std::cout << "n: " << std::bitset<32>(n) << std::endl;
	std::cout << "m: " << std::bitset<32>(m) << std::endl;

	replaceBits(n, i, j, m);

	std::cout << "After replace:" << std::endl;

	std::cout << "n: " << std::bitset<32>(n) << std::endl;
	std::cout << "m: " << std::bitset<32>(m) << std::endl;

	return 0;
}
