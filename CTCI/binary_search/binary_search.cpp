#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



class IceCream 
{
public:
	int cost;
	int index;

	IceCream(int cost, int index) : cost(cost), index(index) {}
};



int binarySearch(int first, int last, vector<IceCream> arr, int search) 
{
	if (first > last)
		return -1;

	int left = first;
	int right = last;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (search < arr[mid].cost)
			right = mid - 1;
		else if (search > arr[mid].cost)
			left = mid + 1;
		else if (search == arr[mid].cost)
			return arr[mid].index;
	}

	return -1;
}



int main() 
{
	int t;
	int n, m;
	cin >> t;
	for (int test = 0; test < t; test++) 
	{
		cin >> m >> n;
		vector<IceCream> arr;
		arr.reserve(n);

		for (int i = 0; i < n; i++) 
		{
			int cost;
			cin >> cost;
			arr.push_back(IceCream(cost, i + 1));
		}

		sort(arr.begin(), arr.end(), [](const IceCream& a, const IceCream& b) {return a.cost < b.cost; });


		
		for (int i = 0; i < n - 1; i++) 
		{
			int search = m - arr[i].cost;
			if (search >= arr[i].cost) 
			{
				int index = binarySearch(i + 1, n - 1, arr, search);
				if (index != -1) 
				{
					cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
					break;
				}
			}
		}
	}

}

