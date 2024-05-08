#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[22];
int res;

// k 번쨰 수를 택했다면 k+1 번쨰 수도 택할 수 있다.
// k+1번째 수를 택하는 방법 : k+1 번쨰 수를 택한다 / 택하지 않는다.
void func(int k, int total) {
  if(k == n) {
    if(total == s) {
      res++;      
    }
    return;
  }

  func(k+1, total + arr[k]);
  func(k+1, total);
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;

  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }

  func(0, 0);

  if(s == 0) {
    res--;
  }
  cout << res;

  return 0;
}