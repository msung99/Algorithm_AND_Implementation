#include <bits/stdc++.h>
using namespace std;

string board[4];

void go(int num, int dir) {
  int dirs[4] = {};
  num--;
  dirs[num] = dir;

  // 왼쪽으로 회전 전파
  for(int idx = num; idx > 0; idx--) {
    if(board[idx][6] == board[idx-1][2]) {
      break;
    }
    dirs[idx-1] = -dirs[idx];
  }

  // 오른쪽으로 회전 전파
  for(int idx = num; idx < 3; idx++) {
    if(board[idx][2] == board[idx+1][6]) {
      break;
    }
    dirs[idx+1] = -dirs[idx];
  }

  for(int i=0; i<4; i++) {
    if(dirs[i] == 1) { // 시계방향 회전
      rotate(board[i].begin(), board[i].begin() + 7, board[i].end());
    } 
    else if(dirs[i] == -1) { // 반시계방향 회전
      rotate(board[i].begin(), board[i].begin() + 1, board[i].end());
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=0; i<4; i++) {
    cin >> board[i];
  }
  
  int total = 0;
  int k;
  cin >> k;
  while(k--) {
    int num, dir;
    cin >> num >> dir;
    go(num, dir);
  }

  for(int i=0; i<4; i++) {
    if(board[i][0] == '1') {
      total += (1 << i);
    }
  }
  cout << total;

  return 0;
}