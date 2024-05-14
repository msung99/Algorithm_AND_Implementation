#include <bits/stdc++.h>
using namespace std;

int n;
int num[102];
int ops[4];
int mx=-1999999999;
int mn=1999999999;

// k번쨰 숫자에 대한 연산을 진행
void func(int k, int total) {
  if(k == n) {
    mx = max(mx, total);
    mn = min(mn, total);
    return;
  }

  for(int i=0; i<4; i++) {
    if(ops[i] != 0) {
      ops[i]--;
      if(i == 0) {
        func(k+1, total + num[k]);
      } else if(i == 1) {
        func(k+1, total - num[k]);
      } else if(i == 2) {
        func(k+1, total * num[k]);
      } else if(i == 3) {
        func(k+1, total / num[k]);
      }
      ops[i]++;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> num[i];
  }

  for(int i=0; i<4; i++) {
    cin >> ops[i];
  }

  func(1, num[0]);
  cout << mx << "\n";
  cout << mn;

  return 0;
}
