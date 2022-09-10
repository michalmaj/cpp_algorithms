/*
 * Spiral print
 * Write a function that takes in NxM 2D array, and prints the all array elements in a
 * spiral order. Start from top left corner goes to the right, proceeds in a spiral pattern
 * until every element is visited.
 *
 * Input:
 *		 1  2  3  4
 *		 5  6  7  8
 *		 9 10 11 12
 *		13 14 15 16
 * Output:
 *		 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 */

#include <iostream>

template<size_t N, size_t M>
std::pair<size_t, size_t> shape(int (&arr)[N][M])
{
	return std::make_pair(N, M);
}

template<size_t N, size_t M>
void print(int (&arr)[N][M], size_t n, size_t m)
{
	// Create four variables to store directions
	int startRow{ 0 };
	int endRow{static_cast<int>(n) - 1 };
	int startCol{ 0 };
	int endCol{ static_cast<int>(m) - 1 };

	// Outer loop (traverse array boundary)
	while(startCol <= endCol and startRow <= endRow)
	{
		// Start Row
		for(int col{startCol}; col <= endCol; ++col)
		{
			std::cout << arr[startRow][col] << " ";
		}

		// End Col
		for(int row{startRow + 1}; row <= endRow; ++row)
		{
			std::cout << arr[row][endCol] << " ";
		}

		// End Row
		for(int col{endCol - 1}; col >= startCol; --col)
		{
			// Avoid duplicate printing of elements
			if(startRow == endRow)
				break;
			std::cout << arr[endRow][col] << " ";
		}

		// Start Col
		for(int row{endRow - 1}; row >= startRow + 1; --row)
		{
			// Avoid duplicate printing of elements
			if(startCol == endCol)
				break;
			std::cout << arr[row][startCol] << " ";
		}

		// Update the variables to point to inner spiral
		startRow++;
		endRow--;
		startCol++;
		endCol--;
	}
}

int main()
{
	int arr[][4]
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	};

	auto [rows, cols] = shape(arr);
	std::cout << "Number of rows: " << rows << ", number of columns: "
		<< cols << std::endl;

	print(arr, rows, cols);


	return 0;
}