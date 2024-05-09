#include <bits/stdc++.h>
using namespace std;
// 1~n 사이의 숫자중에 중복없이 m개를 고른 수열
int n, m;
int arr[10];
bool isused[10];

void func(int k) {
  if(k == m) {
    for(int i=0; i<m; i++) {
      cout << arr[i] << ' ';
    }
    cout << "\n";
  }

  for(int i=1; i<=n; i++) {
    if(!isused[i]) {
      isused[i] = true;
      arr[k] = i;
      func(k+1);
      isused[i] = false;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  func(0);

  return 0;
}