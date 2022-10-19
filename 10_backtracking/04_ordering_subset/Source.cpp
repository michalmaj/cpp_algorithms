#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
	for (const auto& e : v)
		out << e << ",";
	return out;
}

bool compare(std::string& a, std::string& b)
{
	if (a.length() == b.length())
		return a < b;  // lexicographic order
	return a.length() < b.length(); // from shorter to longer
}

void findSubset(char* input, char* output, int i, int j, std::vector<std::string>& v)
{
	// base case
	if (input[i] == '\0')
	{
		output[j] = '\0';
		std::string temp(output);
		v.push_back(temp);

		return;
	}

	// rec case
	// include the ith letter
	output[j] = input[i];
	findSubset(input, output, i + 1, j + 1, v);

	// exclude the ith letter
	// Overwriting
	findSubset(input, output, i + 1, j, v);
}

int main()
{
	char input[]{ "abc" };
	char output[100];
	std::vector<std::string> my_list;



	findSubset(input, output, 0, 0, my_list);

	std::sort(my_list.begin(), my_list.end(), compare);
	std::cout << my_list << std::endl; 

	return 0;
}