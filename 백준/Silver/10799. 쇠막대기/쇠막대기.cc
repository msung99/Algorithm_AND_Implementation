#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	stack<char> s;
	string str;
	int count = 0;
	cin >> str;

	// 스택에 남아있는 열린 괄호의 개수 == 레이저에 의해 잘린 조각의 개수(레이저 위치 기준으로 왼쪽 조각만 해당)
	// => 레이저가 막대를 끊을 때, 이전 '(' 의 개수만큼 막대가 끊긴다.
	// 스택을 사용하는 이유는, 레어지로 막대가 끊길때 이전 '(' 의 개수를 size() 함수로 나타나기 위함이다. 
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		// 레이저인 경우 - 지금까지 생성된 막대가 레이저에 의해 잘리고, 잘린 조각들이 카운팅 된다
		else if ( (str[i] == ')') && (str[i - 1] == '(') ) 
		{
			s.pop();
			count += s.size(); // 레이저로 인해 만들어진 조각 개수 = 스택에 저장된 열린괄호 개수( s.size() )
		}
		// 막대의 끝인 경우. 레어저 바로 뒷 부분(레이저 오른쪽 부분) 마지막 막대 조각 하나가 카운팅된다.
		else 
		{
			count++; // 레이저로 인해 잘린 레이저 위치 기준 오른쪽 잔여 조각 1개가 카운팅
			s.pop();
		}
	}
	cout << count;
}
