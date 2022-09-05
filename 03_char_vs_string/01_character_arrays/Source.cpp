/*
 * Creating character arrays.
 * Character array stores list of characters.
 */

#include <iostream>


int main()
{
	// Declare a character array
	// data type is a char, then array name, and size of array
	char arr[10]; // declared char array for 10 elements

	// Initialization in different than initialization of int array
	// We need to remember to add a null character '\0'.
	// Otherwise during printing we will get some garbage data
	// For example:
	char wrong_array[]{ 'a', 'b', 'c' };
	// Characteer array can be printed directly using std::cout
	std::cout << wrong_array << std::endl;


	// Correct version (with null character at the end):
	char good_array[]{ 'a', 'b', 'c', '\0'};
	std::cout << good_array << std::endl;

	// We can also initialize char array using string literal, then we don't need
	// the null character as a last character.
	char better_version[]{ "abc" };
	std::cout << better_version << std::endl;

	return 0;
}