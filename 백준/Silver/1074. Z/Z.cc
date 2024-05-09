#include <bits/stdc++.h>
using namespace std;

// 2^n x 2^n 배열에서 (r, c) 를 방문하는 순서를 리턴하는 함수 
int func(int n, int r, int c) {
  if(n == 0) {
    return 0;
  }
  int half = 1 << (n-1);
  if(r < half && c < half) {
    return func(n-1, r, c);
  }
  if(r < half && c >= half) {
    return half*half + func(n-1, r, c-half);
  }
  if(r >= half && c < half) {
    return 2*half*half + func(n-1, r-half, c);
  }
  return 3*half*half + func(n-1, r-half, c-half);    
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, r, c;
  cin >> n >> r >> c;
  cout << func(n, r, c);

  return 0;
}