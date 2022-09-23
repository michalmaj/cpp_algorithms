/*
 * In C++, bitwise operators perform operations on integer data at the individual bit-level.
 * These operations include testing, setting, or shifting the actual bits.
 *
 *		Operator		Description
 *			&		Bitwise AND Operator
 *			|		Bitwise OR Operator
 *			^		Bitwise XOR Operator
 *			~		Bitwise Complement Operator
 *			<<		Bitwise Shift Left Operator
 *			>>		Bitwise Shift Right Operator
 */

#include <iostream>
#include <bitset>

int main()
{
	// Bitwise check if number is even or odd. Any number in binary is odd if last
	// bit is 1. Otherwise the number will be even. For example:
	// 00000001 = 1; 000000010 = 2; 000000011 = 3; 000000100 = 4
	// So to check if number is even or odd we can use & operator with 1

	int x;
	std::cout << "Enter the number to check if is even or odd: ";
	std::cin >> x;

	std::cout << "Number x in binary: " << std::bitset<8>(x) << std::endl;
	std::cout << "Number 1 in binary: " << std::bitset<8>(1) << std::endl;

	if (x & 1)
		std::cout << "Number is odd\n";
	else
		std::cout << "Number is even\n";

	return 0;
}