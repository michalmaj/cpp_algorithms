#include <iostream>
#include "heap.h"

int main()
{
	Heap<int> h{10, "max"};

	h.push(10);
	h.push(20);
	h.push(30);
	h.push(25);
	h.push(40);
	h.push(5);
	h.print();

	std::cout << h.top() << std::endl;
	h.pop();
	h.print();

	return 0;
}