#include <iostream>
#include "list.h"



int main()
{
	List<int> l;
	l.push_front(1);
	l.push_back(2);

	Node<int>* head = l.begin();
	while (head != nullptr)
	{
		std::cout << head->getData() << "->";
		head = head->getNext();
	}


	return 0;
}