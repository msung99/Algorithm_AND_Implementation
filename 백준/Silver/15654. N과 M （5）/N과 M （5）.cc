#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k) {
  if(k == m) {
    for(int i=0; i<m; i++) {
      cout << arr[i] << ' ';
    }
    cout << "\n";
    return;
  }

  for(int i = 0; i < n; i++) {
    if(!isused[i]) {
      arr[k] = num[i];
      isused[i] = true;
      func(k+1);
      isused[i] = false;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0; i<n; i++) {
    cin >> num[i];
  }
  sort(num, num + n);

  func(0);

  return 0;
}