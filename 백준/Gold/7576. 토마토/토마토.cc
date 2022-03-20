#include <iostream>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	queue<pair<int, int>> q;
	
	// board판을 초기화 하면서 동시에 익은 토마토의 좌표를 구하고 큐에다 push
	// 익은 토마토들을 미리 큐에다 push 하고, 그들을 BFS 탐색의 시작점으로 삼는다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) // 익은 토마토 좌표를 찾은 경우 큐에다 push
				q.push({ i,j });
			if (board[i][j] == 0) // 익지 않은 토마토인 경우
				dist[i][j] = -1; // 그 좌표의 distance를 -1로 초기화
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;
			if (dist[x][y] != -1) // 아직 거리 계산하지 않은 좌표들에 대해서만 처리
				continue;
			dist[x][y] = dist[cur.first][cur.second] + 1;
			q.push({ x,y });
		}
	}

	// distance 요소중에 최댓값 찾기. 최댓값이 바로 정답이 된다. 
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) // 모든 토마토가 익지는 못한 상황인 경우
			{
				cout << -1;
				return 0;
			}
			mx = max(mx, dist[i][j]);
		}
	}
	cout << mx;
}
