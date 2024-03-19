#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  arr[1] = 1;
  arr[2] = 3;
  arr[3] = 5;

  cin >> n;

  for(int i=4; i<=n; i++) {
    arr[i] = (arr[i-1] + arr[i-2] * 2) % 10007;
  }

  cout << arr[n];
  return 0;
}