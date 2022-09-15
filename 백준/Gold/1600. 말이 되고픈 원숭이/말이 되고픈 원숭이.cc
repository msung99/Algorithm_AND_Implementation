#include <bits/stdc++.h>
using namespace std;

int board[202][202];
int dist[32][202][202];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dkx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dky[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int init_horse, x, y;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> init_horse >> y >> x;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> board[i][j];

	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int cur_horse, curX, curY;
		tie(cur_horse, curX, curY) = q.front();
		q.pop();

		// => cur_horse : 현 좌표(vx, vy)에 대해서 처리하는 현 순간까지 카운팅된 총 말의 움직임 횟수
		// 현재 시점에서 카운팅된 말의 이동 횟수(vk)를 보아하니, 아직 더 움직일 수 있는경우
		if (cur_horse < init_horse) {  
			// 체크의 나이트 움직임으로 이동 (4방향으로 뻗어서 이동하는 것보다 우선순위가 높다)
			for (int i = 0; i < 8; i++) {
				int nx = curX + dkx[i];
				int ny = curY + dky[i];

				if (nx < 0 || ny < 0 || x <= nx || y <= ny)
					continue;

				if (board[nx][ny])
					continue;

				if (dist[cur_horse + 1][nx][ny])  // 이미 처리한 말의 이동시간대 좌표인 경우
					continue;

				dist[cur_horse + 1][nx][ny] = dist[cur_horse][curX][curY] + 1;
				q.push({ cur_horse + 1, nx, ny });
			}
		}

		// 4방향으로 평범하게 이동
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || x <= nx || y <= ny)
				continue;

			if (board[nx][ny])
				continue;

			if (dist[cur_horse][nx][ny]) 
				continue;
			
			dist[cur_horse][nx][ny] = dist[cur_horse][curX][curY] + 1;
			q.push({ cur_horse, nx, ny });
		}
	}

	int ans = 0x7f7f7f7f;
	for (int i = 0; i < init_horse + 1; i++) {
		if (dist[i][x - 1][y - 1])
			ans = min(ans, dist[i][x - 1][y - 1]);
	}
	if (ans != 0x7f7f7f7f) cout << ans - 1;
	else cout << -1;
;
}
