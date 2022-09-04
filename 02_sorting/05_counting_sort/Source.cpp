/*
 * Counting sort work only with integer arrays.
 * For this algorithm we create a new array, where index 0 represents smallest value
 * in the original array and maximum index will be greatest value plus abs of smallest.
 * In other words we create a frequency map.
 */

#include <iostream>

// function for calculate smallest and greatest value in the array 
template<size_t N>
std::pair<int, int> min_max(int (&arr)[N])
{
	int max{ arr[0] };
	int min{ arr[0] };

	for(const auto& e: arr)
	{
		if (max < e)
			max = e;
		if (min > e)
			min = e;
	}

	// return a pair of min, max value
	return std::make_pair(min, max);
}


template<size_t N>
void counting_sort(int (&arr)[N])
{
	// C++17 structured binding, first element will go to min, second element will go to max
	auto [min, max] = min_max(arr);

	// calculate the biggest index in a frequency array
	int n = max + std::abs(min) + 1;

	// initialize frequency array with 0
	int* freq;
	freq = new int[n](); // fill array with zeros by parentheses ()

	// Update the frequency array
	for (int i{ 0 }; i < N; ++i)
		freq[arr[i] + std::abs(min)]++;

	// for testing purpose - in this example -12 will treat as index 0
	// so original array contains -12 only once, so in frequency array
	// index 0 will contain value 1.
	for (int i{ 0 }; i < n; ++i)
		std::cout << freq[i] << " ";
	std::cout << std::endl;

	// put back the elements from frequency array into original array
	int j = 0;
	// iterate through frequency array
	for(int i{0}; i < n; ++i)
	{
		// if array contains value greater than 0 in certain index
		// that means this index is a value from original array minus abs(lowest value)
		while(freq[i] > 0)
		{
			arr[j] = i - std::abs(min);
			freq[i]--;
			j++;
		}
	}

	delete[] freq;
}

int main()
{
	int arr[]{ -2, 3, 4, -1, 5, -12, 6, 1, 3 };

	counting_sort(arr);

	std::cout << "Array after sorting:" << std::endl;
	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << std::endl;

	return 0;
}