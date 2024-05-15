#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[102];
// 단방향 그래프 2개로 나눔
vector<int> heavy[102]; // heavy[i] : i보다 무거운 구슬 리스트
vector<int> light[102];

bool bfs(int st, vector<int> adj_list[102]) {
    fill(visited, visited + n+1, false);

    queue<int> q;
    q.push(st);
    visited[st] = true;

    int mid = (n+1) / 2;
    int cnt = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int next : adj_list[cur]) {
            if(visited[next]) {
                continue;
            }
            cnt++;
            q.push(next);
            visited[next] = true;
        }
    }

    if(cnt >= mid) {
        return true;
    } else {
        return false;
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
        heavy[u].push_back(v);
        light[v].push_back(u);
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        int st = i;
        ans += (bfs(st, heavy) || bfs(st, light));
    }
    cout << ans;

    return 0;
}