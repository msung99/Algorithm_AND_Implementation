#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	while (1)
	{
		stack<int> s;
		string str;
		bool check = true;
		
		getline(cin, str); // 문자열에 공백이 포함되어 있으므로 getline 으로 읽어들임

		if (str == ".")
			break;

		for (int i = 0; i < str.size(); i++)
		{
			// 여는 괄호인 경후 
			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			{
				s.push(str[i]); // 스택에 저장
			}
			// 닫는 괄호인 경우
			else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			{
				if (s.empty())
				{
					check = false;
					break;
				}

				if (s.top() == '(')
				{
					if (str[i] != ')')
					{
						check = false;
						break; // for문에서 탈출하고, 다음 while 루프 실행
					}
				}
				else if (s.top() == '{')
				{
					if (str[i] != '}')
					{
						check = false;
						break;
					}
				}
				else if (s.top() == '[')
				{
					if (str[i] != ']')
					{
						check = false;
						break;
					}
				}
				s.pop(); // 스택의 top() 값을 확인해보니 올바른 괄호 쌍일경우 pop()시킴
			} 
		}
		// 문자열을 다 확인하고 나서 스택을 확인해보니 비어있는게 아니면, 
		// 즉 아직도 처리해야할 열린 괄호가 스택에 담겨있다면 false
		if (!s.empty())
			check = false;

		if (check)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}