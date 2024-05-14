#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100002];
int d[100002]; // d[i] : i번째 항까지의 연속합 중에 최댓값

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }
  
  for(int i=0; i<n; i++) {
    d[i] = max(0, d[i-1]) + arr[i];
  }
  
  cout << *max_element(d, d + n);

  return 0;
}