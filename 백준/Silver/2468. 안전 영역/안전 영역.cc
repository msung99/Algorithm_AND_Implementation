#include <bits/stdc++.h>
using namespace std;

int n;
int board[101][101];
int visited[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void dfs(int x, int y, int rain) {
    visited[x][y] = 1;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }
        if(!visited[nx][ny] && board[nx][ny] > rain) {
            dfs(nx, ny, rain);
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
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    int result = 1;
    for(int rain= 1; rain <= 100; rain++) {
        int temp = 0;
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && board[i][j] > rain) {  // board[i][j] > rain  ==  1
                    dfs(i, j, rain);
                    temp++;
                }
            }
        }
        result = max(result, temp);
    }
    cout << result;
    return 0;
}