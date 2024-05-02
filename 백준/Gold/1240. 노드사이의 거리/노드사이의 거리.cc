#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> adj_list[1002];
bool visited[1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n-1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj_list[u].push_back({v, d});
        adj_list[v].push_back({u, d});
    }

    while(m--) {
        int source, dest;
        cin >> source >> dest;
        fill(visited, visited + n + 1 , false);
        queue<pair<int,int>> q;
        q.push({source, 0});
        visited[source] = true;

        while(!q.empty()) {
            auto [cur, dist] = q.front();
            q.pop();

            if(cur == dest) {
                cout << dist << "\n";
                break;
            }

            for(auto [next, nextDist] : adj_list[cur]) {
                if(visited[next]) {
                    continue;
                }
                visited[next] = true;
                q.push({next, dist + nextDist});
            }
        }
    }

    return 0;
}