#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int count = 0;
	stack<char> s;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') { // 막대기(열린괄호) 인 경우
			s.push(str[i]);
		}
		else if (str[i] == ')') { // 닫힌괄호(레이저 or 막대기의 끝) 인 경우
			if (str[i-1] == '(') {  // 레이저인 경우
				s.pop();
				count += s.size();
			}
			else if (str[i - 1] == ')') {  // 막대기의 끝인 경우
				s.pop();
				count++;
			}
		}
	}
	cout << count;
}