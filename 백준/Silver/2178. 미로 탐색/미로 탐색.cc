#include <bits/stdc++.h>
using namespace std;

int n,m;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int board[101][101];
int dist[101][101];

void bfs() {
    queue<pair<int,int>> q;
    dist[0][0] = 1;
    q.push({0,0});
    int x,y;    

    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 0) {
                continue;
            }
            if(dist[ny][nx]) {
                continue;
            }
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
    printf("%d", dist[n-1][m-1]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &board[i][j]);
        }
    }
    bfs();
}