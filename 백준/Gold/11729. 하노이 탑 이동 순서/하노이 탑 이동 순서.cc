#include <bits/stdc++.h>
using namespace std;

void func(int n, int a, int b) {
  if(n == 1) {
    cout << a << ' ' << b << "\n";
    return;
  }

  func(n-1, a, 6-a-b);
  cout << a << ' ' << b << "\n";
  func(n-1, 6-a-b, b);
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  cout << (1<<n) - 1 << "\n";
  func(n, 1, 3);

  return 0;
}