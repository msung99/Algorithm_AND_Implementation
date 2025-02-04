#include <bits/stdc++.h>
using namespace std;

char board[66][66];

void func(int n, int startX, int startY) {
    if(n == 1) {
        cout << board[startX][startY];
        return;
    }

    char color = board[startX][startY];
    bool isSameArea = true;
    for(int i=startX; i<startX+n; i++) {
        for(int j=startY; j<startY+n; j++) {
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
                func(size, startX + size*i, startY + size*j);
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
            board[i][j] = s[j];            
        }
    }

    func(n, 0, 0);

    return 0;
}