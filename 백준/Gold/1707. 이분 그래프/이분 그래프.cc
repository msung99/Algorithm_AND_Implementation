#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20001
#define RED 1 
#define BLUE 2

vector<int> adj_list[20001];
int color[20001]; // 색깔의 종류는 RED(= 1) 과 BLUE(= 2)로 두가지이다. 만일 0 이라면 아직 색깔을 처리안한 정점인 것이다.
int v, e;
int u, v1;

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	color[start] = RED; // 색깔
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto nxt : adj_list[cur])
		{
			if (color[nxt] != 0) // 이미 색깔 처리 완료한 정점이라면 skip
				continue;

			// 현재 인접해 있는 정점들에 대해서 현재 색깔과 다른 색깔로 칠해준다.
			if (color[cur] == RED) // 색깔 1이라면
			{
				color[nxt] = BLUE; // 색깔 2로 설정
				q.push(nxt);
			}

			else if (color[cur] == BLUE) // 색깔 2이라면
			{
				color[nxt] = RED; // 색깔 1로 설정
				q.push(nxt);
			}
		}
	}
}

// 이분 그래프인지 판단 
bool is_Divide_Graph()
{
	for (int i = 1; i <= v; i++)
	{
		for(int j = 0; j < adj_list[i].size(); j++)
		{
			int nxt = adj_list[i][j];
			if (color[i] == color[nxt]) // 정점 i와 인접한 정점들 중에서 동일한 색깔이 존재한다면 이분 그래프가 아니다. 
				return false;         
		}
	}
	return true;
}

int main(void)
{
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		cin >> v >> e;
		while (e--)
		{
			cin >> u >> v1;
			adj_list[u].push_back(v1);
			adj_list[v1].push_back(u);
		}
		
		// 각 정점에 대해 BFS를 실행함으로써 각 정점들에 대해 색깔을 채워 넣는다.
		// (그래프가 모두 연결되어 있다는 보장이 없으므로, 색깔 처리가 완료되지 않은 정점들에 대해 BFS를 실행)
		for (int i = 1; i <= v; i++)
		{
			if (!color[i])
				BFS(i);
		}

		if (is_Divide_Graph())
			cout << "YES\n";
		else
			cout << "NO\n";

		// 그래프 인접리스트 및 색깔 초기화
		for (int i = 1; i <= v; i++)
			adj_list[i].clear();

		fill(color, color + v + 1, 0);
	}
}