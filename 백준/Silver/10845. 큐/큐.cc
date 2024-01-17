#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	queue<int> q;
	while (t--) {
		string cmd; 
		cin >> cmd;
		if (cmd == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (cmd == "pop") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "empty") {
			if (q.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (cmd == "front") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (cmd == "back") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
}