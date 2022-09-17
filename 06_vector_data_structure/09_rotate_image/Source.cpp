/*
 * Rotate Image
 * You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees
 * (clockwise).
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix
 * directly. DO NOT allocate another 2D matrix and do the rotation.
 *
 * Sample Input:
 * matrix = [[1,2,3],[4,5,6],[7,8,9]]
 *
 * Sample Output:
 * [[7,4,1],[8,5,2],[9,6,3]]
 */

#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	for (const auto& e : vec)
		out << e << " ";
	return out;
}

void rotate(std::vector<std::vector<int> >& matrix)
{

	std::reverse(matrix.begin(), matrix.end());

	int size = matrix.size();

	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}
}

int main()
{
	std::vector<std::vector<int>> mat
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	rotate(mat);

	for(const auto& e : mat)
	{
		std::cout << e << std::endl;
	}
	std::cout << std::endl;

	return 0;
}