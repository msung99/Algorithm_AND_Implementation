#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> adj_list[101];
bool visited[101];

int main(void)
{
	int n, m; // v : 정점의 수(컴퓨터의 수), n : 간선의 수
	cin >> n >> m;

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	int count = 0;  // 바이러스 걸리는 컴퓨터의 수
	stack<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int cur = q.top();
		q.pop();
		for (auto num : adj_list[cur])
		{
			if (visited[num])
				continue;
			count++;
			q.push(num);
			visited[num] = true;
		}
	}
	cout << count;
}