#include <iostream>

// Pass by reference
void apply_tax(float& income)
{
	constexpr float tax{ 0.1f };
	income -= income * tax;
}

int main()
{
	float income;
	std::cout << "Enter your income: ";
	std::cin >> income;

	apply_tax(income);

	std::cout << "Your income after tax: " << income << std::endl;

	return 0;
}