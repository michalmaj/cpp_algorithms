#include <iostream>

int main()
{
	// Address
	int x = 10;
	float y{ 5.5 };

	std::cout << "Address of x: " << &x << std::endl;
	std::cout << "Address of y: " << &y << std::endl;

	// Pointer
	int* x_ptr = &x;

	std::cout << "Address of x using a pointer: " << x_ptr << std::endl;


	return 0;
}