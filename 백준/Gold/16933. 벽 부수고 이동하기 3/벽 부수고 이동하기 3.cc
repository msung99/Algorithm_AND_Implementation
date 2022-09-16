#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist[1002][1002][12][2]; 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	queue<tuple<int, int, int, int>> q;
	q.push({ 0,0,0,0 });
	dist[0][0][0][0] = 1;

	while (!q.empty()) {
		int x, y, w, t;
		tie(x, y, w, t) = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][w][t] << '\n';
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			// 만약 (nx, ny) 가 빈 곳이라면 편하게 가면 된다.
			if (board[nx][ny] == '0') {
				int nw = w; // 벽 부수기 횟수 증가 x
				int nt = 1 - t; // t = 1 이라면 nt = 0 이 할당되고, t = 0 이라면 nt = 1 이 할당 (낮과 밤이 바뀜)

				if (dist[nx][ny][nw][nt] > 0)
					continue;

				dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
				q.push({ nx,ny,nw,nt });
			}
			// 비어있지 않다면 (즉, 벽이 있는 좌표라면)
			else {
				if (w == k) // 이미 k번 벽을 부순경우 더 이상 부술 수 없다.
					continue;

				// 낮이라면 꺠고 넘어가면 된다. (문제조건 : 낮에만 벽을 부술 수 있다)
				if (t == 0) {
					int nw = w + 1;
					int nt = 1 - t;

					if (dist[nx][ny][nw][nt] > 0)
						continue;

					dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
					q.push({ nx,ny,nw,nt });
				}

				// 밤인 경우, 낮이 올때까지 기다려야 한다.
				else {
					int nt = 1 - t;

					if (dist[x][y][w][nt] > 0) // 다음 좌표가 (nx, ny, nw, nt)가 아닌 (x, y, w, nt)라는 점에 주의한다.
						continue;

					dist[x][y][w][nt] = dist[x][y][w][t] + 1; 
					q.push({ x,y,w,nt });
				}
			}
		}
	}
	cout << -1;
}