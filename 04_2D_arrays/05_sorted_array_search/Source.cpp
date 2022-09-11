/*
 * Write a function that search for an element in row wise and column wise sorted 2D array.
 */

#include <iostream>

template<size_t N, size_t M>
std::pair<int, int> staircaseSearch(int (&arr)[N][M], int n, int m, int key)
{
	// later if the element is not present return {-1, -1}
    if (key < arr[0][0] or key > arr[n - 1][m - 1])
        return { -1, -1 };

    // Staircase search
    int i{ 0 }; // starting from first row
    int j{ m - 1 }; // starting from last column

    while(i < n and j >= 0)
    {
        if (arr[i][j] == key)
            return { i, j };
        else if (arr[i][j] > key)
            j--;
        else
            i++;
    }
    return { -1, -1 };
}

int main()
{
    // 2D Row & Column Wise Sorted Array
    int arr[][4]
    {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };

    int n{ 4 }, m{ 4 };

    // Value to search
    int value{ 33 };

    auto [x, y] = staircaseSearch(arr, n, m, value);
    std::cout << "Index of " << value << " is: (" << x << "," << y << ")\n";

    return 0;
}