/*
 * Make Zeroes
 * Given a two-dimensional array, if any element within is zero, make its whole row and
 * column zero.
 *
 * Input Format:
 * In the function a 2d vector is passed.
 *
 * Output Format:
 * Return the updated 2d vector.
 *
 * Sample Input:
 * { {5, 4, 3, 9}, {2, 0, 7, 6}, {1, 3, 4, 0}, {9, 8, 3, 4} }
 *
 * Sample Output
 * { {5, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {9, 0, 3, 0} }
 */

#include <iostream>
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	for (const auto& e : vec)
		out << e << " ";
	return out;
}

void zero_row(std::vector<std::vector<int>>& vec, size_t row)
{
	for (size_t i{ 0 }; i < vec.size(); ++i)
		vec[row][i] = 0;
}

void zero_col(std::vector<std::vector<int>>& vec, size_t col)
{
	for (size_t i{ 0 }; i < vec[0].size(); ++i)
		vec[i][col] = 0;
}

std::vector<std::vector<int>> makeZeroes(std::vector<std::vector<int>> arr)
{
	std::vector<std::vector<int>> output = arr;

	for(size_t r{0}; r < arr.size(); ++r)
	{
		for(size_t c{0}; c < arr[r].size(); ++c)
		{
			if (arr[r][c] == 0)
			{
				zero_row(output, r);
				zero_col(output, c);
			}
		}
	}

	return output;
}

int main()
{
	std::vector<std::vector<int>> arr
	{
		{5, 4, 3, 9},
		{2, 0, 7, 6},
		{1, 3, 4, 0},
		{9, 8, 3, 4}
	};


	auto result = makeZeroes(arr);

	for (const auto& e : result)
	{
		std::cout << e << std::endl;
	}
	std::cout << std::endl;
	return 0;
}