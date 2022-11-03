#include <iostream>
#include "queue.h"


int main()
{
	Queue<int> q{ 7 };

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);

	q.pop();
	q.pop();

	q.push(9);

	while (!q.empty())
	{
		std::cout << q.getFront() << std::endl;
		q.pop();
	}

	return 0;
}