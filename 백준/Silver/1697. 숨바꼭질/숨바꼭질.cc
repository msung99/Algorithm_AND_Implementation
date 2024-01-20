#include <bits/stdc++.h>
using namespace std;

int dist[100002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int start, end;
	cin >> start >> end;
	fill(dist, dist + 100001, -1);
	dist[start] = 0;

	queue<int> q;
	q.push(start);


	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : {cur + 1, cur - 1, cur * 2}) {
			if (next < 0 || next > 100000 || dist[next] != -1)
				continue;

			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
	cout << dist[end];
	return 0;
}