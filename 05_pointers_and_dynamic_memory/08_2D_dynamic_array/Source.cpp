#include <iostream>

// 2D Dynamic Array
// We need to allocate each row (treat them as separate 1D array
int** create2DArray(int rows, int cols)
{
	// We are create array of pointers
	// Each pointer inside will be a pointer to 1D array
	int** arr = new int* [rows];

	// Allocate memory for each row
	for(int i{0}; i < rows; ++i)
	{
		arr[i] = new int[cols];
	}

	// Initialize the array with increasing list of numbers
	int value{ 0 };
	for(int i{0}; i < rows; ++i)
	{
		for (int j{ 0 }; j < cols; ++j)
			arr[i][j] = value++;
	}

	return arr;
}

int main()
{
	int rows;
	int cols;
	std::cout << "Enter how big 2D array you want: ";
	std::cin >> rows >> cols;

	int** arr = create2DArray(rows, cols);

	for (int i{ 0 }; i < rows; ++i)
	{
		for (int j{ 0 }; j < cols; ++j)
			std::cout << arr[i][j] << " ";
		std::cout << std::endl;
	}

	for (int i = 0; i < rows; i++) 
	{
		delete[] arr[i];
	}

	delete[] arr;
	arr = nullptr;

	return 0;
}