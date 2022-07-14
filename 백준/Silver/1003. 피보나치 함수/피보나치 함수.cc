#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int t;
int d0[41];  // 0의 등장횟수  => d0[k] : fib(k) 에 대한 숫자 0의 등장횟수
int d1[41];  // 1의 등장횟수  => d1[k] : fib(k) 에 대한 숫자 1의 등장횟수

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	d0[0] = 1;
	d0[1] = 0;

	d1[0] = 0;
	d1[1] = 1;

	for (int i = 2; i <= 40; i++) {
		d0[i] = d0[i - 1] + d0[i - 2];  // 점화식 : d0[k] = d0[k-1] + d0[k-2]
		d1[i] = d1[i - 1] + d1[i - 2];
	}

	while (t--) {
		int n;
		cin >> n;
		cout << d0[n] << ' ' << d1[n] << '\n';
	}
}