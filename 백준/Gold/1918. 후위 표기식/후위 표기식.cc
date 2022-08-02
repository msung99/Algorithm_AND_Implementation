/*
/*
중위 표기식을 후위 표기식으로 변환

case1) 숫자면 그냥 바로 출력

case2) 연산자를 만난 경우
- 자신보다 우선순위가 높거나 같은 연산자들을 모두 스택에서 pop 하면서 출력하고, 자신을 스택에다 push
- 수식이 끝나면, 스택에 담긴 연산자들을 모두 pop하여 출력한다.

case3) "(" 를 만난 경우
- 그냥 "(" 를 스택에 push

case4) ")" 를 만난 경우
- 스택에서 연산자들을 ")" 가 나오기전까지 pop 하면서 출력 
*/
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	stack<char> s;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];

		else if (str[i] == '+' || str[i] == '-') {  // 우선순위가 낮은 연산자인 + 또는 - 인 경우
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}

		else if (str[i] == '*' || str[i] == '/') {  // 우선순위가 높은 연산자인 * 또는 / 인 경우
			while (!s.empty() && (s.top() == '*' || s.top() == '/')){
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}

		else if (str[i] == '(')
			s.push(str[i]);

		else if (str[i] == ')') {
			while (!s.empty() && s.top() != '(') {  // 스택에 쌓인 연산자들을 ')' 을 만나기 전까지 모두 pop 하며 출력
				cout << s.top();
				s.pop();
			}
			s.pop(); // ')' 연산자를 스택에서 제거
		}
	}

	// 스택에 아직 남아있는 잔여 연산자들을 모두 출력
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}




