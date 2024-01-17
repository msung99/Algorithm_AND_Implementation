#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	deque<int> dq;

	int t;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_front") {
			int data;
			cin >> data;
			dq.push_front(data);
		}
		else if (cmd == "push_back") {
			int data;
			cin >> data;
			dq.push_back(data);
		}
		else if (cmd == "pop_front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				int data = dq.front();
				dq.pop_front();
				cout << data << "\n";
			}
		}
		else if (cmd == "pop_back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				int data = dq.back();
				dq.pop_back();
				cout << data << "\n";
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << "\n";
		}
		else if (cmd == "empty") {
			if (dq.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (cmd == "front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (cmd == "back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}
}