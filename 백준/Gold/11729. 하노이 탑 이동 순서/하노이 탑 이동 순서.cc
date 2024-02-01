#include <bits/stdc++.h>
using namespace std;
int cnt;
queue<pair<int, int>> q;

void func(int a, int b, int n) {
	if (n == 1) {
		q.push({ a, b });
		// cout << a << ' ' << b << "\n";
		return;
	}
	func(a, 6 - a - b, n - 1); // n-1개의 원판을 기둥 a에서 기둥 6-a-b로 이동
	q.push({a, b});
	// cout << a << ' ' << b << "\n"; // n번째 원판을 a 에서 b 로 옮긴다.
	func(6 - a - b, b, n - 1); // n-1개의 원판을 기둥 6-a-b 에서 기둥 b로 옮긴다.
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;
	func(1, 3, num);

	cout << q.size() << "\n";
	while (!q.empty()) {
		cout << q.front().first << ' ' << q.front().second << "\n";
		q.pop();
	}
}