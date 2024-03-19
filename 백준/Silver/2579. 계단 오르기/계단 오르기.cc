// d[i][j] : 현재까지 j개의 계단을 연속해서 밟고 i번째 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓값, 단 i번째 계단은 반드시 밟아야 함.
// d[i][1] = max(d[i-2][1], d[i-2][2]) + arr[i]
// d[i][2] = d[i-1][1] + arr[i]
#include <bits/stdc++.h>
using namespace std;

int n;
int d[302][3];
int arr[302];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> arr[i];
  }

  d[1][1] = arr[1];
  d[1][2] = 0;
  d[2][1] = arr[2];
  d[2][2] = arr[1] + arr[2];

  for(int i=3; i<=n; i++) {
    d[i][1] = max(d[i-2][1], d[i-2][2]) + arr[i];
    d[i][2] = d[i-1][1] + arr[i];
  }

  cout << max(d[n][1], d[n][2]);

  return 0;
}