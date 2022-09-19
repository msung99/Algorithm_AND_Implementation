#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100004], d[100004];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = d[i - 1] + a[i]; // d[i] : 1 ~ i번쨰 사이의 수의 합
	}

	// i ~ j 번째 수의 합 = (1~j 번째 사이의 수의 합) - (1 ~ i-1 번쨰 사이의 수의 합)
	while (m--) {
		int start, end;
		cin >> start >> end;
		cout << d[end] - d[start - 1] << '\n';
	}
}