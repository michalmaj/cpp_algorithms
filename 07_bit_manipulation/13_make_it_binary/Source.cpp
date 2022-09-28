#include <iostream>

int convertToBinary(int n)
{
	int ans{ 0 };
	int p{ 1 };
	while (n > 0)
	{
		int last_bit{ n & 1 };
		ans += p * last_bit;

		p *= 10;
		n = n >> 1;
	}

	return ans;
}

int main()
{
	int n{ 9 };

	std::cout << convertToBinary(n) << std::endl;

	return 0;
}