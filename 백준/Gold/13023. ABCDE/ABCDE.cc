#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[2002];
bool visited[2002];
int ans;

void dfs(int depth, int cur) {
    visited[cur] = true;

    if(depth == 4) {
        ans = 1;
        return;
    }

    for(int next : adj_list[cur]) {
        if(visited[next]) {
            continue;
        }
        dfs(depth + 1, next);
    }
    visited[cur] = false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        fill(visited, visited + n + 1, false);
        dfs(0, i);
    }
    cout << ans;

    return 0;
}