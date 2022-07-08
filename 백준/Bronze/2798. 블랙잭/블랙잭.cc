#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[300001];

int main(void)
{
	int n, m;
	cin >> n >> m;
	int min_gap = 9999999;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// i, j, k 범위 설정에 주의하자!!
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (abs(sum - m) < min_gap && sum <= m) { // abs(sum - m) : m에 최대한 가까운 카드를 구하기 위함  / sum <= m : m을 넘지 않는 카드 3장의 합을 구하기 위함
					min_gap = abs(sum - m);
					ans = sum;
				}
			}
		}
	}
	cout << ans;
}