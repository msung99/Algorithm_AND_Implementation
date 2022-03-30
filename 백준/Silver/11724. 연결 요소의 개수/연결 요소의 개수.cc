#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj_list[1005];
int visited[1005];

int main(void)
{
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	int count = 0; //  구역의 개수( = 연결 요소의 개수)

	// 이전에 풀었던 BOJ "그림" 문제랑 동일한 원리로 코드를 구성하면 된다.
	// BFS 실행 - 구역의 개수를 구함
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		count++;
		queue<int> q;
		q.push(i);

		// 본격적인 BFS 탐색 진행
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			
			// 예전에 다차원 배열에서는 cur 와 인접한 정점을 돌기 위해 상하좌우에 있는 애들을 탐색했다면,
			// 그래프에서는 인접 리스트에 저장해 놓은 인접한 정점들에 대해서 탐색을 진행하면 된다.
			for (auto tmp : adj_list[cur])
			{
				if (visited[tmp])
					continue;
				q.push(tmp);
				visited[tmp] = true;
			}
		}
	}
	cout << count;
}