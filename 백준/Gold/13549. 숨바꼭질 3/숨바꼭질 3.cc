#include <bits/stdc++.h>
using namespace std;

int dp[100001];
int n, k;
int dx[3] = { 2,1,-1 };

void bfs(int start, int end) {
	queue<int> q;
	q.push(start);
	dp[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == end) {
			cout << dp[end];
			break;
		}

		for (int i = 0; i < 3; i++) {
			int nx = 0;
			int time = 0;
			if (i == 0) { // 순간이동
				nx = cur * dx[i];
				time = 0;  // 0초의 시간소요
			}
			else {  // 걸어서 이동
				nx = cur + dx[i];
				time = 1; // 1초의 시간소요
			}

			// dp[nx] > dp[cur] + time : 이미 좌표 nx 에 방문했고 시간이 dp[nx] 에 적혀있을 떄, 
			//  기존에 적힌 시간(= dp[nx] )과 새롭게 최신화하려는 시간 ( = dp[cur] + time ) 중에 해당 좌표(nx) 까지 도달하는데 걸리는 시간이 가장 빠른 시간으로 최신화시킨다.
			if (nx >= 0 && nx < 100001 && (dp[nx] > dp[cur] + time)) {
				dp[nx] = dp[cur] + time;
				q.push(nx);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	fill(dp, dp + 100001, 99999999);
	bfs(n, k);
	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[200002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(dist, dist + 200000, -1);
	deque<int> dq;
	dq.push_back(n);
	dist[n] = 0;

	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();

		// 순간이동은 deque 의 앞쪽에 push
		// +1,-1 칸 이동하는것보다 순간이동하는 것에 대해 우선순위를 두고 처리
		if (2 * cur < 200000 && dist[2 * cur] == -1) {
			dist[2 * cur] = dist[cur];
			dq.push_front(2 * cur); // 순간이동에 대해 먼저 처리하기 위해 deque 의 맨앞에다 push
		}

		// 걷는이동은 deque 의 뒤쪽에 push
		// +1, -1 칸 이동하는것에 대해 처리
		for (int nxt : {cur - 1, cur + 1}) {
			if (nxt < 0 || nxt >= 200000 || dist[nxt] != -1)
				continue;

			dist[nxt] = dist[cur] + 1;
			dq.push_back(nxt);
		}
	}
	cout << dist[k];
}
*/