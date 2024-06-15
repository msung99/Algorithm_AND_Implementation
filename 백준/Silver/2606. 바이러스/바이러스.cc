#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[102];
bool visited[102];

void bfs(int st) {
    queue<int> q;
    q.push(st);
    visited[st] = true;

    int area = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        area++;

        for(int next : adj_list[cur]) {
            if(visited[next]) {
                continue;
            }
            visited[next] = true;
            q.push(next);
        }
    }    
    cout << area -1;
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

    bfs(1);

    return 0;
}