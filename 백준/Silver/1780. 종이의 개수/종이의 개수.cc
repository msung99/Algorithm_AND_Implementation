#include <iostream>
#include <string>
using namespace std;

int n;
int board[2200][2200];
int ans[3];

bool check(int x, int y, int n)
{
	int first_element = board[x][y];
	for (int i = x; i < x + n; i++) 
		for (int j = y; j < y + n; j++) 
			if (first_element != board[i][j])
				return false;
	return true;
}

void func(int x, int y, int n)
{

	if (check(x, y, n))
	{
		ans[board[x][y] + 1] += 1; // 카운팅
		return;
	}

	int size = n / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			func(x + size * i, y + size * j, size);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> board[i][j];

	func(0,0,n);

	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
}