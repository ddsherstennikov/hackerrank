#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;





long long bubble_count(vector<int>& a, int from_idx, int to_idx)
{
	long long res = 0;

	for (int i=from_idx; i<=to_idx-1; ++i)
		for (int j = i; j <= to_idx; ++j)
			if (a[i] > a[j])
			{
				res++;
				swap(a[i], a[j]);
			}

	return res;
}

long long count(vector<int>& a, int from_idx, int to_idx)
{
	if (to_idx - from_idx <= 3)
	{
		return bubble_count(a, from_idx, to_idx);
	}
	else
	{
		int pivot_idx = (int)((to_idx + from_idx) / 2);
		long long res = count(a, from_idx, pivot_idx) + count(a, pivot_idx + 1, to_idx);

		vector<int> t;

		int left = from_idx;
		int right = pivot_idx + 1;

		while (left <= pivot_idx && right <= to_idx)
		{
			// merge and count cross-boundary inversions
			if (a[left] > a[right])
			{ 
				res += pivot_idx + 1 - left;
				t.push_back(a[right]);
				right++;
			}
			else
			{
				t.push_back(a[left]);
				left++;
			}
		}	

		while (left <= pivot_idx)
		{
			t.push_back(a[left]);
			left++;
		}
		while (right <= to_idx)
		{
			t.push_back(a[right]);
			right++;
		}

		for (int i = from_idx; i <= to_idx; ++i)
		{
			swap(a[i], t[i - from_idx]);
		}

		return res;
	}
}

long long count_inversions(vector<int>& a)
{
	return count(a, 0, a.size() - 1);
}



int main() 
{
	int t;
	cin >> t;

	for (int a0 = 0; a0 < t; a0++) 
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int arr_i = 0; arr_i < n; arr_i++) 
		{
			cin >> arr[arr_i];
		}
		cout << count_inversions(arr) << endl;
	}
	return 0;
}
