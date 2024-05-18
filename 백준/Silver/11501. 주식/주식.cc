// 뒤에서 부터 최대값을 정해주며 값을 더해준다.
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        int maxValue = arr[n-1];
        long long res = 0;

        for(int i=n-2; i>= 0; i--) {
            if(maxValue < arr[i]) {
                maxValue = arr[i];
            } 
            res += maxValue - arr[i];
        }
        cout << res << "\n";
    }

    return 0;
}