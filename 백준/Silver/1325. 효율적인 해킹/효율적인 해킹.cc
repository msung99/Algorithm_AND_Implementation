#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[10001];
bool visited[10001];
// vector<pair<int,int>> sortArr;
vector<int> arr;

int bfs(int start) {
	int cnt = 1;
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj_list[cur]) {
			if (visited[nxt])
				continue;
			q.push(nxt);
			visited[nxt] = true;
			cnt++;
		}
	}

	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj_list[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		int cur_count = bfs(i);
		arr.push_back(cur_count),
		fill(visited, visited + n + 1, false);
	}

	int max_value = *max_element(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		if (max_value == arr[i])
			cout << i + 1 << ' ';
	}
}