#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr + n);

    int cnt = 0;
    int time = 0;

    for(int i=0; i<n; i++) {
        if(time <= arr[i].second) {
            time = arr[i].first;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}