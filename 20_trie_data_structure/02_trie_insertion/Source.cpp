#include <iostream>
#include <memory>
#include <unordered_map>

class Node
{
public:
	char data;
	std::unordered_map<char, Node*> m;
	bool isTerminal;

public:
	Node(char data) : data(data), isTerminal(false) {}
};


class Trie
{
	Node* root;

public:
	Trie()
	{
		root = new Node('\0');
	}

	~Trie()
	{
		delete root;
	}

	void insert(std::string word)
	{
		Node* temp = root;

		for(char ch : word)
		{
			if(temp->m.count(ch) == 0)
			{
				Node* n = new Node(ch);
				temp->m[ch] = n;
				delete n;
				n = nullptr;
			}
			temp = temp->m[ch];
		}
		temp->isTerminal = true;
	}
};

int main()
{

	return 0;
}
