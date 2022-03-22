#include <iostream>
using namespace std;

// ** 귀납법 활용
// 1승을 계산할 수 있다.
// k승의 나머지를 계산했으면 2k승과 2k+1승의 나머지도 O(1) 에 계산할 수 있다.

// a^b mod m   => a^b 를 m 으로 나눈 나머지 결과
long long POW(long long a, long long b, long long m) {
	if (b == 1) // 1승의 나머지 계산 결과
		return a % m; // a가 m보다 클 수 있어서 a를 리턴하는 대신 a % m 을 리턴

	// 재귀적으로 a^(b/2) mod m 을 계산해 val에 대입하고  val 을 제곱함.
	// b = 7인 경우 b/2 = 3 이므로  val = val * val % m;  줄의 내용이 끝나면 val 은 a^6 mod m 의 값이 들어간다.
	 // 즉, b가 짝수이면 그냥 val의 값을 리턴하면 끝이지만, b가 홀수이면 val에 a를 한번 더 곱하고 나머지 결과를 다시 계산해서 리턴해야함
	
	long long val = POW(a, b / 2, m); // a의 (b/2)승 나머지 결과를 val에 저장
	val = val * val % m; // a의 b승 나머지 결과 = { ( a의 (b/2)승 나머지 결과 ) x ( a의 (b/2)승 나머지 결과 ) } 의 나머지 결과 
	
	if (b % 2 == 0) // b가 짝수인 경우
		return val; 

	return val * a % m; // b가 홀수인 경우 =>  val 에 a를 한번 더 곱해서 나머지 결과를 리턴해야 함
} 


int main(void)
{
	long long a, b, c, res;
	cin >> a >> b >> c;

	res = POW(a, b, c);
	cout << res;
}