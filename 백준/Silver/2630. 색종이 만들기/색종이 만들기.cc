#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int cnt[2];

void func(int n, int startX, int startY) {
  if(n == 1) {
    cnt[board[startX][startY]]++;
    return;
  }

  bool isSameArea = true;
  int color = board[startX][startY];

  for(int i=startX; i < startX + n; i++) {
    for(int j=startY; j < startY + n; j++) {
      if(color != board[i][j]) {
        isSameArea = false;
        break;
      }
    }
  }

  if(isSameArea) {
    cnt[board[startX][startY]]++;
  } else {
    int size = n/2;
    for(int i=0; i<2; i++) {
      for(int j=0; j<2; j++) {
        int newX = startX + size * i;
        int newY = startY + size * j;
        func(size, newX, newY);
      }
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> board[i][j];
    }
  }

  func(n, 0, 0);

  cout << cnt[0] << "\n";
  cout << cnt[1];

  return 0;
}