#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <memory>

class Node
{
public:
	std::string name;
	std::list<std::string> nbrs;

	Node(const std::string& name): name(name){}

};

class Graph
{
	// All Nodes
	// Hashmap (std::string, Node*)
	std::unordered_map<std::string, std::unique_ptr<Node>> m;

public:
	Graph(const std::vector<std::string>& cities)
	{
		for(const auto& city : cities)
		{
			m[city] = std::make_unique<Node>(city);
		}
	}

	void addEdge(std::string x, std::string y, bool undir=true)
	{
		m[x]->nbrs.push_back(y);
		if (undir)
			m[y]->nbrs.push_back(x);
	}

	void printAdjList() const
	{
		for(const auto& [city, node] : m)
		{
			std::cout << city << "-->";
			for(const auto& nbr : node->nbrs)
			{
				std::cout << nbr << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	Graph g{ std::vector<std::string>{"Delhi", "London", "Paris", "New York"}};
	g.addEdge("Delhi", "London");
	g.addEdge("New York", "London");
	g.addEdge("Delhi", "Paris");
	g.addEdge("Paris", "New York");

	g.printAdjList();


	return 0;
}