#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
cnt : 현재보고 있는 수가 몇 번 등장했는지 카운팅 
=> 초기값 : 0
=> 현재 보고 있는수가 제일 앞에 있는 수이거나, 
현재 보고 있는 수가 바로 직전에 나온 수와 같을떄는 그냥 cnt를 1증가시킨다.

mxval : 현재까지 가장 많이 등장한 수의 값 
=> 초기값 : -2^62 - 1 (등장가능한 수의 최솟값보다 더 작은 값으로 초기값을 설정)

mxcnt : 현재까지 가장 많이 등장한 수의 등장횟수 
=> 초기값 :  0
*/ 

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long list[100005];

	// 수의 범위가 -2^62 ~ 2^62 이므로, int가 아닌 long long 을 사용하자.
	int cnt = 0;
	long long mxval = -(111 << 62) - 1;
	//long long mxval = pow(2, 62) * -1;
	int mxcnt = 0;

	int n;
	cin >> n;
	for(int i=0; i < n; i++){
		cin >> list[i];
	}
	// 우선 O(nlogn) 으로 정렬
	sort(list, list + n);

	// O(n) 시간에 정렬을 수행하기
	// sort() 로 정렬후에 같은 숫자끼리는 바로 옆 인덱스에서 따닥따닥 인접하게 된다는 성질을 이용한다.
	for (int i = 0; i < n; i++) {
		if (i == 0 || list[i] == list[i - 1]) 
			cnt++;  // 현재 바라보고 있는 숫자의 등장횟수 카운팅
		else {
			if (mxcnt < cnt) { // 현재 바라본 숫자의 등장횟수와, 지금껏 구한 여러 숫자들중의 최대 등장횟수를 비교하고
				mxcnt = cnt;   // 현재 바라본 숫자의 등장횟수가 가장 크다면 최대 등장횟수를 최신화
				mxval = list[i - 1];   // 현재 바라본 숫자가 최댓값인 경우 현재까지 가장 많이 등장한 수의 값도 최신화한다.
			}
			cnt = 1; // list[i] 에 담긴 해당 숫자에 대한 카운팅
		}
	}

	if (cnt > mxcnt)   // 제일 마지막 수에 대한 처리를 해야함에 유의하자.
		mxval = list[n - 1];   // => 이 처리를 하지 않으면, 제일 마지막 수는 등장 횟수를 카운팅하지 않게된다.

	cout << mxval;
}