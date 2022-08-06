/*
투 포인터 방식으로 간단하게 해결 가능하다.

일단 포인터 2개를 두고 합이 s 이상일때까지 en 을 증가시키다가  s 이상이 된 순간 st 를 옮기고, 
다시 en 을 옮기고, ... 이런식으로 진행하면 된다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, s, tot;
int a[100005];
int mn = 0x7fffffff;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	tot = a[0];
	int en = 0;

	for (int st = 0; st < n; st++) {
		while (en < n && tot < s) {
			en++;
			if (en != n)
				tot += a[en];
		}
		if (en == n) // en 이 범위를 벗어날 시 종료
			break;
		mn = min(mn, en - st + 1); // 구간의 길이 : en - st + 1
		tot -= a[st];
	}
	if (mn == 0x7fffffff)
		mn = 0;
	cout << mn;
}