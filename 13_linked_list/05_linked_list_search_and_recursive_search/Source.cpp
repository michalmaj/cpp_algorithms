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

	l.print();

	std::cout << "Item is present at index: " << l.search(3) << std::endl;
	std::cout << "Item is present at index: " << l.recursiveSearch(3) << std::endl;


	return 0;
}