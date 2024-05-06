#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[1002][1002];
int dist[1002][1002][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs() {
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    
    while(!q.empty()) {
        auto cur = q.front();
        int x, y, broken;
        tie(x, y, broken) = cur;
        q.pop();

        if(x == n-1 && y == m-1) {
            cout << dist[x][y][broken];
            return;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if(dist[nx][ny][broken] == -1 && board[nx][ny] == '0') {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }

            if(dist[nx][ny][broken] == -1 && board[nx][ny] == '1' && !broken) {
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    cout << -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    bfs();

    return 0;
}