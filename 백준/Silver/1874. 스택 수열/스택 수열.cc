#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<int> s;
	int cnt = 1;
	string ans;

	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		// 현재 처리를 해야하는 수인 num 에 접근해서 처리하기 위해, cnt 를 계속 1씩 더해간다.
		while (cnt <= num) { // 현재 처리를 해야하는 수는 cnt 이다. cnt 이상인 값 num 이 주어지면,
			s.push(cnt);  // 그 값을 pop 할 수 있게 cnt 가 num 이 될때까지 push 해야한다.
			cnt++;
			ans += "+\n";
		}
		// 값 cnt 에 대한 처리를 하기전에, 올바른 수열인지를 검사한다.
		if (s.top() != num) {  // 올바르지 않은 수열인 경우
			cout << "NO \n";
			return 0;
		}
		// 값 cnt 에 대한 처리
		s.pop();
		ans += "- \n";
	}
	cout << ans;
}
