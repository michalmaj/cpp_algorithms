/*
 * Binary Search using Recursion
 * Given a sorted array, return the index of an element x in the array. Use binary search to find the
 * element in the array ! Return -1 if the element is not present.
 *
 * Input Format:
 *	In the function an integer vector  is passed.
 * Output Format:
 *	Return an integer denoting index of the element to be find.
 */

#include <iostream>
#include <vector>

int help(std::vector <int> v, int x, int s, int e)
{
    if (s <= e)
    {
        int mid = (s + e) / 2;
        int ret;
        if (v[mid] == x) // ----- case 1
            return mid;
        else if (x > v[mid]) // ----- case 2
            ret = help(v, x, mid + 1, e);
        else // ---- case 3
            ret = help(v, x, s, mid - 1);
        return ret;
    }
    else
        return -1;
}
int binarySearch(std::vector <int> v, int x)
{
    int n = v.size();
    int t = help(v, x, 0, n - 1);
    return t;
}

int main()
{
	std::vector<int> v{ 1, 3, 5, 7, 9 };
	int key{ 3 };

	auto res = binarySearch(v, key);
	std::cout << "result: " << res << std::endl;


	return 0;
}