#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1002][1002];
int d[1002][1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=1; j<=m; j++) {
            if(s[j-1] == '1')  {
                board[i][j] = 1;
            }
        }
    }

    int maxLength = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(board[i][j] == 1) {
                d[i][j] = min(min(d[i-1][j-1], d[i-1][j]), d[i][j-1]) + 1;
            }
            maxLength = max(maxLength, d[i][j]);
        }
    }

    cout << maxLength * maxLength;

    return 0;
}