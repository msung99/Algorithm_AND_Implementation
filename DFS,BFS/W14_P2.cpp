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

			if (visited[i]) // 해당 노드를 이미 방문한 경우 = 해당 노드(visited[i]) 가 속해있는 connected 컴포넌트에 대해 이미 방문처리를 완료한 경우
				continue;  // 스킵
			
			// 아직 방문처리안한 connected 컴포넌트일때 방문처리를 아래와 같이 실행
			
			queue<int> q;
			q.push(i);
			visited[i] = true;

			int min = i;  // 각 conncted 컴포넌트의 최솟값 => for문을 돌릴때마다 최솟값 min 의 값은 1,2,3,4,... 순으로 값이 
			min_list[i] = min; // 최솟값 리스트에서 우선 자신(인덱스 i) 에 대한 최솟값을 최신화
			
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
					
					q.push(nxt);
					visited[nxt] = true;
					// 최솟값을 자신과 인접한 정점들에게 점점 감염되는것 마냥 전파시킴
					min_list[nxt] = min; // // 최솟값 리스트의 각 정점이 저장하고 있는 최솟값들을 최신화
				}
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
