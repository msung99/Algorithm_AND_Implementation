#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10]; // i번째 숫자 사용 유무 

// k 번째 숫자와, 다음번에 뽑을 k+1 번째 숫자는 서로 다른 숫자여야 한다.

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << num[arr[i]] << ' ';
		}
		cout << "\n";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[k] = i; // k번째 숫자로 인덱스 i에 해당하는 숫자가 사용되었다고 표기함
			isused[i] = true;  // 인덱스 i에 해당하는 숫자가 사용되었다고 표기
			func(k + 1);
			isused[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; // 4, 2

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);

	func(0);

	return 0;
}