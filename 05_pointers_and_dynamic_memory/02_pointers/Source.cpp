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

	std::cout << "Address of pointer: " << &x_ptr << std::endl;

	// Pointer to the pointer
	int** x_pptr = &x_ptr;

	std::cout << "Address of x_ptr using a pointer to pointer: " << x_pptr << std::endl;

	return 0;
}