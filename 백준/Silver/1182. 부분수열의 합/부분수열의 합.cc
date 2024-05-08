// k 번째 수에 대해서까지 부분수열을 만들었다면 k+1 번쨰 수에 대해서도 부분수열을 만들 수 있다.
// k+1 번쨰 수에 대해 부분수열을 만드는 방법 : k번째 수를 택하는 경우 / k번쨰 수를 택하지 않는 경우
#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[22];
int res;

void func(int k, int total) {
  // n번째 숫자에 대해서까지 선택 여부를 모두 결정해줬다면
  if(k == n) {
    if(total == s) {
      res++;
    }
    return;
  }

  func(k+1, total);
  func(k+1, total + arr[k]);
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }

  func(0, 0);
  if(s == 0) {
    res--;
  }
  cout << res;

  return 0;
}