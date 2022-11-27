#include <iostream>
#include <vector>

// recursive code
int knapsack(int wts[], int prices[], int N, int W)
{
	// base case
	if (N == 0 or W == 0)
		return 0;

	// recursive case
	int inc{ 0 };
	int exc{ 0 };
	if(wts[N-1] <= W)
	{
		inc = prices[N - 1] + knapsack(wts, prices, N - 1, W - wts[N - 1]);
	}
	exc = knapsack(wts, prices, N - 1, W);
	return std::max(inc, exc);
}

// bottom up
int knapsackDP(int wt[], int price[], int N, int W)
{
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));

	for(int n{1}; n <= N; ++n)
	{
		for(int w{1}; w <= W; ++w)
		{
			int inc{ 0 };
			int exc{ 0 };

			if(wt[n-1] <= w)
			{
				inc = price[n - 1] + dp[n - 1][w - wt[n - 1]];
			}
			exc = dp[n - 1][w];

			dp[n][w] = std::max(inc, exc);
		}
	}

	return dp[N][W];
}

int main()
{
	int wts[]{ 2, 7, 3, 4 };
	int prices[]{ 5, 20, 20, 10 };

	int N = 4;
	int W = 11;

	std::cout << knapsackDP(wts, prices, N, W) << std::endl;

	return 0;
}