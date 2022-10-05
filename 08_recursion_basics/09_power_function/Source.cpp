#include <iostream>

/**
 * \brief Recursive function for power a^n.
 * \param a Base.
 * \param n Exponent.
 * \return Result of exponentiation.
 */
long  int power(long int a, int n)
{
	// base case
	// for any number (except 0) power of 0 is 1
	if (n == 0)
		return 1;
	return a * power(a, n - 1);
}

int main()
{
	long int a = 2;
	int n = 10;

	std::cout << power(a, n) << std::endl;

	return 0;
}