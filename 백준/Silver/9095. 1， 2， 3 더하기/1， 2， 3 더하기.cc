#include <bits/stdc++.h>
using namespace std;

int t;
int d[12]; // d[i] : 정수 i를 나타내는 방법 
// d[i] = d[i-1] + d[i-2] + d[i-3]

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  d[1] = 1;
  d[2] = 2;
  d[3] = 4;

  for(int i=4; i<=11; i++) {
    d[i] = d[i-1] + d[i-2] + d[i-3];
  }

  while(t--) {
    int n;
    cin >> n;
    cout << d[n] << "\n";
  }


  return 0;
}