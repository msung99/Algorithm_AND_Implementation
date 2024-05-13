#include <bits/stdc++.h>
using namespace std;

int n;
int num[12];
int ops[12];
int mn = 1999999999;
int mx = -1999999999;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> num[i];
  }

  for(int op=0, idx=1; op<4; op++) {
    int x;
    cin >> x;
    while(x--) {
      ops[idx++] = op;
    }
  }
  
  do {
    int res = 0;
    for(int i=0; i<n; i++) {
      if(ops[i] == 0) {
        res += num[i];
      } else if(ops[i] == 1) {
        res -= num[i];
      } else if(ops[i] == 2) {
        res *= num[i];
      } else if(ops[i] == 3) {
        res /= num[i];
      }
    }
    mx = max(res, mx);
    mn = min(res, mn);
  } while(next_permutation(ops+1, ops+n));

  cout << mx << "\n";
  cout << mn;

  return 0;
}