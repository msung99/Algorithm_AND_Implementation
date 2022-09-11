#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int n, m;
int dx[3] = { 1,-1, 2 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	queue<int> q;
	q.push(n);

	fill(dist, dist + 100001, -1);
	dist[n] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int nx = 0;

			if (i == 2) // 순간이동을 하는 경우
				nx = cur * dx[i];
			else  // 걷는 경우 
				nx = cur + dx[i];

			if (nx < 0 || nx > 100000)
				continue;

			if (dist[nx] != -1)
				continue;

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}
	cout << dist[m];
}
