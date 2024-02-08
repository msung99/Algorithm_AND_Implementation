#include <bits/stdc++.h>
using namespace std;

int arr[8];
int n, m;

// 현재 k개까지 수를 택했다.
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}	

	int start = 1; // 첫번째로 선택할땐 1을 선택

	if (k != 0) { // 그 외의 선택에선 지난번에 선택한 숫자(k-1번째 숫자) 보다 더 큰 숫자를 선택
		start = arr[k - 1];
	}

	for (int i = start; i <= n; i++) {
		arr[k] = i;
		func(k + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}