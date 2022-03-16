#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int n;
	int count = 0;

	cin >> n;
	while (n--)
	{
		stack<char> s;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (s.empty())
				s.push(str[i]);
			else
			{
				if (s.top() == str[i]) // 현재 문자와 스택의 상단 문자가 동일하면, 스택의 상단 문자를 제거
					s.pop();
				else
					s.push(str[i]);
			}
		}
		if (s.empty()) // 적절한 쌍을 다 찾았다면, 스택은 비어있게 됨
			count++; // 카운팅
	}
	cout << count;
}