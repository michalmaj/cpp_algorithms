#include <iostream>
#include <stack>

void stockSpan(int* prices, int n, int* span)
{
	std::stack<int> s;
	s.push(0);
	span[0] = 1;

	// loop for rest of the days
	for(int i{1}; i < n; ++i)
	{
		int currentPrice = prices[i];
		// top most elemnt is higher than current prices
		while (!s.empty() and prices[s.top()] <= currentPrice)
		{
			s.pop();
		}

		if(!s.empty())
		{
			int prev_highest = s.top();
			span[i] = i - prev_highest;
		}
		else
		{
			span[i] = i + 1;
		}

		// push this elemet into the stack
		s.push(i);
	}
}

int main()
{
	int prices[]{100, 80, 60, 70, 60, 75, 85};
	int n{ sizeof(prices) / sizeof(int) };
	int span[10000]{ 0 };

	stockSpan(prices, n, span);

	for(int i{0}; i < n; ++i)
	{
		std::cout << span[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}