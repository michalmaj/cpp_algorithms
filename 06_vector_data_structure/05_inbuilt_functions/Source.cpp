/*
 * The Standard Template Library (STL) is a set of C++ template classes to provide common
 * programming data structures and functions such as lists, stacks, arrays, etc. It is a
 * library of container classes, algorithms, and iterators.
 *
 * STL has 4 components:
 *	- Algorithms
 *	- Containers
 *	- Functions
 *	- Iterators
 *
 * Example using in this program:
 * std::find
 * Returns an iterator to the first element in the range [first,last) that compares equal to
 * val. If no such element is found, the function returns last.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

	std::vector<int> arr{ 10, 11, 2, 3, 4, 6,7, 8 };
	int key{ 11 };

	// Search for item in given array and return an iterator
	std::vector<int>::iterator it = std::find(arr.begin(), arr.end(), key);

	// If we found our item (check if iterator doesn't point to the place after last element)
	if (it != arr.end())
		// To show index of searching item we need to subtract arr.begin() from given iterator
		std::cout << "Index of " << key << ": " << (it - arr.begin()) << std::endl;
	else
		std::cout << "Item not found!" << std::endl;



	return 0;
}