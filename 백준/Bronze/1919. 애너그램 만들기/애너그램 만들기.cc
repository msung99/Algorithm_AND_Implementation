#include <bits/stdc++.h>
using namespace std;

int len[2][26]; // 배열, 변수를 전역변수로 선언하면 자동으로 0으로 초기화된다.
int res;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2;
 
  cin >> s1 >> s2;
  
  for(char c : s1)
    len[0][c-'a']++;
  
  for(char c : s2)
    len[1][c-'a']++;
  
  for(int i=0; i<26; i++)
    res += abs(len[0][i]-len[1][i]);
  
  cout << res;
}