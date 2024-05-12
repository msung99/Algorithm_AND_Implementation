#include <bits/stdc++.h>
using namespace std;

int n;
int k;
int l;
int board[102][102];
deque<pair<int,int>> dq;
queue<pair<int,char>> switchDir;
int moveDir = 1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> k;
    while(k--) {
        int x, y;
        cin >> x >> y;
        board[x][y] = -1; // 사과를 -1로 표시
    }

    cin >> l;
    while(l--) {
        int time;
        char command;
        cin >> time >> command;
        switchDir.push({time, command});
    }

    dq.push_back({1, 1});

    int time = 0;
    while(true) {
        time++;
        auto head = dq.front();
        int x = head.first;
        int y = head.second;
        board[x][y] = 1; 

        int nx = x + dx[moveDir];
        int ny = y + dy[moveDir];

        // 범위를 벗어난 경우
        if(nx < 1 || nx > n || ny < 1 || ny > n) {
            break;
        }
        // 뱀의 본인 몸통 자신을 만나서 충돌한 경우
        if(board[nx][ny] == 1) {
            break;
        }

        // 이동한 좌표에 사과가 없다면, 꼬리를 잘라낸다.
        if(board[nx][ny] != -1) {
            auto tail = dq.back(); // 꼬리 좌표를 추출
            // 꼬리 제거
            board[tail.first][tail.second] = 0;  
            dq.pop_back();
        }

        auto dir = switchDir.front();
        if(dir.first == time) {
            char command = dir.second;
            if(command == 'D') {
                moveDir = (moveDir + 3) % 4;
            }
            if(command == 'L') {
                moveDir = (moveDir + 1) % 4;
            }
            switchDir.pop();
        }
        dq.push_front({nx, ny}); // 뱀의 머리를 최신화. 현재 새롭게 이동한 좌표로 최신화한다.
    }
    
    cout << time;

    return 0;
}