#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool visited[105];
int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m; // 7, 6

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int start = 1;
    queue<int> q;
    q.push(start);

    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(visited[cur]) {
            continue;
        }

        visited[cur] = true;
        cnt++;

        for(auto next : adj_list[cur]) {
            q.push(next);
        }
    }

    cout << cnt -1;

    return 0;
}