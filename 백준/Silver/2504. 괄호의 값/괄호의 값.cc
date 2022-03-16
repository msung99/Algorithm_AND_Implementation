#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int tmp = 1, output = 0;
	string str;
	bool wrong = false;
	stack<char> s;

	// 분배법칙 적용
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			tmp *= 2;  // 변수 output 에 더해질 값 tmp 값을 구함
			s.push(str[i]);
		}
		else if (str[i] == '[')
		{
			tmp *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (s.empty())
			{
				wrong = true;
				break;
			}
			if (s.top() == '(')
			{
				if (str[i-1] == '(')
					output += tmp;
				tmp = tmp / 2;
				s.pop();
			}
			else // '(' 말고 다른게 스택에 있는 경우. 예를들어 '[', ']' 등이 있으면 잘못된 괄호열 쌍이다.
			{
				wrong = true;
				break;
			}
		}
		else if (str[i] == ']')
		{
			if (s.empty())
			{
				wrong = true;
				break;
			}
			if (s.top() == '[')
			{
				if (str[i - 1] == '[')
					output += tmp;
				tmp = tmp / 3;
				s.pop();
			}
			else  // '[' 말고 다른게 스택에 있는 경우. 예를들어 '(', ')' 등이 있으면 잘못된 괄호열 쌍이다.
			{
				wrong = true;
				break;
			}
		}
	}
	if (wrong || !s.empty())
		cout << 0 << endl;
	else
		cout << output << endl;
}