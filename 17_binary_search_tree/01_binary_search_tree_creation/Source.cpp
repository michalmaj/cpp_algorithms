#include <iostream>

class Node
{
public:
	int key;
	Node* left;
	Node* right;

	Node(int key)
	{
		this->key = key;
		left = right = nullptr;
	}

	~Node()
	{
		std::cout << "destructor for key: " << key << std::endl;
		delete left;
		delete right;
	}
};

Node* insert(Node* root, int key)
{
	if (root == nullptr)
		return new Node(key);

	// rec case
	if(key < root->key)
	{
		root->left = insert(root->left, key);
	}
	else
	{
		root->right = insert(root->right, key);
	}

	return root;
}

void printInOrder(Node* root)
{
	if (root == nullptr)
		return;

	// left, root, right
	printInOrder(root->left);
	std::cout << root->key << " ";
	printInOrder(root->right);
}

int main()
{
	Node* root = nullptr;
	int arr[]{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };

	for (int x : arr)
		root = insert(root, x);

	printInOrder(root);

	std::cout << "\n================================================\n\n";

	delete root;
	root = nullptr;

	return 0;
}