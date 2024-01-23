#include <bits/stdc++.h>
using namespace std;

int dz[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dx[6] = {0,0,0,0,1,-1};
int n, m, h;
int board[102][102][102];
int dist[102][102][102];
queue<tuple<int, int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// m : 5, n : 3, h ;2
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) { // 2
		for (int j = 0; j < n; j++) { // 3
			for (int k = 0; k < m; k++) { // 5
				int tmp;
				cin >> tmp;
				board[j][k][i] = tmp;
				if (tmp == 1)
					q.push({j,k,i});
				if (tmp == 0)
					dist[j][k][i] = -1;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int curx, cury, curz;
		tie(curx, cury, curz) = cur;

		for (int i = 0; i < 6; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			int nz = curz + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
				continue;

			if (dist[nx][ny][nz] >= 0)
				continue;

			dist[nx][ny][nz] = dist[curx][cury][curz] + 1;
			q.push({ nx, ny, nz });
		}
	}

	int ans = 0;
	for(int i=0; i<h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1 << "\n";
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}