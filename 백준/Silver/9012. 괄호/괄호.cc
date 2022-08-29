#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str; 
		stack<char> s;
		bool isValid = true;

		for (auto cur : str) {
			if (cur == '(')  // 여는괄호 "(" 만 스택에 push 
				s.push(cur);
			
			else if (cur == ')') {
				if (s.empty()) { // 스택이 비어있다는 것은 곧, 현재 바라보고 있는 닫는괄호에 대한 여는괄호 쌍이 존재하지 않는다는것
					isValid = false;
					break;
				}
				else  
					s.pop();
			}
		}

		// 스택에 아직 여는괄호가 남아 있다는 것 == 적절한 닫는괄호 쌍을 못찾은 것
		if (!s.empty())
			isValid = false;

		if (!isValid)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
