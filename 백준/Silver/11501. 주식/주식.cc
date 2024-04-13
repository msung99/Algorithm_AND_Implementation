#include <bits/stdc++.h>
using namespace std;

int t;
int arr[10000002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        long long ans = 0;
        int maxValue = arr[n-1];
        for(int i=n-2; i>=0; i--) {
            if(arr[i] > maxValue) {
                maxValue = arr[i];
            }
            ans += maxValue - arr[i];            
        }
        cout << ans << "\n";
    }

    return 0;
}