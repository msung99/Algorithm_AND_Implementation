#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[502][502];
bool visited[502][502];
int cnt;
int area;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    int cur_area = 0;

    while(!q.empty()) {
        cur_area++;
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        visited[x][y] = true;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if(visited[nx][ny] || board[nx][ny] != 1) {
               continue; 
            }
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    area = max(area, cur_area);
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
            if(!visited[i][j] && board[i][j] == 1) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    cout << area;

    return 0;
}