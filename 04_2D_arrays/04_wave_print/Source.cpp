/*
 * Wave Print!
 * Given a matrix, print it in Reverse Wave Form.
 *
 * Input Format::
 * Given integer m (number of rows), integer n (number of columns) and 2d vector.
 *
 * Output Format:
 * Return a linear vector of integers in the required order.
 *
 * Examples:
 * Input :
 *		 1  2  3  4
 *		 5  6  7  8
 *		 9 10 11 12
 *		13 14 15 16
 *
 * Output :
 * 4 8 12 16 15 11 7 3 2 6 10 14 13 9 5 1
 */

#include <iostream>
#include <vector>

// For testing - overload std::ostream operator<< for vectors
template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	for (const auto v : vec)
		out << v << " ";
	return out;
}

// For testing print function for 2D vectors
template<class T>
void print(std::vector<std::vector<T>>& vec)
{
	for(const auto& v : vec)
	{
		std::cout << v << "";
	}
	std::cout << std::endl;
}

std::vector<int> WavePrint(int m, int n, std::vector<std::vector<int>> arr)
{
	// Create vector that will be returned
	std::vector<int> output;

	int startRow{ 0 };
	int endRow{ m - 1 };
	int startCol{ 0 };
	int endCol{ n - 1 };

	// Loop until end colmun is greater or equal to star column 
	while (startCol <= endCol)
	{
		// Start adding items to output vector from last column top-bottom,
		// then add items from one less column bottom-top, etc.

		// Top-Bottom
		for (int row{ startRow }; row <= endRow; ++row)
		{
			//std::cout << arr[row][endCol] << " "; // Testing purpose
			output.push_back(arr[row][endCol]);
		}

		// Remember after every column we need to decrement by one to move to
		// the left direction
		endCol--;

		// Bottom-Top
		for (int row{ endRow }; row >= startRow; --row)
		{
			//std::cout << arr[row][endCol] << " "; // Testing purpose
			output.push_back(arr[row][endCol]);
		}

		// Remember after every column we need to decrement by one to move to
		// the left direction
		endCol--;

	}
	
	return output;
}

int main()
{
	std::vector<std::vector<int>> matrix
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	};

	int m = matrix.size();
	int n = matrix[m - 1].size();

	auto res = WavePrint(m, n, matrix);
	std::cout << res << std::endl;

	return 0;
}