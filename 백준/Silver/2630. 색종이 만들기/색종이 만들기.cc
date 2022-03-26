#include <iostream>
#include <string>
using namespace std;

int board[2200][2200];
int n;
int ans[2];

bool check(int x, int y, int n)
{
	int first_element = board[x][y]; // 그 색종이 구역의 첫번째 원소
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (first_element != board[i][j])
				return false;
		}
	}
	return true;
}

void func(int x, int y, int n)
{
	if (check(x, y, n))
	{
		ans[board[x][y]] += 1;
		return;
	}
	// 그 색종이 구역의 원소가 하나라도 다를 경우, 4분할을 시행
	int size = n / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			func(x + i * size, y + j * size, size);
}


int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> board[i][j];

	func(0, 0, n);
	cout << ans[0] << '\n' << ans[1];
}