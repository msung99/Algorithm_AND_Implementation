#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1002][1002];
int dist[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    queue<pair<int,int>> q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            
            if(board[i][j] == 0) {
                dist[i][j] = -1;
            }

            if(board[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if(dist[nx][ny] >= 0) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int res = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            res = max(res, dist[i][j]);
        }
    }
    cout << res;
    
    return 0;
}