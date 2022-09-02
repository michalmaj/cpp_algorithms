/*
 * Given an integer vector and a value k, your task is to rotate the array k times clockwise.
 * Input Format:
 *		In the function an integer vector and number k is passed.
 * Output Format:
 *		Return an integer vector.
 * Sample Input:
 *		{1, 3, 5, 7, 9}, x = 2
 * Sample Output:
 *		{7, 9, 1, 3, 5}
 * Explanation:
 *		After 1st rotation - {9, 1, 3, 5, 7}
 *		After 2nd rotation - {7, 9, 1, 3, 5}
 */

#include <iostream>
#include <vector>

std::vector<int> kRotate(std::vector<int> a, int k)
{
    int val = k % a.size();
    int back{static_cast<int>(a.size() - 1) };
	std::vector<int> temp(a.size());
	int it{};

	for (int i{ val }; i < temp.size(); ++i)
		temp[i] = a[it++];
    while (val > 0)
    {
		temp[--val] = a[back--];
    }

	return temp;
}

int main()
{
	std::vector<int> v{ 1, 3, 5, 7, 9 };

	std::vector<int> res = kRotate(v, 7);

	for (auto e : res)
		std::cout << e << " ";
	std::cout << std::endl;
	return 0;
}