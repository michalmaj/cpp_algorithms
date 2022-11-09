#include <iostream>
#include <queue>
#include <vector>

template<typename Q>
void printPriorityQueue(Q q)
{
	while (!q.empty())
	{
		std::cout << q.top() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

int main()
{
	int arr[]{ 10, 15, 20, 13, 6, 90 };
	int n = std::size(arr);

	std::priority_queue<int, std::vector<int>, std::greater<>> heap; // by default it is a max heap, if we want min heap we need to add two more parameters
	for(const auto& e : arr)
	{
		heap.push(e);
	}

	printPriorityQueue(heap);


	return 0;
}