#include <bits/stdc++.h>
using namespace std;

int n;
char board[102][102];
bool visited[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(int sx, int sy) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }
            
            if(board[x][y] != board[nx][ny] || visited[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx, ny});
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
        string s;
        cin >> s;

        for(int j=0; j<n; j++) {
            board[i][j] = s[j];
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;


    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                cnt1++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == 'R') {
                board[i][j] = 'G';
            }
        }
    }

    for(int i=0; i<n; i++) {
        fill(visited[i], visited[i] + n, false);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                cnt2++;
            }
        }
    }

    cout << cnt1 << ' ' << cnt2;

    return 0;
}