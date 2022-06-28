#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	int testCase = 0;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;

		vector<int> adj_list[1002];
		queue<int> q;
		bool visited[1002];

		fill(visited, visited + 1002, false);
		int count = 0;
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
			// 무방향 트리의 조건 : 간선/2 == 정점 -1   => 이를 활용해서 트리인지 아닌지를 판단
			int edge = 0;
			int vertex = 0;
			if (visited[i] == false) // 해당 노드를 이미 방문한 경우 = 해당 노드(visited[i]) 가 속해있는 connected 컴포넌트에 대해 이미 방문처리를 완료한 경우
			{
				count++;
				q.push(i);
				while (!q.empty())
				{
					int cur = q.front();
					q.pop();

					if (visited[cur])  // 이미 방문한 정점이면 정점 개수에 추가 x
						continue;
					
					vertex++; // 정점개수 카운팅
					visited[cur] = true; 

					// 양방향 그래프의 간선이 추가된다.

					for (int j = 0; j < adj_list[cur].size(); j++)
					{
						edge++; // 간선 개수 카운팅
						q.push(adj_list[cur][j]);
					}
				}
				if (edge / 2 != vertex - 1) // 트리이기 위해서는 "간선 / 2 ==  정점 -1" 이어야 한다.
					count--;

				edge = 0;
				vertex = 0;
			}
		}
		if (count >= 2) {
			cout << "Case " << ++testCase << ": A forest of " << count << " trees." << endl;
		}
		else if (count == 1) {
			cout << "Case " << ++testCase << ": There is one tree." << endl;
		}
		else if (count == 0) {
			cout << "Case " << ++testCase << ": No trees." << endl;
		}
	}
}
