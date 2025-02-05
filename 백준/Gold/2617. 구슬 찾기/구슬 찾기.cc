#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> heavy[101];
vector<int> light[101];
bool visited[101];

bool bfs(int st, vector<int> adj_list[101]) {
    fill(visited, visited + n+1, false);
    queue<int> q;
    q.push(st);
    visited[st] = true;

    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next : adj_list[cur]) {
            if(visited[next]) {
                continue;
            }
            cnt++;
            visited[next] = true;
            q.push(next);
        }
    }

    int mid = (n+1)/2;

    if(cnt >= mid) {
        return true;
    }
    return false;
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
        heavy[u].push_back(v);
        light[v].push_back(u);
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans += (bfs(i, heavy) || bfs(i, light));
    }
    cout << ans;

    return 0;
}