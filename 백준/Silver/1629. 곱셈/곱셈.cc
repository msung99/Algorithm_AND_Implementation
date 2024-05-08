#include <bits/stdc++.h>
using namespace std;

int res = 1;
// a를 k-1번 곱한 결과를 구할 수 있다면, k번 곱한 결과도 구할 수 있다.

long long func(long long a, long long b, long long c) {
  if(b == 1) {
    return a % c;
  }

  long long val = func(a, b/2, c);
  val = val * val % c;
  if(b%2 == 1) {
    return val * a % c;
  }
  return val;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long a, b, c;

  cin >> a >> b >> c;

  cout << func(a, b, c);

  return 0;
}