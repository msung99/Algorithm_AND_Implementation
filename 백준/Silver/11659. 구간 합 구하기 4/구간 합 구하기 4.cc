#include <bits/stdc++.h>
using namespace std;

int n, m;
long long arr[100002];
long long total[100002];
long long d[100002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    cin >> arr[i];
    total[i] = total[i-1] + arr[i];
  }

  while(m--) {
    int start, end;
    cin >> start >> end;

    cout << total[end] - total[start-1] << "\n";
  }

  return 0;
}