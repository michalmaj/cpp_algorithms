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
	Vector(int max_size=1)
	{
		current_size = 0;
		this->max_size = max_size;
		arr = new T[max_size];
	}

	// Destructor
	~Vector()
	{
		delete[] arr;
	}

	// Methods
	void push_back(T data)
	{
		// Two cases
		if(current_size == max_size)
		{
			// create a new array and delete the old one, double the capacity
			T* old_arr = arr;
			max_size *= 2;
			arr = new T[max_size];
			for (int i{ 0 }; i < current_size; ++i)
				arr[i] = old_arr[i];

			delete[] old_arr;
		}
		arr[current_size++] = data;
	}

	void pop_back()
	{
		if(current_size > 0)
			current_size--;
	}

	bool is_empty() const
	{
		return current_size == 0;
	}

	// Front, back, at(i)
	T front() const
	{
		return arr[0];
	}

	T back() const
	{
		return arr[current_size - 1];
	}

	T at(int idx) const
	{
		return arr[idx];
	}

	int size() const
	{
		return current_size;
	}

	int capacity () const
	{
		return max_size;
	}

	// Overload operator[]
	T operator[](int i) const
	{
		return arr[i];
	}
	
};