#include <bits/stdc++.h>
using namespace std;

int n;
int val;
int board[502][502];
bool visited[502][502];
int mx = -1999999999;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int area = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        area++;

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx <= 0 || nx > n || ny <= 0 || ny > n) {
                continue;
            }

            if(board[nx][ny] != val || visited[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    mx = max(area, mx);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    int x, y;
    cin >> x >> y;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> board[i][j];
        }
    }

    val = board[x][y];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(!visited[i][j] && board[i][j] == val) {
                bfs(i, j);
            }
        }
    }
    cout << mx;

    return 0;
}