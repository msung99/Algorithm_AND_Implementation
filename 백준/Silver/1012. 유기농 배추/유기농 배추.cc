#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int board[100][100];
int visited[100][100];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int m, n, k;

	cin >> t;
	while (t--)
	{
		cin >> m >> n >> k;
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			board[y][x] = 1;
		}

		queue<pair<int, int>> q;
		int area_count = 0; // 총 배추 영역 개수( = 지렁이 개수)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {	
				if (board[i][j] == 1 && visited[i][j] == 0) // 각 배추 영역에 대해 실행
				{
					area_count++; // 배추 영역 1증가
					q.push({ i,j }); // 그 배추 영역의 BFS 탐색 시작점을 큐에 push 
					visited[i][j] = 1;

					// BFS 탐색 실행
					while (!q.empty())
					{
						auto cur = q.front();
						q.pop();

						for (int i = 0; i < m; i++) {
							int x = cur.first + dx[i];
							int y = cur.second + dy[i];

							if (x < 0 || x >= n || y < 0 || y >= m)
								continue;
							if (board[x][y] != 1 || visited[x][y] == 1)
								continue;

							q.push({ x,y });
							visited[x][y] = 1;
						}
					}
				}
			}
		}
		cout << area_count << '\n';
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(visited[i], visited[i] + m, false);
		}
	}
}