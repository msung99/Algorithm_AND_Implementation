#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10];
int num[15];

// k+1번쨰 숫자를 택하는데, 이때 로또 공 중에서 cur 번쨰 숫자부터 택한다.
void func(int k, int cur) {
  if(k == 6) { // 7번쨰 숫자를 택하는 경우. 즉, 이미 6개의 공을 모두 선택한 경우
    for(int i=0; i<6; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i=cur; i<n; i++) {
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
    cout << '\n';
  }

  return 0;
}