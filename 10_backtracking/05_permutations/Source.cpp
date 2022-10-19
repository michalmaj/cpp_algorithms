#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
	for (const auto& e : v)
		out << e << " ";
	return out;
}

template <class T>
std::vector<T> stl_permutation(T& input)
{
	std::vector<T> output;
	do
	{
		output.push_back(input);
	} while (std::next_permutation(input.begin(), input.end()));

	return output;
}


int main()
{
	std::string s{ "abc" };

	auto res = stl_permutation(s);

	std::cout << res << std::endl;

	return 0;
}