#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        arr.push_back(data);
    }

    sort(arr.begin(), arr.end());

    int ans = 0;

    for(int i=1; i<=n; i++) {
        ans = max(ans, arr[n-i] * i);
    }
    cout << ans;

    return 0;
}