#include <iostream>
#include <stack>
#include <algorithm>

int reverse(int n)
{
	int output{ 0 };
	std::stack<int> temp;
	std::stack<int> swap;

	while(n > 0)
	{
		temp.push(n % 10);
		n /= 10;
	}

	while(!temp.empty())
	{
		swap.push(temp.top());
		temp.pop();
	}

	while(true)
	{
		output += swap.top();
		swap.pop();
		if(swap.empty())
			break;
		output *= 10;
	}
	

	return output;
}

int main()
{
	int n{ 456 };

	auto res = reverse(n);

	std::cout << res << std::endl;

	return 0;
}
