#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10]; // 수열
bool isused[10]; // isused[i] : 숫자 i가 현재 사용되었는지 유무

// 현재 k 개까지 숫자를 택한 상황에서 arr[k] 를 정하는 함수
void func(int k) {
	if (k == m) {  // base condition : 현재 m개를 택했다면 수열을 출력하고 종료
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	
	// i부터 n까지 수를 차례대로 확인하며 아직 쓰이지 않은 수를 찾아낸다.
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i; // 숫자 i를 아직 사용안했다면 수열의 k번째 숫자로 i를 선택
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	func(0);
}