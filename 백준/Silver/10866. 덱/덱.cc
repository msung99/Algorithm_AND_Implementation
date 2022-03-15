#include <deque>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	deque<int> dq;

	int n;
	cin >> n;
	string command;

	while (n--)
	{
		cin >> command;
		if (command == "push_front")
		{
			int a;
			cin >> a;
			dq.push_front(a);
		}
		else if (command == "push_back")
		{
			int a;
			cin >> a;
			dq.push_back(a);
		}
		else if (command == "pop_front")
		{
			if (dq.empty())
				cout << "-1\n";
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (command == "pop_back")
		{
			if (dq.empty())
				cout << "-1\n";
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (command == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (command == "empty")
		{
			if (dq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (command == "front")
		{
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.front() << '\n';
		}
		else if (command == "back")
		{
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.back() << '\n';
		}
	}
}