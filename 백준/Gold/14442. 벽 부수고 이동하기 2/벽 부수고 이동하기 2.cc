#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist[1002][1002][12];
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

	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int curX, curY, count;
		tie(curX, curY, count) = q.front();
		q.pop();

		if (curX == n-1 && curY == m-1) {
			cout << dist[curX][curY][count];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			int new_count = count;
			if (board[nx][ny] == '1')
				new_count += 1;

			if (new_count > k || dist[nx][ny][new_count] > 0)
				continue;

			dist[nx][ny][new_count] = dist[curX][curY][count] + 1;
			q.push({ nx,ny,new_count });
		}
	}
	cout << -1;
}