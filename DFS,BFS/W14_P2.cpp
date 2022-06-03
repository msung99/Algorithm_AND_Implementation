#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;


int main(void)
{
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int n, m, question;
		cin >> n >> m >> question;

		vector<int> adj_list[1000];
		bool visited[1000];
		int min_list[1000];  // 최솟값 리스트

		// 초기화 작업 (초기 셋팅)
		fill(visited + 1, visited + n + 1, false);

		for (int i = 0; i < 100; i++)
			min_list[i] = 0;

		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		// BFS 

		for (int i = 1; i <= n; i++)
		{

			if (visited[i])
				continue;

			queue<int> q;
			q.push(i);
			visited[i] = true;

			int min = q.front();  // 각 conncted 컴포넌트의 최솟값

			// while이 다 끝나면 현재 BFS를 돌린 시작정점과 연결된 정점들이 다 방문처리가 되었을 것이다.
			// 즉, 시작정점이 속해있는 해당 conncted 컴포넌트가 모두 방문처리 된다! 
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto nxt : adj_list[cur])
				{
					if (visited[nxt])
						continue;
					// 현재 정점과 인접한 정점들이 각각 최솟값이 될수 있는지를 확인
					if (min > nxt)
						min = nxt;
					q.push(nxt);
					visited[nxt] = true;

					min_list[nxt] = min; // // 최솟값 리스트의 각 정점이 저장하고 있는 최솟값들을 최신화
				}
				min_list[i] = min; // 최솟값 리스트에서 인접한 정점들에 대해서 최솟값을 최신화 했으니, 자신도 최신화 시켜줌
			}
		}

		// for (int i = 0; i < 20; i++)
		//	cout << i << ":" << min_list[i] << endl;

		// 질문 시작
		while (question--)
		{
			int ans;
			cin >> ans;
			cout << min_list[ans] << endl;
		}
	}
}