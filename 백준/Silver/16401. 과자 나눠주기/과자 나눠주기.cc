#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1000002];

// 막대 과자의 길이가 len일 경우 m조각 이상이 나오는가?
bool solve(int len) {
    if(len == 0) {
        return true;
    }
    long long cnt = 0;
    for(int i=0; i<n; i++) {
        cnt += arr[i] / len;
    }
    return cnt >= m;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int st = 0;
    int en = *max_element(arr, arr + n);

    while(st < en) {
        int mid = (st + en + 1) / 2;
        if(solve(mid)) {
            st = mid;
        } else {
            en = mid - 1;
        }
    }

    cout << st << "\n";

    return 0;
}