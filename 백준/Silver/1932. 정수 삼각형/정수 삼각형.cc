#include <bits/stdc++.h>
using namespace std;

int n;
int s[505][505];
int d[505][505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			cin >> s[i][j];

	d[1][1] = s[1][1];
	d[2][1] = d[1][1] + s[2][1];
	d[2][2] = d[1][1] + s[2][2];

	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = max(d[i-1][j-1], d[i-1][j]) + s[i][j];
		}
	}
	cout << *max_element(d[n], d[n] + n + 1);
}