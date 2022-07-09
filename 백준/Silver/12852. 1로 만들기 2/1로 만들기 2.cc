// 참고) BFS 풀이법 : dist 배열을 하나 만들어두고, 
// 1을 초기값으로 한뒤 x2, x3, +1 로 뻗어나가면 된다.

/*
DP 에서 경로를 추적하는 방법

테이블을 채울 때 추가적인 정보를 어딘가에 기입해야 한다.

원래 테이블을 값 테이블, 
추가적인 정보가 들어갈 테이블을 "경로 복원용 테이블" 이라고 부른다.


원래 테이블 D 에서 D[1] = 0 인것은 당연하고,
pre[1] 은 어차피 참조가 안되는 값이라 큰 의미를 두지 않아도 된다.

테이블에서 2번쨰 칸으

*/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int d[1000005];
int pre[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	d[1] = 0;

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;

		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2;
		}

		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
			pre[i] = i / 3;
		}
	}
	cout << d[n] << '\n';

	int cur = n;
	while (true) {
		cout << cur << ' ';
		if (cur == 1)
			break;
		cur = pre[cur];
	}
}