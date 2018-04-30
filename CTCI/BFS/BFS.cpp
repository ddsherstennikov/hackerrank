#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


class Graph 
{
public:
	Graph(int n) : n(n), adj_list(n, list<int>())
	{
	}

	void add_edge(int u, int v) 
	{
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<int> shortest_reach(int start) 
	{
		vector<int> distance(n, -1);
		queue<int> q;
		q.push(start);
		distance[start] = 0;

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (int child : adj_list[cur])
				if (distance.at(child) == -1)
				{
					distance[child] = distance[cur] + 6;
					q.push(child);
				}
		}

		return distance;
	}

	int n;
	vector<list<int>> adj_list;
};

int main() 
{
	int queries;
	cin >> queries;

	for (int t = 0; t < queries; t++) 
	{

		int n, m;
		cin >> n;
		// Create a graph of size n where each edge weight is 6: 
		Graph graph(n);
		cin >> m;
		// read and set edges
		for (int i = 0; i < m; i++) 
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			// add each edge to the graph
			graph.add_edge(u, v);
		}
		int startId;
		cin >> startId;
		startId--;
		// Find shortest reach from node s
		vector<int> distances = graph.shortest_reach(startId);

		for (int i = 0; i < distances.size(); i++) 
		{
			if (i != startId) 
			{
				cout << distances[i] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
