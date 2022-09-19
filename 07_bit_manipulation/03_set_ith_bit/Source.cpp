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
	int mask{ 1 << i };
	n = (n | mask);
}

int main()
{
	int n = 5;
	int i;
	std::cout << "Enter which bit do you want to change: ";
	std::cin >> i;

	setIthBit(n, i);
	std::cout << "After set bit in index " << i << " we have: " << n << std::endl;

	return 0;
}