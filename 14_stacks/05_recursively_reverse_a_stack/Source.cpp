#include <iostream>
#include <stack>

template<typename T>
void insertAtBottom(std::stack<T>& s, T data)
{
	if (s.empty())
	{
		s.push(data);
		return;
	}

	// recursive case
	T temp = s.top();
	s.pop();

	insertAtBottom(s, data);

	s.push(temp);
}

template <typename T>
void reverse(std::stack<T>& s)
{
	if(s.empty())
		return;

	T temp = s.top();
	s.pop();

	reverse(s);

	insertAtBottom(s, temp);
	
}

int main()
{
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverse(s);

	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}