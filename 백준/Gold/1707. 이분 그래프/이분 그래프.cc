#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int> adj_list[20002];
int flag[20002]; // -1: 아직 방문안함 / 1 또는 2로 구성 

bool solve() {
  fill(flag, flag + v + 1, -1);

  for(int i=1; i<=v; i++) {
    if(flag[i] != -1) {
      continue;
    }

    queue<int> q;
    q.push(i);
    flag[i] = 1;

    while(!q.empty()) {
      int cur = q.front();
      q.pop();

      for(int next : adj_list[cur]) {
        // next 가 이미 색칠되어 있는 경우
        if(flag[next] != -1) {
          if(flag[cur] == flag[next]) { // 현재 칸(cur) 과 다음 칸(next) 의 색깔이 서로 같다면
            return false;
          } else {
            continue;
          }
        }

        // flag[next] == -1 인 경우 (처음 방문하는 경우)
        if(flag[cur] == 1) {
          flag[next] = 2;
        } else if(flag[cur] == 2) {
          flag[next] = 1;
        }
        q.push(next);
      }
    }
  }
  return true;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while(t--) {
    cin >> v >> e;

    for(int i=1; i<= v; i++) {
      adj_list[i].clear();
    }

    for(int i=0; i<e; i++) {
      int u, v;
      cin >> u >> v;
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }

    if(solve()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}