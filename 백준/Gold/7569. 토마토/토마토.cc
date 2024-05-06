#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int board[102][102][102];
int dist[102][102][102];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h; // 5, 3, 1

    queue<tuple<int,int,int>> q;

    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                cin >> board[i][j][k];
                if(board[i][j][k] == 0) {
                    dist[i][j][k] = -1;
                }
                if(board[i][j][k] == 1) {
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        int z, x, y;
        tie(z, x, y) = cur;
        q.pop();

        for(int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) {
                continue;
            }

            if(dist[nz][nx][ny] != -1) {
                continue;
            }

            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push(make_tuple(nz, nx, ny));
        }
    }

    int res =0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(dist[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                res = max(res, dist[i][j][k]);
            }
        }
    }
    cout << res;

    return 0;
}