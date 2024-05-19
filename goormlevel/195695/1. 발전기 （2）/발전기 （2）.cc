#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[1002][1002];
bool visited[1001][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int sz[1002];

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

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }

            if(board[cur.first][cur.second] != board[nx][ny] || visited[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    if(area >= k) {
        sz[board[x][y]]++;        
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k; // 원소가 k개 이상인 연결 요소를 단지로 취급

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    int mx = -999999999;
    for(int i=1; i<=30; i++) {
        mx = max(mx, sz[i]);
    }

    vector<int> buildings;
    for(int i=1; i<=30; i++) {
        if(sz[i] == mx) {
            buildings.push_back(i);
        }
    }
    sort(buildings.begin(), buildings.end(), greater<>());
    cout << buildings[0];

    return 0;
}