#include <iostream>

struct Node
{
	Node(int x) : data(x), left(0), right(0) {}

	Node* right;
	Node* left;
	int data;
};

#include <vector>

using namespace std;


void infix_traverse(Node* n, vector<int>& v)
{	
	if (n->left)
	{
		infix_traverse(n->left, v);
	}

	v.push_back(n->data);

	if (n->right)
	{
		infix_traverse(n->right, v);
	}
}

bool checkBST(Node* root)
{
	if (!root)
		return false;

	vector<int> v;
	infix_traverse(root, v);

	int i = 0;
	while ((i < v.size() - 1) && (v[i] < v[i + 1]))
		++i;

	if (i == v.size() - 1)
		return true;
	else
		return false;
}

int main()
{
	Node* root = new Node(3);

	Node* l = new Node(2);
	root->left = l;

	Node* r = new Node(6);
	root->right = r;

	Node* ll = new Node(1);
	l->left = ll;

	Node* lr = new Node(4);
	l->right = lr;

	Node* rr = new Node(7);
	r->right = rr;

	Node* rl = new Node(5);
	r->left = rl;

	bool res = checkBST(root);

	std::cout << (res ? "YES" : "NO");

	std::cin.get(); std::cin.get();
}