#include <iostream>
#include <vector>

std::pair<int, std::vector<std::vector<int>>> wines_bottom_up(int prices[], int n)
{
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));


	for(int i{n - 1}; i >= 0; --i)
	{
		// bottom row to top row
		for(int j{0}; j < n; ++j)
		{
			if (i == j)
				dp[i][j] = n * prices[i];
			else if(i < j)
			{
				// dp(i, j)
				int year = n - (j - i);
				int pick_left = prices[i] * year + dp[i + 1][j];
				int pick_right = prices[j] * year + dp[i][j - 1];

				dp[i][j] = std::max(pick_left, pick_right);
			}
		}
	}
	return { dp[0][n - 1], dp };
}

int main()
{
	int a[]{ 2, 3, 5, 1, 4 };
	int n{ std::size(a) };

	auto [result, dp] = wines_bottom_up(a, n);

	std::cout << "Optimal solution: " << result << std::endl;

	std::cout << "\n==========================================\n\n";

	std::cout << "dp contains:\n";

	for(const auto& vec : dp)
	{
		for (const auto& v : vec)
			std::cout << v << " ";
		std::cout << std::endl;
	}

	return 0;
}
