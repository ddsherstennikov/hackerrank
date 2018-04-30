#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int& a, int& b)
{
	a -= b; b += a; a = b - a;
}

void bubble_sort(vector<int>& a, int& swaps)
{
	int n = a.size();

	for (int i = 0; i < n; i++)
	{
		int numberOfSwaps = 0;

		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				numberOfSwaps++;
			}
		}
		swaps += numberOfSwaps;

		if (numberOfSwaps == 0) {
			break;
		}
	}
}


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++)
		cin >> a[a_i];

	int swaps = 0;
	bubble_sort(a, swaps);

	printf("Array is sorted in %d swaps.\n", swaps);
	printf("First Element: %d\n", a[0]);
	printf("Last Element: %d\n", a[n - 1]);
}
