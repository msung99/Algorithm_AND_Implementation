#include <bits/stdc++.h>
using namespace std;

string board[4];
int k;

void move(int num, int dir) {
    int dirs[4] = {};
    num--;
    dirs[num] = dir;

    // 왼쪽으로 회전 전파
    for(int i=num; i>0; i--) {
        if(board[i][6] == board[i-1][2]) {
            break;
        }
        dirs[i-1] = -dirs[i];
    }

    // 오른쪽으로 회전 전파
    for(int i=num; i<3; i++) {
        if(board[i][2] == board[i+1][6]) {
            break;
        }
        dirs[i+1] = -dirs[i];
    }

    for(int i=0; i<4; i++) {
        if(dirs[i] == 1) { // 시계방향으로 회전
            rotate(board[i].begin(), board[i].begin()+7, board[i].end());
        }

        else if(dirs[i] == -1) { // 반시계방향으로 회전
            rotate(board[i].begin(), board[i].begin()+1, board[i].end());
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

    cin >> k;

    while(k--) {
        int num, dir;
        cin >> num >> dir;
        move(num, dir);
    }

    int total = 0;
    for(int i=0; i<4; i++) {
        if(board[i][0] == '1') {
            total += (1 << i);
        }
    }    

    cout << total;

    return 0;
}