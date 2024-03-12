#include <bits/stdc++.h>
using namespace std;

int n,m,start;
vector<int> adj_list[1005];
bool visited[1005];

void dfs() {
    stack<int> s;
    s.push(start);
    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        if(visited[cur]) {
            continue;
        }
        visited[cur] = true;
        cout << cur << ' ';
        for(int i=0; i<adj_list[cur].size(); i++) {
            int next = adj_list[cur][adj_list[cur].size() - 1 - i];
            if(visited[next]) {
                continue;
            }
            s.push(next);
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for(int next : adj_list[cur]) {
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

    cin >> n >> m >> start;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    dfs();
    cout << "\n";
    fill(visited+1, visited+n+1, false);
    bfs();
}