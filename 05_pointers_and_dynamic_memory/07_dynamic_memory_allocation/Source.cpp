/*
 * Dynamic memory allocation in C/C++ refers to performing memory allocation manually by a
 * programmer. Dynamically allocated memory is allocated on Heap, and non-static and local
 * variables get memory allocated on Stack.
 *
 * new:
 * The new operator denotes a request for memory allocation on the Free Store. If sufficient
 * memory is available, a new operator initializes the memory and returns the address of the
 * newly allocated and initialized memory to the pointer variable.
 *
 * delete:
 * Since it is the programmer’s responsibility to deallocate dynamically allocated memory,
 * programmers are provided delete operator in C++ language. 
 */

#include <iostream>

int main()
{
	int n;
	std::cout << "How big array do you want to create?: ";
	std::cin >> n;

	// Dynamic array
	int* arr = new int[n];

	for(int i{0}; i < n; ++i)
	{
		std::cout << "Enter " << i + 1 << " element to array: ";
		std::cin >> arr[i];
	}

	std::cout << "Our array contains: ";
	for(int i{0}; i < n; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// Delete array (clean up)
	delete[] arr;
	arr = nullptr;

	return 0;
}