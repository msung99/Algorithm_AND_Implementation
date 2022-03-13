#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> st;

	string command;
	int count;
	int res = 0;
	cin >> count;

	while (count--)
	{
		cin >> command;
		if (command == "push")
		{
			int a;
			cin >> a;
			st.push(a);
		}

		else if (command == "pop")
		{
			if (st.empty()) {
				cout << "-1" << '\n';
			}
			else{
				res = st.top(); // pop() 메소드는 리턴값이 없으므로, 그 대신 top() 메소드를 사용!
				cout << res << '\n';
				st.pop();
			}
		}
		else if (command == "size")
		{
			if (st.empty())
				cout << "0" << '\n';
			else
				cout << st.size() << '\n';
		}
		else if (command == "empty")
		{
			if (st.empty())
			{
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (command == "top")
		{
			if (st.empty())
				cout << "-1\n";
			else
				cout << st.top() << '\n';
		}
	}
}