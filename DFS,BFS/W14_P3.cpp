#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> adj_list[1000];  // 범위설정 제대로 하자!!! 100 으로 설정하면 런에러뜬다 ㅡㅡ 
		bool visited[1000];
		fill(visited + 1, visited + n + 1, false);

		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		// BFS  <=> DFS 에서 "큐" 만 활용하면 끝!
		int count = 1; //  홀수일때만 출력하도록 카운팅하는 변수
		queue<int> q; // BFS 돌기전에 시작정점 1 삽입
		q.push(1);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			if (visited[cur])
				continue;

			visited[cur] = true;  // 방문처리

			if (count % 2 == 1)
				cout << cur << ' ';
			for (auto nxt : adj_list[cur]) // 현재 보고있는 정점과 인접한 모든 정점들에 대해 확인
			{
				if (visited[nxt]) // 이미 방문한 정점이라면 스킵
					continue;
				q.push(nxt); // 처음 방문하는 정점이라면 큐에 push
			}
			count++;
		}
		cout << endl;
	}
}