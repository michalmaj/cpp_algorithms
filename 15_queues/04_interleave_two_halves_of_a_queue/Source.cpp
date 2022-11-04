/*
 * Interleave two halves of a queue:
 *	Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.
 *
 * Input Format:
 *	In the function an integer queue passed.
 * Output Format:
 *	Return the interleaved queue.
 *
 * Sample Input:
 *	11 12 13 14 15 16 17 18 19 20
 * Sample Output:
 *	11 16 12 17 13 18 14 19 15 20
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, queue<T> q)
{
	while (!q.empty())
	{
		out << q.front() << " ";
		q.pop();
	}
	return out;
}

queue<int> interLeave(queue<int> q) {
	queue<int> output;
	queue<int> temp;
	size_t half{ q.size() / 2 };
	for (size_t i{ 0 }; i < half; ++i)
	{
		temp.push(q.front());
		q.pop();
	}

	while (!temp.empty())
	{
		output.push(temp.front());
		output.push(q.front());
		temp.pop();
		q.pop();
	}

	return output;
}


int main()
{
	vector<int> v{ 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	queue<int> q;

	for (const auto& e : v)
		q.push(e);

	cout << q << endl;



	cout << interLeave(q) << endl;

	return 0;
}