#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[505][505], d[505][505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;


	// 2차원 배열 a에 삼각형을 저장
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++)    
			cin >> a[i][j];  // a[i][j] : 삼각형에서 (i, j) 좌표의 정수 삼각형 정보가 저장됨

	// 초기값 설정
	d[1][1] = a[1][1]; 

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)   // i번째 까지 내려왔을때 j번째 좌표에 위치한 정수 삼각형은 (즉, (i, j) 좌표의 삼각형 정보는)
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];   // 문제의 조건에 따라서 대각선 왼쪽(= d[i-1][j-1]) 또는 대각선 오른쪽(= d[i-1][j+1]) 에 있는 값 중에서 하나를 물려받음

	cout << *max_element(d[n] + 1, d[n] + n + 1);
}