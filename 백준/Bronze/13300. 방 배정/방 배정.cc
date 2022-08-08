#include <bits/stdc++.h>
using namespace std;

int arr[2][7];
int n, k, cnt;

int main(void)
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int gender, grade;
		cin >> gender >> grade;
		arr[gender][grade]++;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			if (arr[i][j] != 0) {
				//cout << "i:" << i << " j:" << j << " " << arr[i][j] << '\n';
				int res = arr[i][j] / k;
				if (arr[i][j] % k == 0)
					cnt += res;
				else
					cnt = cnt + res + 1;
			}
		}
	}
	cout << cnt;
}