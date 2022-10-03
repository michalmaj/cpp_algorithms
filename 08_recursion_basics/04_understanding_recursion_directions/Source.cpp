#include <iostream>

/**
 * \brief Function to print numbers from n to 1.
 * \param n Number from which we want to start.
 */
void printDecreasing(int n)
{
	// Base case, we want to print values to 1
	if(n == 0)
		return;

	// First print, then use recursive function
	std::cout << n << std::endl;
	printDecreasing(n - 1);
}

/**
 * \brief Function to print numbers from 1 to n.
 * \param n Highest number we want to print.
 */
void printIncreasing(int n)
{
	// Base case, we want to print values from 1
	if (n == 0)
		return;

	// First call recursive function, then print.
	printIncreasing(n - 1);
	std::cout << n << std::endl;

}

int main()
{
	std::cout << "\nDecreasing order: \n";
	printDecreasing(5);

	std::cout << "\nIncreasing order: \n";
	printIncreasing(5);
	return 0;
}