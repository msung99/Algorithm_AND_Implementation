#include <bits/stdc++.h>
using namespace std;

int num[2000001];
int n, sum;
int cnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		num[data]++; // 입력받은 숫자에 해당하는 인덱스에 존재한다고 1표시
	}
	cin >> sum; // 목표 합

	for (int i = 0; i < (sum + 1) / 2; i++) { // (2,3) 과 (3,2) 중복 카운팅 방지
		// i 와 sum-i 라는 숫자가 존재하는지 확인
		if (num[i] == 1 && num[sum - i] == 1)  // => 생각해보면, (i) + (sum-i) = sum 이므로, 2번쨰 피연산자인 sum-i 가 배열에 존재하는지 확인하면 된다.
			cnt++; // 목표하는 두 숫자쌍을 찾은 경우 cnt 를 카운팅
	}
	cout << cnt;
}

/*
	// 2중 for문을 돌리면 런타임에러 발생 =>  O(n^2) 보다 더 효율적인 방법이 필요하다.
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == ans)
				cnt++;
		}
	}
*/
