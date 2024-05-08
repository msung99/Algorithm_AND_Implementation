#include <bits/stdc++.h>
using namespace std;

// k-1 번쨰 수를 택하여 순열을 만들 수 있다면, K번째 수를 택하여 순열을 만들 수 있다.
// 택하는 방법 : 중복되는 원소들을 제거하여 그 중 원소를 택한다.
int n, m;
int arr[10002];
int num[10];
bool isAppeared[10002];

void func(int k, int cnt) {
  if(k == m) {
    for(int i=0; i<m; i++) {
      cout << arr[i] << ' ';
    }
    cout << "\n";
    return;
  } 

  for(int i=0; i<cnt; i++) {
    arr[k] = num[i];
    func(k+1, cnt);
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  int cnt = 0; // 중복된 숫자를 제거하고 남은 순수한 원소 갯수

  for(int i=0; i<n; i++) {
    int data;
    cin >> data;
    if(!isAppeared[data]) {
      isAppeared[data] = true;
      num[cnt] = data;
      cnt++;
    }
  }

  sort(num, num + cnt);
  func(0, cnt);

  return 0;
}