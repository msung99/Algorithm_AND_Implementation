#include <bits/stdc++.h>
using namespace std;

int dist[200002];
int prevPos[200002];
int start, e;
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> start >> e;

	fill(dist, dist + 200002, -1);

	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : {cur + 1, cur - 1, cur * 2}) {
			if (next < 0 || next >= 100001)
				continue;
			if (dist[next] >= 0)
				continue;

			dist[next] = dist[cur] + 1;
			prevPos[next] = cur;
			q.push(next);
		}
	}

	cout << dist[e] << "\n";

	deque<int> dq;
	dq.push_front(e);

	while (dq.front() != start) {
		dq.push_front(prevPos[dq.front()]);
	}

	while (!dq.empty()) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}

	return 0;
}