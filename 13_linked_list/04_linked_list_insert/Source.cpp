#include <iostream>
#include "list.h"



int main()
{
	List<int> l;
	l.push_front(0);
	l.push_back(1);
	l.push_back(3);
	l.push_back(4);

	l.insert(2, 2);
	l.insert(10, 0);

	//Node<int>* head = l.begin();
	//while (head != nullptr)
	//{
	//	std::cout << head->getData() << "->";
	//	head = head->getNext();
	//}

	// second option
	l.print();


	return 0;
}