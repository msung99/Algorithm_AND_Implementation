#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int d[10002]; 
int coin[22];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--) {
        fill(d, d + 10001, 0);
        d[0] = 1; // 동전 0원을 만드는 경우의 수는 1가지
        
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> coin[i];
        }

        cin >> m;

        for(int i=0; i<n; i++) {
            for(int j=coin[i]; j<=m; j++) {
                d[j] += d[j - coin[i]];
            }
        }
        cout << d[m] << "\n";
    }
    return 0;
}