#include <bits/stdc++.h>
using namespace std;

int n;
int board[130][130];
int cnt[2];

bool check(int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (board[i][j] != board[x][y])
				return false;
		}
	}
	return true;
}

void func(int x, int y, int size) {
	if (check(x, y, size)) {
		cnt[board[x][y]]++;
		return;
	}

	int divideSize = size / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			func(x + i*divideSize, y + j*divideSize, divideSize);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	func(0, 0, n);
	for (int i = 0; i < 2; i++) {
		cout << cnt[i] << "\n";
	}
	return 0;
}