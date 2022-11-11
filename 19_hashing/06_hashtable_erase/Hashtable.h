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
		std::cout << "Delete: " << key << std::endl;
		if (next != nullptr)
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

	void rehash()
	{
		std::cout << "In rehash function\n";

		// Save the pointer to the oldTable and we will do insertion in the new table
		Node<T>** oldTable = table;


		int oldTs = ts;

		// Increase the table size
		cs = 0;
		ts = 2 * ts + 1;
		table = new Node<T>*[2 * ts + 1];

		for (int i{ 0 }; i < ts; ++i)
			table[i] = nullptr;

		for (int i{ 0 }; i < oldTs; ++i)
		{
			Node<T>* temp = oldTable[i];
			while (temp != nullptr)
			{
				std::string key = temp->key;
				T value = temp->value;

				// Happen in the new table
				insert(key, value);
				temp = temp->next;
			}

			// destroyed the ith linked list
			if (oldTable[i] != nullptr)
				delete oldTable[i];
		}

		delete[] oldTable;
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

	~Hashtable()
	{
		for(int i{0}; i < ts; ++i)
		{
			if(table[i] != nullptr)
			{
				delete table[i];
			}
		}
		delete[] table;
	}

	void insert(std::string key, T val)
	{
		int idx = hashFn(key);

		Node<T>* n = new Node<T>(key, val);

		n->next = table[idx];
		table[idx] = n;

		cs++;

		float load_factor{ cs / static_cast<float>(ts) };

		if (load_factor > 0.7)
		{
			rehash();
		}
	}

	T* search(std::string key)
	{
		int idx = hashFn(key);
		Node<T>* temp = table[idx];

		while (temp != nullptr)
		{
			if (temp->key == key)
				return &temp->value;
			temp = temp->next;
		}
		return nullptr;
	}

	void erase(std::string key) {
		int idx = hashFn(key);
		Node<T>* temp = table[idx];
		Node<T>* prev = nullptr;
		while (temp != nullptr) {
			if (temp->key == key) {
				if (prev == nullptr) {
					table[idx] = temp->next;
				}
				else {
					prev->next = temp->next;
				}
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}

	void print() const
	{
		// Iterate over buckets
		for (int i{ 0 }; i < ts; ++i)
		{
			std::cout << "Bucket: " << i << "->";
			Node<T>* temp = table[i];
			while (temp != nullptr)
			{
				std::cout << temp->key << "->";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
	}
};