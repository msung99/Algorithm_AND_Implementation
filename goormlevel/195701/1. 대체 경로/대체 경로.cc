#include <bits/stdc++.h>
using namespace std;

int n, m, s, e;
vector<int> adj_list[1002];
int dist[1002];

// city : 현재 Round 에서 공사중인 도시
void bfs(int city) {
	queue<int> q;
	q.push(s);
	dist[s] = 1;
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if(cur == city) {
			continue;
		}
		
		if(cur == e) {
			cout << dist[cur] << "\n";
			return;
		}
		
		for(int next : adj_list[cur]) {
			if(dist[next] != -1) {
				continue;
			}
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
	cout << -1 << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> s >> e;
	
	while(m--) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	
	for(int i=1; i<=n; i++) {
		fill(dist, dist + n + 1, -1);
		bfs(i);
	}
	
	return 0;
}