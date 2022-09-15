/*
 * std::vector
 *	1) std::vector is a sequence container that encapsulates dynamic size arrays.
 *	2) std::pmr::vector is an alias template that uses a polymorphic allocator.
 *
 * The elements are stored contiguously, which means that elements can be accessed not only
 * through iterators, but also using offsets to regular pointers to elements. This means
 * that a pointer to an element of a vector may be passed to any function that expects a
 * pointer to an element of an array.
 */

#include <iostream>
#include <vector>

//We can use std::ostream to use std::cout for printing our vector
template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	for (const auto& e : vec)
		out << e << " ";
	return out;
}

int main()
{
	// declaration, and implementation
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6 };

	// printing our vector
	std::cout << vec << std::endl;
	return 0;
}