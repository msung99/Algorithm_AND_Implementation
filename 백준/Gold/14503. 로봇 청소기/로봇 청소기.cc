#include <bits/stdc++.h>
using namespace std;

int n, m, d;
int x, y; // (x,y): 로봇의 현재 좌표
int board[52][52]; // -1: 이미 방문한 좌표
int ans; 
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

    int checkCnt = 0; // 방향 탐지 횟수
    while(true) {
        // 청소하지 않은 빈 칸일 경우 청소함.
        if(board[x][y] == 0) {
            ans++;
        }
        board[x][y] = -1; // 방문(청소 완료) 처리
        bool cleaned = false; // 4방향 중 청소된 곳이 있는지
        for(int i=0; i<4; i++) {
            d = (d + 3) % 4; // 반시계 방향으로 회전함.
            if(board[x + dx[d]][y + dy[d]] == 0) {
                x = x + dx[d];
                y = y + dy[d];
                cleaned = true;
                break;
            }
        }

        if(cleaned) {
            continue;
        }

        // 4방향 중 청소를 못한 경우, 후진하여 청소를 시도
        if(board[x-dx[d]][y-dy[d]] == 1) {
            break; // 후진이 불가능하면 멈춤
        }

        // 후진이 가능하다면 후진을 함.
        x = x - dx[d];
        y = y - dy[d];
    }
    cout << ans;
    
    return 0;
}