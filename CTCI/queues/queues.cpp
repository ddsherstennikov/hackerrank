#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue 
{
public:
	void push(int x) 
	{
		bottom.push(x);
	}

	void pop() 
	{
		if (higher.size() > 0)
			higher.pop();
		else if (bottom.size() > 0)
		{
			refill();
			higher.pop();
		}
		else 
			throw std::runtime_error("Attempt to dequeue an empty queue");
	}

	int front() 
	{
		if (higher.size() > 0)
			return higher.top();
		else if (bottom.size() > 0)
		{
			refill();
			return higher.top();
		}
		else
			throw std::runtime_error("Attempt to see front of an empty queue");
	}

private:
	void refill()
	{
		while (!bottom.empty())
		{
			higher.push(bottom.top());
			bottom.pop();
		}
	}

	stack<int> higher;
	stack<int> bottom;
};

int main() {
	MyQueue q1;
	int q, type, x;
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x;
			q1.push(x);
		}
		else if (type == 2) {
			q1.pop();
		}
		else cout << q1.front() << endl;
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
