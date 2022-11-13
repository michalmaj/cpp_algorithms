#include <iostream>
#include <unordered_map>

class Node
{
	char data;
	std::unordered_map<char, Node*> m;
	bool isTerminal;

public:
	Node(char data) : data(data), isTerminal(false){}
};


class Trie
{
	Node* root;

public:
	Trie()
	{
		root = new Node('\0');
	}
};

int main()
{

	return 0;
}
