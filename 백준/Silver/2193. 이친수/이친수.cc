/*
끝자리가 1이 등장하는 경우 => 1가지로 파생한다.
끝자리가 0이 등장하는 경우 => 2자리로 파생한다.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
long long d[91];  // d 에 담기는 값이 생각보다 커서, int 형 배열이 아닌, long long 타입의 배열을 선언했다.

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	// 점화식 d[k] = d[k-1] + d[k-2]
	d[1] = 1;
	d[2] = 1;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n];
}