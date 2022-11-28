#include <iostream>

int wines(int dp[][10], int prices[], int L, int R, int y)
{
	// base case
	if (L > R)
		return 0;

	// need if a state is already computed
	if (dp[L][R] != 0)
		return dp[L][R];

	// recursive case
	int pick_left = y * prices[L] + wines(dp, prices, L + 1, R, y + 1);
	int pick_right = y * prices[R] + wines(dp, prices, L, R - 1, y + 1);

	return dp[L][R] = std::max(pick_right, pick_left);
}

int main()
{
	int a[]{ 2, 3, 5, 1, 4 };
	int n{ std::size(a)};
	int dp[10][10]{ 0 };


	std::cout << "Optimal solution: " << wines(dp, a, 0, n - 1, 1) << std::endl;

	std::cout << "\n==========================================\n\n";

	std::cout << "Show dp table:\n";

	for(int i{0}; i < n; ++i)
	{
		for(int j{0}; j < n; ++j)
		{
			std::cout << dp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}