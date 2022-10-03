#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;

// 원하는 값을 배열에 존재하는지 여부를 0과 1로 리턴하는 이분탐색 함수
int binarysearch(int target) {
	int st = 0;
	int en = n - 1;
	while (st <= en) {
		int mid = (st + en) / 2; 
		if (a[mid] < target)  // 목표값이 현재 중앙점보다 오른쪽에 있는경우 
			st = mid + 1;
		else if (a[mid] > target) // 목표값이 현재 중앙점보다 왼쪽에 있는경우
			en = mid - 1;
		else                 // 목표값을 찾은 경우 (a[mid] == target 인 경우)
			return 1;
	}
	return 0; // 목표값을 찾지 못한경우
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int m;
	cin >> m;
	while (m--) {
		int t;
		cin >> t;
		cout << binarysearch(t) << '\n';
	}
}