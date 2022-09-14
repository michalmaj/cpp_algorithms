/*
 * This concept let's us pass objects by reference.
 * Pass-by-reference means to pass the reference of an argument in the calling function to
 * the corresponding formal parameter of the called function. The called function can modify
 * the value of the argument by using its reference passed in.
 */

#include <iostream>

void pass_by_copy(int x)
{
	x++; // increment x
	std::cout << "Variable value inside pass_by_copy: " << x << std::endl;
	std::cout << "Variable address inside pass_by_copy: " << &x << std::endl;
}

void pass_by_reference(int& x)
{
	x++; // increment x
	std::cout << "Variable value inside pass_by_reference: " << x << std::endl;
	std::cout << "Variable address inside pass_by_copy: " << &x << std::endl;
}

int main()
{
	// We create two variables 'a' and 'b'  both with the same value
	int a{ 5 };
	int b{ 5 };

	std::cout << "Value of a: " << a << std::endl;
	std::cout << "Address of a: " << &a << std::endl;

	std::cout << "Value of b: " << b << std::endl;
	std::cout << "Address of b: " << &b << std::endl;

	// Variable 'a' is sent as a copy
	pass_by_copy(a);

	// Variable 'b' is sent as a reference
	pass_by_reference(b);


	// Value of 'a' doesn't change, because in function we have a copy
	std::cout << "Value of a after function call: " << a << std::endl;

	// But value of 'b' changes, because in function we have the same
	// address as the original 'b'
	std::cout << "Value of b after function call: " << b << std::endl;


	return 0;
}