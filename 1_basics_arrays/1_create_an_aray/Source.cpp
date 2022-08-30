#include <iostream>


int main()
{
	// array for 100 students - all values initialized to 0 
	int marks[100]{};

	int n{};
	std::cout << "Enter number of students: ";
	std::cin >> n;

	// assign a value for index 0
	marks[0] = -1;

	// input
	for(int i{1}; i <= n; ++i)
	{
		std::cout << "Enter " << i << " mark: ";
		std::cin >> marks[i];
		// update the value - in this case multiply by 2
		marks[i] = marks[i] * 2;
	}

	std::cout << std::endl;

	// output
	for(int i{0}; i < 100; ++i)
	{
		std::cout << marks[i] << ", ";
	}
	std::cout << std::endl;

	return 0;
}