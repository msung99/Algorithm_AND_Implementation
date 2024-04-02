#include <bits/stdc++.h>
using namespace std;

int k;
string board[6];

// num번째 톱니바퀴를 dir 방향으로 회전시킴
void go(int num, int dir) {
    int dirs[5] = {};
    dirs[num] = dir; // num번쨰 톱니바퀴의 회전방향을 dir 로 설정

    // 왼쪽 방향으로 회전을 전파
    int pos = num;
    while(pos >= 1 && board[pos][6] != board[pos-1][2]) {
        dirs[pos-1] = -dirs[pos];
        pos--;
    }

    // 오른쪽 방향으로 회전을 전파
    pos = num;
    while(pos <= 4 && board[pos][2] != board[pos+1][6]) {
        dirs[pos+1] = -dirs[pos];
        pos++;
    }

    // c++ rotate() 함수를 활용하여 톱니바퀴를 회전시킴
    for(int i=1; i<=4; i++) {
        // 반시계 방향으로 회전
        if(dirs[i] == -1) { 
            rotate(board[i].begin(), board[i].begin() + 1, board[i].end());            
        }
        // 시계 방향으로 회전
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

    for(int i=1; i<=4; i++) {
        cin >> board[i];
    }

    cin >> k;
    while(k--) {
        int num, dir;
        cin >> num >> dir;
        go(num, dir);
    }

    int ans = 0;
    for(int i=1; i<=4; i++) {
        if(board[i][0] == '1') {
            ans += (1 << (i-1));
        }
    }
    cout << ans;

    return 0;
}