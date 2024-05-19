#include <bits/stdc++.h>
using namespace std;

int n, k;
char board[202][202];
int dist[202][202];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> board[i][j];
        }
    }

    while(k--) {
        int x, y;
        cin >> x >> y;

        if(board[x][y] == '#') {
            
        } else if(board[x][y] == '@') {
            dist[x][y] += 2;
        } else {
            dist[x][y] += 1;
        }


        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <= 0 || nx > n || ny <= 0 || ny > n) {
                continue;
            }

            if(board[nx][ny] == '#') {
                continue;
            } else if(board[nx][ny] == '@') {
                dist[nx][ny] += 2;
            } else {
                dist[nx][ny] += 1;
            }
        }
    }

    int mx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mx = max(mx, dist[i][j]);
        }
    }
    cout << mx;


    return 0;
}