#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool isused[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << num[arr[i]] << ' ';
		}
		cout << "\n";
		return;
	}

	int start = 0;
	if (k != 0) {
		start = arr[k - 1] + 1;
	}

	for (int i = start; i < n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[k] = true;
			func(k + 1);
			isused[k] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);

	func(0);
}