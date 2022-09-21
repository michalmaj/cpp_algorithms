#include <iostream>
#include <bitset>

int count_bits(int n)
{
	int count{ 0 };
	while (n > 0)
	{
		int last_bit{ n & 1 };
		count += last_bit;
		n = n >> 1;
	}

	return count;
}

int count_bits_hack(int n)
{
	int ans{ 0 };
	while( n > 0)
	{
		std::cout << "n: " << std::bitset<8>(n) << std::endl;
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

int main()
{
	int n{ 9 };

	std::cout << count_bits_hack(n) << std::endl;

	return 0;
}