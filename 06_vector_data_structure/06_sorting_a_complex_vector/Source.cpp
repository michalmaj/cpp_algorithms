/*
 * std::sort
 * Sorts the elements in the range [first,last) into ascending order.
 * The elements are compared using operator< for the first version, and comp for the second.
 * Equivalent elements are not guaranteed to keep their original relative order.
 */

#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	for (const auto& e : vec)
		out << e << " ";

	return out;
}

// Function for calculate marks from vector
int calculate_total_marks(const std::vector<int>& marks)
{
	int sum{ 0 };
	for (const auto& e : marks)
		sum += e;
	return sum;
}

// Comparator, biggest sum of marks is better
bool compare(const std::pair<std::string, std::vector<int>>& s1,
	const std::pair<std::string, std::vector<int>>& s2)
{
	std::vector<int> m1 = s1.second;
	std::vector<int> m2 = s2.second;

	return calculate_total_marks(m1) > calculate_total_marks(m2);
}

int main()
{
	// We want to create a rank list based on marks
	std::vector<std::pair<std::string, std::vector<int>>> student_marks
	{
		{"John Snow", {10, 20, 11}},
		{"Tyrion Lannister", {10, 21, 2}},
		{"Arya Stark", {4, 5, 6}},
		{"Daenerys Targaryen", {10, 13, 20}},
	};

	std::sort(student_marks.begin(), student_marks.end(), compare);

	for (const auto& s : student_marks)
	{
		std::cout << "Student named: " << s.first << " who has this scores: "
			<< s.second << ". Has a final result: "
			<< calculate_total_marks(s.second) << std::endl;
	}

	return 0;
}