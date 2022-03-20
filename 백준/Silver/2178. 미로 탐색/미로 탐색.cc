#include <iostream>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string board[100];
	int distance[100][100];

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	// distance 원소 -1로 초기화
	for (int i = 0; i < n; i++)
		fill(distance[i], distance[i] + m, -1);

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	distance[0][0] = 0;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;
			// distance[x][y] >= 0  => distance가 0 이상이면 이전에 그 좌표에 대한 거리를 계산했다는 의미
			// distnace 값이 -1인 칸에 대해서만 처리.이 외에는 이전에 이미 방문해서 처리한 칸이다.
			if (distance[x][y] != -1 || board[x][y] != '1' )
				continue;
			q.push({ x,y });
			distance[x][y] = distance[cur.first][cur.second] + 1; // 직전 칸의 값에다 +1
		}
	}
	cout << distance[n - 1][m - 1] + 1;
}