/*
 * Implement a Stack class, which uses 2 Queues internally as a data structure.
 * Make LIFO data structure using FIFO data structure
 */

#include <iostream>
#include <queue>

template <typename T>
class Stack
{
	std::queue<T> q1, q2;

public:
	void push(T data)
	{
		// Insert data into non-empty queue 
		if (!q1.empty())
			q1.push(data);
		else
			q2.push(data);
	}

	void pop()
	{
		if(q1.empty())
		{
			// Shift elements from q2 to q1
			while(!q2.empty())
			{
				int front = q2.front();
				q2.pop();
				if(q2.empty())
					break;
				q1.push(front);
			}
		}
		else
		{
			// Shift elements from q1 to q2
			while (!q1.empty())
			{
				int front = q1.front();
				q1.pop();
				if(q1.empty())
					break;
				q2.push(front);
			}
		}
	}

	T top()
	{
		if (q1.empty())
		{
			// Shift elements from q2 to q1
			while (!q2.empty())
			{
				int front = q2.front();
				q2.pop();
				q1.push(front);
				if (q2.empty())
					return front;
			}
		}
		else
		{
			// Shift elements from q1 to q2
			while (!q1.empty())
			{
				int front = q1.front();
				q1.pop();
				q2.push(front);
				if (q1.empty())
					return front;
			}
		}
	}

	bool empty()
	{
		return (q1.empty() and q2.empty());
	}
};

int main()
{
	Stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}