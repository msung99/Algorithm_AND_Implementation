#include <bits/stdc++.h>
using namespace std;

string board[26];
bool visited[26][26];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int n;

int bfs(int curX, int curY) {
	queue<pair<int, int>> q;
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

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (visited[nx][ny] || board[nx][ny] == '0')
				continue;

			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}
	return area;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		board[i] = str;
	}

	vector<int> areas;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && board[i][j] == '1') {
				int res = bfs(i, j);
				areas.push_back(res);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	sort(areas.begin(), areas.end());
	for (int i = 0; i < areas.size(); i++) {
		cout << areas[i] << "\n";
	}
	return 0;
}