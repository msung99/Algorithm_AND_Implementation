#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> adj[100001];
int parent[100001];

void BFS(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			if (parent[cur] == nxt)
				continue;
			q.push(nxt);
			parent[nxt] = cur;
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	BFS(1);
	for (int i = 2; i < n+1; i++)
	{
		cout << parent[i] << '\n';
	}
}