#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	deque<pair<int, int>> dq;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		// 새로운 숫자가 deque 내에서 가장 큰 값의 숫자이고 마지막에 위치하도록 한다.
		// deque 안의 숫자들은 오름차순 상태를 유지하게 하고, 구간내 가장 작은값은 항상 맨앞(front) 에 있는 상태를 가지게된다.
		while (!dq.empty() && dq.back().second >= num) 
			dq.pop_back();

		// 새로운 숫자는 항상 삽입된다.
		dq.push_back({ i, num });

		// 주어진 구간을 벗어나는 outdate 된 숫자들을 제거
		if (dq.front().first <= i - m)
			dq.pop_front();

		cout << dq.front().second << ' ';
	}
}