// https://ongveloper.tistory.com/36
#include <bits/stdc++.h>

using namespace std;

string str1, str2;
int d[1002][1002]; // d[i][j] : str1 의 i행까지의 문자열과, str2 의 j열까지의 문자열 사이의 LCS 길이

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> str1;
  cin >> str2;

  int len1 = str1.length();
  int len2 = str2.length();

  for(int i=1; i<=len1; i++) {
    for(int j=1; j<=len2; j++) {
      if(str1[i-1] == str2[j-1]) {
        d[i][j] = d[i-1][j-1] + 1;
      } else {
        d[i][j] = max(d[i-1][j], d[i][j-1]);
      }
    }
  }

  cout << d[len1][len2];

  return 0;
}