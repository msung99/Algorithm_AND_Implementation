#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[502];
int dist[502];

void bfs(int sx) {
    queue<int> q;
    q.push(sx);
    dist[sx] = 0;

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
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    fill(dist, dist + n+1, -1);
    bfs(1);

    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(dist[i] == 1 || dist[i] == 2) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}