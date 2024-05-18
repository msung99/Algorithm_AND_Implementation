// https://beginnerdeveloper-lit.tistory.com/36
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int mx = arr[n-1]; // 우선 최댓값을 가장 큰 로프 하나만 이용했을 때로 초기화
    int cur;

    for(int i=n-1; i >= 0; i--) {
        // 현재 로프를 n-i 개 사용했으며, 사용하는 로프들 중에 i번째 루프가 들 수 있는 중량이 가장 작은 루프임
        cur = arr[i] * (n-i); // 현재 로프의 중량 ( * 몇 개 달았는지)
        mx = max(mx, cur);
    }
    cout << mx;

    return 0;
}