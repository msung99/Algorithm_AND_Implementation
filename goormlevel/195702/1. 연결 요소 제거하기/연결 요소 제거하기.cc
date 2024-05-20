#include <bits/stdc++.h>
using namespace std;

int n, k, q; // 배열 크기, 연결 요소를 지울 연결요소의 크기 값 기준, 문자를 적을 횟수
char board[52][52];
bool visited[52][52];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// (x, y) 에 대한 연결요소의 크기가 k 이상이면 해당 연결요소를 모두 빈칸으로 만들어버리는 함수
void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    vector<pair<int,int>> points; // 현 연결요소에 대한 모든 좌표를 저장하는 함수

    int area = 0;
    while(!q.empty()) {
        area++;
        auto cur = q.front();
        q.pop();
        points.push_back({cur.first, cur.second});

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx <= 0 || nx > n || ny <= 0 || ny > n) {
                continue;
            }

            if(visited[nx][ny] || board[cur.first][cur.second] != board[nx][ny]) {
                continue;
            }

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }


    if(area >= k) {
        for(int i=0; i<points.size(); i++) {
            board[points[i].first][points[i].second] = '.';
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> q;

    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=1; j<=n; j++) {
            board[i][j] = s[j-1];
        }
    }

    while(q--) {
        int x, y;
        char c;
        cin >> x >> y >> c;

        board[x][y] = c;

        for(int i=1; i<=n; i++) {
            fill(visited[i], visited[i] + n + 1, false);
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(!visited[i][j]) {
                    bfs(i, j);
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}