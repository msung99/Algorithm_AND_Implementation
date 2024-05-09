#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int cntMinus;
int cntZero;
int cntOne;

void func(int n, int startX, int startY) {  // 6
  if(n == 1) {
    if(board[startX][startY] == -1) {
      cntMinus++;
    }
    if(board[startX][startY] == 0) {
      cntZero++;
    }
    if(board[startX][startY] == 1) {
      cntOne++;
    }
    return;
  }

  int isSameArea = true;
  int color = board[startX][startY];
  for(int i=startX; i<startX+n; i++) {
    for(int j=startY; j<startY+n; j++) {
      if(color != board[i][j]) {
        isSameArea = false;
        break;
      }
    }
  }

  int size = n/3;
  if(!isSameArea) {
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        int newX = startX + size * i;
        int newY = startY + size * j;
        func(size, newX, newY);
      }
    }
  }

  if(isSameArea){
    if(color == -1) {
      cntMinus++;
    }
    if(color == 0) {
      cntZero++;
    }
    if(color == 1) {
      cntOne++;
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
  cout << cntMinus << "\n";
  cout << cntZero << "\n";
  cout << cntOne;

  return 0;
}