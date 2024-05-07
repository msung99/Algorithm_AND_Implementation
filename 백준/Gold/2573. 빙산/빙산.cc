// zero[i][j] ; (i, j) 에 위치한 빙산의 상하좌우에 몇개의 0이 존재하는지
// 빙산이 남아있는 아무 칸 중 하나를 선택해서, cnt1 와 BFS 를 돌리면서 카운팅된 결과인 cnt2 가 서로 같은지 확인한다.
#include <bits/stdc++.h>
using namespace std;

int n, m;
int year;
int board[302][302];
bool visited[302][302];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void melt() {
    int zero[302][302] = {0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] != 0) {
                for(int dir=0; dir<4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }

                    if(board[nx][ny] == 0) {
                        zero[i][j]++;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            board[i][j] = max(0, board[i][j] - zero[i][j]);
        }
    }
}

// 0 : 빙산이 다 녹음, 1 : 아직 한 덩이, 2 : 분리됨
int checkStatus() {
    int cnt1 = 0;
    int startX, startY; // BFS 를 시작할 (x, y) 좌표
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] != 0) {
                startX = i; // 빙산인 좌표들 중에 아무거나 BFS 시작점 좌표로 선정
                startY = j;
                cnt1++; // 현재 남아있는 빙산의 개수를 카운팅
            }
        }
    }

    // 현재 남아있는 빙산이 업다면 (0개라면)
    if(cnt1 == 0) {
        return 0;
    }

    // BFS 수행
    int cnt2 =0;
    queue<pair<int,int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while(!q.empty()) {
        auto cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();

        cnt2++;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if(visited[nx][ny] || board[nx][ny] == 0) {
                continue;
            }

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    if(cnt1 == cnt2) {
        return 1;
    } else {
        return 2;
    }
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

    while(true) {
        year++; // 1년 추가
        for(int i=0; i<n; i++) {
            fill(visited[i], visited[i] + m, false);
        }

        melt(); // 빙산 녹이기
        int res = checkStatus();

        // 빙산이 아예 존재하지 않는 경우
        if(res == 0) {
            cout << 0;
            break;
        }

        // 아직 덩어리가 분리되지 않고 1개인 경우
        if(res == 1) {
            continue;
        }

        // 덩어리의 개수가 2개 이상으로 분리된 경우
        if(res == 2) {
            cout << year;
            break;
        }
    }

    return 0;
}