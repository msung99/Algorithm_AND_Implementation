#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	deque<int> dq;
	int n, m;
	int index = 0;
	int count = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	while (m--) {
		int data;
		cin >> data;
		
		// 탐색하려는 숫자의 인덱스 저장
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == data) {
				index = i;
				break;
			}
		}

		// 왼쪽으로 가는게 더 횟수가 적은경우
		if (index < dq.size() - index) {
			while (dq.front() != data) {  // 계속 왼쪽으로 한칸씩 이동시키다가 맨 앞 원소가 원하던 숫자임을 찾아낼때 까지 반복
				int front_data = dq.front();
				dq.push_back(front_data);
				dq.pop_front();
				count++;
			}
			dq.pop_front();
		}

		// 오른쪽으로 가는게 더 횟수가 적은경우
		else if (index >= dq.size() - index) {
			while (dq.front() != data) {  // 오른쪽으로 한칸씩 계속 이동시키다가 원하던 숫자를 찾아낼 때 까지 반복
				int back_data = dq.back();
				dq.push_front(back_data);
				dq.pop_back();
				count++;
			}
			dq.pop_front();
		}
	}

	cout << count;
}