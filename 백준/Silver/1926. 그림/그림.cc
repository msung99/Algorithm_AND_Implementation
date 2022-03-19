#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std;

int board[502][502];
int visit[502][502];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int mx = 0; // 그림의 최댓값
	int num = 0; // 그림의 수
	cin >> n >> m;

	// board판 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// board판의 모든 정점에 대해 실행
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 상하좌우 탐색 시작 이전에, 탐색을 시작할 정점을 설정
			if (board[i][j] == 0 || visit[i][j])
				continue;
			// if문에 걸리지 않은 board[i][j] 가 시작 정점이 된다.
			queue<pair<int, int>> q;
			pair<int, int> start = { i,j }; // 시작 좌표(i,j)
			q.push(start);
			visit[i][j] = 1; // 방문 처리
			num++; // 그림의 총 개수 증가

			int case_max = 0; // 각 그림의 넓이 
			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();
				case_max++;

				// 상하좌우 탐색
				for (int i = 0; i < 4; i++) {
					int x = cur.first + dx[i];
					int y = cur.second + dy[i];

					if (x < 0 || x >= n || y < 0 || y >= m)
						continue;
					if (board[x][y] != 1 || visit[x][y]) // 이전에 방문한 노드이거나, 그림이 없는 칸인 경우
						continue;

					q.push({ x,y });
					visit[x][y] = 1;
				}
			}
			mx = max(mx, case_max);
		}
	}
	cout << num << '\n' << mx;
}
