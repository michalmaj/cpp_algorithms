#include <iostream>
#include <list>
#include <queue>

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

	void addEdge(int i, int j, bool undri = true)
	{
		l[i].push_back(j);
		if (undri)
			l[j].push_back(i);
	}

	void printAdjList() const
	{
		// Iterate over all the rows
		for (int i{ 0 }; i < vertices; ++i)
		{
			std::cout << i << "->";
			// every element of ith linked list
			for (const auto& node : l[i])
			{
				std::cout << node << " ";
			}
			std::cout << std::endl;
		}
	}

	void bfs(int source)
	{
		std::queue<int> q;
		bool* visited = new bool[vertices] {0};

		q.push(source);
		visited[source] = true;

		while (!q.empty())
		{
			int f = q.front();
			std::cout << f << std::endl;
			q.pop();

			// Push the neighbors of current node inside q if they are not already visited
			for(auto nbr : l[f])
			{
				if(!visited[nbr])
				{
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
};



int main()
{
	Graph g{ 7 };

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);

	//g.printAdjList();
	g.bfs(1);


	return 0;
}