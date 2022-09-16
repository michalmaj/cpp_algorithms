#include "Vector.h"

int main()
{
	// Build a vector with base capacity of 5
	Vector<int> v(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.pop_back();

	std::cout << "Size of our vector: " << v.size() << std::endl;
	std::cout << "Capacity of our vector: " << v.capacity() << std::endl;

	std::cout << "First element in our vector: " << v.front() << std::endl;
	std::cout << "Last element in our vector: " << v.back() << std::endl;
	std::cout << "Element at index 2 in our vector: " << v.at(2) << std::endl;

	// Print all elements in our vector
	for (int i{ 0 }; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	return 0;
}
