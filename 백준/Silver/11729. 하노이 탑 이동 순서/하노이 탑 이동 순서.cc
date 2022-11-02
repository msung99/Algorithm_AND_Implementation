#include <bits/stdc++.h>
using namespace std;

int n, total;

// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
void func(int a, int b, int n) {
	if (n == 1) { // 원판이 1개일때는 a에서 b로 옮길 수 있다.
		cout << a << ' ' << b << '\n'; 
		return;
	}

	func(a, 6 - a - b, n - 1); // n-1개의 원판을 기둥 a에서 6-a-b로 옮기고
	cout << a << ' ' << b << '\n'; // n번쨰 원판을 기둥 a에서 b로 옮긴다.
	func(6-a-b, b, n - 1); // n-1 개의 원판을 기둥 6-a-b 에서 기둥 b로 옮긴다.
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cout << (1 << n) - 1 << '\n';
	func(1, 3, n);
	// 원판의 총 이동횟수 : 원판 k개를 옮기기 위해 A번 이동이 필요했다고 하자.
	// 그러면 원판 k+1개를 옮길때는 k개의 원판을 빈곳으로 옮길 때 k번,
	// k+1번쨰 원판을 옮길 때 1번,
	// k개의 원판을 다시 빈 곳에서 목적지로 옮길 때 A번이 필요하니,
	// 총 2A+1 번 이동이 필요하다.
}