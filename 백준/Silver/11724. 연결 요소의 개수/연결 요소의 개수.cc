#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[1002];
bool visited[1002];

void bfs(int x) {
    visited[x] = true;

    queue<int> q;
    q.push(x);

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int data : adj_list[cur]) {
            if(visited[data]) {
                continue;
            }
            q.push(data);
            visited[data] = true;
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

    int area = 0;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            area++;
            bfs(i);
        }
    }

    cout << area;

    return 0;
}