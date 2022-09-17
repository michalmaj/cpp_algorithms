/*
 * Sort Fruits!
 * Given a vector of pairs of a string and an integer representing names and prices of
 * different fruits. A string is also passed as a parameter with name equals either "price",
 * meaning you have to sort the fruits on the basis of their price or "name", which means you
 * have to sort the fruit on the basis of their name.
 *
 * Input Format:
 * In the function an integer vector of pairs is passed.
 *
 * Output Format:
 * Return an integer vector of pairs in sorted order.
 *
 * Sample Input:
 * { (Mango,100), (Guava,70), (Grapes,40), (Apple,60), (Banana,30) }, S = "price"
 *
 * Sample Output
 * { ("Banana", 30), ("Grapes", 40), ("Apple", 60), ("Guava", 70), ("Mango", 100) }
 */

#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	for (const auto& e : vec)
		out << e << " ";
	return out;
}

bool comparator(std::pair<std::string, int>& p1, std::pair<std::string, int>& p2)
{
	return p1.second < p2.second;
}

std::vector<std::pair<std::string, int>> sortFruits(
	std::vector<std::pair<std::string, int>> v, std::string S)
{
	if (S == "price")
		std::sort(v.begin(), v.end(), comparator);
	if(S == "name")
		std::sort(v.begin(), v.end());
	return v;

}

int main()
{
	std::vector<std::pair<std::string, int>> fruits
	{
		{"Banana", 30}, {"Grapes", 40}, {"Apple", 60}, {"Guava", 70}, {"Mango", 100}
	};

	for (const auto& e : fruits)
		std::cout << e.first << ": " << e.second << std::endl;
	std::cout << std::endl;

	auto result = sortFruits(fruits, "price");
	for (const auto& e : result)
		std::cout << e.first << ": " << e.second << std::endl;
	std::cout << std::endl;

	return 0;
}