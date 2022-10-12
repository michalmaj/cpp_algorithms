/*
 * Rotated Search
 * Write a function that takes input an sorted array of distinct integers, which is rotated
 * about a pivot point and find the index of any given element.
 */

#include <iostream>
#include <vector>

int rotated_search(std::vector<int> a, int key)
{
	size_t n = a.size();

	// Logic
	size_t s = 0;
	size_t e = n - 1;

	while(s<=e)
	{
		size_t mid = (s + e) / 2;

		if (a[mid] == key)
			return mid;

		// 2 cases
		if(a[s] <= a[mid])
		{
			// left
			if(key >= a[s] and key <=a [mid])
			{
				e = mid - 1;
			}
			else
			{
				s = mid + 1;
			}
		}
		else
		{
			// right
			if(key >= a[mid] and key <= a[e])
			{
				s = mid + 1;
			}
			else
			{
				e = mid - 1;
			}
		}
	}
	return -1;
}

int main()
{
	std::vector<int> a{ 4, 5, 6, 7, 0, 1, 2, 3 };
	int key{ 3 };

	std::cout << rotated_search(a, key) << std::endl;

	return 0;
}