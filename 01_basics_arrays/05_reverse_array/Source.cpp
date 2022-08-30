/*
 * This algorithm let's us to reverse an array.
 * This algorithm has a time complexity O(N) - linear
 */

#include <iostream>

// Function for reverse and array contains classic swap values technique
// with addition temp variable
template<class T, size_t N>
void reverse_array(T (&arr)[N])
{
	// Variable for classic swap method
	T temp;
	// Index of last element.
	int e{ N - 1 };

	// iterate from index 0 through the half of our array
	for(int i{0}; i < N/2; ++i)
	{
		// to our temp variable put value from actual last index
		temp = arr[e - i];
		// to last index copy value from actual first index
		arr[e - i] = arr[i];
		// to first index copy value from temp variable
		arr[i] = temp;
	}
}

template<class T, size_t N>
void reverse_array1(T (&arr)[N])
{
	// Start index.
	int s{ 0 };
	// Last index
	int e{ N - 1 };

	while(s < e)
	{
		// Provided for us swap function.
		// We can swap first element with last element.
		std::swap(arr[s], arr[e]);

		// Then we need to update indexes.
		++s; // increment start index by 1
		--e; // decrement last index by 1
	}
}


int main()
{
	int arr[]{ 10, 20, 30, 45, 60, 80, 90 };
	reverse_array1(arr);

	for(const auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;


	return 0;
}