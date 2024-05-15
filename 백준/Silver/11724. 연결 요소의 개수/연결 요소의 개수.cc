#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[1005];
bool visited[1005];

void bfs(int i) {
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()) {
        int cur = q.front();
         q.pop();
        for(auto next : adj_list[cur]) {
            if(visited[next]) {
                continue;
            }
            q.push(next);
            visited[next] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m; // 6, 5

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if(visited[i]) {
            continue;
        }
        bfs(i);
        cnt++;
    }
    cout << cnt;
    return 0;
}