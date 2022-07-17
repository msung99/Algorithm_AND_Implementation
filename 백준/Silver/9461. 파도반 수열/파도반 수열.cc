/*
1. 테이블 설정하기

테이블은 문제에서 제공된 P[k] 가 곧 테이블이다. P[k] 를 그대로 사용하면 된다.


2. 점화식 설정하기 

P(k) 값들의 특징을 잘 살펴보면, 일정한 패턴을 잘 찾아낼 수 있다.
=> P[i] = P[i-3] + P[i-2]  이라는 특징을 지니고 있다!


3. 초기값 설정하기

P[1] = 1 
P[2] = 1
P[3] = 1
*/

#include <bits/stdc++.h>
using namespace std;

int t;
long long p[105];  // p[90], p[100] 과 같이 p[k] 에서 k 값이 매우 큰 경우에, 정수형 배열의 범위를 초과해서 
// 오버플로우가 발생한다. 따라서 long long 타입의 배열로 선언해준다!

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	p[1] = p[2] = p[3] = 1;

	for (int i = 4; i <= 102; i++) {
		p[i] = p[i - 3] + p[i - 2];
	}

	while (t--) {
		int k;
		cin >> k;
		cout << p[k] << "\n";
	}
}