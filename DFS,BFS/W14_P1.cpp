#include <iostream>
#include <stack>
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

		// DFS
		int count = 1; //  홀수일때만 출력하도록 카운팅하는 변수
		stack<int> s; // DFS 돌기전에 시작정점 1 삽입
		s.push(1);
		while (!s.empty())
		{
			int cur = s.top();
			s.pop();
			
			if (visited[cur])
				continue;
			
			visited[cur] = true;  // 방문처리

			if (count % 2 == 1)
				cout << cur << ' ';
			for (int i = 0; i < adj_list[cur].size(); i++)
			{
				// 스택의 특성상 역순으로 넣어야지 먼저 간선이 만들어진 정점이 스택이 먼저 쌓이고, 나중에 탐색을 진행하게 된다.
				int nxt = adj_list[cur][adj_list[cur].size() - 1 - i];
				if (visited[nxt])  // 이미 방문한 정점이라면 스킵
					continue;
				s.push(nxt);
			}
			count++;
		}
		cout << endl;
	}
}
