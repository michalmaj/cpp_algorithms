// The Fibonacci numbers may be defined by the recurrence relation:
//tex:
// \begin{aligned}F_{0}=0, F_{1}=1\\\end{aligned}
// \begin{aligned}and\\\end{aligned}
// \begin{aligned}F_{n}=F_{n-1}+F_{n-2}\\\end{aligned}
// \begin{aligned}for\ n > 1\\\end{aligned}


#include <iostream>

int fib(int n)
{
	// check if our n is 0 or 1, if yes return it
	if (n == 0 or n == 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

int main()
{
	auto result = fib(7);
	std::cout << "Fibonacci = " << result << std::endl;
	return 0;
}