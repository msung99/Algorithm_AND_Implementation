#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int board[1002][1002];
int dist1[1002][1002]; // 불에 대한 거리
int dist2[1002][1002]; // 상근이에 대한 거리

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{

		int w, h;  // 빌딩의 너비, 높이
		cin >> w >> h;

		// 거리값을 모두 0으로 초기화
		for (int i = 0; i < h; i++) {
			fill(dist1[i], dist1[i] + w, 0);
			fill(dist2[i], dist2[i] + w, 0);
		}

		queue<pair<int, int>> q1; // 불에 관한 큐
		queue<pair<int, int>> q2; // 상근이에 관한 큐	

		// 받아온 문자를 board 에다 넣을 때 숫자화 시키기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char c;
				cin >> c;
				if (c == '#') { // 벽인 좌표는 board 값을 -1로 초기화
					board[i][j] = -1;
				}
				else {
					if (c == '*') // 불의 시작 좌표인 경우
					{
						q1.push({ i,j });
						dist1[i][j] = 1;
					}
					else if (c == '@') // 상근이의 처음 시작 좌표인 경우
					{
						q2.push({ i,j });
						dist2[i][j] = 1;
					}
					board[i][j] = 0; // 벽이 아닌 좌표는 board 값을 0으로 초기화
				}
			}
		}
				
		// 불에 대한 BFS - 상근이가 출발하기전에 각 칸에 불이 번지는 시간대를 미리 적어놓는다.
		while (!q1.empty())
		{
			auto cur = q1.front();
			q1.pop();
			for (int i = 0; i < 4; i++) {
				int x = cur.first + dx[i];
				int y = cur.second + dy[i];
				if (x < 0 || h <= x || y < 0 || w <= y)
					continue;
				if (dist1[x][y] != 0 || board[x][y] == -1) // 이미 거리계산 완료한 칸이거나, 그 칸이 벽인경우
					continue;
				dist1[x][y] = dist1[cur.first][cur.second] + 1;
				q1.push({ x,y });
			}
		}

		bool escape = false; // 탈출 성공 여부를 저장
		while ((!q2.empty()) && (!escape))
		{
			auto cur = q2.front();
			q2.pop();
			for (int i = 0; i < 4; i++) {
				int x = cur.first + dx[i];
				int y = cur.second + dy[i];
				if (x < 0 || x >= h || y < 0 || y >=  w) // 범위를 벗어난 경우 = 탈출에 성공한 경우
				{
					cout << dist2[cur.first][cur.second] << '\n'; // 탈출하는데 걸리는 시간 출력후 다음 테스트 케이스 실행
					escape = true;
					break;
				}
				if (dist2[x][y] != 0 || board[x][y] == -1) // 이미 거리 계산을 한 칸이거나, 그 칸이 벽인경우
					continue;
				if (dist1[x][y] != 0 && dist1[x][y] <= dist2[cur.first][cur.second] + 1) // 불이 번진 칸으로 이동하려는 경우
					continue;                                    // => 불의 데이터 값이 사람 데이터 값보다 더 작은 것은 곧 예전에 그 칸에 불이 이미 퍼졌다는 의미이다,
				dist2[x][y] = dist2[cur.first][cur.second] + 1;
				q2.push({ x,y });
			}
		}

		// 탈출에 실패한 경우
		if(!escape)
			cout << "IMPOSSIBLE\n";
	}
}
