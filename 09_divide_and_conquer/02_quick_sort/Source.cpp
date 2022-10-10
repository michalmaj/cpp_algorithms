#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)
{
	for (const auto& e : v)
		out << e << " ";
	return out;
}

int partition(std::vector<int>& a, int s, int e)
{
	int pivot{ a.at(e) };  // in this case pivot will be last element
	int i = s - 1;

	for(int j{s}; j < e; j++)
	{
		if(a.at(j) < pivot)
		{
			i++;
			std::swap(a.at(i), a.at(j));
		}
	}
	std::swap(a.at(i + 1), a.at(e));
	return i + 1;
}

void quick_sort(std::vector<int>& a, int s, int e)
{
	// base case
	if(s >= e)
		return;

	// recursive case
	int p = partition(a, s, e);

	quick_sort(a, s, p - 1);
	quick_sort(a, p + 1, e);
}

int main()
{
	std::vector<int> arr{ 10, 5, 2, 0, 7, 6, 4 };
	size_t n{ arr.size() };

	quick_sort(arr, 0, n - 1);

	std::cout << arr << std::endl;

}