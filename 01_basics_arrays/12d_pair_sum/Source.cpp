/*
 * Given a sorted array and a number x, find a pair in array whose sum is closest to x.
 * Input Format:
 *		In the function an integer vector and number x is passed.
 * Output Format:
 *		Return a pair of integers.
 */

#include <iostream>
#include <vector>

std::pair<int, int> closestSum(std::vector<int> arr, int x) {
	int current{ 0 };
	int closest{ 10000 };
	int c_x{};
	int c_y{};

	// two loops for make pairs
	for(int i{}; i < arr.size(); ++i)
	{
		// get value of first item in pair
		int a{ arr[i] };
		for(int j{i + 1}; j < arr.size(); ++j)
		{
			// get value of second item in pair
			int b{ arr[j] };
			// calculate how far is sum of pair from checking value
			current = std::abs(x - (a + b));
			// if current value is smaller than closest
			// set new closest and new points in pair
			if(current <= closest)
			{
				closest = current;
				c_x = a;
				c_y = b;
			}			
		}
	}
 	return std::make_pair<int>(static_cast<int>(c_x),
		static_cast<int>(c_y));
}

int main()
{
	std::vector<int> v{ 10, 22, 28, 29, 30, 40 };
	std::cout << closestSum(v, 54).first << " " << closestSum(v, 54).second << std::endl;

	return 0;
}