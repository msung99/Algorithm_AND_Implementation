#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[1002][1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;

    for(int i=0; i<n; i++) {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;

        for(int j=0; j<m; j++) {
            board[i][j] = s[j];

            if(board[i][j] == 'J') {
                q1.push({i, j});
                dist1[i][j] = 0;
            }

            if(board[i][j] == 'F') {
                q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }

    // 불에 대한 처리
    while(!q2.empty()) {
        auto cur = q2.front();
        q2.pop();

        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }            

            if(board[nx][ny] == '#' || dist2[nx][ny] != -1) {
                continue;
            }
            dist2[nx][ny] = dist2[x][y] + 1;
            q2.push({nx, ny});
        }
    }

    // 지훈이에 대한 처리
    while(!q1.empty()) {
        auto cur = q1.front();
        q1.pop();

        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist1[x][y] + 1; // 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 된다.
                return 0;
            }

            if(board[nx][ny] == '#' || dist1[nx][ny] != -1) {
                continue;
            }

            // 불의 전파 시간을 조건에 추가
            if(dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[x][y] + 1) {
                continue;
            }

            dist1[nx][ny] = dist1[x][y] + 1;
            q1.push({nx, ny});
        }
    }    

    cout << "IMPOSSIBLE";

    return 0;
}