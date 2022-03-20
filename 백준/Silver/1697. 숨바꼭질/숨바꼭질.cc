#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int dist[100002];

int main(void)
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);

	fill(dist, dist + 100001, -1);
	dist[n] = 0; // 방문 처리 => 방문처리 안하면 나중에 이 좌표를 또 방문할 수도 있다.

	while (dist[k] == -1)
	{
		int cur = q.front();
		q.pop();

		for (int i : {cur + 1, cur - 1, 2 * cur})
		{
			if (i < 0 || i > 100000)
				continue;
			if (dist[i] != -1) // 이미 방문한(거리 계산을 완료한) 좌표인 경우
				continue;
			dist[i] = dist[cur] + 1;
			q.push(i);
		}
	}
	cout << dist[k];
}