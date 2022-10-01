#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<bool> v(n + 1, 1); // 0 ~ n 이 소수인지 아닌지 판별

	// 에라토스테네스의 체
	for (int i = 2; i * i <= n; i++) {
		if (v[i] == 0)
			continue;
		for (int j = i + i; j <= n; j += i) {
			v[j] = 0;  // j 는 i의 배수이기 때문에 소수가 아니다.
		}
	}
	vector<int> prime;
	for (int i = 2; i <= n; i++) {
		if (v[i])
			prime.push_back(i); // v[i] 가 1인 값만 prime 벡터에 추가하여 연속된 소수의 집합 생성
	}

	// 투 포인터 생성
	int s = 0, e = 0; // 소수 값을 참조할 인덱스를 저장할 두개의 변수 선언 => 투포인터
	int sum = 0; // 연속된 소수의 합
	int ans = 0; // n을 만들 수 있는 경우의 수
	while (true) {
		if (sum > n) { // sum 이 n보다 크다면 s번째 소수 값을 sum 에서 뺸뒤, s값 증가
			sum -= prime[s];
			s++;
		}
		else if (sum < n) { // sum이 n보다 작으면 e번째 소수 값을 sum 에 더한뒤, e값 증가
			if (e >= prime.size()) { // e가 소수를 저장한 벡터의 크기와 같거나 크다면 멈춤
				break;
			}
			sum += prime[e];
			e++;
		}
		else {  // sum이 n과 같다면 경우의 수 1증가
			ans++;
			if (e >= prime.size()) // e가 소수를 저장한 벡터의 크기와 같거나 크다면 멈춤
				break;
			// 그렇지않다면 sum에 e번째 소수값을 sum에 더한뒤, e값 증가
			sum += prime[e];
			e++;
		}
	}
	cout << ans;
}