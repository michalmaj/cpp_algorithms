#include <iostream>
#include <list>

class Graph
{
	int vertices;
	std::list<int>* l;

public:
	Graph(int v)
	{
		vertices = v;
		l = new std::list<int>[vertices];
	}

	~Graph()
	{
		delete[] l;
	}

	void addEdge(int i, int j, bool undri=true)
	{
		l[i].push_back(j);
		if (undri)
			l[j].push_back(i);
	}

	void printAdjList() const
	{
		// Iterate over all the rows
		for(int i{0}; i < vertices; ++i)
		{
			std::cout << i << "->";
			// every element of ith linked list
			for(const auto& node : l[i])
			{
				std::cout << node << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	Graph g{ 6 };

	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);

	g.printAdjList();


	return 0;
}