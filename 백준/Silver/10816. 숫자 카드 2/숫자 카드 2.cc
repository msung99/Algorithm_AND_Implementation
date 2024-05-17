#include <bits/stdc++.h>
using namespace std;

int n;
int arr[500005];

// target 이 들어갈 수 있는 가장 왼쪽 위치
int lower_idx(int target, int len) {
    int st = 0;
    int en = len;

    while(st < en) {
        int mid = (st + en) / 2;
        if(arr[mid] >= target) {
            en = mid;
        } else {
            st = mid + 1;
        }
    }
    return st;
}

// target 이 들어갈 수 있는 가장 오른쪽 위치
int upper_idx(int target, int len) {
    int st = 0;
    int en = len;
    while(st < en) {
        int mid = (st + en) / 2;
        if(arr[mid] > target) {
            en = mid;
        } else {
            st = mid + 1;
        }
    }
    return st; 
}

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

    int m;
    cin >> m;
    while(m--) {
        int target;
        cin >> target;

        cout << upper_idx(target, n) - lower_idx(target, n) << " ";
    }

    return 0;
}