#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Heap
{
	std::vector<T> v;

public:
	Heap(int default_size = 10)
	{
		v.reserve(default_size + 1);
		v.push_back(-1);
	}

	void push(T data)
	{
		// add data to end of th heap
		v.push_back(data);
		size_t index = v.size() - 1;
		size_t parent = index / 2;

		while (index > 1 and v.at(index) < v.at(parent))
		{
			std::swap(v.at(index), v.at(parent));
			index = parent;
			parent = parent / 2; 
		}
	}

	void print() const
	{
		for (size_t i{1}; i < v.size(); ++i)
			std::cout << v.at(i) << " ";
		std::cout << std::endl;
	}
};