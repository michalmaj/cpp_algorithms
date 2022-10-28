#pragma once

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
	}

};