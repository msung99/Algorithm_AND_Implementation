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
        fill(visited, visited + n + 1, false);

        queue<pair<int,int>> q;
        q.push({source, 0});
        visited[source] = true;

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            if(cur.first == dest) {
                cout << cur.second << "\n";
                break;
            }
            
            for(auto next : adj_list[cur.first]) {
                if(visited[next.first]) {
                    continue;
                }
                visited[next.first] = true;
                q.push({next.first, cur.second+next.second});
            }
        }
    }

    return 0;
}