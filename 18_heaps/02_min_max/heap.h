#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Heap
{
	std::vector<T> v;
	std::string type;

	void heapify(size_t i)
	{
		size_t left = 2 * i;
		size_t right = 2 * i + 1;

		if(type == "min")
		{
			size_t minIdx = i;

			if(left < v.size() and v.at(left) < v.at(i))
			{
				minIdx = left;
			}
			if(right < v.size() and v.at(right) < v.at(minIdx))
			{
				minIdx = right;
			}

			if(minIdx != i)
			{
				std::swap(v.at(i), v.at(minIdx));
				heapify(minIdx);
			}
		}
		if(type == "max")
		{
			size_t maxIdx = i;

			if (left < v.size() and v.at(left) > v.at(i))
			{
				maxIdx = left;
			}
			if (right < v.size() and v.at(right) > v.at(maxIdx))
			{
				maxIdx = right;
			}

			if (maxIdx != i)
			{
				std::swap(v.at(i), v.at(maxIdx));
				heapify(maxIdx);
			}
		}
	}

public:
	Heap(int default_size = 10, std::string type="min")
	{
		v.reserve(default_size + 1);
		v.push_back(-1);
		this->type = type;
	}

	void push(T data)
	{
		// add data to end of th heap
		v.push_back(data);
		size_t index = v.size() - 1;
		size_t parent = index / 2;

		if(type == "min")
		{
			while (index > 1 and v.at(index) < v.at(parent))
			{
				std::swap(v.at(index), v.at(parent));
				index = parent;
				parent = parent / 2;
			}
		}
		if(type == "max")
		{
			while (index > 1 and v.at(index) > v.at(parent))
			{
				std::swap(v.at(index), v.at(parent));
				index = parent;
				parent = parent / 2;
			}
		}
	}

	// Return minimum element
	T top() const
	{
		return v.at(1);
	}

	// Remove minimum element
	void pop()
	{
		// 1. Swap first and last element
		size_t index = v.size() - 1;
		std::swap(v.at(1), v.at(index));
		v.pop_back();
		heapify(1);

	}

	bool empty() const
	{
		return v.size() == 1;
	}

	void print() const
	{
		for (size_t i{ 1 }; i < v.size(); ++i)
			std::cout << v.at(i) << " ";
		std::cout << std::endl;
	}
};