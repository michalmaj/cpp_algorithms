#include <iostream>
#include <vector>
#include <climits>

// Bottom Up Approach
int minNumberOfCoinsForChange(int m, std::vector<int> denoms)
{
	std::vector<int> dp(m + 1, 0);

	for(int i{1}; i <= m; ++i)
	{
		dp[i] = INT_MAX;
		for(const int c : denoms)
		{
			if (i - c >= 0 and dp[i - c] != INT_MAX)
				dp[i] = std::min(dp[i], dp[i - c] + 1);
		}
	}

	return dp[m] == INT_MAX ? -1 : dp[m];
}

int main()
{
	std::vector<int> denoms{ 1, 5, 7, 10 }; // types of coins
	int m{ 16 };
	std::cout << minNumberOfCoinsForChange(m, denoms) << std::endl;

	return 0;
}