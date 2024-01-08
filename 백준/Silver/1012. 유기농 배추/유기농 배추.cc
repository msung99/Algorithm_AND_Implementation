#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
int board[51][51];
bool visited[51][51];
int result;
int m ,n, k;

void bfs(int startY, int startX) {
    queue<pair<int, int>> q;
    q.push(make_pair(startY, startX));

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y < 0 || y >= n || x < 0 || x >= m || visited[y][x] || board[y][x] == 0) {
            continue;
        }
        q.push({y, x});
        visited[y][x] = true;

        for(int i=0; i<4; i++) {
            int curY = y + dy[i];
            int curX = x + dx[i];
            q.push({curY, curX});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        fill(&board[0][0], &board[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        cin >> m >> n >> k;

        for(int i=0; i<k; i++) {
            int y, x;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && board[i][j] == 1) {
                    bfs(i, j);
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
    return 0; 
}