#include <bits/stdc++.h>
using namespace std;

int n;
int s[1005];
int d[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	fill(d, d + n + 1, 1);

	for (int i = 1; i <= n; i++)
		cin >> s[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (s[i] > s[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	cout << *max_element(d, d + n + 1);
}