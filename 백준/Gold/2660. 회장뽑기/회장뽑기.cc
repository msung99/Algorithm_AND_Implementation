#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj_list[55];
int dist[55];
int score[55];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  while(true) {
    int u, v;
    cin >> u >> v;

    if(u == -1 && v == -1) {
      break;
    }

    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  for(int i=1; i<=n; i++) {
    queue<int> q;
    fill(dist, dist + n + 2, -1);

    dist[i] = 0;
    q.push(i);

    while(!q.empty()) {
      int cur = q.front();
      q.pop();

      for(int next : adj_list[cur]) {
        if(dist[next] != -1) {
          continue;
        }

        dist[next] = dist[cur] + 1;
        q.push(next);
      }
    }

    int minValue = *max_element(dist + 1, dist + n + 1);
    score[i] = minValue;
  }

  int minScore = *min_element(score + 1, score + n + 1);
  vector<int> personList;
  int cnt = 0;

  for(int i=1; i<=n; i++) {
    if(score[i] == minScore) {
      personList.push_back(i);      
      cnt++;
    }    
  }

  cout << minScore << ' ' << cnt << "\n";
  for(int i=0; i<personList.size(); i++) {
    cout << personList[i] << ' ';
  }

  return 0;
}