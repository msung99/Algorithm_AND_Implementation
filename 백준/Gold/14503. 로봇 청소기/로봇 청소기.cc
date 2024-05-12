#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y, d;
// d => 1: 북, 2: 동, 3: 남, 4: 서
int board[52][52];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> x >> y >> d;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0; // 방향 탐지 횟수
    while(true) {

        // 현재 칸이 청소되지 않았다면 청소를 한다.
        if(board[x][y] == 0) {
            cnt++;
        }
        board[x][y] = -1; // 현재 칸에 대해 방문 완료(청소 완료) 처리

        bool isCleaned = false; // 4방향 중 청소된 곳이 있는지
        for(int i=0; i<4; i++) {
            d = (d + 3) % 4;  // 반시계 방향으로 회전함.
            if(board[x+dx[d]][y+dy[d]] == 0) {
                x = x + dx[d];
                y = y + dy[d];
                isCleaned = true;
                break;
            }
        }

        // 4방향 중에 청소 가능한 곳이 있어서 그곳으로 이동한 경우
        if(isCleaned) {
            continue;
        }

        // 4방향 중 청소를 못한 경우, 후진하여 청소를 시도
        if(board[x-dx[d]][y-dy[d]] == 1) {
            break;
        }

        // 후진이 가능하다면 후진을 한다.
        x = x - dx[d];
        y = y - dy[d];
    }

    cout << cnt;

    return 0;
}