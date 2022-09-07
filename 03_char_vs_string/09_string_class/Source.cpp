/*
 * The C++ strings library includes support for three general types of strings::
 *		1) std::basic_string - a templated class designed to manipulate strings of any
 *		   character type.
 *		2) std::basic_string_view (C++17) - a lightweight non-owning read-only view into a
 *		   subsequence of a string.
 *		3) Null-terminated strings - arrays of characters terminated by a special null character.
 */

#include <iostream>
#include <string> // Header for std::getline()
#include <vector>

// Overload std::ostream for vector
template<class T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vec)
{
	for (const auto& e : vec)
		out << e << " ";
	return out;
}

int main()
{
	std::string str{ "Hello World" }; // In memory it is a dynamic array.
	std::cout << "Our created string: " << str << std::endl;

	// We can also read the string:
	std::getline(std::cin, str);
	std::cout << "Our read string: " << str << std::endl;

	// If we want we can change the way to terminate input
	std::getline(std::cin, str, '#'); // Read until '#'
	std::cout << "Our read string: " << str << std::endl;

	// Loop for characters in string
	for(const auto& e : str)
		std::cout << e << ",";
	std::cout << std::endl;

	// Create a vector of strings
	int number_of_strings{ 5 };
	std::vector<std::string> str_vec;
	while (number_of_strings--)
	{
		std::string temp;
		std::getline(std::cin, temp);
		str_vec.push_back(temp);
	}

	std::cout << str_vec << std::endl;


	return 0;
}