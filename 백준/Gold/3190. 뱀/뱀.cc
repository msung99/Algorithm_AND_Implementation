#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int board[102][102];
int move_dir = 1; // 현재 뱀의 이동 방향 
int second;
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int,int>> dq;
queue<pair<int, char>> switchDir;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = -1;
    }

    cin >> l;
    
    while(l--) {
        int time;
        char command;
        cin >> time >> command;
        switchDir.push({time, command});
    }

    dq.push_front({1, 1}); // 뱀의 시작점은 (1,1)    
    // dq에 담기는 정보 = 현재 뱀의 위치
    while(true) {
        move_dir %= 4;
        pair<int,int> head = dq.front(); // 현재 뱀의 머리 좌표 == q.front()
        board[head.first][head.second] = 1; // 현재 좌표에 뱀의 몸통 표식을 채우기
        second++;

        int nx = head.first + dx[move_dir];
        int ny = head.second + dy[move_dir];

        // 벽을 만났거나 뱀 자기자신의 몸과 만난경우 
        if(nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == 1) {
            break;
        }

        // 사과가 없는 좌표를 지나간다면
        if(board[nx][ny] != -1) {
            // 꼬리를 자름
            auto tail = dq.back();
            board[tail.first][tail.second] = 0; 
            dq.pop_back();                
        }
        dq.push_front({nx, ny});

        auto sd = switchDir.front();
        if(sd.first == second) {
            if(sd.second == 'D') {
                move_dir += 3;
            } else if(sd.second == 'L') {
                move_dir += 1;
            }
            switchDir.pop();
        }
    }

    cout << second;

    return 0;
}