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

	int hashFn(std::string key)
	{
		int idx{ 0 };
		int power = 1;

		for (auto ch : key)
		{
			idx = (idx + ch * power) % ts;
			power = (power * 29) % ts;
		}
		return idx;
	}

public:
	Hashtable(int default_size = 7)
	{
		cs = 0;
		ts = default_size;
		table = new Node<T>*[ts];

		for (int i{ 0 }; i < ts; ++i)
			table[i] = nullptr;
	}

	void insert(std::string key, T val)
	{
		int idx = hashFn(key);

		Node<T>* n = new Node<T>(key, val);

		n->next = table[idx];
		table[idx] = n;
	}
};