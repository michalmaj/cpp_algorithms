/*
 * Creating character arrays.
 * Character array stores list of characters.
 */

#include <iostream>
#include <cstring> // Header which contains strlen:
				   // Returns the length of the given byte string, that is,
				   // the number of characters in a character array whose first element
				   // is pointed to by str up to and not including the first null character.
				   // The behavior is undefined if there is no null character in the
				   // character array pointed to by str.


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

	// Some functions we can use
	char letters[]{ "abcdefghi" };
	std::cout << letters << std::endl;

	std::cout << "Number of visible elements: " << strlen(letters) << std::endl;
	std::cout << "Number of elements (include null character): "
		<< sizeof(letters) << std::endl;

	// To read characters into character array using we can use std::cin.
	// We don't need to use a for loop (like with the std::cout).
	// But there is a pitfall - we can't use a space.
	char test[100];
	std::cin >> test;

	std::cout << test << std::endl;


	return 0;
}