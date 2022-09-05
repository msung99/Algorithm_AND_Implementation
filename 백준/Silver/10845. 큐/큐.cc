#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (str == "pop") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}
		else if (str == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << "\n";
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}

			cout << q.back() << '\n';
		}
	}
}