#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph
{
	int vertices;
	std::list<int>* l;

	void dfsHelper(int node, bool* visited)
	{
		visited[node] = true;
		std::cout << node << " ";

		// make a dfs call on all its unvisited neighbours
		for (int nbr : l[node])
		{
			if (!visited[nbr])
			{
				dfsHelper(nbr, visited);
			}
		}
		return;
	}

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

	void addEdge(int i, int j)
	{
		l[i].push_back(j);
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

	void bfs(int source) const
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
			for (auto nbr : l[f])
			{
				if (!visited[nbr])
				{
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		delete[] visited;
	}

	void dfs(int source)
	{
		bool* visited = new bool[vertices] {0};
		dfsHelper(source, visited);

		delete[] visited;
	}

	void topological_sort()
	{
		std::vector<int> indegree(vertices, 0);

		// iterate over all the edges to find the right indegree
		for(int i{0}; i < vertices; ++i)
		{
			for (auto nbr : l[i])
			{
				indegree[nbr]++;
			}
		}

		// bfs
		std::queue<int> q;

		// init the q with nodes having 0 indegree
		for (int i{ 0 }; i < vertices; ++i)
		{
			if (indegree[i] == 0)
				q.push(i);
		}

		// start popping
		while (!q.empty())
		{
			int node = q.front();
			std::cout << node << " ";
			q.pop();

			// iterate over the neighbors of this node and reduce their indegree by 1
			for(auto nbr : l[node])
			{
				indegree[nbr]--;
				if(indegree[nbr] == 0)
				{
					q.push(nbr);
				}
			}
		}
	}
};



int main()
{
	Graph g{ 6 };

	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(1, 4);
	g.addEdge(1, 2);

	g.topological_sort();


	return 0;
}