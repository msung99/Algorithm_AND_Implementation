#include <bits/stdc++.h>
using namespace std;

string board[101];
bool visited1[101][101];
int n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs1(int x, int y) {
	queue<pair<int, int>> q1;
	q1.push({ x,y});
	while (!q1.empty()) {
		int x = q1.front().first;
		int y = q1.front().second;
		q1.pop();
		visited1[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (board[x][y] != board[nx][ny] || visited1[nx][ny])
				continue;

			q1.push({ nx,ny });
			visited1[nx][ny] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	// 적록색약이 아닌 경우 (R, G 를 다른 색깔로 분류)
	int count1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited1[i][j]) {
				bfs1(i, j);
				count1++;
			}
		}
	}

	// 적록색약인 경우 (R, G 를 동일한 색깔로 취급)
	// => 초록과 빨강을 구분 못하므로 초록을 빨강으로 바꿔줌
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		fill(visited1[i], visited1[i] + n, false);
	}

	int count2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited1[i][j]) {
				bfs1(i, j);
				count2++;
			}
		}
	}
	cout << count1 << ' ' << count2;
	return 0;
}