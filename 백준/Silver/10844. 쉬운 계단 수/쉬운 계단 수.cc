// d[i][j] : i번쨰 수로 숫자 j를 선택하는 경우의 수 
// d[i][j] = d[i-1][j+1] + d[i-1][j-1]

#include <bits/stdc++.h>
using namespace std;

int n;
int d[102][102];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int cnt = 0;

  for(int i=1; i<=9; i++) {
    d[1][i] = 1;
  }

  for(int i=2; i<=n; i++) {
    for(int j=0; j<=9; j++) {
      if(j != 0) {
        d[i][j] += d[i-1][j-1];
      }
      if(j != 9) {
        d[i][j] += d[i-1][j+1];
      }
      d[i][j] %= 1000000000;
    }
  }

  long long res = 0;
  for(int i=0; i<=9; i++) {
    res += d[n][i];
  }
  cout << res % 1000000000;

  return 0;
}