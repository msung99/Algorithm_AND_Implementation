#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int board1[10][10];  // 입력으로 주어진 사무실 모양을 저장
int board2[10][10]; // cctv 방향을 정한후, cctv 감시 영역에 걸리는 빈칸을 7로 바꾸는 작업을 할 변수
vector<pair<int, int>>cctv; // cctv 좌표를 담을 변수

// 좌표 (x, y) 가 범위를 벗어나는지 체크
bool OOB(int a, int b) {
	return a < 0 || a >= n || b < 0 || b >= m;
}

// dir의 값(0~3사이의 값)에 따라서 dx[4], dy[4] 배열중 어디로 이동할지 결정후 이동
void upd(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir]; // 좌표(x,y) 에서부터 시작해서 지정된 dir 방향으로 이동
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) // 벽을 만났거나 적절한 좌표가 아닌 경우
			return;
		if (board2[x][y] != 0) // 해당 셀이 cctv 가 있는 곳일때 무시
			continue;
		board2[x][y] = 7; // 해당 감시영역 셀을 7로 바꿈
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int mn = 0;  // 사각지대의 최소 크기, 즉 답을 저장하는 변수 

	// board1 에 좌표 모양를 저장하고, board2 에  빈칸을 저장하고,
	// mn 에 일단 우선 빈칸의 수를 저장하고, cctv에 cctv 좌표를 저장하는 작업
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6) // 해당 좌표셀이 cctv 인 경우 ( = 빈칸이 아니거나 벽이 아닌 경우 )
				cctv.push_back({ i,j }); // cctv 좌표 배열에 추가
			if (board1[i][j] == 0) // 빈칸을 입력받으면 mn을 1증가
				mn++;
		}
	}

	// cctv 들의 방향을 정함 
	// cctv 가 k (= cctv.size()) 개 있을때, tmp 는 4^k -1 개를 돌아야함 (ex. cctv 가 3개인 경우 tmp = 0 ~ 63 까지 반복)
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board1[i][j]; // board1 의 좌표 내용을 board2 에 복사
			}
		}
		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].X; // cctv 의 x 좌표와 y 좌표를 담음
			int y = cctv[i].Y;
			// board1 은 원본이고, board2 는 upd 함수를 걸치며 계속 내부의 값이 변함
			if (board1[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (board1[x][y] == 2) {
				upd(x, y, dir);
				upd(x, y, dir + 2);
			}
			else if (board1[x][y] == 3) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
			}
			else if (board1[x][y] == 4) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
			}
			else if (board1[x][y] == 5) {
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
				upd(x, y, dir + 4);
			}
		}
		// 시뮬레이션 종료후, 빈칸의 개수를 확인안후 mn 을 최신화 
		int val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				val += (board2[i][j] == 0);
			}
		}
		mn = min(mn, val); // 2^(k-1) 개의 case 중에 한 case 에 대해서 확인을 하고 빈칸 개수를 카운팅했다면, 지금까지 구한 최솟값 mn 과 현재 구한 빈칸의 개수 val 을 비교하고 mn 을 최신화
 	}
	cout << mn; // 모든 case 에 대해서 빈칸을 확인하고 가장 작은 최솟값을 찾아낸 mn 을 출력
}