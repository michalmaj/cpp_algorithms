/*
 * There are two ways to store 2D array, because  in memory everything must be linearized.
 * So two common ways of storing the arrays:
 *		1) Row Major Form.
 *		2) Column Major Form.
 * For example, we have 2D array (3 rows x 4 columns):
 *
 *		{
 *			{8, 6, 5, 4},
 *			{2, 1, 9, 7},
 *			{3, 6, 4, 2}
 *		}
 *	In Row-Major will be stored as:
 *		8,6,5,5,2,1,9,7,3,6,4,2
 *	In Column-Major will be stored as:
 *		8,2,3,6,1,6,5,9,4,4,7,2 
 */
#include <iostream>

template <size_t N, size_t M>
void print(int (&arr)[N][M], int n, int m)
{
	for (int i{}; i < n; ++i)
	{
		for (int j{}; j < m; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	//Constrain
	int arr[100][100];

	// n rows, m columns
	int n, m;
	std::cout << "Eeter number of rows and columns: ";
	std::cin >> n >> m;

	for(int i{}; i < n; ++i)
	{
		std::cout << "Enter " << i << " row:" << std::endl;
		for(int j{}; j < m; ++j)
		{
			std::cin >> arr[i][j];
		}
	}
	print(arr, n, m);

	return 0;
}