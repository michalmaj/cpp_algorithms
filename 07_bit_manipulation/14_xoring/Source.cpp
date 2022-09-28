/*
 * We are given an array containg n numbers. All the numbers are present twice except for one number
 * which is only present once. Find the unique number without taking any extra spaces and in linear
 * time.
 *
 * Input format:
 *	An integer vector is passed in the function
 *
 * Constraints:
 *	n < 10^5
 *
 * Output Format:
 *	return a single integer containing the unique number
 *
 * Sample Input
 *	{ 1, 2, 3, 1, 4, 2, 3 }
 *
 * Sample Output:
 *	4
 */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int xoring(vector<int> v)
{
    int n{ 0 };
    for (const auto& e : v)
    {
        cout << "n = " << n << ", bit = " << bitset<8>(n) << endl;
        cout << "e = " << e << ", bit = " << bitset<8>(e) << endl;
        cout << "n^e = " << (n^e) << ", bit = " << bitset<8>(n^e) << endl;
	    n = n ^ e;
        cout << endl;
    }

    return n;
}


int main()
{
    vector<int> test{ 1, 2, 3, 1, 4, 2, 3 };
    xoring(test);

    return 0;
}