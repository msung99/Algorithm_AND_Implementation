#include <bits/stdc++.h>
using namespace std;

char arr[20][20];
int alpha[25];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
int answer;

// 현재위치, 현재까지의 길이
void dfs(int x, int y, int dist) {
	answer = max(dist, answer);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		int temp = (int)arr[nx][ny] - 65;
		if (alpha[temp]) // alpha 가 1이면 => 해당 알파벳을 이미 입력했다면
			continue;

		alpha[temp] = 1;
		dfs(nx, ny, dist + 1);
		alpha[temp] = 0;
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int num = (int)arr[0][0] - 65;
	alpha[num] = 1; // 첫번쨰 문자입력
	dfs(0, 0, 1);

	cout << answer;
}