#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <tuple>
using namespace std;

int board[100][100][100];
int dist[100][100][100]; // dist[i][j][k] : 해당 좌표의 토마토가 익는데 걸리는 시간

// dz를 추가함으로써 상하좌우 4방향 말고도 위 아래로도 뻗어서 총 6방향으로 뻗는다.
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,-1,1};

int main(void)
{
	int m, n, h;
	cin >> m >> n >> h;
	queue<tuple<int, int, int>> q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[j][k][i];
				if (board[j][k][i] == 1) // 토마토가 있는 좌표를 모두 큐에 담음. 그리고 나중에 큐에서 pop시키면서 BFS 탐색하기
					q.push({ j,k,i });
				if (board[j][k][i] == 0) // 익지 않은 토마토의 칸에 대한 dist 값을 -1로 설정
					dist[j][k][i] = -1;
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur; // 튜플 cur에 있는 데이터 값을 차례대로 curX,curY,curZ 에 할당

		for (int i = 0; i < 6; i++) {
			int x = curX + dx[i];
			int y = curY + dy[i];
			int z = curZ + dz[i];
			if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h)
				continue;
			if (dist[x][y][z] != -1) // 이미 거리계산을 마친 칸인경우
				continue;
			dist[x][y][z] = dist[curX][curY][curZ] + 1;
			q.push({ x,y,z });
		}
	}

	int mx = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1 << '\n';
					return 0;
				}
				mx = max(mx, dist[j][k][i]);
			}
		}
	}
	cout << mx;
}