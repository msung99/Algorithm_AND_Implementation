/*

D[i] : 1 ~i 번쨰 사이의 수들의 합

사용할 공식1) D[i] = D[i-1] + A[i] 
=> D[i] = D[i-1] + A[i] 인것을 이용하면 테이블 전체를 O(n) 에 채울 수 있다.


사용할 공식2) i~j 번째 사이의 수들의 합 = D[j] - D[i-1]

= A[i] + A[i+1] + A[i+2] + ... + A[j-1] + A[j] 
= (1 ~ j번째 사이의 수들의 합) - (1 ~ (i-1) 번쨰 사이의 수들의 합) 
= (A[1] + A[2] + ... + A[j-1] + A[j]) - (A[1] + A[2] + ... + A[i-1])
= D[j] - D[i-1]
*/

#include <iostream>
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

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	d[1] = s[1];

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + s[i];
	}

	while (m--) {
		int start, end;
		cin >> start >> end;
		cout << d[end] - d[start - 1] << '\n';
	}
}