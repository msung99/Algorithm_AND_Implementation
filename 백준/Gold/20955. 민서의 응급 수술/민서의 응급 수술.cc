/*
가능한 연산 종류 : 1) 연결되지 않은 두 뉴런을 연결하기 2) 이미 연결된 두 뉴런의 연결을 끊기


* 뉴런끼리 연결을 끊어야만 하는 경우가 언제인가?
=> 사이클이다! 민서는 트리를 만들고 싶어하는 것이니, 사이클을 필히 지워주어야 한다.
따라서 "연결요소의 개수 - 1 + 사이클 개수" 가 최소 연산 횟수가 된다.

(사이클에서 간선 하나만 지우면 되므로)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100005];
bool visited[100005];
bool cycle[100005];
int n, m, cnt = 0;

void dfs(int s, int prev) {
	visited[s] = true;
	for (int tmp : adj_list[s]) {
		if (!visited[tmp])
			dfs(tmp, s);
		else if (!cycle[tmp] && tmp != prev)
			cnt++;
	}
	cycle[s] = true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) { 
			dfs(i, 0);
			ans++; // 연결요소의 개수를 카운팅
		}
	}
	cout << ans - 1 + cnt;
}
