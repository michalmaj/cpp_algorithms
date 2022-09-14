/*
 * the dereference operator or indirection operator, sometimes denoted by "*"
 * (i.e. an asterisk), is a unary operator (i.e. one with a single operand) found in C-like
 * languages that include pointer variables. It operates on a pointer variable, and returns
 * an l-value equivalent to the value at the pointer address.
 */

#include <iostream>

int main()
{
	// Address
	int x = 10;
	float y{ 5.5 };

	std::cout << "Address of x: " << &x << std::endl;
	std::cout << "Address of y: " << &y << std::endl;

	std::cout << "\n===============================================\n" << std::endl;

	// Pointer
	int* x_ptr = &x;

	std::cout << "Address of x using a pointer: " << x_ptr << std::endl;
	std::cout << "Address of pointer: " << &x_ptr << std::endl;

	std::cout << "\n===============================================\n" << std::endl;

	// Pointer to the pointer
	int** x_pptr = &x_ptr;

	std::cout << "Address of x_ptr using a pointer to pointer: " << x_pptr << std::endl;

	std::cout << "\n===============================================\n" << std::endl;

	// Dereference
	std::cout << "Address of x: " << &x << std::endl;
	std::cout << "Address of x as a value holds by x_ptr: " << x_ptr << std::endl;
	std::cout << "Dereference x_pptr (pointer to pointer), we can see address stored in x_ptr: "
		<< *x_pptr << std::endl;

	std::cout << std::endl; 

	// We can also show values
	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Value of x as a value holds by x_ptr: " << *x_ptr << std::endl;
	std::cout << "Dereference x_pptr (pointer to pointer), we can see value stored in x_ptr: "
		<< **x_pptr << std::endl;

	return 0;
}