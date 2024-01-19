#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int result = 0;
	int num = 1;
	stack<char> s;

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			num *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[') {
			num *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(') {
				result += num;
			}
			s.pop();
			num /= 2;
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') {
				result += num;
			}
			s.pop();
			num /= 3;
		}
	}
	if (s.empty()) {
		cout << result;
	}
	else {
		cout << 0;
	}
	return 0;
}