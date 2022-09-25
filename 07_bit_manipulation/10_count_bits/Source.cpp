#include <iostream>

/**
 * \brief Count number of 1's bits in given number n.
 * \param n Number in which we want to count number of 1's bits.
 * \return Sum of 1's in given number n.
 */
int count_bits(int n)
{
	int count{ 0 };
	while(n > 0)
	{
		// Calculate using AND to check if bit at given position is 1 or 0
		int last_bit{ n & 1 };

		// If 0 count will remain the same 
		count += last_bit;

		// Right shift to check another position.
		n = n >> 1;
	}

	return count;
}

int main()
{
	int n{ 9 };

	std::cout << count_bits(n) << std::endl;

	return 0;
}