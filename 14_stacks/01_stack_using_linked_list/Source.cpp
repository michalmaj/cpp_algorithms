#include <iostream>
#include "stackLL.h"

int main()
{
	Stack<char> s;
	s.push('h');
	s.push('e');
	s.push('l');
	s.push('l');
	s.push('o');

	while(!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}