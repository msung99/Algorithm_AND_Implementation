#include <bits/stdc++.h>
using namespace std;

int dist[1000002];
int f, s, g, u, d;
int dx[2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// f층 건물, 현재 s층, 목표 층수는 g층, u층을 위로가는 버튼, d층을 아래로 가는버튼
	cin >> f >> s >> g >> u >> d;

	dx[0] = u;
	dx[1] = -d;
	fill(dist, dist + f + 1, -1);

	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int nx = cur + dx[i];
			
			if (nx <= 0 || nx > f) // "nx < 0" 이 아니라, "nx <= 0" 임을 주의하자!! 0층은 없기 떄문이다! 
				continue;

			if (dist[nx] != -1)
				continue;

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}

	//for (int i = 0; i < f + 2; i++) {
	//	cout << dist[i] << ' ';
	//}
	//cout << endl;

	if (dist[g] == -1)
		cout << "use the stairs";
	else
		cout << dist[g];
}