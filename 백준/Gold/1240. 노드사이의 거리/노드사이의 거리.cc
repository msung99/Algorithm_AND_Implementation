#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<pair<int, int>> adj_list[1001]; 
int n, m;
bool visited[1001];

int BFS(int x, int y) 
{
	fill(visited, visited + 1001, false);
	queue<pair<int, int>> q;
	visited[x] = true;
	q.push(make_pair( x,0 ));

	while (!q.empty())
	{
		int curX = q.front().first;
		int curDist = q.front().second;
		q.pop();

		if (curX == y)   // BFS 탐색을 돌리다가 우리가 원하는 x의 반대편 정점인 y 를 찾게되면 
			return curDist; // 현재까지 계산한 거리 값을 리턴

		// 현재 탐색중인 정점 curX 와 인접한 정점들에 대해 모두 탐색
		for (int i = 0; i < adj_list[curX].size(); i++) {
			
			int nextX = adj_list[curX][i].first;
			int nextDist = adj_list[curX][i].second;

			if (!visited[nextX]) {
				visited[nextX] = true;
				q.push(make_pair(nextX, curDist + nextDist));  // 현재까지 탐색하면서 이어온 정점까지의 거리(curDist) 에 다음 정점으로 넘어갔을때의 정점까지의 거리(nextDist) 를 추가
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	fill(visited, visited + 1001 , false);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v, dist;
		cin >> u >> v >> dist;
		adj_list[u].push_back({ v, dist });
		adj_list[v].push_back({ u, dist });
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << BFS(x, y) << '\n';
	}
}