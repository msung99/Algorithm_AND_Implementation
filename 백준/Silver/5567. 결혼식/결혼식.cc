#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj_list[505];
int dist[505]; // dist[i] : i번째 이웃

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(dist, dist + 505, -1);

    cin >> n; // 6
    cin >> m; // 5

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int start = 1;
    queue<int> q; 
    q.push(start);  
    dist[start] = 0;

    while(!q.empty()) {
        int cur = q.front(); 
        q.pop();

        for(auto next : adj_list[cur]) {
            if(dist[next] != -1) {
                continue;
            }

            q.push(next);
            dist[next] = dist[cur] + 1; 
        }
    }

    int cnt = 0;
    for(int i=0; i<505; i++) {
        if(dist[i] == 1 || dist[i] == 2) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}