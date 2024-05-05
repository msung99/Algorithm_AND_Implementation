#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[102][102];
int dist[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});

    dist[0][0] = 0;

    while(!q.empty()) {
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
            if(board[nx][ny] != 1 || dist[nx][ny] != -1) {
                continue;
            }
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        fill(dist[i], dist[i] + m, -1);
    }

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j<m; j++) {
            if(str[j] == '1') {
                board[i][j] = 1;
            }
        }
    }

    bfs(0, 0);

    cout << dist[n-1][m-1] + 1;

    return 0;
}