#include <bits/stdc++.h>
using namespace std;

int n;
long long d[1002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  d[1] = 1;
  d[2] = 3;

  for(int i=3; i<=n; i++) {
    d[i] = (d[i-1] + 2*d[i-2]) % 10007;
  }
  cout << d[n];

  return 0;
}