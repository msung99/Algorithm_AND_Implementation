/*
블로그 풀이 : https://blog.encrypted.gg/499
유튜브 풀이 : https://youtu.be/yPuow6aACvE
*/


#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n, t;
int state[100005];

void run(int x) {
	int cur = x;
	while (true) {
		state[cur] = x;
		cur = arr[cur];
		// 이번 방문에서 지나간 학생에 도달했을 경우
		if (state[cur] == x) {
			while (state[cur] != -1) {
				state[cur] = -1;
				cur = arr[cur];
			}
			return;
		}
		// 이전 방문에서 지나간 학생에 도달했을 경우
		else if (state[cur] != 0)
			return;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		fill(state + 1, state + n + 1, false);

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] == 0)
				run(i);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (state[i] != -1)
				cnt++;

		cout << cnt << '\n';
	}
}