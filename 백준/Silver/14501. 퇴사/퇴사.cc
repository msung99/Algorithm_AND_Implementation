#include <bits/stdc++.h>
using namespace std;

int n;
int d[20]; // i번째 날에 상담을 진행했을 때 얻을 수 있는 최대 "누적 " 수익
int t[20];
int p[20];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> t[i] >> p[i];
  }

  for(int i=n; i>0; i--) {
    // 상담이 진행 가능한 날짜인 경우
    if(i + t[i] <= n+1) {
      // i + t[i] 번째 날에 상담을 진행했을 때와, 상담을 진행하지 않았을때 얻을 수 있는 최대 "누적" 수익 중에 최댓값을 취함
      d[i] = max(d[i + t[i]] + p[i], d[i+1]);
    } 
    // 상담이 진행 불가능한 날짜인 경우
    else {
      d[i] = d[i+1];
    }
  }

  cout << *max_element(d+1, d+n+1);

  return 0;
}