#include <bits/stdc++.h>
using namespace std;

// 2^n x 2^n 배열에서 (r,c) 를 방문하는 순서를 반환하는 함수 
int func(int n, int r, int c) {
	if (n == 0)
		return 0;

	int half = 1 << (n - 1);
	// (r,c) 가 1번 삼각형에 있을 때
	if (r < half && c < half)
		return func(n - 1, r, c);

	// (r,c) 가 2번 삼각형에 있을 때
	if (r < half && c >= half)
		return (half * half) + func(n - 1, r, c - half);
	// => (half * half) : 1번 삼각형의 면적 
	// => func(n - 1, r, c - half) : 2번 삼각형 내부에서 (r,c) 를 방문하는 순서

	// (r,c) 가 3번 삼각형에 있을 때 
	if (r >= half && c < half)
		return 2 * (half * half) + func(n - 1, r - half, c);
	// => (half * half) : 1번 + 2번 삼각형의 면적 

	// (r,c) 가 4번 삼각형에 있을 때 
	return 3 * (half * half) + func(n - 1, r - half, c - half);
	// => (half * half) : 1번 + 2번  + 3번 삼각형의 면적 
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}