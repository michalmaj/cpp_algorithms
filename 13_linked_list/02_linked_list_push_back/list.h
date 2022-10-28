#pragma once

template <class T>
class Node
{
	T data;
	Node* next;

public:
	Node(T d)
		: data{ d }, next{ nullptr } {}
};


template <class T>
class List
{
	Node<T>* head;
	Node<T>* tail;

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

};