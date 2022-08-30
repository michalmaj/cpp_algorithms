#include <iostream>

// This is an example of function for print an array.
// In this example array has an integer type.
// In this case our responsibility is to pass as a parameter a size of an array
void print_array(int arr[], int n_size)
{
	// Size of the array will be unknown, because in this function we have only
	// the address of the array. So the output will be 8 bytes, because a pointer has 8 bytes
	std::cout << "In function: n_size of array: " << sizeof(arr) << std::endl;
	for(int i{0}; i < n_size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// This is an example of generic function (thanks to templates).
// In this case array can by any type.
// We don't need to provide a size of an array.
template <class T, size_t N>
auto print_array(T (&arr)[N]) -> void
{
	// Using this trick (template + size_t) we have access to size of an array.
	std::cout << "In function: size of array: " << sizeof(arr) << std::endl;

	// Example of range-based for loop
	for(const auto& e: arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	// calculate number of elements inside an array
	//// old version - divide size of the object by first item in collection
	//int n = sizeof(arr) / sizeof(arr[0]);

	//// it's possible to use type of array in denominator instead of first item
	/// but still the std::size is a better choice
	//int n = sizeof(arr) / sizeof(int);

	// new better version using std::size, it's calculate array size for us
	int n = std::size(arr);

	// size of array will be known in main, because our array is inside main function
	std::cout << "In main: size of array: " << sizeof(arr) << std::endl;
	print_array(arr); // add second parameter, size, to get result of first function

	return 0;
}