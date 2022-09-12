/*
 * Pascal's Triangle
 * Pascal’s triangle is a triangular array of the binomial coefficients. Write a function
 * that takes an integer value n as input and returns 2D array with first n lines of the
 * Pascal’s triangle.
 *
 * Following are the first 5 rows of Pascal’s Triangle:
 *									1
 *								  1	  1
 *								1	2	1
 *							  1	  3	  3	  1
 *							1	4	6	4	1
 *
 * Input Format:
 *	In the function an integer N is passed.
 *
 * Output Format:
 *	Return the output as vector of vectors.
 */

#include <iostream>
#include <vector>


std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec)
{
	for(const auto& v : vec)
	{
		out << v << " ";
	}
	return out;
}

void print(std::vector<std::vector<int>>& vec)
{
	for (const auto& v : vec)
		std::cout << v;

}

std::vector<std::vector<int>> printPascal(int n)
{
	std::vector<std::vector<int>> output;
	std::vector<int> above{ 1 };
	std::vector<int> current;
	output.push_back(above);
	if (n == 1)
		return output;

	for(int i{2}; i <= n; ++i)
	{
		for(int j{0}; j < i; ++j)
		{
			if (j == 0)
				current.push_back(above[j]);
			else if (j == i - 1)
				current.push_back(above[j - 1]);
			else
				current.push_back(above[j] + above[j - 1]);
		}
		above.clear();
		above = current;
		output.push_back(current);
		current.clear();
	}

	return output;
}

int main()
{
	auto res = printPascal(5);

	for (const auto& e : res)
		std::cout << e << std::endl;
	std::cout << std::endl;



	return 0;
}