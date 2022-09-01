/*
 * Vector is a sequence container with dynamic size,
 * so size can be changed dynamically.
 * Just like arrays vectors use contiguous storage locations for elements.
 * Elements can be accessed in constant time O(1).
 * Unlike arrays, vectors are passed to a function by value.
 * So you have explicit pass by reference. 
 */

#include <iostream>
#include <vector>

int main()
{
	// declaration of a vector
	std::vector<int> vec;

	// size tells us how many elements inside
	std::cout << "Size of declared vector, without any values inside: "
		<< vec.size() << std::endl;

	// declaration vector and initialization
	std::vector<int> vec2{ 1, 2, 3, 4, 5 };
	std::cout << "Size of declared vector, with some values inside: "
		<< vec2.size() << std::endl;

	// we can also check capacity (how much memory is allocated)
	std::cout << "Memory allocated: " << vec2.capacity() << std::endl; // it's 5 right now

	// but if we add a new element to our vector (push_back() add element to the end
	// of our vector - this operation is O(1) time complexity)
	vec2.push_back(6);

	// so now our size is:
	std::cout << "Size of declared vector, with some values inside: "
		<< vec2.size() << std::endl;

	// and our capacity
	std::cout << "Memory allocated: " << vec2.capacity() << std::endl;

	// we can also print values from vector
	std::cout << "Vector contains: ";
	for (int i{}; i < vec2.size(); ++i)
		std::cout << vec2[i] << " ";
	std::cout << std::endl;

	// we can remove last element
	vec2.pop_back();

	// we can use a range based loop to print our container
	std::cout << "Vector after remove last element: ";
	for (const auto& e : vec2)
		std::cout << e << " ";
	std::cout << std::endl;

	// delete element from given index
	vec2.erase(vec2.begin() + 2); // delete item at index 2
	std::cout << "Vector after remove element at index 2: ";
	for (const auto& e : vec2)
		std::cout << e << " ";
	std::cout << std::endl;

	// insert a value at given index
	vec2.insert(vec2.begin() + 1, 99);
	std::cout << "Vector after add a new element at index 1: ";
	for (const auto& e : vec2)
		std::cout << e << " ";
	std::cout << std::endl;

	// we can also construct our vector with same numbers n times
	std::vector<int> vec3(10, 7); // it's a functional initialization
	std::cout << "Vector filled with one value many times: ";
	for (const auto& e : vec3)
		std::cout << e << " ";
	std::cout << std::endl;



	return 0;
}