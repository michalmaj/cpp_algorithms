/*
 * In mathematics, the factorial of a non-negative integer n, denoted by n!, is the product of all
 * positive integers less than or equal to n. The factorial of n also equals the product of n with
 * the next smaller factorial:
*/
 //tex:
// \begin{aligned}n!&=n\times (n-1)\times (n-2)\times (n-3)\times \cdots \times 3\times 2\times 1=n\times (n-1)!\\\end{aligned}

#include <iostream>

int fact(int n)
{
	// base case
	if (n == 0)
		return 1;

	// recursive case
	return n * fact(n - 1);
}

int main()
{
	auto result = fact(3);
	std::cout << "Factorial = " << result << std::endl;

	return 0;
}
