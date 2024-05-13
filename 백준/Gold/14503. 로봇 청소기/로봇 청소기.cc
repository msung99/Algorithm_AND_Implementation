#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y;
int board[52][52];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir; // 0: 북, 1: 동, 2: 남, 3: 서

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  cin >> x >> y >> dir;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> board[i][j];
    }
  }

  int cnt = 0;
  while(true) {
    if(board[x][y] == 0) {
      cnt++;
    }
    board[x][y] = -1;

    bool isClean = false;
    for(int i=0; i<4; i++) {
      dir = (dir + 3) % 4;
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(board[nx][ny] == 0) {
        x = nx;
        y = ny;
        isClean = true;
        break;
      }
    }

    if(!isClean) {
      bool isBack = true;

      int nx = x - dx[dir];
      int ny = y - dy[dir];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
        isBack = false;
        break;
      }

      if(board[nx][ny]== 1) {
        isBack = false;
        break;
      }

      if(isBack) {
        x = nx;
        y = ny;
      }
    }
  }
  cout << cnt;

  return 0;
}