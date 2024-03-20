#include <bits/stdc++.h>
using namespace std;

int t;
int arr[102];
long long d[102];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  d[1] = 1;
  d[2] = 1;
  d[3] = 1;

  for(int i=4; i<=100; i++) {
    d[i] = d[i-2] + d[i-3];
  }

  cin >> t;  
  while(t--) {
    int data;
    cin >> data;
    cout << d[data] << "\n";
  }
  return 0;
}