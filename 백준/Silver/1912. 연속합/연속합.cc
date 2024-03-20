#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100002]; // 입력값
int d[100002]; // d[i] : i번째 항으로 끝나는 연속합 중에 최댓값

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> arr[i];
  }

  for(int i=1; i<=n; i++) {
    d[i] = max(0, d[i-1]) + arr[i];
    // max(0, d[i-1]) => d[i-1] 이 양수라면 이득이므로 더한다. 반대로 음수이므로 더하지 않고 그대로 냅둔다. (= 0을 더한다)
  }

  cout << *max_element(d + 1, d + n + 1);
  return 0;
}
