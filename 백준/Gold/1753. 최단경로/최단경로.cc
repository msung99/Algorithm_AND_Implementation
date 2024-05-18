// 1번 정점에서 n번 정점으로 이동 가능한 최단 경로 2가지
// 1 -> a -> b -> n
// 1 -> b -> a -> n
#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<pair<int,int>> adj_list[805];
int dist[805];
int infinite = 0x3f3f3f3f;

long long djikstra(int source, int dest) {
    fill(dist, dist + n + 1, infinite);
    dist[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dist[source], source});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        for(auto next : adj_list[cur.second]) {
            if(dist[next.second] <= dist[cur.second] + next.first) {
                continue;
            }
            dist[next.second] = dist[cur.second] + next.first;
            pq.push({dist[next.second], next.second});
        }
    }
    return dist[dest];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e;

    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({w, v});
        adj_list[v].push_back({w, u});
    }

    int v1, v2;
    cin >> v1 >> v2;

    long long ans1 = djikstra(1, v1) + djikstra(v1, v2) + djikstra(v2, n);
    long long ans2 = djikstra(1, v2) + djikstra(v2, v1) + djikstra(v1, n);
    long long res = min(ans1, ans2);

    if(res >= infinite) {
        res = -1;
    }
    cout << res;

    return 0;
}
