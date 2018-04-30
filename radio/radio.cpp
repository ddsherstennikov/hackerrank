#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;



int number_of_transmitters(vector<int>& houses, int N, int K)
{
	sort(houses.begin(), houses.end());

	int host_idx = 0;
	int n = 1;
	vector<int> coverage_idxs;

	int i = 0;
	while(i < N)
	{
		if (abs(houses[i] - houses[host_idx]) <= K)
		{
			coverage_idxs.push_back(i);
			i++;
		}
		else if (abs(houses[coverage_idxs[0]] - houses[i]) <= 2 * K && abs(houses[coverage_idxs[0]] - houses[host_idx + 1]) <= K && host_idx + 1 <= coverage_idxs.back())
		{
			while(abs(houses[coverage_idxs[0]] - houses[host_idx + 1]) <= K && host_idx + 1 <= coverage_idxs.back())
				host_idx++;
		}
		else
		{
			n++;
			host_idx = i;
			coverage_idxs.clear();
			coverage_idxs.push_back(i);
			i++;
		}
	}

	return n;
}



int main() 
{
	int N, K;
	cin >> N >> K;

	vector<int> houses(N);
	for (int i = 0; i < N; ++i)
		cin >> houses[i];

	cout << number_of_transmitters(houses, N, K);

	return 0;
}
