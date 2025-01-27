#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[502][502];
bool visited[502][502];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int cnt;
int mx;

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int area = 0;
    while(!q.empty()) {
        area++;
        auto cur = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
 
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if(visited[nx][ny] || board[nx][ny] == 0) {
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

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];            
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    cout << mx;

    return 0;
}