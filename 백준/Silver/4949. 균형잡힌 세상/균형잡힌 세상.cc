#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string str;
		// cin >> str;   => cin 은 공백을 기준으로하여 하나의 문자열을 구성하므로, 공백이 기준이 아닌 공백포함 문자열 저장시 getline() 를 활용
		getline(cin, str); // getline() : <string> 에 정의. string 형에 문자열을 저장시 사용
		// 인자1 : 입력방식(파일입력, 표준입력 등등), 인자2 : string형 변수명
		if (str == ".")
			break;

		stack<char> s;
		bool isValid = true;

		for (auto mychar : str) {
			//cout << "mychar:" << mychar << '\n';

			if (mychar == '(' || mychar == '[')
				s.push(mychar);

			else if (mychar == ')') {
				if (s.empty() || s.top() != '(' ) { // 닫는 괄호를 만났는데, 부적합한 괄호쌍이거나 스택이 비어있는 경우
					isValid = false;
					break;
				}
				s.pop();
			}

			else if (mychar == ']') {
				if (s.empty() || s.top() != '[') {
					isValid = false;
					break;
				}
				s.pop();
			}
		}

		if (!s.empty())
			isValid = false;

		if (isValid)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}

