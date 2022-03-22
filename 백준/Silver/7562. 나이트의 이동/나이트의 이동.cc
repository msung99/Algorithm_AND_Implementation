#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;

int dist[300][300];

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2 ,-2 ,-1};

int main(void)
{
	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int length;
		cin >> length;
		for (int i = 0; i < length; i++) // dist 데이터 값을 -1로 다 초기화
			fill(dist[i], dist[i] + length,  -1);

		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y; // 나이트의 처음 좌표
		cin >> end_x >> end_y; // 나이트가 도달하고자 하는 최종 이동 좌표 

		queue<pair<int, int>> q;
		q.push({ start_x,start_y });
		dist[start_x][start_y] = 0;

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				int x = cur.first + dx[i];
				int y = cur.second + dy[i];
				if (x < 0 || x >= length || y < 0 || y >= length)
					continue;
				if (dist[x][y] != -1) // 이미 거리계산 완료한 좌표 칸인 경우
					continue;
				dist[x][y] = dist[cur.first][cur.second] + 1;
				q.push({ x,y });
			}
		}
		cout << dist[end_x][end_y] << '\n';
	}
}