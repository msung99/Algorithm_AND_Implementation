#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[20001];
int dist[20001];

void bfs() {
	fill(dist, dist + n + 1, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj_list[cur]) {
			if (dist[nxt] != -1)
				continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	bfs();

	int max_dist = *max_element(dist, dist + n + 1);

	for (int i = 1; i <= n; i++) {
		if (max_dist == dist[i]) {
			cout << i << ' ';
			break;
		}
	}

	cout << max_dist << ' ';

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (max_dist == dist[i])
			count++;
	}
	cout << count;
}
