#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int prefix_sum[1002];

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

    int res = arr[0];
    prefix_sum[0] = arr[0];

    for(int i=1; i<n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
        res += prefix_sum[i];
    }

    cout << res;

    return 0;
}