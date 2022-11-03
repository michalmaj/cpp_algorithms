#pragma once

template<typename T>
class Queue
{
	T* arr;
	int current_size;
	int max_size;

	int front;
	int rear;

public:
	Queue(int default_size = 5)
	{
		max_size = default_size;
		arr = new T[max_size];
		current_size = 0;
		front = 0;
		rear = max_size - 1;
	}

	~Queue()
	{
		delete[] arr;
	}

	bool full()
	{
		return current_size == max_size;
	}

	bool empty()
	{
		return current_size == 0;
	}

	void push(T data)
	{
		if(!full())
		{
			// take the rear to the next index
			rear = (rear + 1) % max_size;
			arr[rear] = data;
			current_size++;
		}
	}

	void pop()
	{
		if(!empty())
		{
			// take the front pointer forward
			front = (front + 1) % max_size;
			current_size--;
		}
	}

	T getFront()
	{
		return arr[front];
	}

};