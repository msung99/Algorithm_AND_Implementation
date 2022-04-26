#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj_list[501];
int dist[501];

int main(void)
{
	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto num : adj_list[cur])
		{
			if (dist[num] != 0)
				continue;
			dist[num] = dist[cur] + 1;
			q.push(num);
		}
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 2 || dist[i] == 3)
			count++;
	}
	cout << count;
}