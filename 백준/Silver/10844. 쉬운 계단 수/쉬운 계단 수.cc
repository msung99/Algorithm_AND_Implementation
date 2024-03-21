#include <bits/stdc++.h>
using namespace std;

int n;
int d[102][10];
// d[i][j] : 길이 i를 가지며 맨 끝 자릿수(일의 자리 수)가 j로 끝나는 수의 가짓수

// d[i][j] = d[i-1][j+1] + d[i-1][j-1]
// d[[2][2] = d[1][3] + d[1][[1]  => d[2][2] : 길이 2지를 가지며 맨 끝수가 1인 숫자의 경우의 수

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=1; i<=9; i++) {
    d[1][i] = 1;
  }

  for(int i=2; i<=n; i++) {
    for(int j=0; j<=9; j++) {
      // 끝 자리수가 0일때 특이 케이스 처리 : 끝 자리수의 바로 다음 자릿수(끝에서 2번쨰 자릿수) 로 반드시 1만 올 수 있음
      if(j == 0) {
        d[i][0] = d[i-1][1];
      }

      // 끝 자리수가 9일때 특이 케이스 처리 : 끝 자리수의 바로 다음 자릿수(끝에서 2번쨰 자릿수) 로 반드시 8만 올 수 있음
      else if(j == 9) {
        d[i][9] = d[i-1][8];
      }

      // 끝 자리수가 2~8일때
      else {
        d[i][j] = d[i-1][j+1] + d[i-1][j-1];
      }
      
      d[i][j] %= 1000000000;
    }
  }

  int result =0;
  for(int i=0; i<=9; i++) {
    result = (result + d[n][i]) % 1000000000;
  }
  cout << result;

  return 0;
}