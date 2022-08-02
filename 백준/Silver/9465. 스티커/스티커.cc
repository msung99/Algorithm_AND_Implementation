/*
1. 테이블 설정하기

D[1][k] : 왼쪽에서 부터 차례대로 스터기를 떄오며 1행 k번째 열에 도달했을 떄의 최댓값
D[2][k] : 2행 k번째 열에 도달했을 떄의 최댓값


2. 점화식 설정하기

D[1][i] = max(D[1][i-1], D[1][i-2]) + arr[1][i]
D[2][i] = max(D[2]i-1], D[2][i-2]) + arr[2][i]


3. 초기값 설정하기

D[1][1] = 0
D[2][0] = 0
D[1][1] = arr[1][1]
D[2][1] = arr[2][1]
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 0;
	int mx = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		int arr[2][100001];
		int d[2][100001];

		for (int r = 0; r < 2; r++) 
			for (int c = 1; c <= n; c++) 
				cin >> arr[r][c];

		d[0][0] = 0;
		d[1][0] = 0;
		d[0][1] = arr[0][1];
		d[1][1] = arr[1][1];

		for (int c = 2; c <= n; c++) {
			d[0][c] = max(d[1][c - 1], d[1][c - 2]) + arr[0][c];
			d[1][c] = max(d[0][c - 1], d[0][c - 2]) + arr[1][c];
		}

		cout << max(d[0][n], d[1][n]) << '\n';
	}
}