#include <bits/stdc++.h>
using namespace std;

long long a, b, c;
// 1승을 계산할 수 있다.
// k승을 계산했으면 2k 승과 2k+1 승도 O(1) 계산할 수 있다.
// a^n x a^n = a^2n
// 12^58 : 4 (% 67) => 12^116 : 16(%67)

long long func(long long a, long long b, long long c) {
	if (b == 1)
		return a % c;

	long long val = func(a, b / 2, c); // a^(b/2) % c 를 계산해서 val 에 할당
	val = (val * val) % c;  // val 을 제곱합

	if (b % 2 == 0)
		return val;
	// if(b % 2 == 1) // b가 홀수이면 val 에 a를 한번더 곱해서 리턴해야한다. => 만약 b가 7이라하면 b/2 는 3이므로 
	return (val * a) % c;     // val = (val * val) % c 를 실행하면 "a^7 % c" 가 아닌 "a^6 % c" 가 할당될 것이다. 따라서 a를 한번더 곱해준다.
}

/*
long long func(long long a, long long b, long long c) {
	long long val = 1;
	while (b--) {
		val = val * a % c;
	}
	return val;
}
*/

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	cout << func(a, b, c);
}