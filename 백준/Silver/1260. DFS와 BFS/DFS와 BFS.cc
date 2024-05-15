#include <bits/stdc++.h>
using namespace std;

int n, m, st;
vector<int> adj_list[1002];
bool visited[1002];

// 비재귀 DFS
void dfs2() {
    stack<int> s;
    s.push(st);
    visited[st] = true;

    while(!s.empty()) {
        int cur = s.top();
        cout << cur << ' ';
        s.pop();
        visited[cur] = true;

        for(int i=0; i<adj_list[cur].size(); i++) {
            // 스택의 특성상 정점을 역순으로 넣아야한다.
            int next = adj_list[cur][adj_list[cur].size()-(i+1)];
            if(!visited[next]) {
                s.push(next);
                visited[next] = true;
            }
        }
    }
}

// 재귀 DFS
void dfs(int cur) {
    visited[cur] = true;
    cout << cur << ' ';
    for(auto next : adj_list[cur]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(st);
    visited[st] = true;

    while(!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        visited[cur] = true;

        for(auto next : adj_list[cur]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> st;

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    dfs(st);
    cout << "\n";
    fill(visited, visited + n+1, false);
    bfs();

    return 0;
}