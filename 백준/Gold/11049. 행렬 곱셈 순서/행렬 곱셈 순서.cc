#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int sum[505], matrix[505][2], dp[505][505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> r >> c;
		matrix[i][0] = r;
		matrix[i][1] = c;
	}

	// 행렬 곱셈의 연산의 수 = N x M x K
	// dp[i][j] : 구간 i ~ j 의 곱셈 연산의 최솟값
	for (int i = 1; i < n; i++) {  // i = 구간의 길이
		for (int j = 1; i + j <= n; j++) { // j = 구간의 시작점 
			dp[j][i + j] = 1000000000;
			for (int k = j; k <= i + j; k++) {  // k = 구간 범위를 두 부분으로 나눌 떄의 기준점 => dp[3][7] 을 구할때 dp[3][4] 와 dp[4][7] 로 나눈다.
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
			}
		}
	}// matrix[j][0]*matrix[k][1]*matrix[i+j][1])  => 두 행렬의 곱셈 연산 수
     // matrix[j][0] : 구간 시작 부분의 행렬의 행 (N 역할)
	// matrix[k][1] : 구간을 둘로 나누는 기준점 행렬의 열 (M 역할)
	// matrix[i+j][1] : 구간 마지막 부분의 행렬의 열(K 역할) 
	
	cout << dp[1][n];
}