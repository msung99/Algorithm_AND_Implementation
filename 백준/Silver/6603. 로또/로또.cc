#include <bits/stdc++.h>
using namespace std;

int n;
int arr[20];
int num[20];

void func(int k, int start) {
  if(k == 6) {
    for(int i=0; i<6; i++) {
      cout << arr[i] << ' ';
    }
    cout << "\n";
    return;
  }

  for(int i=start; i<n; i++) {
    arr[k] = num[i];
    func(k+1, i+1);
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while(true) {
    cin >> n;
    if(n == 0) {
      break;
    }
    for(int i=0; i<n; i++) {
      cin >> num[i];
    }

    func(0, 0);
    cout << "\n";
  }

  return 0;
}