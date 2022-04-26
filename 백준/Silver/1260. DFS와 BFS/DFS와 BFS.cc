#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, start;
vector<int> adj_list[1001] ;
bool visited[1001];

// 비재귀 DFS
void DFS_1()
{
	stack<int> s;
	s.push(start);
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		if (visited[cur])
			continue;
		visited[cur] = true;
		cout << cur << ' ';
		for (int i = 0; i < adj_list[cur].size(); i++)
		{
			// 스택의 특성상 역순으로 넣어야지 작은 정점이 스택의 상단에 위치하게 되서, 작은 정점을 먼저 방문하게 됨
			int nxt = adj_list[cur][adj_list[cur].size() - 1 - i];
			if (visited[nxt])
				continue;
			s.push(nxt);
		}
	}
}

// 재귀 DFS
void DFS_2(int cur)
{
	visited[cur] = true;
	cout << cur << ' ';
	for (auto nxt : adj_list[cur])
	{
		if (visited[cur])
			continue;
		DFS_2(nxt);
	}
}


// BFS
void BFS()
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (auto nxt : adj_list[cur])
		{
			if (visited[nxt])
				continue;
			q.push(nxt);
			visited[nxt] = true;
		}
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> start;

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	// 번호가 작은 것부터 방문하기 위해 정렬
	for (int i = 1; i <= n; i++)
		sort(adj_list[i].begin(), adj_list[i].end());

	DFS_1();
	cout << '\n';
	fill(visited+1, visited+n+1, false);
	BFS();
}