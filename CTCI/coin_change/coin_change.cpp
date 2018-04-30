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


bool check_validity(vector<int>& coins, int money)
{
	if (money <= 0)
		return 0;
	else if (coins.size() == 0)
		return 0;
	else if (coins.size() == 1 && money % coins[0] != 0)
		return 0;
	else
	{
		for (auto& c : coins)
		{
			if (c <= 0)
				return 0;
		}
	}

	return 1;
}


long long make_change(vector<int>& coins, int money) 
{
	if (!check_validity(coins, money))
		return 0;

	static vector<long long> memo(money + 1, 0);

	memo[0] = 1;

	for (int coin : coins)
		for (int amount = 1; amount <= money; ++amount)
			if (amount >= coin)
				memo[amount] += memo[amount-coin];

	return memo[money];
}

int main() 
{
	int n;
	int m;
	cin >> n >> m;
	vector<int> coins(m);
	for (int coins_i = 0; coins_i < m; coins_i++) 
	{
		cin >> coins[coins_i];
	}
	std::sort(coins.begin(), coins.end());
	cout << make_change(coins, n) << endl;
	return 0;
}
