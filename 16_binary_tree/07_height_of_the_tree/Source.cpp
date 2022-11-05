#include <iostream>
#include <queue>

// input for preorder build: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// input for level order build: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1

// preorder: 1 2 4 5 7 3 6
// inorder: 4 2 7 5 1 3 6
// postorder: 4 7 5 2 6 3 1

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

// Level order build
template <typename T>
Node<T>* levelOrderBuild()
{
	T d;
	std::cin >> d;

	Node<T>* root = new Node<T>(d);

	std::queue<Node<T>*> q;
	q.push(root);

	while (!q.empty())
	{
		Node<T>* current = q.front();
		q.pop();

		int c1, c2;
		std::cin >> c1 >> c2;

		if (c1 != -1)
		{
			current->left = new Node<T>(c1);
			q.push(current->left);
		}
		if (c2 != -1)
		{
			current->right = new Node<T>(c2);
			q.push(current->right);
		}
	}

	return root;
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
	if (root == nullptr)
		return;
	printInorder(root->left);
	std::cout << root->data << " ";
	printInorder(root->right);
}

template<typename T>
void printPostorder(Node<T>* root)
{
	if (root == nullptr)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	std::cout << root->data << " ";
}

template<typename T>
void levelOrderPrint(Node<T>* root)
{
	std::queue<Node<T>*> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty())
	{
		Node<T>* temp = q.front();
		if (temp == nullptr)
		{
			std::cout << std::endl;
			q.pop();

			// Insert a new nullptr for the next level
			if (!q.empty())
			{
				q.push(nullptr);
			}
		}
		else
		{
			q.pop();
			std::cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
}

// Helper function: height of the tree
template <typename T>
int height(Node<T>* root)
{
	if (root == nullptr)
		return 0;
	int h1 = height(root->left);
	int h2 = height(root->right);

	return 1 + std::max(h1, h2);
}

int main()
{
	Node<int>* root = levelOrderBuild<int>();

	levelOrderPrint(root);

	std::cout << "Height of our tree: " << height(root) << std::endl;

	return 0;
}