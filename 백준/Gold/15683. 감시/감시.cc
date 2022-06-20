#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board1[10][10];
int board2[10][10];
vector<pair<int, int>> cctv;

bool check(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

void work(int x, int y, int dir) {
	dir = dir % 4;
	while (1) {
		x = x + dx[dir];
		y = y + dy[dir];
		if (check(x, y) || board2[x][y] == 6)
			return;
		if (board2[x][y] != 0 && board2[x][y] != 6)
			continue;
		board2[x][y] = 7;
	}
}

int main(void)
{
	cin >> n >> m;
	int mn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] == 0)
				mn++;
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i,j });
		}
	}

	for (int tmp = 0; tmp < (1 << 2 * (cctv.size())); tmp++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute = brute / 4;
			int x = cctv[i].first;
			int y = cctv[i].second;
			if (board1[x][y] == 1) {
				work(x, y, dir);
			}
			else if (board1[x][y] == 2) {
				work(x, y, dir);
				work(x, y, dir + 2);
			}
			else if (board1[x][y] == 3) {
				work(x, y, dir);
				work(x, y, dir + 1);
			}
			else if (board1[x][y] == 4) {
				work(x, y, dir);
				work(x, y, dir + 1);
				work(x, y, dir + 2);
			}
			else if (board1[x][y] == 5) {
				work(x, y, dir);
				work(x, y, dir + 1);
				work(x, y, dir + 2);
				work(x, y, dir + 3);
			}
		}
		int val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board2[i][j] == 0)
					val++;
			}
		}
		mn = min(mn, val);
	}
	cout << mn;
}