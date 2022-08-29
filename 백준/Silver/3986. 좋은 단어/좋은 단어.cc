#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int count = 0;
	cin >> t;

	while (t--) {
		string str;
		stack<char> s;
		cin >> str;

		for (auto mychar : str) {
			if (s.empty() || mychar != s.top()) // 스택이 비어있는 경우를 감안할 것!
				s.push(mychar);
			else
				s.pop();
		}

		// 모든 내용을 다 처리했음에도 아직 스택에 잔여물이 남아있다면 "좋은 단어" 가 아니다. 스택이 비어있어야 좋은단어임!
		if (s.empty())
			count++;
	}
	cout << count;
}