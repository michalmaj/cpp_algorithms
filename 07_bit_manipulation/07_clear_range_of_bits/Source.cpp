#include <iostream>
#include <bitset>

void clearBitsInRange(int& n, int i, int j)
{
	int a{ (~0) << (j + 1)};
	int b{ (1 << i) - 1 };

	std::cout << "a: " << std::bitset<8>(a) << std::endl;
	std::cout << "b: " << std::bitset<8>(b) << std::endl;
	int mask{ a | b };
	n = n & mask;

}

int main()
{
	int n = 31;
	int i{ 2 };
	int j{ 3 };

	clearBitsInRange(n, i, j);
	std::cout << "n " << std::bitset<8>(n) << ", with value: " << n << std::endl;

	return 0;
}