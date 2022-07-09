#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// D[n] = D[n-1] + 2 * D[n-2]

int d[1005];
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	// 초기값 설정
	d[1] = 1;
	d[2] = 3;

	// 점화식 : D[i] = D[i-1] + D[i-2]  => 이때 문제의 조건에 따라, 10007 로 나눈 나머지를 구해야함
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 10007;
	}

	cout << d[n];
}