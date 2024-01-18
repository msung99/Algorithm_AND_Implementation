#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; // n : 큐의 크기, m : 뽑아내려고 하는 원소 개수
	cin >> n >> m;

	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	int count = 0;

	while (m--) {
		int data;
		cin >> data;

		int idx = find(dq.begin(), dq.end(), data) - dq.begin();
		if (idx < (dq.size() / 2) + 1 ) { // 원소가 앞단에 있다면
			while (true) {
				if (dq.front() == data) {
					dq.pop_front();
					break;
				} 
				int front = dq.front();
				dq.pop_front();
				dq.push_back(front);
				count++;
			}
		}
		else { // 원소가 뒷단에 있다면
			while (true) {
				if (dq.front() == data) {
					dq.pop_front();
					break;
				}
				int back = dq.back();
				dq.pop_back();
				dq.push_front(back);
				count++;
			}
		}
	}
	cout << count;
}