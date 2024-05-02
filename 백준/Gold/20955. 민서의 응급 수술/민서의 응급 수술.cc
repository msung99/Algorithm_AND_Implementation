// connected component 개수 - 1 = 정답
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[100002];
bool visited[100002];

void dfs(int cur) {
    if(visited[cur]) {
        return;
    }
    visited[cur] = true;
    for(auto next : adj_list[cur]) {
        dfs(next);
    }
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
        
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if(visited[i]) {
            continue;
        }
        dfs(i);
        cnt++;
    }

    cout << (cnt -1) + (m+cnt-1) - (n-1);

    return 0;
}