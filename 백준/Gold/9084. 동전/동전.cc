#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int money;
int d[10002];
int coin[10002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--) {
        fill(d, d + 10001, 0);
        cin >> n;
        d[0] = 1;
        for(int i=0; i<n; i++) {
            cin >> coin[i];
        }
        cin >> money;

        for(int i=0; i<n; i++) {
            for(int j=coin[i]; j<=money; j++) {
                d[j] += d[j - coin[i]];
            }
        }
        cout << d[money] << "\n";
    }

    return 0;
}