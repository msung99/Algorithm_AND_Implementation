#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100002];

bool binarySearch(int target) {
    int st = 0;
    int en = n-1;

    while(st <= en) {
        int mid = (st + en) / 2;
        if(arr[mid] > target) {
            en = mid-1;
        } 
        else if(arr[mid] < target) {
            st = mid + 1;
        } 
        else {
            return true;
        }
    }
    return false;
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

    cin >> m;
    while(m--) {
        int t;
        cin >> t;
        if(binarySearch(t)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}