#include "stdafx.h"

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

template<class ForwardIt>
ForwardIt myrotate(ForwardIt first, ForwardIt new_first, ForwardIt last)
{
	ForwardIt next = new_first;

	while (first != next)
	{
		std::swap(*first++, *next++);
		if (next == last)
			next = new_first;
		else if (first == new_first)
			new_first = next;
	}

	return new_first;
}

vector<int> array_left_rotation(vector<int> a, int n, int k) 
{
	std::vector<int>::iterator it = a.begin()+k;
	myrotate(a.begin(), it, a.end());
	return a;
}

int main() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	vector<int> output = array_left_rotation(a, n, k);
	for (int i = 0; i < n; i++)
		cout << output[i] << " ";
	cout << endl;
	return 0;
}
