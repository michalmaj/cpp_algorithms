#pragma once

#include <iostream>

template<class T>
class Vector
{
private:
	// Data members
	T* arr;
	int current_size;
	int max_size;

public:
	// Constructor
	Vector()
	{
		current_size = 0;
		max_size = 1;
		arr = new T[max_size];
	}

	// Methods
	void push_back(T data)
	{
		// Two cases
	}

	
};