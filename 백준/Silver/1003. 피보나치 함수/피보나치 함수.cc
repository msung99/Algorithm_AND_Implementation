#include <bits/stdc++.h>
using namespace std;

int zero[42];
int one[42];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  zero[0] = 1;
  zero[1] = 0;
  zero[2] = 1;

  one[0] = 0;
  one[1] = 1;
  one[2] = 1;

  for(int i=3; i<=40; i++) {
    zero[i] = zero[i-1] + zero[i-2];
    one[i] = one[i-1] + one[i-2];
  }

  int t;
  cin >> t;
  while(t--) {
    int data;
    cin >> data;

    cout << zero[data] << ' ' << one[data] << "\n";
  }
  return 0;
}