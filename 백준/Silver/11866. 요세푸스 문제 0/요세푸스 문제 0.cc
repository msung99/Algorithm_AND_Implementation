#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int k, n;
	cin >> k >> n;
	for (int i = 1; i <= k; i++) {
		q.push(i);
	}

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < n-1; i++) {
			int num = q.front();
			q.push(num);
			q.pop();
		}
		if (q.size() == 1) {
			cout << q.front();
			q.pop();
		}
		else {
			cout << q.front() << ", ";
			q.pop();
		}
	}
	cout << ">";
}