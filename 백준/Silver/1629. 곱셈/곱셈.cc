#include <bits/stdc++.h>
using namespace std;

long long func(int a, int b, int c) {
  if(b == 1) {
    return a % c;
  }

  long long div = func(a, b/2, c);
  if(b % 2 == 0) {
    return div * div % c;
  } else {
    return ((div * div % c) * a) % c;
  }
}


int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, b, c;
  cin >> a >> b >> c;
  cout << func(a, b, c);

  return 0;
}