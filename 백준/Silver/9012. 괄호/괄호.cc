#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	while (n--)
	{
		stack<char> s;
		bool check = true;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
			{
				s.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (s.size() == 0)
				{
					check = false;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}

		if (!s.empty())
			check = false;

		if (check)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}

