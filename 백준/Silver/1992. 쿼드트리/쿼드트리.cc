#include <bits/stdc++.h>
using namespace std;

int board[66][66];

void func(int n, int sx, int sy) {
    if(n == 1) {
        cout << board[sx][sy];
        return;
    }

    bool isSameArea = true;
    int color = board[sx][sy];
    for(int i=sx; i<sx+n; i++) {
        for(int j=sy; j<sy+n; j++) {
            if(board[i][j] != color) {
                isSameArea = false;
                break;
            }
        }
    }

    if(isSameArea) {
        cout << color;
    } else {
        cout << "(";
        int size = n/2;
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                func(size, sx + size*i, sy + size*j);
            }
        }
        cout << ")";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    func(n, 0, 0);

    return 0;
}