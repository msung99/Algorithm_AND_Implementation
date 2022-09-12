#include <bits/stdc++.h>
using namespace std;

int board[302][302];
bool visited[302][302];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int n, m, year;

// 1년단위 빙산 녹이기
void melting() {
	int zero[302][302] = { 0 }; // (x,y) 좌표에 있는 빙산 칸에 대해 4방향으로 뻗었을떄 존재하는 0의 개수를 저장
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0)
				continue;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if ((nx >= 0 && nx < n && ny >= 0 && ny <= m) && board[nx][ny] == 0)
					zero[i][j]++; // 빙산 칸 (i,j) 에 대해 주변 4방향으로 뻗었을 때 0의 개수를 카운팅하고 저장
			}
		}
	}

	// 앞서 구한 zero 배열의 정보를 기반으로, 모든 빙산 칸에 대해 빙산을 녹이는 과정을 시작
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = max(0, board[i][j] - zero[i][j]); // 0 이랑 비교하는 이유는, 
		// 예를들어 (i,j) 빙산에 대해 주변 0의 개수가 3개이고, (즉 zero[i][j] = 3 일때) board[i][j] = 1 일떄
		// 주변의 3개의 0들로 인해 (i,j) 좌표에 있는 빙산이 1 - 3 = -2 가 될텐데 이러면 안되지 않는가? -2 가 아니라 0에서 멈춰야 할것이다.
		// 이런 이유로 혹시 모르니까 0과 비교한다.
		}
	}
}

void reset() {
	for (int i = 0; i < n; i++) 
		fill(visited[i], visited[i] + m, false);
}

// 리턴값 0 : 빙산이 다 녹은경우, 1 : 아직 빙산이 잘 안녹아서 한덩이밖에 없는 경우, 2 : 두 덩이 이상으로 빙산이 분리된 경우 
int status(){
	// (1)이중 for 문을 돌리면서 구해낸 총 빙산 칸의 개수와,
	// (2) 특정 아무 빙산 칸에 대해 큐에 push 후 BFS 를 돌리면서 구해낸 총 빙산 칸의 개수를 비교한다.
	// => (1) 빙산칸 개수 == (2) 빙산칸 개수 일 경우, 이는 곧 빙산 덩어리가 1개라는 의미 
	// => (1) 빙산칸 개수 == 0 일 경우, 이는 곧 빙산 덩어리의 개수가 0개 라는 것.
	// => (1) 빙산칸 개수 != (2) 빙산칸 개수 일 경우, 이는 곧 빙산 칸의 개수가 2개 이상이라는 의미
	int x = -1, y = -1;
	int cnt1 = 0; // 빙산 칸의 개수

	// (x,y) 좌표 == BFS 탐색을 시작할 빙산 칸의 좌표
	// (x,y) 를 큐에 push 하고, BFS 를 하면서 빙산 칸의 개수를 구하는데 활용될 것이다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]) {
				x = i; // 빙산 칸 아무걸로나 (x,y) 설정
				y = j;
				cnt1++;
			}
		}
	}

	if (cnt1 == 0) // 빙산 칸이 아무것도 없는경우 == 빙산 덩어리가 0개인 경우
		return 0;

	int cnt2 = 0;  // (x,y) 와 붙어있는 빙산의 수
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		cnt2++;
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (visited[nx][ny] == 1 || board[nx][ny] <= 0)
				continue;

			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	if (cnt1 == cnt2) // 빙산 덩어리가 1개인 경우
		return 1;

	return 2; // 빙산 덩이리가 2개 (이상인) 경우
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> board[i][j];

	while (true) {
		year++;
		melting(); // 1년단위 빙산 녹이기
		reset(); // 방문기록 초기화
		int check = status(); // 1년단위 빙산 녹이기를 진행후, 현재 빙산의 총 덩어리 개수를 확인 

		if (check == 0) { // 현재 남은 빙산 덩어리가 이제 더 이상 없는 경우. 즉, 빙산 칸이 다 녹을때까지 빙산 덩어리가 분리되지 않은 경우
			cout << 0; 
			return 0;
		}

		else if (check == 1) // 현재 남은 빙산 덩어리가 1개인 경우 
			continue; // 다시 1년단위 빙산 녹이기 작업을 진행

		else if (check == 2) // 빙산 덩어리가 2개 이상으로 분리된 경우
			break; // 빙산들 그만 녹임
	}

	cout << year;
}


