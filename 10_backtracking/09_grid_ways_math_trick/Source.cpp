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

// Calculate factorial
int fac(int n)
{
	return (n == 0) || (n == 1) ? 1 : n * fac(n - 1);
}

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
	//tex:
	// Formula 1: $$\frac{(m - 1 + n - 1}{(Bb)}$$
	int ans = (fac(m - 1 + n - 1) / (fac(m - 1) * fac(n - 1)));
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