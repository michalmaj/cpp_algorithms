#include <iostream>
#include <vector>

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	for (const auto& e : vec)
		out << e << " ";
	return out;
}

int main()
{
	// Without any declaration newly crated vector will have 0 size and 0 capacity
	std::vector<int> arr1;

	// Size of the vector
	std::cout << "arr1 size: " << arr1.size() << std::endl;

	// Capacity of the vector
	std::cout << "arr1 capacity: " << arr1.capacity() << std::endl;

	// With initialization with 5 elements vector will have 5 size and 5 capacity
	std::vector<int> arr2{1, 2, 10, 12, 15};

	// Size of the vector
	std::cout << "arr2 size: " << arr2.size() << std::endl;

	// Capacity of the vector
	std::cout << "arr2 capacity: " << arr2.capacity() << std::endl;

	// Add new element at the end
	arr2.push_back(16);

	// Size of the vector
	std::cout << "arr2 size after push_back: " << arr2.size() << std::endl;

	// Capacity of the vector
	std::cout << "arr2 capacity after push_back: " << arr2.capacity() << std::endl;

	// Remove last element
	arr2.pop_back();

	// Size of the vector
	std::cout << "arr2 size after pop_back: " << arr2.size() << std::endl;

	// Capacity of the vector
	std::cout << "arr2 capacity after pop_back: " << arr2.capacity() << std::endl;

	// Insert new element into given index (in this case index 1)
	arr2.insert(arr2.begin() + 1, 99);

	std::cout << "Vector after operations: " << arr2 << std::endl;

	// Size of the vector
	std::cout << "arr2 size after insertion: " << arr2.size() << std::endl;

	// Capacity of the vector
	std::cout << "arr2 capacity after insertion: " << arr2.capacity() << std::endl;

	// We can fill our vector with fill constructor (number of items and value)
	// In this case our vector contains 10 elements, every element is equal to 7
	std::vector<int> arr3(10, 7);
	std::cout << "Filled vector: " << arr3 << std::endl;

	return 0;
}