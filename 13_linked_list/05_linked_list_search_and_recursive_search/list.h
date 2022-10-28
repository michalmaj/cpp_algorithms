#pragma once

#include <iostream>

template <class T>
class Node
{
	T data;
	Node* next;
	template <class T> friend class List;

public:
	Node(T d)
		: data{ d }, next{ nullptr } {}

	T getData()
	{
		return data;
	}

	Node* getNext()
	{
		return next;
	}
};


template <class T>
class List
{
	Node<T>* head;
	Node<T>* tail;

	int searchHelper(Node<T>* start, int key)
	{
		// Base case
		if (start == nullptr)
			return -1;

		// value matches
		if (start->data == key)
			return 0;

		// remaining part of the linked list
		int subIdx = searchHelper(start->next, key);
		if (subIdx == -1)
			return -1;

		return subIdx + 1;
	}

public:
	List()
		: head{ nullptr }, tail{ nullptr } {}

	void push_front(T data)
	{
		if (head == nullptr)
		{
			Node<T>* n = new Node<T>(data);
			head = tail = n;
		}
		else
		{
			Node<T>* n = new Node<T>(data);
			n->next = head;
			head = n;
		}
	}

	void push_back(T data)
	{
		if (head == nullptr)
		{
			Node<T>* n = new Node<T>(data);
			head = tail = n;
		}
		else
		{
			Node<T>* n = new Node<T>(data);
			tail->next = n;
			tail = n;
		}
	}

	void insert(T data, int pos)
	{
		if (pos == 0)
		{
			push_front(data);
			return;
		}

		// Otherwise
		Node<T>* temp = head;
		for (int jump{ 1 }; jump <= pos - 1; jump++)
		{
			temp = temp->next;
		}
		Node<T>* n = new Node<T>(data);
		n->next = temp->next;
		temp->next = n;
	}

	// Searching in a Linked List
	int search(T key)
	{
		Node<T>* temp = head;
		int idx{ 0 };

		while (temp != nullptr)
		{
			if (temp->data == key)
				return idx;
			idx++;
			temp = temp->next;
		}
		return -1;
	}

	// Recursive search in Linked List
	int recursiveSearch(int key)
	{
		int idx = searchHelper(head, key);
		return idx;
	}

	Node<T>* begin()
	{
		return head;
	}

	void print()
	{
		Node<int>* h = head;
		while (h != nullptr)
		{
			std::cout << h->getData() << "->";
			h = h->getNext();
		}
		std::cout << std::endl;
	}

};