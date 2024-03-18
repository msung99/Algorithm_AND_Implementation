#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[101];
vector<int> heavy[101]; // heavy[i] : i보다 무거운 구슬 리스트
vector<int> light[101];

bool solve(int start, vector<int> (&adj_list)[]) {
  fill(visited, visited + n + 1, false);

  queue<int> q;
  q.push(start);
  visited[start] = true;

  int mid = (n+1) / 2;
  int cnt = 0;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    for(int next : adj_list[cur]) {
      if(visited[next]) {
        continue;
      }
      cnt++;
      q.push(next);
      visited[next] = true;
    }
  }

  if(cnt >= mid) {
    return true;
  } 
  return false;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0; i<m; i++) {
    int u, v;
    cin >> u >> v;
    heavy[u].push_back(v);
    light[v].push_back(u);
  }

  int ans = 0;
  for(int i=1; i<=n; i++) {
    int start = i;
    ans += (solve(start, heavy) || solve(start, light));
  }

  cout << ans;
  return 0;
}
