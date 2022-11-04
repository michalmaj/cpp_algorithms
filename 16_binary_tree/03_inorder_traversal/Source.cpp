#include <iostream>

// input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

// preorder: 1 2 4 5 7 3 6
// inorder: 4 2 7 5 1 3 6

template<class T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;

	Node(T d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

// Preorder Build of the Tree: Root, Left, Right
template<class T>
Node<T>* buildTree()
{
	T d;
	std::cin >> d;

	if (d == -1)
		return nullptr;
	Node<T>* n = new Node<T>(d);
	n->left = buildTree<T>();
	n->right = buildTree<T>();
	return n;
}

template<typename T>
void printPreorder(Node<T>* root)
{
	if (root == nullptr)
		return;

	std::cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

template<typename T>
void printInorder(Node<T>* root)
{
	if(root == nullptr)
		return;
	printInorder(root->left);
	std::cout << root->data << " ";
	printInorder(root->right);
}

int main()
{
	Node<int>* root = buildTree<int>();

	std::cout << "Print preorder: ";
	printPreorder(root);
	std::cout << std::endl;

	std::cout << "Print inorder: ";
	printInorder(root);
	std::cout << std::endl;


	return 0;
}