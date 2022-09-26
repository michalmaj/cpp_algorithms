#include <iostream>
#include <bitset>

/**
 * \brief Count number of 1's bits in given number n.
 * \param n Number in which we want to count number of 1's bits.
 * \return Sum of 1's in given number n.
 */
int count_bits(int n)
{
	int count{ 0 };
	while (n > 0)
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

/**
 * \brief Count number of 1's bits in given number n.
 * \param n Number in which we want to count number of 1's bits.
 * \return Sum of 1's in given number n.
 */
int count_bits_hack(int n)
{
	int ans{ 0 };
	while( n > 0)
	{
		std::cout << "n: " << std::bitset<8>(n) << std::endl;
		std::cout << "n: " << std::bitset<8>(n - 1) << std::endl;

		// Remove last set bit (1) from the current number
		n = n & (n - 1);
		ans++;
		std::cout << std::endl;
	}
	return ans;
}

int main()
{
	int n{ 11 };

	std::cout << count_bits_hack(n) << std::endl;

	return 0;
}