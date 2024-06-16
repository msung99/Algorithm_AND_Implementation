#include <bits/stdc++.h>
using namespace std;

int s, e;
vector<int> adj_list[102];
int dist[102];

void bfs() {
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int next : adj_list[cur]) {
            if(dist[next] != -1) {
                continue;
            }
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
    cout << dist[e];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin >> s >> e;

    int t;
    cin >> t;
    while(t--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }    


    fill(dist, dist + n + 1, -1);

    bfs();

    return 0;
}