/*
1. 테이블 설정하기

D[i][j] : i번째 집까지 칠할때 비용의 최솟값. 단 i번째 집은 빨강 or 초록 or 파랑 
(j=1 일떄 빨강, j=2 일떄  초록, j=3 일떄 파랑)

D[i][0] = i번쨰 집까지 칠할때 비용의 최솟값, 단 i번쨰 집은 빨강
D[i][1] = i번째 집까지 칠할떄 비용의 최솟값, 단 i번쨰 집은 초록
D[i][2] = i번쨰 집까지 칠할때 비용의 최솟값, 단 i번쨰 집은 파랑


2. 점화식 설정하기

D[i][0] = min(D[i-1][1], D[i-1][2]) + R[i]
D[i][1] = min(D[i-1][0], D[i-1][2]) + G[i]
D[i][2] = min(D[i-1][0], D[i-1][1]) + B[i]

3. 초기값 설정하기

D[1][0] = R[1]
D[1][1] = G[1]
D[1][2] = B[1]
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int D[1005][3];
int r[1005];
int g[1005];
int b[1005];

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}

	D[1][0] = r[1];
	D[1][1] = g[1];
	D[1][2] = b[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2; j++) {
			if (j == 0)
				D[i][j] = min(D[i - 1][1], D[i - 1][2]) + r[i];
			else if (j == 1)
				D[i][j] = min(D[i - 1][0], D[i - 1][2]) + g[i];
			else if (j == 2)
				D[i][j] = min(D[i - 1][0], D[i - 1][1]) + b[i];
		}
	}

	cout << min({D[n][0], D[n][1], D[n][2]});
}