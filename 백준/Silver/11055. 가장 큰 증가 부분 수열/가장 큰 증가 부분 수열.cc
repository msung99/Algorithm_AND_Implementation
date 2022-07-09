/*
탐색 순서는
i=3일 때 1, 2번째
i=4일 때 1, 2, 3번째와
비교한다.

입력받는 수를 담을 배열 arr[]와
i번째까지 증가하는 수열의 합을 담을 배열 dp[]를
정의해준다.

d[]의 모든 원소는 arr[] 자기자신 값으로 초기화해준다.
가장 긴 증가하는 수열이 자기자신 뿐으로 총 합이 자기자신일 수도 있다.

i=3일 때 j=1, 2
i=4일 때 j=1, 2, 3 이라고 하면

arr[i]가 arr[j]보다 작을 경우는 패쓰하고
arr[i]가 arr[j]보다 클 경우에는 d[i] = d[j] + arr[i]을 해준다.
여기서 주의할 점
arr[4]가 arr[2]보다 크고 arr[3]보다 큰데
d[2] = 1, d[3] = 100일 때 d[4]는 100이 되어야 한다.
그러면 매번 d[j]+arr[i]값을 비교했을 때 더 큰 값을 선택해주면 된다.
즉, d[i] = max(d[i], d[j]+arr[i])을 반복해주면 된다.
*/

#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{
	int n;
	cin >> n;

	int arr[1001];
	int dp[1001];

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++) 
        dp[i] = arr[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    sort(dp, dp + n + 1);

    
    cout << dp[n];
}