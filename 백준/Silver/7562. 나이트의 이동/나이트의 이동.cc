#include <bits/stdc++.h>
using namespace std;

int dist[302][302];
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int s1, s2, e1, e2;
		cin >> s1 >> s2;
		cin >> e1 >> e2;
		pair<int, int> start = make_pair(s1, s2);
		pair<int, int> end = make_pair(e1, e2);

		for (int i = 0; i < n; i++) {
			fill(dist[i], dist[i] + n, -1);
		}

		queue<pair<int, int>> q;
		q.push({ s1,s2 });
		dist[s1][s2] = 0;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				if (dist[nx][ny] != -1)
					continue;

				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
		cout << dist[end.first][end.second] << "\n";
	}
	return 0;
}