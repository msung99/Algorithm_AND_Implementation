#include <bits/stdc++.h>
using namespace std;
// start : 5, end : 17

// 5-10-9-18-17
// 5-4-8-16-17
int dist[100001];
int cnt[100001]; // cnt[i] : 출발장소에서 도착지 i 에 도달할 수 있는 방법의 수

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(dist, dist + 100001, -1);
	fill(cnt, cnt + 100001, -1);

	int source, dest;
	cin >> source >> dest;

	queue<int> q;
	q.push(source);
	dist[source] = 0;
	cnt[source] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : {cur + 1, cur - 1, cur * 2}) {
			if (next < 0 || next >= 100001)
				continue;
			// 방문 했던 곳이라면
			if (dist[next] != -1) {
				// 최단 거리 값이 같다면
				if (dist[next] == dist[cur] + 1) {
					cnt[next] += cnt[cur];
				}
			} 
			// 처음 방문하는 곳이라면
			else {
				dist[next] = dist[cur] + 1;
				cnt[next] = cnt[cur];
				q.push(next);
			}
		}
	}

	cout << dist[dest] << "\n";
	cout << cnt[dest];
	return 0;
}