/*

* 사용되는 이론 : Prefix num (구간합) 
* 시간복잡도 : 각 질의에서 최대 N번의 수를 더해야 한다. 또 그러한 질의가 최대 M개 들어오므로, 시간복잡도는 O(NM) 이 된다.
  N, M 크기를 생각해봤을 때 N x M 은 100억이니 어림도 없다.. 그렇다면 뭔가 획기적인 방법이 필요하다!


사용할 공식 1) D[i] = D[i-1] + A[i]  (테이블 채우기)
=> D[i] = D[i-1] + A[i] 인걸 이용하면 전체를 O(n) 에 채울 수 있다.

사용할 공식 2) i ~ j 번째 사이의 수들의 합 = D[j] - D[i-1]

A[i] + A[i+1] + A[i+2] + ... + A[j-1] + A[j] 
= (A[1] + A[2] + A[3] + ... + A[j-1] + A[j]) - (A[1] + A[2] + A[3] + ... A[i-2] + A[i-1]) 
= D[j] - D[i-1]

이 되어서 각 질의를 무려 O(1) 에 계산이 가능하다.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int s[100005];
int d[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	d[0] = 0;

	// 테이블 채우기
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		d[i] = d[i - 1] + s[i];  // 점화식1 : D[j] = D[i-1] + S[i]
	}

	// i ~ j 번째 사이의 수들의 합 구하기
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << d[j] - d[i - 1] << '\n';  // 점화식2 : D[j] = D[i-1] + S[i]
	}
}