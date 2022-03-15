#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	queue<int> q;
	int top;
	int n;
	
	cin >> n;
	// 1부터 n까지의 원소 큐에 삽입
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() > 1) // q.size() == 1일때, 즉 큐에 원소가 하나 남을때 중단
	{
		q.pop(); // 맨 앞 원소 삭제
		top = q.front(); // 맨 앞 원소를 저장
		q.pop(); // 그 다음 맨 앞 원소 삭제
		q.push(top);
	}
	cout << q.front(); // 최종적으로 큐에 하나 남은 원소를 출력
}