#include <iostream>
#include <vector>

// helper function
void merge(std::vector<int>& array, int s, int e)
{
	int i = s;
	int m = (s + e) / 2;
	int j = m + 1;
	std::vector<int> temp;

	while (i <= m and j <= e)
	{
		if(array[i] < array[j])
		{
			temp.push_back(array[i]);
			i++;
		}
		else
		{
			temp.push_back(array[j]);
			j++;
		}
	}

	// copy remaining elements from first array
	while(i <= m)
	{
		temp.push_back(array[i++]);
	}
	// or copy remainder from second array
	while(j <= e)
	{
		temp.push_back(array[j++]);
	}

	// copy back the elements from temps to original array
	int k = 0;
	for(int idx = s; idx <= e; ++idx)
	{
		array[idx] = temp[k++];
	}
	return;
}

// sorting function
void merge_sort(std::vector<int>& array, int s, int e)
{
	// base case
	if(s >= e)
		return;

	// recursive case
	int mid{ (s + e) / 2 };
	merge_sort(array, s, mid);
	merge_sort(array, mid + 1, e);

	return merge(array, s, e);
}

int main()
{
	std::vector<int> arr{ 10, 5, 2, 0, 7, 6, 4 };
	int s = 0;
	int e = arr.size() - 1;

	merge_sort(arr, s, e);
	for (int x : arr)
		std::cout << x << " ";
	std::cout << std::endl;

	return 0;
}