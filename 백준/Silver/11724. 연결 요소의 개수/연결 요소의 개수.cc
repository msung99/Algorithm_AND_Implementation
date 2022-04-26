#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		count++;
		queue<int> q;
		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for(auto nxt : adj_list[cur])
			{
				if (visited[nxt])
					continue;
				q.push(nxt);
				visited[nxt] = true;
			}
		}
	}
	cout << count;
}