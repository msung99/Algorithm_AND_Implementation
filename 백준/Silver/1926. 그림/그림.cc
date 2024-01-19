#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[501][501];
bool visited[501][501];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int bfs(int curX, int curY) {
	queue<pair<int,int>> q;
	q.push({curX, curY});

	int area = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		visited[x][y] = true; 
		area++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (!visited[nx][ny] && board[nx][ny] == 1) {
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
	}
	return area;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int data;
			cin >> data;
			board[i][j] = data;
		}
	}

	int maxVal = 0;
	int areas = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && board[i][j] == 1) {
				maxVal = max(maxVal, bfs(i, j));
				areas++;
			}
		}
	}

	cout << areas << "\n" << maxVal;
	return 0;
}