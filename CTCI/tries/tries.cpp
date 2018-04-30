#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;



class Trie
{
public:

	struct Node;
	using hashmap = unordered_map<char, Node*>;

	struct Node
	{
		Node(char c = '\0', bool f = false) : symbol(c), full(f), count(0) {}

		char symbol;
		bool full;
		int count;

		hashmap children;
	};

	Trie() : current_(root_) { root_ = new Node(); }
	~Trie() { cleanup(root_); };

	void Add(string path);
	pair<int, Node*> Find(string path);

	void Reset() { current_ = root_; }
	void Print(Node*);

private:
	void cleanup(Node* n);

	Node* root_;
	Node* current_;
};


//-----------------------------------------------------------------------------------------------------------
void Trie::cleanup(Node* n)
{
	for (auto child : n->children)
		cleanup(child.second);

	delete n;
}

//-----------------------------------------------------------------------------------------------------------
void Trie::Add(string path)
{
	if (path.empty())
	{
		current_->full = true;
	}
	else
	{
		char c = path[0];
		path = std::move(string(path.begin() + 1, path.end()));
		hashmap::iterator it = current_->children.find(c);

		if (it != current_->children.end())
		{
			current_ = it->second;
			current_->count++;
			return Add(path);
		}
		else
		{
			auto n = new Node(c);
			auto p = current_->children.insert({ c, n });
			current_ = p.first->second;
			current_->count++;
			Add(path);
		}
	}
}

pair<int, Trie::Node*> Trie::Find(string path)
{
	if (path.empty())
	{
		return make_pair(current_->count, current_);
	}
	else
	{
		char c = path[0];
		path = std::move(string(path.begin() + 1, path.end()));
		hashmap::iterator it = current_->children.find(c);

		if (it != current_->children.end())
		{
			current_ = it->second;
			return Find(path);
		}
		else
		{
			return make_pair(0, root_);
		}
	}
}

void Trie::Print(Node* n)
{
	if (n = nullptr)
		n = root_;

	for (auto child : n->children)
	{
		cout << "[" << child.second->symbol << ", " << (child.second->full ? 1 : 0) << ", " << child.second->count << "] ";
	}

	cout << endl;

	for (auto child : n->children)
	{
		Print(child.second);
		cout << endl;
	}
}

//-----------------------------------------------------------------------------------------------------------
void ProcessFind(std::string& nm, Trie& t, std::unordered_map<string, Trie::Node*>& prefix_idx)
{
	int res;
	Trie::Node* hint = nullptr;

	auto it = prefix_idx.find(nm);
	if (it != prefix_idx.end())
	{
		hint = it->second;
		res = hint->count;
	}
	else
	{
		t.Reset();

		auto p = t.Find(nm);
		res = p.first;
		hint = p.second;

		if (res)			
			prefix_idx.insert({ nm, hint });
	}

	cout << res << endl;
}


//-----------------------------------------------------------------------------------------------------------
int main()
{
	Trie t;
	std::unordered_map<string, Trie::Node*> prefix_idx;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::string opcode, nm;
		cin >> opcode >> nm;

		if (opcode == "add")
		{
			t.Reset(); t.Add(nm);
		}
		else if (opcode == "find")
		{
			ProcessFind(nm, t, prefix_idx);
		}
		else if (opcode == "print")
		{
			t.Print(nullptr);
		}
		else
		{
			cout << "wrong op code!" << endl; break;
		}
	}

	return 0;
}
