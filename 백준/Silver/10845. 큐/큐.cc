#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int n;
	string command;
	cin >> n;
	while (n--)
	{
		cin >> command;
		if (command == "push")
		{
			int a;
			cin >> a;
			q.push(a);
		}
		else if (command == "pop")
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (command == "size")
		{
			cout << q.size() << "\n";
		}
		else if (command == "empty")
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (command == "front")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else if (command == "back")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}
}