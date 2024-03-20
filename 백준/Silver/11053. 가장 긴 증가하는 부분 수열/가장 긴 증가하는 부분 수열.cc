#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1002];
int d[1002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> arr[i];
    d[i] = 1;
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<i; j++) { // 현재 i보다 작은 인덱스들, 즉 i번쨰 이전의 부분 합들 중에서 최대인 것을 추출
      if(arr[i] > arr[j]) {
        d[i] = max(d[i], d[j] + 1);
      }
    }
  }

  cout << *max_element(d + 1, d + n + 1);

  return 0;
}