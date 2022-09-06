/*
 * We have some functions for C-style null-terminated byte strings
 *
 * // std::strlen:
 * Returns the length of the given byte string, that is, the number of characters in
 * a character array whose first element is pointed to by str up to and not including
 * the first null character. The behavior is undefined if there is no null character in
 * the character array pointed to by str.
 *
 * std::strcpy:
 * Copies the character string pointed to by src, including the null terminator, to the
 * character array whose first element is pointed to by dest.
 * The behavior is undefined if the dest array is not large enough. The behavior is
 * undefined if the strings overlap.
 *
 * std::strcmp:
 * Compares two null-terminated byte strings lexicographically.
 *
 * std::strcat:
 * Appends a copy of the character string pointed to by src to the end of the character
 * string pointed to by dest. The character src[0] replaces the null terminator at the
 * end of dest. The resulting byte string is null-terminated.\
 * The behavior is undefined if the destination array is not large enough for the
 * contents of both src and dest and the terminating null character.
 * The behavior is undefined if the strings overlap.
 */

#define _CRT_SECURE_NO_WARNINGS // directive - some compilers won't let us using std::strcpy

#include <iostream>
#include <cstring> //This header is for C-style null-terminated byte strings.

int main()
{
	char arr1[1000]{ "apple" };
	char arr2[1000];
	char arr3[1000]{ "orange" };

	std::cout << "Your character array contains: " << arr1 << std::endl;

	// std::strlen - calculate length
	std::cout << "Number of elements in arr1: " << std::strlen(arr1) << std::endl;

	// std::strcpy - copy elements from one array to another.
	// FIrst parameter is destination, second is the source.
	std::strcpy(arr2, arr1);
	std::cout << "arr2 after copy elements: " << arr2 << std::endl;

	// Compare C-style string lexicography.

	



	return 0;
}