#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[22][22];
int dice[7];
//   [1] 
//[5][2][6]
//   [3]
//   [4]

int idx[5][4] = {
    {},
    {2, 6, 4, 5},
    {2, 5, 4, 6},
    {3, 2, 1, 4},
    {2, 3, 4, 1},
};

void roll(int command) {
    int tmp[7];
    for(int i=1; i<=6; i++) {
        tmp[i] = dice[i];
    }

    for(int i=0; i<4; i++) {
        tmp[idx[command][i]] = dice[idx[command][(i+1) % 4]];
    }

    for(int i=1; i<=6; i++) {
        dice[i] = tmp[i];
    }
}

bool isOk(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return true;
}

void move(int command) {
    int nx = x;
    int ny = y;
    if(command == 1) {
        ny++;
    } else if(command == 2) {
        ny--;
    } else if(command == 3) {
        nx--;
    } else {
        nx++;
    }

    if(isOk(nx, ny)) {
        x = nx;
        y = ny;

        roll(command);

        if(board[nx][ny] == 0) {
            board[nx][ny] = dice[4];
        } else {
            dice[4] = board[nx][ny];
            board[nx][ny] = 0;
        }
        cout << dice[2] << "\n";
    }     
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y >> k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    while(k--) {
        int command;
        cin >> command;
        move(command);
    }

    return 0;
}