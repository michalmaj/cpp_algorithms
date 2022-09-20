/*
 * Replace bits in N by M
 * We have two 32-bit numbers, N and M, and two bit positions i and j. We need to write a method
 * to set all bits between i and j in N equal to M. (M becomes a substring of N from j to i)
 */

#include <iostream>
#include <bitset>

void clearBitsInRange(int& n, int i, int j)
{
	int a{ (~0) << (j + 1) };
	int b{ (1 << i) - 1 };

	int mask{ a | b };
	n = n & mask;
}

void replaceBits(int& n, int i, int j, int m)
{
	clearBitsInRange(n, i, j);
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
