#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include <set>
#include <climits>


class Graph
{
	int V;
	//std::list<std::pair<int, int>>* l;
	std::unique_ptr<std::list<std::pair<int, int>>[]> l;

public:
	Graph(int v) : V(v)/*, l{new std::list<std::pair<int, int>>[V]}*/
	{
		l = std::make_unique<std::list<std::pair<int, int>>[]>(V);
	}

	void addEdge(int u, int v, int wt, bool undir = true)
	{
		l[u].push_back({ wt, v });
		if(undir)
		{
			l[v].push_back({ wt, u });
		}
	}

	int dijkstra(int src, int dest)
	{
		// Data structures
		std::vector<int> dist(V, INT_MAX);
		std::set<std::pair<int, int>> s; // current node and current distance

		// 1. Init
		dist[src] = 0;
		s.insert({ 0, src });

		while(!s.empty())
		{
			auto it = s.begin();

			int node = it->second; // distance
			int distTillNow = it->first; // current node

			s.erase(it); // Pop

			// Iterate over the neighbors of node
			for(auto& nbrPair : l[node])
			{
				int nbr = nbrPair.second;
				int currentEdge = nbrPair.first;

				if(distTillNow + currentEdge < dist[nbr])
				{
					// remove if neighbor already exists in the set
					auto f = s.find({ dist[nbr], nbr });
					if (f != s.end())
						s.erase(f);

					// insert the updated value with the new distance
					dist[nbr] = distTillNow + currentEdge;
					s.insert(std::make_pair(dist[nbr], nbr));
				}
			}
		}

		// Single Source Shortest Dist to all other nodes
		for(int i{0}; i < V; ++i)
		{
			std::cout << "Node i: " << i << ", distance: " << dist[i] << std::endl;
		}
		return dist[dest];
	}

};

int main()
{
	Graph g{ 5 };
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(0, 2, 4);
	g.addEdge(0, 3, 7);
	g.addEdge(3, 2, 2);
	g.addEdge(3, 4, 3);

	std::cout << g.dijkstra(0, 4) << std::endl;
}