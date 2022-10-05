#include <iostream>

/**
 * \brief Recursive function for power a^n.
 * \param a Base.
 * \param n Exponent.
 * \return Result of exponentiation.
 */
long  int powerOptimized(long int a, int n)
{
	// base case
	// for any number (except 0) powerOptimised of 0 is 1
	if (n == 0)
		return 1;


	// It will be:
	//tex:
	// \begin{aligned}(a^{n/2})^2\\\end{aligned}
	int sub_prob = powerOptimized(a, n / 2); // Here we are calculating parentheses
	int sub_prob_sq = sub_prob * sub_prob; // Here power of 2

	// Bitwise check if n is odd
	if (n & 1)
		return a * sub_prob_sq; // For odd exponent we have to multiply by a

	return sub_prob_sq;
}

int main()
{
	long int a = 2;
	int n = 10;

	std::cout << powerOptimized(a, n) << std::endl;

	return 0;
}