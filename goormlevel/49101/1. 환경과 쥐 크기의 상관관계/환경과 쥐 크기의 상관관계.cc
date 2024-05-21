#include <bits/stdc++.h>
using namespace std;

int n;
int arr1[100002];
int arr2[100002];
int mx1 = 0, mx2 = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
        mx1 = max(mx1, arr1[i]);
    }

    for(int i = 0; i < n; i++) {
        cin >> arr2[i];
        mx2 = max(mx2, arr2[i]);
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);

    int maxCnt1 = 0;
    int res1 = INT_MAX;

    for(int x = 1; x <= mx1 - 2; x++) {
        auto lower = lower_bound(arr1, arr1 + n, x - 2);
        auto upper = upper_bound(arr1, arr1 + n, x + 2);
        int curCnt = upper - lower;
        if(curCnt > maxCnt1) {
            maxCnt1 = curCnt;
            res1 = x;
        } else if(curCnt == maxCnt1) {
            res1 = min(res1, x); // ensure the smallest x is chosen
        }
    }

    int maxCnt2 = 0;
    int res2 = INT_MAX;

    for(int x = 1; x <= mx2 - 2; x++) {
        auto lower = lower_bound(arr2, arr2 + n, x - 2);
        auto upper = upper_bound(arr2, arr2 + n, x + 2);
        int curCnt = upper - lower;
        if(curCnt > maxCnt2) {
            maxCnt2 = curCnt;
            res2 = x;
        } else if(curCnt == maxCnt2) {
            res2 = min(res2, x); // ensure the smallest x is chosen
        }
    }

    cout << res1 << ' ' << res2 << "\n";

    if(res1 > res2) {
        cout << "good";
    } else {
        cout << "bad";
    }

    return 0;
}
