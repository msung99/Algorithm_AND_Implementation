#include <bits/stdc++.h>
using namespace std;

int n;
int board[42][42];
int tmp[42][42];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


void play(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }

        if(board[nx][ny] == 0) {
            if(tmp[x][y] == 0) {
                continue;
            }
            tmp[x][y]--;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    bool isComplete;
    int ans = 0;
    while(true) {
        isComplete = true;

        // board -> tmp 에 카피
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                tmp[i][j] = board[i][j];
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] != 0) {
                    play(i, j);
                    isComplete = false;
                }
            }
        }

        // tmp -> board 에 카피
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] = tmp[i][j];
            }
        }

        if(isComplete) {
            break;
        }

        ans++;
    }

    cout << ans;

    return 0;
}