#include <bits/stdc++.h>
using namespace std;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     

int a[1000001];
int ans[1000000];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	stack<int> s;

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= a[i]) // 스택에서 현재 바라보고 있는 원소(a[i]) 보다 작은 값들은 제거시키고,
			s.pop();                          // 스택에 현재 원소보다 큰 값만 남도록 한다.

		// 스택에 남는 원소가 없는경우 == 현재 원소 a[i] 보다 다 작은 원소들이라서 제거된 경우
		if (s.empty()) 
			ans[i] = -1;

		// 스택에 최상단에 남아있는 값 ( = s.top()) 이 a[i] 보다 큰 수중에서 가장 왼쪽에 있는 값이다.
		else
			ans[i] = s.top();

		s.push(a[i]); 
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}
