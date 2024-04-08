#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }

    // 끝나는 시간이 가장 빠른것을 앞단으로 정렬
    // 또한 끝나는 시간이 동일하다면, 시작하는 시간이 빠른 순으로 배치한다.
    sort(arr, arr + n);

    int ans = 0;
    int time = 0; // 현재 시간

    for(int i=0; i<n; i++) {
        if(time > arr[i].second) {
            continue;
        }
        ans++;
        time = arr[i].first; // 지금보는 시간이 time 이하려면 바로 회의를 배정한다.
    }

    cout << ans;

    return 0;
}