#include <bits/stdc++.h>
using namespace std;

int n;
int board[22][22];
 
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> board[i][j];
    }
  }

  vector<int> team(n);
  fill(team.begin() + n/2, team.end(), 1);

  int mn = 1999999999;
  do {
    int cur = 0;
    for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
        if(team[i] != team[j]) {
          continue;
        }
        if(team[i] == 0) {
          cur += (board[i][j] + board[j][i]);
        }
        else {
          cur -= (board[i][j] + board[j][i]);
        }
      }
    }
    mn = min(mn, abs(cur));
  } while(next_permutation(team.begin(), team.end()));

  cout << mn;

  return 0;
}