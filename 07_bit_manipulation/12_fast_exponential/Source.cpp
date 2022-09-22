#include <iostream>

// Fast Exponential
int fast_exponential(int a, int n)
{
	int ans{ 1 };

	while(n > 0)
	{
		int last_bit{ n & 1 };
		if (last_bit)
			ans *= a;
		a *= a;
		n = n >> 1;
	}
	return ans;
}

int main()
{
	int a{ 3 };
	int n{ 5 };

	std::cout << fast_exponential(a, n) << std::endl;

	return 0;
}