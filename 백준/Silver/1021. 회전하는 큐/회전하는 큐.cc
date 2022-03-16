#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void)
{
	deque<int> d;
	int n, find, num, index;
	int count = 0; // 총 연산 횟수

	cin >> n;
	cin >> find;

	for (int i = 1; i <= n; ++i)
	{
		d.push_back(i);
	}

	while (find--) // find번 탐색
	{
		cin >> num; // 탐색하려는 숫자 입력
		for (int i = 0; i < d.size(); ++i)
		{
			if (d[i] == num) // 탐색하려는 숫자의 인덱스 저장
			{
				index = i;
				break;
			}
		}
		// 이제부터 인덱스 번호를 통해, 왼쪽으로 가는 경우와 오른쪽으로 가능 경우에 대해서 더 빠른 경로(방향)를 찾는다.
		// 찾아낸 더 빠른 방향으로  이동하면서 이동한 횟수한큼 카운팅한다.

		if (index < d.size() - index) // 왼쪽으로 이동하는 것이 더 빠른 경우
		{
			while (1)
			{
				if (d.front() == num) // 계속 왼쪽으로 한칸씩 이동시키다가 맨 앞 원소가 원하던 숫자임을 찾아내면 
				{
					d.pop_front();
					break;
				}
				++count; // 연산횟수 카운팅
				// 맨 앞에 있던 것을 맨 뒤로 옮김
				d.push_back(d.front());
				d.pop_front(); 
			}
		}
		else // 오른쪽으로 이동하는 것이 더 빠른 경우 
		{
			while (1)
			{
				if (d.front() == num) // 오른쪽으로 한칸씩 계속 이동하다가 원하던 숫자를 찾아낸 경우
				{
					d.pop_front();
					break;
				}
				count++; // 연산 횟수 카운팅
				// 맨 뒤에있던 원소를 맨 앞으로 옮김
				d.push_front(d.back()); 
				d.pop_back();
			}
		}
	}
	cout << count << "\n";
}