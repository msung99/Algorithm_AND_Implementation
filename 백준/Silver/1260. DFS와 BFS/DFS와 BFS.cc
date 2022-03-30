#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj_list[1002];
bool visited1[1002];
bool visited2[1002];


int main(void)
{
	int n, m, u, v;
	int start;
	
	cin >> n >> m >> start;

	while(m--)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	// 번호가 작은 것 부터 방문하기 위해 정렬
	for (int i = 1; i <= n; i++)
		sort(adj_list[i].begin(), adj_list[i].end());

	// DFS 탐색 - dfs 탐색은 스택에 넣자마자 바로 방문 처리하는 것이 아니다!
	stack<int> s;
	s.push(start); // 정점 start 에서 DFS 탐색을 시작
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		if (visited1[cur])
			continue;
		visited1[cur] = true;
		cout << cur << ' ';
		for (int i = 0; i < adj_list[cur].size(); i++)
		{
			// 스택의 특성상 정점을 역순으로 넣어야지 값이 작은 정점이 스택의 상단에 위치하게 되어서 먼저 방문하게 된다.
			int tmp = adj_list[cur][adj_list[cur].size() - 1 - i];
			if (visited1[tmp])
				continue;
			s.push(tmp);
		}
	}

	cout << '\n';


	// BFS 탐색
	queue<int> q;
	q.push(start); // 정점 start 에서 BFS 탐색을 시작
	visited2[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (auto tmp : adj_list[cur])
		{
			if (visited2[tmp])
				continue;
			q.push(tmp);
			visited2[tmp] = true;
		}
	}
}