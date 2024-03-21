#include <bits/stdc++.h>
using namespace std;

int n;
int t[1002];
int p[1002];
int d[1002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> t[i] >> p[i];
  }

  // 역순으로 순회
  for(int i=n; i >=1; i--) {
    // 상담이 가능한 날짜라면
    if(i + t[i] <= n+1) {
      d[i] = max(d[i+1], d[i + t[i]] + p[i]); 
      // d[i+1] : 상담을 하지 않았을 때 최대 누적 수익 / d[i +t[i]] + p[i] : 상담했을 떄의 누적 수익
    } 
    // 상담이 불가능하다면
    else {
      d[i] = d[i+1];
    }
  }

  cout << *max_element(d + 1, d + n + 1);

  return 0;
}