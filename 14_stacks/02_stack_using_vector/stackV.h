#pragma once
#include <vector>


template <typename T>
class Stack
{
	std::vector<T> arr;

public:
	void push(T data)
	{
		arr.push_back(data);
	}

	void pop()
	{
		arr.pop_back();
	}

	T top()
	{
		return arr.back();
	}

	bool empty()
	{
		return arr.empty();
	}
};