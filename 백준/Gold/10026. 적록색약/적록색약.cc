#include <iostream>
#include <utility>
#include <string>
#include <queue>
using namespace std;


#define X first
#define Y second
char board[101][101];
bool vis[101][101];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int area1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 1)
                continue;
            area1++;
            queue<pair<int, int>> Q1;
            Q1.push({ i,j });
            vis[i][j] = 1;
            while (!Q1.empty()) {
                auto cur = Q1.front();
                Q1.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int x = cur.X + dx[dir];
                    int y = cur.Y + dy[dir];

                    if (x < 0 || x >= n || y < 0 || y >= n)
                        continue;
                    if (vis[x][y] == 1 || board[i][j] != board[x][y])
                        continue;

                    vis[x][y] = 1;
                    Q1.push({ x,y });
                }
            }
        }
    }

    // 적록색약인 사람을 구하기위한 방문배열 초기화
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }

    int area2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 1)
                continue;
            area2++;
            queue<pair<int, int>> Q2;
            Q2.push({ i,j });
           
            vis[i][j] = 1;
            while (!Q2.empty()) {
                auto cur = Q2.front();
                Q2.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int x = cur.X + dx[dir];
                    int y = cur.Y + dy[dir];

                    if (x < 0 || x >= n || y < 0 || y >= n)
                        continue;
                    if (vis[x][y] == 1 || board[i][j] != board[x][y])
                        continue;

                    vis[x][y] = 1;
                    Q2.push({ x,y });
                }
            }
        }
    }

    cout << area1 << ' ' << area2;
}
