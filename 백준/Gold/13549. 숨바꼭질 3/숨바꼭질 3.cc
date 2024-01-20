#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[200002];
queue<int> q;

void teleport(int num) {
	int tmp = num;
	if (!tmp) return;
	while (tmp < 100001 && !dist[k]) {
		if (!dist[tmp]) {
			dist[tmp] = dist[num];
			q.push(tmp);
			if (tmp == k) 
				return;
		}
		tmp <<= 1;
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	q.push(n);
	dist[n] = 1;
	teleport(n);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : {cur + 1, cur - 1}) {
			if (next < 0 || next >= 100000 || dist[next])
				continue;

			dist[next] = dist[cur] + 1;
			q.push(next);
			teleport(next);
		}
	}
	cout << dist[k] - 1;
	return 0;
}