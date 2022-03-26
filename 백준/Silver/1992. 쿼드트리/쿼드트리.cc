#include <iostream>
#include <string>
using namespace std;

int n;
int arr[64][64];

void solve(int n, int y, int x)
{
	if (n == 1) { // base condition
		cout << arr[y][x];
		return;
	}

	bool all_zero = true; // 그 구역의 모든 원소가 0으로 이루어져있는지 체크해주는 변수
	bool all_one = true; // 마찬가지로 1로 이루어져있는지 체크해주는 변수

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j])  // arr[i][j] == 1  
				all_zero = false; 
			else  // arr[i][j] == 0
				all_one = false;
		}
	}
	if (all_zero) // 그 구역의 모든 원소가 0인경우
		cout << 0;
	else if (all_one) // 그 구역의 모든 원소가 1인경우
		cout << 1;
	else  // 그 구역의 원소들이 0과 1이 섞여있는경우
	{
		cout << "(";
		int size = n / 2;
		solve(size, y, x); // 왼쪽 위 
		solve(size, y,  x + size); // 오른쪽 위
		solve(size, y + size, x); // 왼쪽 아래
		solve(size, y + size, x + size); // 오른쪽 아래
		cout << ")";
	}
	return;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
			arr[i][j] = str[j] - '0';  // 0을 뻄으로써 str[j]를 정수화시킴
	}
	solve(n, 0, 0);
}