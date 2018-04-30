#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>

using namespace std;



class Heap
{
public:
	Heap() = default;
	~Heap() = default;

	Heap(const std::vector<int>& v) : items(v)
	{
		Heapify();
	}

	int Peek();
	void Insert(int x);

	bool IsEmpty() { return items.size() != 0; }
	int Size() { return items.size(); }

protected:
	int parent_idx(int n) { return (int)((n - 1) / 2); }
	int left_idx(int n) { return 2 * n + 1; }
	int right_idx(int n) { return 2 * n + 2; }

	void Heapify();
	virtual void SiftUp(int n) = 0;
	virtual void SiftDown(int n) = 0;

	std::vector<int> items;
};

class MinHeap : public Heap
{
public:
	MinHeap() = default;
	~MinHeap() = default;

	int ExtractMin();
protected:
	virtual void SiftUp(int n);
	virtual void SiftDown(int n);
};

class MaxHeap : public Heap
{
public:
	MaxHeap() = default;
	~MaxHeap() = default;

	int ExtractMax();
protected:
	virtual void SiftUp(int n);
	virtual void SiftDown(int n);
};

//-------------------------------------------------------------------------------------

int Heap::Peek()
{
	return items[0];
}

void Heap::Insert(int x)
{
	items.push_back(x);
	SiftUp(items.size() - 1);
}

void Heap::Heapify()
{
	int heap_size = items.size();

	for (int i = heap_size / 2; i >= 0; --i)
		SiftDown(i);
}

//-------------------------------------------------------------------------------------

int MinHeap::ExtractMin()
{
	int res = items[0];

	items[0] = items[items.size() - 1];
	items.pop_back();
	SiftDown(0);

	return res;
}

void MinHeap::SiftUp(int n)
{
	int parent = parent_idx(n);
	if (n < 1 || parent < 0 || n > items.size())
		return;

	if (items[parent] > items[n])
	{
		swap(items[parent], items[n]);
		SiftUp(parent);
	}
}

void MinHeap::SiftDown(int n)
{
	int left = left_idx(n);
	int right = right_idx(n);
	int heap_size = items.size();
	int argmin;

	if (left < heap_size && items[left] < items[n])
		argmin = left;
	else
		argmin = n;

	if (right < heap_size && items[right] < items[argmin])
		argmin = right;

	if (argmin != n)
	{
		swap(items[n], items[argmin]);
		SiftDown(argmin);
	}
}

//-------------------------------------------------------------------------------------

int MaxHeap::ExtractMax()
{
	int res = items[0];

	items[0] = items[items.size() - 1];
	items.pop_back();
	SiftDown(0);

	return res;
}

void MaxHeap::SiftUp(int n)
{
	int parent = parent_idx(n);
	if (n < 1 || parent < 0 || n > items.size())
		return;

	if (items[parent] < items[n])
	{
		swap(items[parent], items[n]);
		SiftUp(parent);
	}
}

void MaxHeap::SiftDown(int n)
{
	int left = left_idx(n);
	int right = right_idx(n);
	int heap_size = items.size();
	int argmax;

	if (left < heap_size && items[left] > items[n])
		argmax = left;
	else
		argmax = n;

	if (right < heap_size && items[right] > items[argmax])
		argmax = right;

	if (argmax != n)
	{
		swap(items[n], items[argmax]);
		SiftDown(argmax);
	}
}

//-------------------------------------------------------------------------------------

void AddNumber(int x, MinHeap& mnh, MaxHeap& mxh)
{
	if (x < mxh.Peek())
		mxh.Insert(x);
	else
		mnh.Insert(x);
}

void Rebalance(MinHeap& mnh, MaxHeap& mxh)
{
		while (mnh.Size() - mxh.Size() > 1)
			mxh.Insert(mnh.ExtractMin());

		while (mxh.Size() - mnh.Size() > 1)
			mnh.Insert(mxh.ExtractMax());
}

double GetMediane(MinHeap& mnh, MaxHeap& mxh)
{
	double res;

	if (mnh.Size() == mxh.Size())
		res = ((double)mnh.Peek() + (double)mxh.Peek()) / 2.0;
		
	else if (mnh.Size() > mxh.Size())
		res = double(mnh.Peek());
	else
		res = double(mxh.Peek());

	return res;
}

int main() 
{
	MinHeap mnh;
	MaxHeap mxh;

	int n;
	cin >> n;
	vector<int> a(n);

	cout << fixed << setprecision(1);

	if (n >= 1)
	{
		cin >> a[0];
		cout << double(a[0]) << endl;
	}
	if (n >= 2)
	{
		cin >> a[1];
		cout << (double)(((double)a[1] + (double)a[0]) / 2.0) << endl;
	}
	if (n >= 3)
	{
		mnh.Insert(max(a[0], a[1]));
		mxh.Insert(min(a[0], a[1]));

		for (int i = 2; i < n; ++i)
		{
			cin >> a[i];
			
			AddNumber(a[i], mnh, mxh);
			Rebalance(mnh, mxh);
			double r = GetMediane(mnh, mxh);

			cout << r << endl;
		}
	}

	return 0;
}