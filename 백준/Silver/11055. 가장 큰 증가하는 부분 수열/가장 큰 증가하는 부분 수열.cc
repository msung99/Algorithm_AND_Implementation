#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1002];
int d[1002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> arr[i];
    d[i] = arr[i]; // d[i] 의 초기값도 설정
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<i; j++) {
      if(d[i] > d[j]) {
        d[i] = max(d[i], d[j] + arr[i]);
      }
    }
  }

  cout << *max_element(d + 1, d + n + 1);

  return 0;
}