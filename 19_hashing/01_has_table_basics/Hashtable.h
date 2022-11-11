#pragma once

#include <iostream>

template <typename T>
struct Node
{
	std::string key;
	T value;
	Node* next;

	Node(const std::string& key, T value) : key(key), value(value)
	{
		next = nullptr;
	}
	~Node()
	{
		std::cout << value << std::endl;
		delete next;
	}

};

template<typename T>
class Hashtable
{
	Node<T>** table;
	int cs; // total entries that have been inserted
	int ts; // size of table

public:
	Hashtable(int default_size=7)
	{
		cs = 0;
		ts = default_size;
		table = new Node<T>*[ts];

		for (int i{ 0 }; i < ts; ++i)
			table[i] = nullptr;
	}

	~Hashtable()
	{
		delete table;
	}

};