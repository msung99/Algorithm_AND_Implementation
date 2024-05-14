#include <bits/stdc++.h>
using namespace std;

int n;
int d[100002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++) {
    d[i] = i;
    for(int j=1; j*j<=i; j++) {
      d[i] = min(d[i], d[i - j*j] + 1);
    }
  }

  cout << d[n];

  return 0;
}