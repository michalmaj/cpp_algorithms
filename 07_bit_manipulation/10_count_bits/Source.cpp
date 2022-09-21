#include <iostream>

int count_bits(int n)
{
	int count{ 0 };
	while(n > 0)
	{
		int last_bit{ n & 1 };
		count += last_bit;
		n = n >> 1;
	}

	return count;
}

int main()
{
	int n{ 9 };

	std::cout << count_bits(n) << std::endl;

	return 0;
}