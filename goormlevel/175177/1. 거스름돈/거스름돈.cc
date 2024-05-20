#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    arr.push_back(40);
    arr.push_back(20);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(1);

    int n;
    cin >> n;

    int ans = 0;
    for(int i=0; i<arr.size(); i++) {
        while(n - arr[i] >= 0) {
            n -= arr[i];
            ans++;
        }
    }
    cout << ans;

    return 0;
}