#include <iostream>
#include "stackV.h"

int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(5);
	s.push(10);

	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}


	return 0;
}