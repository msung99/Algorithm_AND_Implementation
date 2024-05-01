#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj_list[100003];
int p[100003];

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int next : adj_list[cur]) {
            if(p[cur] == next) {
                continue;
            }
            q.push(next);
            p[next] = cur;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bfs(1);

    for(int i=2; i<=n; i++) {
        cout << p[i] << "\n";        
    }

    return 0;
}