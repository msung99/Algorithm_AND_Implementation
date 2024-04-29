#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[50][4];
string a = "ACGT";

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while(n--) {
        string s;
        cin >> s;
        for(int i=0; i<m; i++) {
            int j = a.find(s[i]);
            d[i][j]++;
        }
    }

    int sum = 0;
    for(int i=0; i<m; i++) {
        int mx = -1;
        int idx = -1;
        for(int j=0; j<4; j++) {
            sum += d[i][j];
            if(mx >= d[i][j]) {
                continue;
            }
            mx = d[i][j];
            idx = j;
        }
        sum -= mx;
        cout << a[idx];
    }
    cout << "\n";
    cout << sum << "\n";

    return 0;
}