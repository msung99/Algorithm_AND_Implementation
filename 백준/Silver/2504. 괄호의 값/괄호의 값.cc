/*
() 혹은 [] 를 만나면 sum 에 점수를 더해줌.
() 혹은 [] 이 몇 점인가는 중첩된 소괄호/대괄호의 곱으로
계산 가능하고 이는 변수 num에 저장이 됨
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

	int sum = 0; // 누적해서 더해질 값 
	int num = 1; //  곱해질 값 
	// => ex. 10 x (10 + 2 + 3) 이러한 식에서 num 에 할당되는 값은 10(= 10 x 1), 20(= 20 x 1), 30(= 30 x 1) 이다.

	// 분배법칙을 사용하자!
	for (int i = 0; i < str.size(); i++) {
		// 여는괄호

		if (str[i] == '(') {
			num *= 2; // 소괄호가 나오면 곱해질 값 2배 증가
			s.push(str[i]);
		}

		else if (str[i] == '[') {
			num *= 3; // 대괄호가 나오면 곱해질 값 3배 증가
			s.push(str[i]);
		}

		// 닫는괄호

		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(') // 직전 괄호가 여는 괄호였다면 sum 에 값 추가
				sum += num;
			s.pop(); // 여는괄호에 대한 연산이 끝났으므로 스택에서 연산이 끝난 열린괄호를 pop0
			num /= 2; // 소괄호 쌍이 사라졌으니 2로 나눔
		}

		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[')
				sum += num;
			s.pop();
			num /= 3;
		}
	}
	
	if (!s.empty()) {
		cout << 0 << endl;
		return 0;
	}

	cout << sum;
}


