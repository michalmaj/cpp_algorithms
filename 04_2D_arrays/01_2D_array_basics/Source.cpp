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