#include <bits/stdc++.h>
using namespace std;

string board[4];

void func(int num, int dir) {
    int dirs[4] = {};
    dirs[num] = dir;

    int idx = num;
    // 왼쪽으로 회전 전파
    while(idx > 0 && board[idx-1][2] != board[idx][6]) {
        dirs[idx-1] = -dirs[idx];
        idx--;
    }

    idx = num;
    // 오른쪽으로 회전 전파
    while(idx < 3 && board[idx][2] != board[idx+1][6]) {
        dirs[idx+1] = -dirs[idx];
        idx++;
    }

    for(int i=0; i<4; i++) {
        if(dirs[i] == -1) {
            rotate(board[i].begin(), board[i].begin() + 1, board[i].end());
        }
        else if(dirs[i] == 1) {
            rotate(board[i].begin(), board[i].begin() + 7, board[i].end());
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<4; i++) {
        cin >> board[i];
    }

    int k;
    cin >> k;
    while(k--) {
        int num, dir;
        cin >> num >> dir;
        func(num -1, dir);
    }

    int ans = 0;
    for(int i=0; i<4; i++) {
        if(board[i][0] == '1') {
            ans += (1 << i);
        }
    }
    cout << ans;

    return 0;
}