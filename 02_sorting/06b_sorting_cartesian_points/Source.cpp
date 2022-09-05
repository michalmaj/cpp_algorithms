/*
 * Sorting Cartesian Points
 * Given co-ordinates of N points on X-Y axis, your task is to sort them in accordance
 * to the x-coordinate. If the x-coordinates are same then compare y-coordinates.
 *
 * Input Format:
 *		In the function an integer vector of pairs is passed.
 * Output Format:
 *		Return the vector in sorted order.
 */

#include <iostream>
#include <algorithm>
#include <vector>

// comparator for std::pair
bool comparator(std::pair<int, int> lhs, std::pair<int, int> rhs)
{
    // condition to define smallest x-element 
    if (lhs.first < rhs.first)
        return true;
    // condition for equal x-element, find smallest y-element
    else if (lhs.first == rhs.first and lhs.second < rhs.second)
        return true;
    else
        return false;
}

std::vector<std::pair<int, int>> sortCartesian(std::vector<std::pair<int, int>> v)
{
    // sorting using comparator
    std::sort(v.begin(), v.end(), comparator);

    return v;
}

int main()
{
    std::vector<std::pair<int, int>> vec{ {3, 4}, {2, 3}, {3, 7}, {1, 5}, {3, 4} };

    for (const auto& e : vec)
        std::cout << "(" << e.first << "," << e.second << ") ";
    std::cout << std::endl;

    auto res = sortCartesian(vec);

    for (const auto& e : res)
        std::cout << "(" << e.first << "," << e.second << ") ";
    std::cout << std::endl;

    return 0;
}