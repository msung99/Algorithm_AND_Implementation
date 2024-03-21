#include <bits/stdc++.h>
using namespace std;

int d[1002][1002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string str1, str2;
  cin >> str1 >> str2;

  int size1 = str1.length();
  int size2 = str2.length();

  for(int i=1; i<=size1; i++) {
    for(int j=1; j<=size2; j++) {
      if(str1[i-1] == str2[j-1]) {
        d[i][j] = d[i-1][j-1] + 1;
      } else {
        d[i][j] = max(d[i-1][j], d[i][j-1]);
      }
    }
  }

  cout << d[size1][size2];

  return 0;
}