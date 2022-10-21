/*
 * Grid Paths
 * Given a MxN grid, find the number of ways to reach the bottom right corner starting
 * from top left. At each cell you can move right or down.
 *
 * Input
 * 2D matrix
 *
 * Output
 * Integer denoting the number of ways.
 */

#include <iostream>

/**
 * \brief Function  to check how many possible ways to reach (m,n) from (i, j)
 * \param i Starting point (row)
 * \param j Starting point (column)
 * \param m Ending point (row)
 * \param n Ending point (column)
 * \return Sum of ways.
 */
int gridWays(int i, int j, int m, int n)
{
	if (i == m - 1 and j == n - 1)
		return 1;

	if (j >= n or i >= m)
		return 0;

	int ans = gridWays(i + 1, j, m, n) + gridWays(i, j + 1, m, n);
	return ans;
}

int main()
{
	int m, n;

	std::cout << "Enter how big grid do you want (MxN): ";
	std::cin >> m >> n;

	std::cout << gridWays(0, 0, m, n) << std::endl;;

	return 0;
}