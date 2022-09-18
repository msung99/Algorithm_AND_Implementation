/*
1. 테이블 정의하기
D[k] : 정수 k가 1이 되는데 필요한 연산 횟수의 최솟값

2. 점화식 설정하기
D[k] = min(D[k/2], D[k/3], D[k-1])

3. 초기값 설정하기
D[1] = 0  D[2] = 1  D[3] = 1
*/

#include <bits/stdc++.h>
using namespace std;

int d[1000005];
int n;

int main(void)
{
	cin >> n;

	d[1] = 0;
	d[2] = d[3] = 1;

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
	}
	cout << d[n];
}