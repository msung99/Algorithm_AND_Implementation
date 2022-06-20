#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int row, col;
int paper[12][12];
int note[42][42];

bool paste_able(int x, int y) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (paper[i][j] == 1 && note[x+i][y+j] == 1) {
				return false;
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if(paper[i][j] == 1)
				note[x + i][y + j] = 1;
		}
	}
	return true;
}

void rotate() {
	int tmp[12][12];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			tmp[i][j] = paper[i][j];
		}
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			paper[i][j] = tmp[row-1-j][i];
		}
	}
	swap(row, col);
}



int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (k--)
	{
		cin >> row >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> paper[i][j];
			}
		}

		for (int rot = 0; rot < 4; rot++) {  // 최대 4번 회전
			bool is_paste = false;
			for (int x = 0; x <= n - row; x++) {   // x 와 y 로 만들어진 좌표 (x,y) 는 현재의 스티커가 노트북에 붙여질 영역의 시작점 좌표
				if (is_paste)
					break;
				for (int y = 0; y <= m - col; y++) {
					if (paste_able(x, y)) {
						is_paste = true;
						break;
					}
				}
			}
			if (is_paste)
				break;
			rotate();
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (note[i][j] == 1)
				cnt++;
		}
	}
	cout << cnt;
}