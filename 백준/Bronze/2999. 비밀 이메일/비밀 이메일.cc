#include <bits/stdc++.h>
using namespace std;

char b[100][100];
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    int rc = s.length();
    int r = 1;
    int c = rc;

    for(int i=1; i*i <= rc; i++) {
        if(rc % i != 0) {
            continue;
        }
        r = i;
        c = rc / r;
    }

    int idx = 0;
    for(int j=0; j<c; j++) {
        for(int i=0; i<r; i++) {
            b[i][j] = s[idx++];
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << b[i][j];
        }
    }

    return 0;
}