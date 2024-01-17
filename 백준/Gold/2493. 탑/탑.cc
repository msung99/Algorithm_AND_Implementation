#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>> st; // height, rank
	st.push({100000001, 0});

	for (int i = 1; i <= n; i++) {
		int cur;
		cin >> cur;

		while (st.top().first < cur) {
			st.pop();
		}
		cout << st.top().second << ' ';
		st.push({cur , i});
	}
	return 0;
}