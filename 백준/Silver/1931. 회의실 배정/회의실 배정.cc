// 최적의 해 : 가능한 회의 중에서 가장 먼저 끝나는 회의를 택하기

/*
명제 : 현재 시간이 t라고 할때, 시작 시간이 t 이상인 모든 회의 중에서 가장 먼저 끝나는 회의를 택하는 것이 최적해이다.

=> 증명 : "귀류법" 을 사용하자. 명제를 거짓이라고 가정하고,
회의 A 대신 회의 B를 택했을 때 더 많은 회의를 배정할 수 있다고 가정
*/

#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> s[100005]; // (종료시간, 시작시작) 쌍으로 저장

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].second >> s[i].first;
	}
	sort(s, s + n); // 끝나는 시간이 빠른 순으로, 끝나는 시간이 같다면 시작하는 시간이 빠른 순으로 정렬

	int ans = 0; 
	int t = 0; // 현재시간

	for (int i = 0; i < n; i++) {
		if (t > s[i].second)  
			continue;
		// 지금보는 스캐쥴의 시작시간이 t 이하면 바로 회의를 배정
		// => 회의를 배정한다는 것? = ans 를 1증가시키고, t 는 s[i].first 로 변경시키는 것
		ans++;
		t = s[i].first; 
	}

	cout << ans;
}