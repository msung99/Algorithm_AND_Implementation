/*
블로그 풀이 : https://blog.encrypted.gg/499
유튜브 풀이 : https://youtu.be/yPuow6aACvE
*/

#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x) {
	int cur = x;
	while (true) {
		state[cur] = x;
		cur = arr[cur];
		// 이번 방문(사이클인지 판단하는 이번 방문) 에서 지나간 학생에 도달했을 경우
		if (state[cur] == x) {
			while (state[cur] != CYCLE_IN) { // 이번 방문에서 사이클에는 속한다고 판별된 학생들에만 대해서
				state[cur] = CYCLE_IN; // 사이클에 포함된 학생이라고 상태를 처리
				cur = arr[cur]; // 사이클에 속하는 다음 학생의 인덱스를 구하고 cur 에 할당
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
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		fill(state + 1, state + n + 1, 0);
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_VISITED) // 아직 방문하지 않은 학생 좌표들에 대해 run() 함수에서 
				run(i);                   // 사이클 여부판단 및 방문처리
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] != CYCLE_IN)
				cnt++;
		}
		cout << cnt << '\n';
	}
}
