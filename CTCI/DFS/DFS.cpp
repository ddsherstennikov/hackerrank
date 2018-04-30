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
#include <unordered_set>

using namespace std;


namespace std
{
	template<>
	struct hash<pair<int,int>> {
	public:
		template <typename T, typename U>
		std::size_t operator()(const std::pair<T, U> &x) const
		{
			return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
		}
	};
}



int eat_region(int grid_i, int grid_j, vector<vector<int>>& grid, unordered_set<std::pair<int, int>>& seen)
{
	int n = grid.size();
	int m = grid[0].size();
		
	stack<pair<int, int>> to_visit;
	to_visit.push({ grid_i, grid_j });
	seen.insert({ grid_i, grid_j });
	int sz = 0;

	while (!to_visit.empty())
	{
		auto v = to_visit.top();
		grid[v.first][v.second] = 0;
		sz++;
		to_visit.pop();

		if (v.first >= 1 && v.second >= 1 && grid[v.first - 1][v.second - 1] && seen.count({ v.first - 1, v.second - 1 }) == 0)
		{
			to_visit.push({ v.first - 1, v.second - 1 });
			seen.insert({ v.first - 1, v.second - 1 });
		}
		if (v.first >= 1 && grid[v.first - 1][v.second] && seen.count({ v.first - 1, v.second  }) == 0)
		{
			to_visit.push({ v.first - 1, v.second });
			seen.insert({ v.first - 1, v.second });
		}
		if (v.second >= 1 && grid[v.first][v.second-1] && seen.count({ v.first, v.second - 1 }) == 0)
		{
			to_visit.push({ v.first, v.second -1 });
			seen.insert({ v.first, v.second - 1 });
		}
		if (v.first <= n - 2 && v.second >= 1 && grid[v.first + 1][v.second - 1] && seen.count({ v.first + 1, v.second - 1 }) == 0)
		{
			to_visit.push({ v.first + 1, v.second - 1 });
			seen.insert({ v.first + 1, v.second - 1 });
		}
		if (v.first >= 1 && v.second <= m-2 && grid[v.first - 1][v.second + 1] && seen.count({ v.first - 1, v.second + 1 }) == 0)
		{
			to_visit.push({ v.first - 1, v.second + 1 });
			seen.insert({ v.first - 1, v.second + 1 });
		}
		if (v.second <= m - 2 && grid[v.first][v.second + 1] && seen.count({ v.first, v.second + 1 }) == 0)
		{
			to_visit.push({ v.first, v.second + 1 });
			seen.insert({ v.first, v.second + 1 });
		}
		if (v.first <= n - 2 && v.second <= m - 2 && grid[v.first + 1][v.second + 1] && seen.count({ v.first + 1, v.second + 1 }) == 0)
		{
			to_visit.push({ v.first + 1, v.second + 1 });
			seen.insert({ v.first + 1, v.second + 1 });
		}
		if (v.first <= n - 2 && grid[v.first + 1][v.second] && seen.count({ v.first + 1, v.second }) == 0)
		{
			to_visit.push({ v.first + 1, v.second });
			seen.insert({ v.first + 1, v.second });
		}
	}

	return sz;
}

int get_biggest_region(vector<vector<int>>& grid) 
{
	int n = grid.size();
	int m = grid[0].size();
	int r = 0;

	unordered_set<pair<int, int>> seen;

	for (int grid_i = 0; grid_i < n; ++grid_i)
	{
		for (int grid_j = 0; grid_j < m; ++grid_j)
		{
			if (grid[grid_i][grid_j] == 0)
				continue;
			else
			{
				int region_size = eat_region(grid_i, grid_j, grid, seen);
				if (region_size > r)
					r = region_size;
				if (r >= ceil(n*m / 2))
					break;
			}
		}
	}

	return r;
}

int main() 
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector< vector<int> > grid(n, vector<int>(m));
	for (int grid_i = 0; grid_i < n; grid_i++) 
	{
		for (int grid_j = 0; grid_j < m; grid_j++) 
		{
			cin >> grid[grid_i][grid_j];
		}
	}
	cout << get_biggest_region(grid) << endl;
	return 0;
}
