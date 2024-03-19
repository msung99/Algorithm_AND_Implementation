#include <bits/stdc++.h>
using namespace std;

long arr[92];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  arr[1] = 1;
  arr[2] = 1;

  for(int i=3; i<=n; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }

  cout << arr[n];

  return 0;
}