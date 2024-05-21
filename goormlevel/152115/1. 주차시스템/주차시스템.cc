#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[2002][2002];
bool visited[2002][2002];
int mx = -2100000000;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int score = 0;
    int area = 0;
    while(!q.empty()) {
        area++;
        auto cur = q.front();
        q.pop();

        if(board[cur.first][cur.second] == 0) {
            score += 1;
        } else if(board[cur.first][cur.second] == 2) {
            score -= 2;
        }

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second+ dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if(visited[nx][ny] || board[nx][ny] == 1) {
                continue;
            }

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    mx = max(score, mx);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && board[i][j] != 1) {
                bfs(i, j);
            }           
        }        
    }

    if(mx < 0) {
        cout << 0; 
    } else {
        cout << mx;
    }

    return 0;
}