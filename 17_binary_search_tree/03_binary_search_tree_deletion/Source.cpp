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
	if (key < root->key)
	{
		root->left = insert(root->left, key);
	}
	else
	{
		root->right = insert(root->right, key);
	}

	return root;
}

bool search(Node* root, int key)
{
	if (root == nullptr)
		return false;

	if (root->key == key)
		return true;

	if (key < root->key)
		return search(root->left, key);
	return search(root->right, key);
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

Node* findMin(Node* root)
{
	while (root->left != nullptr)
	{
		root = root->left;
	}
	return root;
}

// BST Deletion
Node* remove(Node* root, int key)
{
	if (root == nullptr)
		return nullptr;
	else if(key < root->key)
	{
		root->left = remove(root->left, key);
	}
	else if(key > root->key)
	{
		root->right = remove(root->right, key);
	}
	else
	{
		// when the current node match with the key
		// 1 - No children
		if(root->left == nullptr and root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		// 2 - Single child
		else if(root->left == nullptr)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == nullptr)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		// 3 - Two children
		else
		{
			Node* temp = findMin(root);
			root->key = temp->key;
			root->right = remove(root->right, temp->key);
		}
	}

	return root;
}

int main()
{
	Node* root = nullptr;
	int arr[]{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };

	for (int x : arr)
		root = insert(root, x);

	int key{ 7 };
	root = remove(root, key);
	printInOrder(root);

	std::cout << "\n================================================\n\n";

	delete root;
	root = nullptr;

	return 0;
}