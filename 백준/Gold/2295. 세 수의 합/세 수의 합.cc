// a[i] + a[j] + a[k] = a[l] 을 만족하는 a[l] 중에서 최댓값

// 배열 two : 미리 배열 a에서 두 원소의 합을 다 묶어놓은 배열. 즉, a[i], a[j], a[k] 중에서 a[i] 와 a[j] 를 미리 합으로 묶어놓은 배열이다.
// 예를들어 a가 1,4,6 이라고 하면 two 는  1+1, 1+4, 4+4, 4+6, 6+6 = 2,5,7,8,10,12 가 된다.

// two[m] + a[k] = a[l] 을 만족하는 a[l] 중에서 최댓값
// => O(n^2 x logN) 풀이 : k, l 에 대한 2중 for문을 돌리고, a[l] - a[k] 가 배열 two 에 있는지 이분탐색 log(N^2) = 2xlogN


#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
vector<int > two;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> a[i];

	sort(a, a + n);
	// 배열 two : 미리 배열 a에서 두 원소의 합을 다 묶어놓은 배열.
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
			two.push_back(a[i] + a[j]);
	}
	sort(two.begin(), two.end()); // 이분탐색을 진행하기 위해 정렬도 시켜놓는다.

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(two.begin(), two.end(), a[i] - a[j])) { // 배열 two 를 이분탐색하면서 a[l] - a[k] 가 존재하는지 탐색
				cout << a[i]; // 존재하면 해당 값을 출력
				return 0;
			}
		}
	}
}